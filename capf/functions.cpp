#include "structs.cpp"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>



//calcul de la distance entre deux noeuds
double distance(node premierNoeud,node deuxiemeNoeud){

    return(sqrt((double)(pow((premierNoeud.rec.x-deuxiemeNoeud.rec.x),2)+pow((premierNoeud.rec.y-deuxiemeNoeud.rec.y),2))));

}

//allocation de l'espace mémoire pour un graphe(matrice de distances)
double** allocateGraph(int N, node* LesNodes)
{

    double** graphe= new double*[N];
    for(int i=0;i<N;i++)
    {
        graphe[i]=new double[N];
    }
    return(graphe);
}
//remplissage du graphe par les toute les distances (brute force)
void distanceMatrix(int N,double** graph,node* LesNodes){
    for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                graph[i][j]=distance(LesNodes[i],LesNodes[j]);
                graph[j][i]=graph[i][j];
            }
}

}

//initialisation des positions des noeuds
void InitGame(int N, node *LesNodes)
{
    //Initialize nodes

    for(int i=0;i<N;i++){
    LesNodes[i].rec.x=rand()%560 + 20;
    LesNodes[i].rec.y=rand()%560 + 20;
    LesNodes[i].rec.width= 20;
    LesNodes[i].rec.height = 20;
    }

}

//visualisation du graphe dans une fenetre
void DrawGame(int N, node *LesNodes,double** graphe){

    BeginDrawing();
    ClearBackground(RAYWHITE);
    for(int i = 0; i < N; i++){
        DrawRectangleRec(LesNodes[i].rec, BLACK);
        //DrawCircle(1, 20,20 , DARKBLUE);
    }
    for (int j=0;j<N;j++){
        for (int i=j+1; i<N;i++){
                if(graphe[i][j]!=-1){
                    DrawLine(LesNodes[j].rec.x+10,LesNodes[j].rec.y+10,LesNodes[i].rec.x+10, LesNodes[i].rec.y+10, BLACK);
                }



        }
    }

    EndDrawing();
}

//creer un graphe de gabriel
void gabriel(int N, node* LesNodes,double** graph){

    for(int i=0;i<N;i++)
    {
        for(int j=0; j<N; j++)
        {

            if(i != j)
            {
                node centre;
                centre.rec.x = (LesNodes[i].rec.x+LesNodes[j].rec.x)/2;
                centre.rec.y = (LesNodes[i].rec.y+LesNodes[j].rec.y)/2;
                double rayon=(distance(LesNodes[i],LesNodes[j]))/2;

                for(int k=0; k<N; k++)
                {
                    if(k!=i && k!=j)
                    {
                        if (distance(LesNodes[k], centre)<rayon){
                            graph[i][j]=-1;
                        }
                    }
                }
            }


        }


    }
}
//affichage de la matrice dans la console
void affichage(int N, double** graph){

    for(int i(0); i<N; ++i){
        for(int j(0); j != N; ++j)
            std::cout << graph[i][j] << ", ";
            std::cout << std::endl;
    }
}


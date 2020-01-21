#include "prototypes.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>



//calcul de la distance entre deux noeuds
double distance(node premierNoeud,node deuxiemeNoeud){

    return(sqrt((double)(pow((premierNoeud.rec.x-deuxiemeNoeud.rec.x),2)+pow((premierNoeud.rec.y-deuxiemeNoeud.rec.y),2))));

}
//allocation de l'espace m�moire pour un graphe(matrice de distances)
double** allocateGraph(int N, node *lesNodes){

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
void InitGameRandom(int N, node* LesNodes){

    //Initialize nodes aleatoirement
    srand(time(0));
    for(int i=0;i<N;i++){
    LesNodes[i].rec.x=rand()%600 + 20;
    LesNodes[i].rec.y=rand()%600 + 20;
    LesNodes[i].rec.width= 20;
    LesNodes[i].rec.height = 20;
    LesNodes[i].indice = i;
    }



}
void InitLoaded_taille(int*N){
    std::ifstream saveFile_taille("../sauvegarde/saveFile_taille.txt");
     if(saveFile_taille){
            saveFile_taille >> *N;
    }
     else{
        std::cout << "ERREUR: Impossible d'ouvrir le fichier de sauvegarde.";
    }

}
void InitGameLoaded(int N, node* LesNodes){
    std::ifstream fichierSauvegarde("../sauvegarde/saveFile.txt");
    if(fichierSauvegarde){
         for(int i=0;i<N;i++)
        {
            fichierSauvegarde >> LesNodes[i].rec.x ;
            fichierSauvegarde >> LesNodes[i].rec.y ;
            LesNodes[i].rec.width= 20;
            LesNodes[i].rec.height = 20;
            LesNodes[i].indice = i;
        }
    }
    else{
        std::cout << "ERREUR: Impossible d'ouvrir le fichier de sauvegarde.";
    }


}
void DrawGame(int N, node *LesNodes,double** graphe,Robot* test){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    if(test->getPosition().indice != test->getDestination().indice){

        for(int i = 0; i < N; i++){
            DrawRectangleRec(LesNodes[i].rec, RED);
        }

        for (int j=0;j<N;j++){
            for (int i=j+1; i<N;i++){
                if(graphe[i][j]!=-1 && graphe[i][j]!=0){
                    DrawLine(LesNodes[j].rec.x+10,LesNodes[j].rec.y+10,LesNodes[i].rec.x+10, LesNodes[i].rec.y+10, BLACK);
                }
            }
        }

        const char* num=TextFormat("%0.02i",test->getPosition().indice);
        DrawText(num,test->getPosition().rec.x,test->getPosition().rec.y+30,15,BLACK);
        delete num;

    }

    else{

        for(int i = 0; i < N; i++){
            DrawRectangleRec(LesNodes[i].rec, RED);
        }

        for (int j=0;j<N;j++){
            for (int i=j+1; i<N;i++){
                if(graphe[i][j]!=-1 && graphe[i][j]!=0){
                    DrawLine(LesNodes[j].rec.x+10,LesNodes[j].rec.y+10,LesNodes[i].rec.x+10, LesNodes[i].rec.y+10, BLACK);
                }
            }
        }


        const char* num=TextFormat("%0.02i",test->getPosition().indice);
        DrawText(num,test->getPosition().rec.x,test->getPosition().rec.y+30,15,BLACK);


        delete num;

        DrawText("congrats, le robot est arrive",100,200,30,BLACK);
    }
    EndDrawing();
}
void Updategame(node* LesNodes,Robot* test,int N){
    if(test->getPosition().indice != test->getDestination().indice){
        if(test->getPosition().indice != test->getPathValue(N-1)){
            if(IsKeyPressed(KEY_SPACE))
                test->deplacer(LesNodes,N);
            if(IsKeyPressed(KEY_F)){
                for(int i=0;i<N;i++){
                    test->deplacer(LesNodes,N);
                }
            }
        } else {
            if(IsKeyPressed(KEY_SPACE))
                std::cout<<"\nWARNING: le chemin de robot ne le permet pas d atteindre sa destination veiller quitter l'application";

            if(IsKeyPressed(KEY_F))
                std::cout<<"\nWARNING: le chemin de robot ne le permet pas d atteindre sa destination veiller quitter l'application";
        }

    }
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
void affichageGraphe(int N, double** graph){
    for(int i(0); i<N; ++i){
        for(int j(0); j != N; ++j)
            std::cout << graph[i][j] << " , ";
            std::cout << std::endl;
    }

}
//sauvegarde d'un graphe dans un fichier
void sauvegarde(int N, node* LesNodes){
    std::string const saveFile("../sauvegarde/saveFile.txt");
    std::string const saveFile_taille("../sauvegarde/saveFile_taille.txt");
    std::ofstream savedInput(saveFile.c_str());
    std::ofstream savedInput_taille(saveFile_taille.c_str());
    if (savedInput)
    {
        if(savedInput_taille){
            savedInput_taille << N;
            for(int i=0;i<N;i++)
            {
                savedInput << LesNodes[i].rec.x <<"\n";
                savedInput << LesNodes[i].rec.y <<"\n";
            }
        }
        else{
        std::cout << "ERREUR: Impossible de sauvegarder\n";
        }
    }

    else
    {
        std::cout << "ERREUR: Impossible de sauvegarder\n";
    }
}









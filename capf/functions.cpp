#include "structs.cpp"
#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <cmath>




double distance(node premierNoeud,node deuxiemeNoeud){
    return(sqrt((double)(pow((premierNoeud.rec.x-deuxiemeNoeud.rec.x),2)+pow((premierNoeud.rec.y-deuxiemeNoeud.rec.y),2))));
}


double** allocateGraph(int N, node* LesNodes)
{

    double** graphe= new double*[N];
    for(int i=0;i<N;i++)
    {
        graphe[i]=new double[N];
    }
    return(graphe);
}
void distanceMatrix(int N,double** graph,node* LesNodes){
    for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                graph[i][j]=distance(LesNodes[i],LesNodes[j]);
                graph[j][i]=graph[i][j];
            }
}
}

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


void DrawGame(int N, node *LesNodes){

    BeginDrawing();
    ClearBackground(RAYWHITE);
    for(int i = 0; i < N; i++){
        DrawRectangleRec(LesNodes[i].rec, BLACK);
        //DrawCircle(1, 20,20 , DARKBLUE);
    }
    for (int j=0;j<N;j++){
        for (int i=j+1; i<N;i++){
                if (i==5){
                    DrawLine(LesNodes[j].rec.x+10,LesNodes[j].rec.y+10,LesNodes[i].rec.x+10, LesNodes[i].rec.y+10, BLACK);
                }


    }
    }

    EndDrawing();
}



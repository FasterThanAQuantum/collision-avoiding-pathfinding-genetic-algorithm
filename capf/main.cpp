#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "prototypes.h"


using namespace std;
//#include "raylib.h"
//#include "structs.cpp"
//#include "functions.cpp"

main()
{
    int N;
    node* nodes= NULL;
    double** grapheGabriel=NULL;
    cout << "donner la nombre de noeuds: " ;
    cin >> N;
    while(N < 2){
        cout <<"veuillez saisir un nombre supèrieur a 1 \n" ;
        cout << "donner la nombre de noeuds: " ;
        cin >> N;
    }

    //node nodes[N];
    nodes=(node*)malloc(N*sizeof(node)); //allocation de la memoire pour une liste de noeuds

    InitGame(N,nodes);
    grapheGabriel= allocateGraph(N,nodes);
    distanceMatrix(N,grapheGabriel,nodes);
    InitWindow(720, 720, "modele");

    while (!WindowShouldClose()){
    DrawGame(N,nodes);

    }

    for(int i(0); i<N; ++i){
        //std :: cout << nodes[i].rec.x <<"\t"<< nodes[i].rec.y<<"\n"  ;
        for(int j(0); j != N; ++j)

            std::cout << grapheGabriel[i][j] << ", ";
            std::cout << std::endl;
    }
    for (int i = 0; i < N; ++i){
        delete [] grapheGabriel[i];
    }


    delete [] grapheGabriel;
    //free(grapheGabriel);
    free(nodes); //

}







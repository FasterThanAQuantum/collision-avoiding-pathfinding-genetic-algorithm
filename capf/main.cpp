#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "prototypes.h"


using namespace std;

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

    nodes=(node*)malloc(N*sizeof(node)); //allocation de la memoire pour une liste de noeuds

    InitGame(N,nodes);

    grapheGabriel= allocateGraph(N,nodes);
    distanceMatrix(N,grapheGabriel,nodes);
    gabriel(N, nodes, grapheGabriel);

    affichage(N,grapheGabriel);

    InitWindow(720, 720, "modele");

    while (!WindowShouldClose()){
    DrawGame(N,nodes,grapheGabriel);
    }


    for (int i = 0; i < N; ++i){
        delete [] grapheGabriel[i];
    }


    delete [] grapheGabriel;
    free(nodes); //

}







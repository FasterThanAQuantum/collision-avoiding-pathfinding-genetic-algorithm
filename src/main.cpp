#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include "prototypes.h"
#include <string>





using namespace std;

main()
{
    string choice;
    cout<<"INFO: pour creer un nouveau graphe veuillez taper: new, sinon veuillez charger un nouveau fichier en tapant: load  ";
    cin >> choice;
    while (choice != "new" && choice !="load"){
        cout<<"\nWARNING: vous ne pouvez entrer que l'un des mots cles: new ou load \n";
        cout<<"INFO: pour creer un nouveau graphe veuillez taper: new, sinon veuillez charger un nouveau fichier en tapant: load  ";
        cin >> choice;
    }

    if(choice == "new"){

    int N;
    node* nodes= NULL;
    double** grapheGabriel=NULL;


    cout << "donner la nombre de noeuds: " ;
    cin >> N;
    while(N<2){
        cout <<"\nWARNING: veuillez saisir un nombre superieur a 1 \n" ;
        cout << "donner la nombre de noeuds: " ;
        cin >> N;
    }

    //CREATION DU GRAPHE DE GABRIEL
    nodes=new node[N];//allocation de la memoire pour une liste de noeuds
    InitGameRandom(N,nodes);//intialisation des noeuds aleatoirement
    grapheGabriel= allocateGraph(N,nodes);
    distanceMatrix(N,grapheGabriel,nodes);
    gabriel(N, nodes, grapheGabriel);

    //CREATION DU ROBOT
    Robot testRobot(nodes,N);
    testRobot.buildPath(N,grapheGabriel);
    while(testRobot.getDestination().indice!=testRobot.getPathValue(N-1)){
        testRobot.buildPath(N,grapheGabriel);
        i++;

    }
    cout<<"\nIteration number: " <<i<<"\n";


    //AFFICHAGE DU GRAPHE
    affichageGraphe(N,grapheGabriel);

    sauvegarde(N,nodes);

    InitWindow(720, 720, "modele");

    while (!WindowShouldClose()){
        Updategame(nodes,&testRobot,N);
        DrawGame(N,nodes,grapheGabriel, &testRobot);
    }


    for (int i = 0; i < N; ++i){
        delete [] grapheGabriel[i];
    }

    delete [] grapheGabriel;
    delete [] nodes;
    }
    if(choice== "load"){
        int N;
        node* nodes= NULL;
        double** grapheGabriel=NULL;

        //CREATION DU GRAPHE DE GABRIEL DEPUIS LA SAUVEGARDE
        InitLoaded_taille(&N);
        nodes= new node[N];
        InitGameLoaded(N,nodes);
        grapheGabriel= allocateGraph(N,nodes);
        distanceMatrix(N,grapheGabriel,nodes);
        gabriel(N, nodes, grapheGabriel);


        //CREATION DU ROBOT
        Robot testRobot(nodes,N);
        testRobot.buildPath(N,grapheGabriel);

        //AFFICHAGE DU GRAPHE
        affichageGraphe(N,grapheGabriel);
        InitWindow(720, 720, "modele");

        while (!WindowShouldClose()){
            Updategame(nodes,&testRobot,N);
            DrawGame(N,nodes,grapheGabriel, &testRobot);
        }


        for (int i = 0; i < N; ++i){
            delete [] grapheGabriel[i];
        }

        delete [] grapheGabriel;
        delete [] nodes;
    }
}













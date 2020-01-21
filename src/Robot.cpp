#include<iostream>
#include "prototypes.h"
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

//constructeur par defaut
Robot::Robot(){
    std::cout << "\nUn Robot est cree par defaut, ses attributs doivent etre initialisee ";
}
//constructeur surcharg¨¦
Robot::Robot(node* Nodes, int N){

    srand(time(0));
    int indiceArriveeAlea=rand()%N;
    int indiceDestinationAlea=rand()%N;
    while(indiceArriveeAlea==indiceDestinationAlea){
        indiceDestinationAlea=rand()%N;
    }

    m_depart.indice=Nodes[indiceArriveeAlea].indice;
    m_depart.rec.x=Nodes[indiceArriveeAlea].rec.x;
    m_depart.rec.y=Nodes[indiceArriveeAlea].rec.y;
    m_depart.rec.width=Nodes[indiceArriveeAlea].rec.width;
    m_depart.rec.height=Nodes[indiceArriveeAlea].rec.height;


    m_destination.indice=Nodes[indiceDestinationAlea].indice;
    m_destination.rec.x=Nodes[indiceDestinationAlea].rec.x;
    m_destination.rec.y=Nodes[indiceDestinationAlea].rec.y;
    m_destination.rec.width=Nodes[indiceDestinationAlea].rec.width;
    m_destination.rec.height=Nodes[indiceDestinationAlea].rec.height;

    m_position.indice=Nodes[indiceArriveeAlea].indice;
    m_position.rec.x=Nodes[indiceArriveeAlea].rec.x;
    m_position.rec.y=Nodes[indiceArriveeAlea].rec.y;
    m_position.rec.width=Nodes[indiceArriveeAlea].rec.width;
    m_position.rec.height=Nodes[indiceArriveeAlea].rec.height;



}

//destructeur
Robot::~Robot(){
    std::cout <<"\nINFO: le robot de depart:  "<<getDepart().indice<<"  et d'arrivee:  "<<getDestination().indice<<"  est detruit \n";
}

//getters
node Robot::getDepart(){
    return  m_depart;
}
node Robot::getDestination(){
    return  m_destination;
}
node Robot::getPosition(){
    return  m_position;
}
int Robot::getPathValue(int indice){
    return m_path[indice];
}

//setters
void Robot::setDepart(node noeud){

    m_depart.indice=noeud.indice;
    m_depart.rec.x=noeud.rec.x;
    m_depart.rec.y=noeud.rec.y;
    m_depart.rec.width=noeud.rec.width;
    m_depart.rec.height=noeud.rec.height;
}
void Robot::setDestination(node noeud){

    m_destination.indice=noeud.indice;
    m_destination.rec.x=noeud.rec.x;
    m_destination.rec.y=noeud.rec.y;
    m_destination.rec.width=noeud.rec.width;
    m_destination.rec.height=noeud.rec.height;
}
void Robot::setPosition(node noeud){

    m_position.indice=noeud.indice;
    m_position.rec.x=noeud.rec.x;
    m_position.rec.y=noeud.rec.y;
    m_position.rec.width=noeud.rec.width;
    m_position.rec.height=noeud.rec.height;
}

//deplacer le robot
void Robot::deplacer(node* Nodes,int N){

        if(m_position.indice==m_depart.indice){
            std::cout <<"INFO: position courante du Robot: " <<m_position.indice;
            setPosition(Nodes[m_path[0]]);
            std::cout <<" est passe a la position-->"<<m_position.indice<< "=============>";
            std::cout <<"destination:"<<m_destination.indice<< std::endl;
        }
        else {
            std::cout <<"INFO: position courante du Robot: " <<m_position.indice;
            for(int i=0; i<N ; i++){
                if(m_path[i]==m_position.indice){
                    setPosition(Nodes[m_path[i+1]]);
                    break;
                }
            }
            std::cout <<" est passe a la position -->"<<m_position.indice<< "=============>";
            std::cout <<"destination:"<<m_destination.indice<< std::endl;


        }
        if(m_position.indice==m_destination.indice){
            std::cout<<"INFO: le robot est arrive, veuillez quitter l'application";
            std::cout << std::endl;

        }

}


//CREATION DU CHEMIN DE ROBOT EN RESPECTANT LES CONTRAINTES DE GRAPHE
void Robot::buildPath(int N, double** MatriceDArcs)
{
    m_path=new int[N];
    int nombreArc = 0;
    int n_ni = 0;   //nombre de noeud interdit
    for(int j = 0; j < N; j++)
    {
        if(MatriceDArcs[m_depart.indice][j] != -1 && MatriceDArcs[m_depart.indice][j] !=  0)
           nombreArc++;
    }

    int* prochainNoeud= new int[nombreArc];
    int n_p =0;
    for(int j = 0; j < N; j++)
    {
        if(MatriceDArcs[m_depart.indice][j] != -1 && MatriceDArcs[m_depart.indice][j] !=  0)
        {
            prochainNoeud[n_p] = j;
            n_p++;
        }
    }
    srand((unsigned)time(NULL));
    m_path[0] = prochainNoeud[rand()%nombreArc];
    delete [] prochainNoeud;



    for(int i = 1; i < N; i++)
    {
        nombreArc = 0;
        if(m_path[i-1] == m_destination.indice){
            m_path[i] = m_path[i-1];
        }
        else
        {

            for(int j = 0; j < N; j++)
            {
                if(MatriceDArcs[m_path[i-1]][j] != -1 && MatriceDArcs[m_path[i-1]][j] !=  0)
                {
                    for(int w = 0; w < i; w++)
                    {
                        if(j == m_path[w] || j == m_depart.indice)
                            {
                                nombreArc--;
                                w = i;
                            }
                    }
                    nombreArc++;
                }
            }


            int* prochainNoeud= new int[nombreArc];
            n_p = 0;
            for(int j = 0; j < N; j++)
            {
                if(MatriceDArcs[m_path[i-1]][j] != -1 && MatriceDArcs[m_path[i-1]][j] !=  0)
                {
                    for(int w = 0; w < i; w++)
                    {
                        if(j == m_path[w] || j == m_depart.indice)
                        {
                            w = i;
                            n_ni++;
                        }
                        else if( w == i-1 )
                        {
                            prochainNoeud[n_p] = j;
                            n_p++;
                        }
                    }
                }
                else
                    n_ni++;
            }

            if( n_ni == N)
            {
                m_path[i] = m_path[i-1];
                n_ni = 0;
            }
            else
            {
                m_path[i] = prochainNoeud[rand()%nombreArc];
                n_ni = 0;

            }
            delete [] prochainNoeud;

        }
    }
        std::cout<<"\n************************************** Chemin du robot **************************************\n";
        for(int o = 0; o < N; o++)
        {
            std::cout<<m_path[o]<<"\t";
        }
        std::cout<<"\n*********************************************************************************************\n";

}





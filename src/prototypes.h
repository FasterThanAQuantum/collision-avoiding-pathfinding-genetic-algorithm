#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

#include"raylib.h"

//structure node
typedef struct node{
    Rectangle rec;
    int indice;
}node;

class Robot
{
    public:
        Robot();
        Robot(node *,int);
        virtual ~Robot();
        void deplacer(node*,int);
        node getDepart();
        node getDestination();
        node getPosition();
        int getPathValue(int);
        void setDepart(node);
        void setDestination(node);
        void setPosition(node);
        void buildPath(int, double** );
    private:
        node m_depart;
        node m_destination;
        node m_position;
        int* m_path;



};




void InitGameRandom(int , node*);
void DrawGame(int , node *,double**,Robot*);
double distance(node,node);
double** allocateGraph(int, node *);
void distanceMatrix(int,double**,node*);
void gabriel(int, node*,double**);
void affichageGraphe(int, double**);
void sauvegarde(int , node*);
void InitGameLoaded(int N, node* LesNodes);
void InitLoaded_taille(int*);
void Updategame(node *,Robot*,int);
#endif



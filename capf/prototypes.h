#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "structs.cpp"
typedef struct node;
typedef struct arc;
void InitGame(int N, node *LesNodes);
void DrawGame(int N, node *LesNodes);
double distance(node premierNoeud,node deuxiemeNoeud);
double** allocateGraph(int N, node* LesNodes);
void distanceMatrix(int N,double** graph,node* LesNodes);

#endif // PROTOTYPES_H_INCLUDED

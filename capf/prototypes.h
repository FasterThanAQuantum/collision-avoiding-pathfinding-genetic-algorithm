#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "structs.cpp"
typedef struct node;
typedef struct arc;


void InitGame(int , node*);
void DrawGame(int , node *,double**);
double distance(node,node);
double** allocateGraph(int, node*);
void distanceMatrix(int,double**,node*);
void gabriel(int, node*,double**);
void affichage(int, double**);
#endif // PROTOTYPES_H_INCLUDED

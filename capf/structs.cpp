#include "raylib.h"
#define MAX_NODE 100

//structure d'un noeud
typedef struct node{
    Rectangle rec;
    float distance[MAX_NODE];
}node;


//structure d'un arc
typedef struct arc{
    node exUn;
    node exDeux;
}arc;

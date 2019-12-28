#include "raylib.h"

//structure d'un noeud
typedef struct node{
    Rectangle rec;
}node;


//structure d'un arc
typedef struct arc{
    node exUn;
    node exDeux;
}arc;

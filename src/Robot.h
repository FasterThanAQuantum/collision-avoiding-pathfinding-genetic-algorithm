/*
#ifndef ROBOT_H
#define ROBOT_H


//#include "prototypes.h"
class Robot
{
    public:
        Robot(node*,int);
        virtual ~Robot();
        void deplacer();
        void setDepart(node);
        void setPosition(node);
        void setArrivee(node);
        node getDepart();
        node getPosition();
        node getArrivee();
        void setPath();
        int* getPath();
        int* r_path;

    private:
        node r_depart;
        node r_arrivee;
        node r_position;

};

#endif // ROBOT_H
*/

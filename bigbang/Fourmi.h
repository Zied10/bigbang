#pragma once
#include "GraphicPrimitives.h"


class Fourmi {
    
public:

    Fourmi(float posX1_ = 0.0f,float posY1_ = 0.0f,
            float posX2_ = 0.0f,float posY2_ = 0.0f,
            float posX3_ = 0.0f,float posY3_ = 0.0f,
            float VposX_ = 0.01f,float VposY_ = 0.02f):
    	posX1(posX1_),
    	posY1(posY1_),
        posX2(posX2_),
        posY2(posY2_),
        posX3(posX3_),
        posY3(posY3_),
    	VposX(VposX_),
    	VposY(VposY_){}
    
    float VposX,VposY;

    float posX1,posY1;
    float posX2, posY2;
    float posX3, posY3;

    void draw();
    void tick();
    
};
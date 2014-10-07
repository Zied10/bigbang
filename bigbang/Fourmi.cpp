
#include "Fourmi.h"

void Fourmi::draw(){
    GraphicPrimitives::drawFillTriangle2D(posX1,posY1,posX2,posY2,posX3,posY3,0.25f,0.25f,0.29f);
}

void Fourmi::tick(){ 
    // abscisses des points du triangles 
    posX1 += VposX; 
    posX2 += VposX; 
    posX3 += VposX; 

    // ordonnées des points 
    posY1 += VposY; 
    posY2 += VposY; 
    posY3 += VposY; 

    if(posX1 > 1.0f || posX1 < -1.0f 
        || posX2 > 1.0f || posX2 < -1.0f 
        || posX3 > 1.0f || posX3 < -1.0f)
    { 
        VposX = - VposX; 
        posX1 += VposX; 
        posX2 += VposX; 
        posX3 += VposX; 
    } 

    if( posY1 > 1.0f || posY1 < -1.0f ||
        posY2 > 1.0f || posY2 < -1.0f || 
        posY3 > 1.0f || posY3 < -1.0f )
    { 
        VposY = - VposY; 
        posY1 += VposY; 
        posY2 += VposY; 
        posY3 += VposY; 
    } 
}
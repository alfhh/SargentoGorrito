//
//  Personaje.cpp
//  SargentoGorrito
//
//  Created by Francisco Canseco on 27/10/15.
//  Copyright (c) 2015 Francisco Canseco. All rights reserved.
//

#include "Personaje.h"
int Personaje::getPosX(){
    return posX;
}
int Personaje::getPosY(){
    return posY;
}
int Personaje::getTamanoX(){
    return tamanoX;
}
int Personaje::getTamanoY(){
    return tamanoY;
}
void Personaje::setPosX(int x){
    posX=x;
}
void Personaje::setPosY(int y){
    posY=y;
}
void Personaje::setVida(int v){
    vida=v;
}
void Personaje::alteraVida(int v){
    vida+=v;
}
bool Personaje::checaColision(Personaje *p){
    if (p->getPosX()+p->getTamanoX()>posX||posX+tamanoX>p->getPosX()){
        if (p->getPosY()+p->getTamanoY()>posY||posY+tamanoY>p->getPosY()){
            return true;
        }
    }
    return false;
}
Personaje::Personaje(int x, int y,int v){
    posX=x;
    posY=y;
    vida=v;
}
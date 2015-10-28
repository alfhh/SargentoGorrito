//
//  Personaje.h
//  SargentoGorrito
//
//  Created by Francisco Canseco on 27/10/15.
//  Copyright (c) 2015 Francisco Canseco. All rights reserved.
//

#ifndef __SargentoGorrito__Personaje__
#define __SargentoGorrito__Personaje__

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <sstream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
using namespace std;


class Personaje {
private:
    string nombre;
    int posX;
    int posY;
    int vida;
    int dano;
    int tamanoX;
    int tamanoY;
    
public:
    Personaje (int x, int y,int vida);
    int getPosX();
    int getPosY();
    int getTamanoX();
    int getTamanoY();
    void setPosX(int x);
    void setPosY(int y);
    void setVida(int v);
    void alteraVida(int v);
    virtual void dibuja()=0;
    virtual void actualizaTamano(int height , int width)=0;
    bool checaColision(Personaje *p);
};
#endif /* defined(__SargentoGorrito__Personaje__) */

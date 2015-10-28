//
//  Ficha.h
//  SargentoGorrito
//
//  Created by Francisco Canseco on 21/10/15.
//  Copyright (c) 2015 Francisco Canseco. All rights reserved.
//

#ifndef __SargentoGorrito__Ficha__
#define __SargentoGorrito__Ficha__

#include <stdio.h>
#include <string>
#inclue <GLFWimage>
using namespace std;

class Ficha {
private:
    string nombre;
    GLFWimage imagen;
    string descipcion;
    bool
public:
    Ficha();
    string getNombre();
    GLFWimage getImagen();
    string getDescripcion();
    void setNombre;
};

#endif /* defined(__SargentoGorrito__Ficha__) */

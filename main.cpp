/**
 * Title: Sargento Gorrito
 * Developed by: Alfredo Hinojosa & Francisco Canseco
 * File: Main class
 */

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


// Globals
GLsizei winWidth =1200, winHeight =800; // Valores de ancho y alto de la pantalla

// Strings
string mainTitle = "Sargento Gorrito";
string btnStart = "Inicio";
string btnLoad = "Cargar";
string btnOptions = "Opciones";

GLubyte itc[] = {

    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xFC,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x07,0xC1,0xE0,
    0x1E,0x3F,0xF9,0xE0,
    0x1E,0x3F,0xF9,0xFC,
    0x1E,0x3F,0xF9,0xFC,
    0x1E,0x3F,0xF9,0xFC,
    0x1E,0x3F,0xF9,0xFC,
    0x1E,0x3F,0xF9,0xFC,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,


};

GLubyte up[] = {

    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x0F,0xFF,0xF0,0x00,
    0x08,0x00,0x10,0x00,
    0x18,0x00,0x18,0x00,
    0x10,0x00,0x08,0x00,
    0x10,0x00,0x08,0x00,
    0x10,0x00,0x08,0x00,
    0x10,0x66,0x08,0x00,
    0x30,0x66,0x0C,0x00,
    0x30,0x66,0x0C,0x00,
    0x78,0x66,0x1E,0x00,
    0x7F,0xFF,0xFE,0x00,
    0x5F,0xFF,0xFA,0x00,
    0x4F,0xC3,0xF2,0x00,
    0x5F,0x81,0xFA,0x00,
    0x7F,0x81,0xFE,0x00,
    0x7F,0xC3,0xFE,0x00,
    0x3F,0xFF,0xFC,0x00,
    0x33,0xFF,0xCC,0x00,
    0x11,0xFF,0x88,0x00,
    0x11,0xFF,0x88,0x00,
    0x19,0xFF,0x98,0x00,
    0x05,0xFF,0xA0,0x00,
    0x05,0xFF,0xA0,0x00,
    0x00,0x01,0x37,0xFF,
    0x00,0x00,0x00,0x00,
};

void init(void) {
    glClearColor(1, 1, 1, 1);
}

// Function in charge of drawing a button with a design pattern
void paintButton() {
    glRectf(50, 100, 700, 300);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //--------------- Display the name of the game
    glPushMatrix();
    glTranslatef(300, 1000, 1); // <- X: 300 Y: 1000
    glScaled(0.6, 0.6, 0.6);
    glColor3f(0.0, 0.0, 0.0); // <- Black color
    for (int k = 0; k < mainTitle.size(); k++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, mainTitle[k]);
    glPopMatrix();

    //--------------- Display three buttons
    int y = 600; // used for healping to organize the buttons
    glColor3f(0.0, 1.0, 0.0); // <- Green color

    // Paint button 1
    glPushMatrix();
        glTranslatef(400, y, 1); // <- X: 300 Y: 1000
        glScaled(0.6, 0.6, 0.6);
        paintButton();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(480, y + 70, 1);
        glColor3f(0.0, 0.0, 0.0);
         for (int k = 0; k < btnStart.size(); k++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, btnStart[k]);
    glPopMatrix();

    // Paint button 2
    y -= 200; // Updated for second button
    glColor3f(0.0, 1.0, 0.0); // <- Green color

    glPushMatrix();
        glTranslatef(400, y, 1); // <- X: 300 Y: 1000
        glScaled(0.6, 0.6, 0.6);
        paintButton();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(480, y + 70, 1);
        glColor3f(0.0, 0.0, 0.0);
         for (int k = 0; k < btnLoad.size(); k++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, btnLoad[k]);
    glPopMatrix();

    // Paint button 3
    y -= 200; // Updated for third button
    glColor3f(0.0, 1.0, 0.0); // <- Green color

    glPushMatrix();
        glTranslatef(400, y, 1); // <- X: 300 Y: 1000
        glScaled(0.6, 0.6, 0.6);
        paintButton();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(480, y + 70, 1);
        glColor3f(0.0, 0.0, 0.0);
         for (int k = 0; k < btnOptions.size(); k++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, btnOptions[k]);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION); // Tipo de proyecion
    glLoadIdentity ();
    gluOrtho2D(0,1200, 0,1200); // Izquierda, derecha, abajo y arriba

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();
}

void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
    switch (theKey) {
        case 27:
            exit(-1); //terminate the program
        default:
            break; // do nothing
    }
}

void myMouse(int button, int state, int x, int y) {

}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(winWidth, winHeight); // Adjust the width and height of the windows
    glutInitWindowPosition(200,0); // Position of the screen where the window appear
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); // Doble buffer for animations
    glutCreateWindow("Sargento Gorrito");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return EXIT_SUCCESS;

}

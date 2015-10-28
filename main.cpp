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
GLsizei winWidth =1200, winHeight =800; // Width and height values of the screen

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

GLubyte sargento[] =  {
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x30,0x18,0x00,
    0x00,0x38,0x38,0x00,
    0x00,0x1C,0x70,0x00,
    0x00,0x0E,0xE0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x1F,0xFF,0xE0,
    0x00,0x1F,0xFF,0xC0,
    0x00,0x07,0xC0,0x80,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x07,0xC0,0x00,
    0x00,0x03,0x80,0x00,
    0x00,0x01,0x00,0x00,
    0x00,0x01,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,

};

void init(void) {
    glClearColor(0.61, 0.36, 0.28, 1); // skin color
}


// Function in charge of drawing a button with a design pattern
void paintButton(int message, int xcor, int ycor) {
    string temp;
    switch(message){
        case 0:
            temp = btnStart;
            break;
        case 1:
            temp = btnOptions;
            break;
        case 2:
            temp = btnLoad;

    }
    glPushMatrix();
        glTranslatef(xcor, ycor, 1);
        glScaled(0.6, 0.6, 0.6);
        glRectf(50, 100, 700, 300);
    glPopMatrix(); // Close previous PushMatrix
    glPushMatrix();
        glTranslatef(480, ycor + 90, 1);
        glScaled(0.5, 0.5, 0.5);
        glColor3f(1.0, 1.0, 1.0);
         for (int k = 0; k < temp.size(); k++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, temp[k]); // Print label
    glPopMatrix();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //--------------- Display the name of the game
    glPushMatrix();
    glTranslatef(winWidth / 4, (winHeight / 4) * 3.5, 1);
    glScaled(0.6, 0.6, 0.6);
    glColor3f(1.0, 1.0, 1.0); // <- Black color
    for (int k = 0; k < mainTitle.size(); k++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, mainTitle[k]);
    glPopMatrix();

    //--------------- Display three buttons
    int y = winHeight; // used for healping to organize the buttons
    int x = (winWidth / 3.1); // also used for organizing buttons

    glColor3f(0.15, 0.15, 0.13); // <- Gray color
    paintButton(0, x, y / 2); // Paint button 1

    glColor3f(0.15, 0.15, 0.13); // <- Gray color
    paintButton(1, x, y / 3.5); // Paint button 2

    glColor3f(0.15, 0.15, 0.13); // <- Gray color
    paintButton(2, x, y / 12); // Paint button 3


    glutSwapBuffers();
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION); // Projection type
    glLoadIdentity ();
    glOrtho (0, 1200, 0, 800, -1.0, 1.0); // Left and right, down and top
    glMatrixMode (GL_MODELVIEW);
    //TODO ADD A GLULOOKAT
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
    int realX = glutGet(GLUT_WINDOW_WIDTH);
    int realY = glutGet(GLUT_WINDOW_HEIGHT);

    if(state == GLUT_DOWN){
        cout << "X: " << x << " Y: " << y << endl;
        if(x > (realX / 3) && x < (realX / 3) * 2){
            cout << "Buttons..." << endl;
            if(y > (realY / 4) &&  y < (realY/4) + (realY/8) ){
                cout << "B1" << endl;
            }
        }
    }
}


int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(winWidth, winHeight); // Adjust the width and height of the windows
    glutInitWindowPosition(200,0); // Position of the screen where the window appear
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH ); // Doble buffer for animations
    glutCreateWindow("Sargento Gorrito");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);
    glutMainLoop();
    return EXIT_SUCCESS;

}

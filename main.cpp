/**
 * Sargento Gorrito
 * Main class
 * Developed: Alfredo Hinojosa - Francisco Canseco
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//*************** Globales

// Cuartos - Niveles
int room = 0; // indica el nivel/cuarto en donde se encuentra el player

// Banderas

// Strings
string mainTitle ="Sargento Gorrito";


void init(void)
{
    glClearColor (1, 1, 1, 0.0);
    glShadeModel (GL_SMOOTH);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    // El jugador se encuentra en el menu principal del juego
    if(room == 0) {

        //--------------- Despliega el titulo principal del juego
        glTranslatef(0, 2, 0);
        glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        for (int k = 0; k < mainTitle.size(); k++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, mainTitle[k]);
        glPopMatrix();

    }

    glutSwapBuffers();
}

void reshape (int w, int h)
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0); // dibujo de perspectiva

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);  // Aqui tenemos la camara, estamos viendo todo desde Z = 5
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 27 :
            exit(-1); //termina el juego
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1200, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Sargento Gorrito");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

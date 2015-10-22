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

static int shoulder = 0, elbow = 0, hand = 0, finger = 0;

void init(void)
{
    glClearColor (1, 1, 1, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glLineWidth(3); //***
    glPushMatrix();
    glTranslatef (-1.0, 0.0, 0.0);
    glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);

    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glColor3f(1, 0, 0);//***
    glutSolidCube(1.0);//***
    glColor3f(0, 0, 0);//***
    glutWireCube (1.0); // <- shoulder
    glPopMatrix();

    glTranslatef (1.0, 0.0, 0.0);
    glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
    glTranslatef (1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef (2.0, 0.4, 1.0);
    glColor3f(0, 0, 1); //***
    glutWireCube (1.0); // <- elbow
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef ((GLfloat) hand, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.4, 1.0);
    glColor3f(0, 1, 0);
    glutWireCube(1.0); // <- hand
    glPopMatrix();

    glTranslatef(.5, 0.0, 0.0);
    glRotatef ((GLfloat) finger, 0.0, 0.0, 1.0);
    glTranslatef(0.25, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.5, 0.4, 1.0);
    glColor3f(0, 1, .5);
    glutWireCube(1.0); // <- finger
    glPopMatrix();

    glPopMatrix();
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
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // tenemos camara
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 's':   /*  s key rotates at shoulder  */
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':  /*  e key rotates at elbow  */
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'h':  /*  e key rotates at hand  */
            hand = (hand + 5) % 360;
            glutPostRedisplay();
            break;
        case 'H':
            hand = (hand - 5) % 360;
            glutPostRedisplay();
            break;
        case 'f':  /*  e key rotates at hand  */
            finger = (finger + 5) % 360;
            glutPostRedisplay();
            break;
        case 'F':
            finger = (finger - 5) % 360;
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Sargento Gorrito");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

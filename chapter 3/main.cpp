#include <stdlib.h>
#include "glextfuncget.h"

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f,1.0f,1.0f);

   gluLookAt(0,0,5,0,0,0,0,1,0);
   glScalef(1.0,2.0f,1.0);
   glutWireCube(1.0);

   glFlush();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   //glOrtho(0.0, 500.0, 0.0, 500.0, -100.0, 100.0);
  // glFrustum(-1.0,1.0,-1.0,1.0,-1.5,20.0);
   //glOrtho(-5.0,5.0,-5.0,5.0,-7.5,100.0);
 //  glMatrixMode(GL_MODELVIEW);
  // glLoadIdentity();
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    //gluOrtho2D(0.0f,(GLdouble)w,0.0f,(GLdouble)h);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   GetFunc();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

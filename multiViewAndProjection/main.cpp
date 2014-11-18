/// matrix Translate,scale,rorate
#include <stdlib.h>
#include "glextfuncget.h"

static GLfloat vertics[] = {
    -25,-25,
    25,-25,
    0,25,
};

static GLubyte indics[] = {0,1,2};

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f,1.0f,1.0f);

   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2,GL_FLOAT,0,vertics);
   glViewport(0,0,250,250);
   glLoadIdentity();
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);

   glViewport(250,0,250,250);
   glLoadIdentity();
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);

   glFlush();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w / 2,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(double)w / h,1,500);
    glTranslatef(0,0,-100);
    glMatrixMode(GL_MODELVIEW);

 /*   glViewport((GLsizei)w / 2,0,(GLsizei)w /2,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,(double)w / h,1,500);
    glTranslatef(0,0,-100);
    glMatrixMode(GL_MODELVIEW);*/
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

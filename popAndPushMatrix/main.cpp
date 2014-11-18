/// matrix Translate,scale,rorate
#include <stdlib.h>
#include "glextfuncget.h"

static GLfloat vertics[] = {
    200,100,
    400,100,
    300,200,
};

static GLubyte indics[] = {0,1,2};

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f,1.0f,1.0f);

   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2,GL_FLOAT,0,vertics);
   glLoadIdentity();
   for(int i = 0; i < 5; ++i)
   {
       glPushMatrix();
       glRotatef(15.0 * i,0,0,1);
       glTranslatef(20,0,0);
       glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);
       glPopMatrix();
   }


   glFlush();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w ,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   // gluPerspective(60,(double)w / h,1,500);
    //glTranslatef(0,0,-100);
    gluOrtho2D(0,w,0,h);
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
   int a;
   glGetIntegerv(GL_MAX_MODELVIEW_STACK_DEPTH,&a);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}

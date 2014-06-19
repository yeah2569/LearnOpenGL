/// matrix Translate,scale,rorate
#include <stdlib.h>
#include "glextfuncget.h"

static GLfloat vertics[] = {
    -25,-25,
    25,-25,
    0,25,
};

static GLubyte indics[] = {0,1,2};

void draw_triangle(void)
{
   glBegin (GL_LINE_LOOP);
   glVertex2f(0.0, 25.0);
   glVertex2f(25.0, -25.0);
   glVertex2f(-25.0, -25.0);
   glEnd();
}

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(1.0f,1.0f,1.0f);

   glEnableClientState(GL_VERTEX_ARRAY);
   glVertexPointer(2,GL_FLOAT,0,vertics);
   glLoadIdentity();
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);

   glEnable (GL_LINE_STIPPLE);
   glLineStipple(1,0xF0F0);
   glLoadIdentity();
   glColor3f(0,0,1);
   glTranslatef(-10,0,0);
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);
   glDisable(GL_LINE_STIPPLE);

   glEnable (GL_LINE_STIPPLE);
   glLineStipple(1,0xF00F);
   glLoadIdentity();
   glScalef(1.5,0.5,1.0);
   glColor3f(0,1,0);
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);
   glDisable(GL_LINE_STIPPLE);

   glEnable (GL_LINE_STIPPLE);
   glLineStipple(1,0x8888);
   glLoadIdentity();
   glRotatef(90,0,0,1.0);
   glColor3f(1.0,0,0);
   glDrawElements(GL_LINE_LOOP,3,GL_UNSIGNED_BYTE,indics);
   glDisable(GL_LINE_STIPPLE);

   glFlush();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w,
             50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
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

#include <GL/glut.h>
#include <stdlib.h>

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 0.0, 0.0);
   glPolygonMode(GL_FRONT,GL_LINE);
   glBegin(GL_POLYGON);
   glEdgeFlag(GL_TRUE);
   glVertex3f(20,50,10);
   glEdgeFlag(GLU_FALSE);
   glVertex3f(100,50,-50);
   glEdgeFlag(GL_TRUE);
   glVertex3f(50,150,60);
   glEnd();

   glFlush ();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 250.0, 0.0, 250.0, -100.0, 100.0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   init ();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}

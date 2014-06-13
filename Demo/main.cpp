#include <stdlib.h>
#include "glextfuncget.h"

#define BUFFER_OFFSET(bytes) ((GLubyte *)NULL +(bytes))
/*
static GLint vertices[] = {
    25,25,
    100,325,
    175,25,
    175,325,
    250,25,
    325,325
};

static GLfloat colors[] = {
    1.0,0.2,0.2,
    0.2,0.2,1.0,
    0.8,1.0,0.2,
    0.75,0.75,0.75,
    0.35,0.35,0.35,
    0.5,0.5,0.5,
};


static GLint oneIndices[] = {
    2,3,5
};

static GLint twoIndices[] = {
    1,2,4
};

static GLsizei count[] = {3,3};
static GLvoid *indices[] = {oneIndices,twoIndices};

static GLfloat intertwinded[] = {
    1.0,0.2,1.0,100,100,0,
    1.0,0.2,0.2,0.0,200.0,0.0,
    1.0,0.1,0.2,100.0,300.0,0.0,
    0.2,0.1,0.2,200.0,300.0,0.0,
    0.2,0.1,1.0,300.0,200.0,0.0,
    0.2,0.0,1.0,200.0,100.0,0.0,
};

*/

#define VERICES 0
#define INDICES 1
#define NUM_BUFFERS 2



void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT);

   GLuint buffers[NUM_BUFFERS];
   GLfloat vertices[][3] = {
       {0.0,0.0,0.0},
       {50.0,0.0,0.0},
       {50.0,50.0,0.0},
       {0.0,50.0,0.0},
       {0.0,0.0,50.0},
       {50.0,0.0,50.0},
       {50.0,50.0,50.0},
       {0.0,50.0,50.0},
   };

   GLubyte indices[][4] = {
       {0,1,2,3},
       {4,7,6,5},
       {0,4,5,1},
       {3,2,6,7},
       {0,3,7,4},
       {1,5,6,2},
   };

   glGenBuffers(NUM_BUFFERS,buffers);
   glBindBuffer(GL_ARRAY_BUFFER,buffers[VERICES]);
   glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);
   glVertexPointer(3,GL_FLOAT,0,BUFFER_OFFSET(0));
   glEnableClientState(GL_VERTEX_ARRAY);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,buffers[INDICES]);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);
   glDrawElements(GL_QUADS, ,GL_UNSIGNED_BYTE,BUFFER_OFFSET(0));

   glFlush();
}

void init (void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 500.0, 0.0, 500.0, -100.0, 100.0);
}


void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f,(GLdouble)w,0.0f,(GLdouble)h);
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

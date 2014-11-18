#include "glextfuncget.h"

static GLint fogMode;

static void init()
{
    GLfloat position [] = {0.5f,0.5f,3.0f,0.0f};

    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0,GL_POSITION,position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    {
        GLfloat mat [3] = {0.1745f,0.01175f,0.01175f};
        glMaterialfv(GL_FRONT,GL_AMBIENT,mat);
        mat[0] = 0.61424f;
        mat[1] = 0.04136f;
        mat[2] = 0.04136f;
        glMaterialfv(GL_FRONT,GL_DIFFUSE,mat);
        mat[0] = 0.727811f;
        mat[1] = 0.626959f;
        mat[2] = 0.626959f;
        glMaterialfv(GL_FRONT,GL_SHININESS,mat);
    }

    glEnable(GL_FOG);
    {
        GLfloat fogColor[] = {0.5f,0.5f,0.5f,1.0f};

        fogMode = GL_EXP;
        glFogi(GL_FOG_MODE,fogMode);
        glFogfv(GL_FOG_COLOR,fogColor);
        glFogf(GL_FOG_DENSITY,0.35f);
        glHint(GL_FOG_HINT,GL_DONT_CARE);
        glFogf(GL_FOG_START,1.0f);
        glFogf(GL_FOG_END,5.0f);
    }

    glClearColor(0.5f,0.5f,0.5f,1.0f);
}

static void renderSphere(GLfloat x,GLfloat y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glutSolidSphere(0.4f,16.0f,16.0f);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderSphere(-2.0f,-0.5f,-1.0f);
    renderSphere(-1.0f,-0.5f,-2.0f);
    renderSphere(0.0f,-0.5f,-3.0f);
    renderSphere(1.0f,-0.5f,-4.0f);
    renderSphere(2.0f,-0.5f,-5.0f);
    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    /*if(w <= h)
        gluOrtho2D(-1.0,1.0, -1.0 *(GLfloat)h/(GLfloat)w,1.0 *(GLfloat)h/(GLfloat)w);
    else
        gluOrtho2D(-1.0 *(GLfloat)w/(GLfloat)h,1.0 *(GLfloat)w/(GLfloat)h,-1.0,1.0);
        */
    if(w <= h)
        glOrtho(-2.5f,2.5f,-2.5 *(GLfloat) h / (GLfloat) w,2.5 *(GLfloat) h / (GLfloat) w,-10.0f,10.0f);
    else
        glOrtho(-2.5 *(GLfloat) w / (GLfloat) h,2.5 *(GLfloat) w / (GLfloat) h,-2.5f,2.5f,-10.0f,10.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key,int x,int y)
{
    switch (key) {
    case 'f':
    case 'F':
        if(fogMode == GL_EXP)
        {
            fogMode = GL_EXP2;
            printf("Fog mode is Gl_EXP2 \n");
        }
        else if(fogMode == GL_EXP2)
        {
            fogMode = GL_LINEAR;
            printf("Fog mode is GL_LINEAR \n");
        }
        else if(fogMode == GL_LINEAR)
        {
            fogMode = GL_EXP;
            printf("Fog mode is GL_EXP \n");
        }
        glFogi(GL_FOG_MODE,fogMode);
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("alpha");
    init();
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

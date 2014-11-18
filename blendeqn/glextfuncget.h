#ifndef GLEXTFUNCGET_H
#define GLEXTFUNCGET_H
#include <GL/glut.h>
#include <GL/glext.h>
#include <GL/freeglut_ext.h>


extern PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
extern PFNGLGENBUFFERSARBPROC glGenBuffers;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLMAPBUFFERPROC glMapBuffer;
extern PFNGLBINDBUFFERARBPROC glBindBuffer;

void GetFunc();


#endif // GLEXTFUNCGET_H

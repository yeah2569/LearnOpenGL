#include "glextfuncget.h"

PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
PFNGLGENBUFFERSARBPROC glGenBuffers;
PFNGLBINDBUFFERARBPROC glBindBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLMAPBUFFERPROC glMapBuffer;
PFNGLDRAWARRAYSINSTANCEDARBPROC glDrawArraysIstanced;

void GetFunc()
{
    glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)glutGetProcAddress("glMultiDrawElements");
    glGenBuffers = (PFNGLGENBUFFERSARBPROC)glutGetProcAddress("glGenBuffers");
    glBindBuffer = (PFNGLBINDBUFFERARBPROC)glutGetProcAddress("glBindBuffer");
    glBufferData = (PFNGLBUFFERDATAPROC)glutGetProcAddress("glBufferData");
    glMapBuffer = (PFNGLMAPBUFFERPROC)glutGetProcAddress("glMapBuffer");
    glDrawArraysIstanced = (PFNGLDRAWARRAYSINSTANCEDARBPROC)glutGetProcAddress("glDrawArraysIstanced");
}


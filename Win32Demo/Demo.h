#pragma once

#include "resource.h"
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             //  �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ
// Windows ͷ�ļ�:
#include <windows.h>

// C ����ʱͷ�ļ�
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <GL/glew.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void DrawScene();
GLvoid ReSizeGLScene(GLsizei width, GLsizei height);				// ����OpenGL���ڴ�С

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

LIBS+=-lGLU -lglut -lGL

SOURCES += main.cpp \
    glextfuncget.cpp

HEADERS += \
    glextfuncget.h


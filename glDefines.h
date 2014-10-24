/***************************************************************
* Program:
*     Project 2, Skeet
* Class:
*     CS 165, Brother Helfrich
* Author
*     Brandon Ackerman
* Description:
*      This is really just the #includes for the openGL library.
***************************************************************/

//#define LINUX
//#define MAC_XCODE
#define WIN_VISUAL_STUDIO

#ifdef MAC_XCODE
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#endif // MAC_XCODE

#ifdef LINUX
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#endif // LINUX

#ifdef WIN_VISUAL_STUDIO
#include <stdio.h>
#include <stdlib.h>
#include <glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#endif // WIN_VISUAL_STUDIO
#include "stdafx.h"
#include <gl/glut.h>
 
// One-time initializtion logic
void init( void )
{
    printf( "OpenGL version: %s\n", (char*)glGetString(GL_VERSION));
    printf( "OpenGL renderer: %s\n", (char*)glGetString(GL_RENDERER));
 
    //Configure basic OpenGL settings
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
}
 
// Main drawing routine. Called repeatedly by GLUT's main loop
void display( void )
{
    //Clear the screen and set our initial view matrix
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
 
    //TODO: Perform drawing here
 
    //We just drew to the back buffer. Now we need to swap that with the
    //front buffer to show it on screen.
    glutSwapBuffers();
}
 
// Entry point - GLUT setup and initialization
int main( int argc, char** argv )
{
 
   glutInit( &argc, argv );
   glutInitDisplayMode (GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 600);
   glutInitWindowPosition (100, 100);
   glutCreateWindow( "MyWIndow" );
   glutDisplayFunc( display );
 
   init();
 
   glutMainLoop();
 
   return 0;
}
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;
// dll linking is performed by a "#pragma comment"

/*Windows
A process can use the FreeConsole function to detach itself from its console. 
If other processes share the console, the console is not destroyed, 
but the process that called FreeConsole cannot refer to it. 
A console is closed when the last process attached to it terminates or calls FreeConsole.
After a process calls FreeConsole, it can call the AllocConsole function 
to create a new console or AttachConsole to attach to another console.

##########################################################################################

glutGet retrieves simple GLUT state represented by integers. 

GLUT_SCREEN_WIDTH
Width of the screen in pixels. Zero indicates the width is unknown or not available. 
GLUT_SCREEN_HEIGHT
Height of the screen in pixels. Zero indicates the height is unknown or not available. 
*/

void display0(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void display1(void){
  //glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the color buffers. Values specified by glClearColor are clamped to the range
  glClearColor(1.0,0.0,0.0,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}

void cocorico(void){
  //glClearColor specifies the red, green, blue, and alpha values used by glClear to clear the color buffers. Values specified by glClearColor are clamped to the range
  glClearColor(0.2,0.2,0.2,0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0f, 0.0f, 1.0f); // Bleue
  glRectf(-1,1,-0.33,-1);
  glColor3f(1.0f, 1.0f, 1.0f); // White
  glRectf(-0.33,1,0.33,-1);
  glColor3f(1.0f, 0.0f, 0.0f); // Red
  glRectf(0.33,1,1,-1);
  glFlush();
}


void test0(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Test 0");

    glutDisplayFunc(display0);
    glutMainLoop();
}

void test1(int argc,char** argv){
  glutInit(&argc,argv);
  glutInitWindowSize(500,500);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Test vermelho");

  glutDisplayFunc(display1);
  glutMainLoop();
}

void test2(int argc,char** argv){
  glutInit(&argc,argv);
  glutCreateWindow("Last test ");

  glutDisplayFunc(cocorico);
  glutMainLoop();
}

int main(int argc,char** argv) {
  //test0(argc,argv);
  //test1(argc,argv);
  test2(argc,argv);
  return EXIT_SUCCESS;
}

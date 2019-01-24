#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

//http://www.songho.ca/opengl/gl_transform.html

/*
Within a 3D rendered scene, there are typically three main matrices used to transform
an object from its own local space (object/model space) to a homogeneous space known as screen space.

World:
The World matrix being the first, is unique for every object within your world,
and is responsible for transforming the vertices of an object from its own local space,
to a common coordinate system called world space.

View:
After that, the view matrix provides the concept of a mobile camera,
when it reality the camera is actually the only constant point of reference within the world.
The view matrix is a transformation that is applied to every object in the scene
(but is not unique to each object), and provides the illusion of a camera.
The view matrix is basically the inverse of what could be considered a world matrix for the camera.
Yet instead of moving the camera itself, it provides the opposite movements to the rest of the scene.

Projection:
Finally the projection matrix is responsible for converting
a 3D world into the homogeneous screen space that you see on your screen.
This is the matrix used to represent your view frustum,
and is usually represented as an orthographic or perspective projection.

At the simplest level, every one of your objects needs to contain its own world matrix,
your "scene" or whichever context you use must contain a view matrix to represent a camera,
and a projection matrix to convert world coordinates to screen coordinates.
All of these then need to be passed to the vertex shader (with the world matrix changing for each object,
but not necessarily the view or projection) to be transformed.

*/

void Q_1(void){
  glColor3f(0.5,0.5,0.5);
 // void glViewport(GLint x,  GLint y,  GLsizei width,  GLsizei height);
  glViewport(50.0,50.0,200.0,200.0);
  glBegin(GL_POLYGON);
    glVertex2f(125.0,125.0);
    glVertex2f(375.0,125.0);
    glVertex2f(375.0,375.0);
    glVertex2f(125.0,375.0);
    glEnd();
  glFlush();
}

void Q_2(void){
  glClearColor(1,1,1,1);//WHITE
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.5,0.5,0.5); //grey   
  glViewport(50.0,50.0,200.0,200.0);

  glBegin(GL_POLYGON);
    glVertex2f(125.0,125.0);
    glVertex2f(375.0,125.0);
    glVertex2f(375.0,375.0);
    glVertex2f(125.0,375.0);
  glEnd();
  glFlush();
}

void Q_3(void){
    glClearColor(1,1,1,1);//WHITE
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(0.5,0.5,0.5);
  glViewport(50.0,50.0,200.0,200.0);
  /*
 glPointSize specifies the rasterized diameter of points.
 If point size mode is disabled (see glEnable with parameter GL_PROGRAM_POINT_SIZE),
 this value will be used to rasterize points. Otherwise,
 the value written to the shading language built-in variable gl_PointSize will be used. 
*/
  glPointSize(20);
  glBegin(GL_POINTS);
    glVertex2f(125.0,125.0);
    glVertex2f(375.0,125.0);
    glVertex2f(375.0,375.0);
    glEnd();
  glFlush();
}

void Q_4(void){
      glClearColor(1,1,1,1);//WHITE
  glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5,0.5,0.5);
    glViewport(200.0,50.0,100.0,100.0);

    glBegin(GL_POLYGON);
        glVertex2f(125.0,125.0);
        glVertex2f(375.0,125.0);
        glVertex2f(375.0,375.0);
        glVertex2f(125.0,375.0);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glViewport(50.0,200.0,100.0,100.0);
    glBegin(GL_POLYGON);
        glVertex2f(125.0,125.0);
        glVertex2f(375.0,125.0);
        glVertex2f(375.0,375.0);
        glVertex2f(125.0,375.0);
    glEnd();

    glFlush();
}

void Q_5(void){
      glClearColor(1,1,1,1);//WHITE
  glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5,0.5,0.5);
    glViewport(200.0,50.0,100.0,100.0);

    glBegin(GL_POLYGON);
        glVertex2f(125.0,125.0);
        glVertex2f(375.0,125.0);
        glVertex2f(375.0,375.0);
        glVertex2f(125.0,375.0);
    glEnd();

    glColor3f(1.0,0.0,0.0);
    glViewport(50.0,200.0,200.0,100.0);
    glBegin(GL_POLYGON);
        glVertex2f(125.0,125.0);
        glVertex2f(375.0,125.0);
        glVertex2f(375.0,375.0);
        glVertex2f(125.0,375.0);
    glEnd();

    glFlush();
}

void init(void) {
  glClearColor(0.0,0.0,0.0,0.0);//BLACK background
  glClear(GL_COLOR_BUFFER_BIT);
  /*
  void glMatrixMode(GLenum mode);
  glMatrixMode sets the current matrix mode.
  mode can assume one of these values:
  
      GL_MODELVIEW
  Applies subsequent matrix operations to the
  modelview matrix stack.
      GL_PROJECTION
  Applies subsequent matrix operations to the
  projection matrix stack.
      GL_TEXTURE
  Applies subsequent matrix operations to the texture
  matrix stack.
  */

  glMatrixMode(GL_PROJECTION);
  /*
  glLoadIdentity replaces the current matrix with the identity matrix.
  It is semantically equivalent to calling glLoadMatrix
  with the identity matrix
  */
  glLoadIdentity();
  gluOrtho2D(0.0,500.0,0.0,500.0);
  /*
  gluOrtho2D — define a 2D orthographic projection matrix
  void gluOrtho2D(GLdouble left,  GLdouble right,  GLdouble bottom,  GLdouble top);
  left, right:
      Specify the coordinates for the left and right vertical clipping planes.
  bottom, top:
      Specify the coordinates for the bottom and top horizontal clipping planes.              
  */ 
  
}

void start1(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Q_1");
    init();
    glutDisplayFunc(Q_1);
    glutMainLoop();
}

void start2(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Q_2");
    init();
    glutDisplayFunc(Q_2);
    glutMainLoop();
}

void start3(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(glutGet(GLUT_SCREEN_WIDTH)/4,glutGet(GLUT_SCREEN_HEIGHT)/4);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Q_3");
    init();
    glutDisplayFunc(Q_3);
    glutMainLoop();
}

void start4(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Q_4");
    init();
    glutDisplayFunc(Q_4);
    glutMainLoop();
}

void start5(int argc,char** argv){
  glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,150);
    glutCreateWindow("Q_5");
    init();
    glutDisplayFunc(Q_5);
    glutMainLoop();
}

int main(int argc,char** argv) {
  //start1(argc,argv);
  //start2(argc,argv);
  //start3(argc,argv);
  //start4(argc,argv);
  start5(argc,argv);
  return EXIT_SUCCESS;
}


#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <C:\Dev-Cpp\include\GL\glut.h>

using namespace std;
float doorAngle = 0.0f;
float windowesAngle = 0.0f;
float cameraAngle1 = 0.0f;
float bikeAngle = 0.0f;
float bikeAnglef = 0.0f;
float bikeAngleb = 0.0f;
float cameraAngle2 = 0.0f;
float cameraAngle3 = 0.0f;
float xDir =-2.0f;
float stop = 0.0f;
const float bi =  3.1415926f;

GLfloat vertices[][3]={{-2.0,-3.0,-30.0},
                       {2.0,-3.0,-30.0},
                       { 2.0,3.0,-30.0},
                       {-2.0,3.0,-30.0},
                       {-2.0,-3.0,-10.0},
                       {2.0,-3.0,-10.0},
                       {2.0,3.0,-10.0},
                       {-2.0,3.0,-10.0}};


void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
void shape(int a, int b, int c, int d)
{
	glBegin(GL_QUADS);
		glColor3fv(vertices[a]);
		glVertex3fv(vertices[a]);
		glColor3fv(vertices[b]);
		glVertex3fv(vertices[b]);
		glColor3fv(vertices[c]);
		glVertex3fv(vertices[c]);
		glColor3fv(vertices[d]);
		glVertex3fv(vertices[d]);
	glEnd();
}

void drawHome()
{
	shape(0,3,2,1);
	shape(2,3,7,6);
	shape(0,4,7,3);
	shape(1,2,6,5);
	shape(4,5,6,7);
	shape(0,1,5,4);
}
void drawRoof(){
    glColor3f(.4,.2,.5);
    glPushMatrix();
   
    glBegin(GL_TRIANGLES);
    glVertex3f(-2.0f, 3.0f,-9.99f);
    glVertex3f(2.0f, 3.0f, -9.99f);
    glVertex3f(0.0f, 4.0f, -9.99f);
    glEnd();
    glPopMatrix();
}

void drawAlternateWindows(){
    glColor3f(1,.4,.3);
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);  
    glBegin(GL_QUADS);
    glVertex3f(.5f, 1.5f,-9.99f);
    glVertex3f(.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 1.5f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, 1.5f,-9.99f);
    glVertex3f(-.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 1.5f,-9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(0.0 ,0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, .4f,-9.99f);
    glVertex3f(-.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(0.0, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(.5f, .4f,-9.99f);
    glVertex3f(.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
}
void windows()
{
    glColor3f(.4,.2,.5);
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);  
    glBegin(GL_QUADS);
    glVertex3f(.5f, 1.5f,-9.99f);
    glVertex3f(.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 2.5f, -9.99f);
    glVertex3f(1.5f, 1.5f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, 1.5f,-9.99f);
    glVertex3f(-.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 2.5f, -9.99f);
    glVertex3f(-1.5f, 1.5f,-9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(-.5f, .4f,-9.99f);
    glVertex3f(-.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, 1.4f, -9.99f);
    glVertex3f(-1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5f, 0.0f,-9.99f);
    glRotatef(windowesAngle, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.5f, 0.0f,9.99f);
    glBegin(GL_QUADS);
    glVertex3f(.5f, .4f,-9.99f);
    glVertex3f(.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, 1.4f, -9.99f);
    glVertex3f(1.5f, .4f, -9.99f);  
    glEnd();
    glPopMatrix();
 }
 void drawAltrnateDoor(){ 
 glPushMatrix();
 glTranslatef(.75f, 0.0f,-9.99f);
   glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
   glTranslatef(-.75f, 0.0f,9.99f);
     glBegin(GL_QUADS); 
    glColor3f(0,0,1);
    glVertex3f(.75f, -1.2f,-9.99f);
    glVertex3f(.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -1.2f, -9.99f);  
    glEnd();
    glPopMatrix();
}
 void door(){ 
      glPushMatrix();
      glTranslatef(.75f, 0.0f,-9.99f);
   glRotatef(doorAngle, 0.0f, 1.0f, 0.0f);
   glTranslatef(-.75f, 0.0f,9.99f);
     glBegin(GL_QUADS); 
    glColor3f(.6,.6,.6);
    glVertex3f(.75f, -1.2f,-9.99f);
    glVertex3f(.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -3.0f, -9.99f);
    glVertex3f(-.75f, -1.2f, -9.99f);  
    glEnd();
    glPopMatrix();
  }


void handleResize(int w, int h) {
    const float ar = (float)w /(float)h;
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
    glFrustum(-ar , ar , -1 , 1 , 2 , 100);
    gluLookAt(.5,0,.5,0,0,0,0,1,0);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}
void DrawCircle(float cx, float cy,float cz, float r, int iter)
{   glColor3f(.0,.0,.0);
   
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < iter; i++)
    {
        float theta = 2.0f * bi * float(i) / float(iter);

        float x = r * cosf(theta);
        float y = r * sinf(theta);

        glVertex3f(x + cx, y + cy,cz);

    }
    glEnd();
    
}
void drawbike(){ 
  glColor3f(.0,.0,.0);
  glPushMatrix();
  glTranslatef(-3.0 ,-2.0f,-9.0f);
  glRotatef(bikeAngle, 0.0f, 1.0f, 0.0f); 
  glRotatef(bikeAnglef, 0.0f, 0.0f, 1.0f); 
  glRotatef(bikeAngleb, 0.0f, 0.0f, 1.0f); 
  glTranslatef(3.0 ,2.0f,9.0f);
  DrawCircle(-3.0,-2.0,-9.0,.4,50);
  DrawCircle(-3.0,-2.0,-9.0,.3,50);
  glBegin(GL_LINES);
    glVertex3f(-3.0,-1.7,-9.0);
    glVertex3f(-3.0,-2.3,-9.0);
    glVertex3f(-3.3,-2,-9.0);
    glVertex3f(-2.7,-2,-9.0);
    glEnd();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.0 ,-2.0f,-9.0f);
  glRotatef(bikeAngle, 0.0f, 1.0f, 0.0f); 
    glRotatef(bikeAnglef, 0.0f, 0.0f, 1.0f); 
  glRotatef(bikeAngleb, 0.0f, 0.0f, 1.0f); 
  glTranslatef(2.0 ,2.0f,9.0f);
  DrawCircle(-2.0,-2.0,-9.0,.4,50);
  DrawCircle(-2.0,-2.0,-9.0,.3,50);
  glBegin(GL_LINES);
    glVertex3f(-2.3,-2,-9.0);
    glVertex3f(-1.7,-2,-9.0);
    glVertex3f(-2.0,-1.7,-9.0);
    glVertex3f(-2.0,-2.3,-9.0);
    glEnd();
  glPopMatrix();
   glLineWidth(4);
    glBegin(GL_LINES);
    glVertex3f(-3.0,-1.6,-9.0);
    glVertex3f(-2.0,-1.6,-9.0);
    glVertex3f(-2.5,-1.6,-9.0);
    glVertex3f(-2.5,-1.4,-9.0);
    glVertex3f(-2.4,-1.4,-9.0);
    glVertex3f(-2.6,-1.4,-9.0);
    glVertex3f(-2.1,-1.6,-9.0);
    glVertex3f(-2.1,-1.0,-9.0);
    glVertex3f(-2.1,-1.0,-9.4);
    glVertex3f(-2.1,-1.0,-8.6);
    glEnd();
     
   
    
}



void theShow() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); 
	glClearColor(0.2,0.6,0.3,1.0);
    
    glLoadIdentity(); 
    glTranslatef(0.0, 0.0f,-20.0f);	
    glRotatef(cameraAngle1, 0.0f, 1.0f, 0.0f);
    glRotatef(cameraAngle2, 1.0f, 0.0f, 0.0f);
	glTranslatef(0.0, 0.0f,20.0f);
	
    drawHome();

    drawRoof();
	windows();
    door();
     
    drawAltrnateDoor();
    drawAlternateWindows();

  glPushMatrix();
  glTranslatef(xDir , 0.0f,0.0f); 
  glTranslatef(stop , 0.0f,0.0f); 
  glTranslatef(0.0, 0.0f,-20.0f);	
  glRotatef(cameraAngle3, 0.0f, 1.0f, 0.0f);
  
	glTranslatef(0.0, 0.0f,20.0f);

  drawbike();
  glPopMatrix();
  
	glFlush();
	
	glutSwapBuffers();
	
}

void keys(unsigned char key, int x, int y)
{   if(key=='o'){   
                  if(doorAngle<180)doorAngle+=4; ;
                  }
	if(key=='c'){   
                  if(doorAngle>0)doorAngle-=4; ;
                  }
    if(key=='O'){   
                 if(windowesAngle < 180)windowesAngle+=4; ;
                  }
    if(key=='C'){   
                 if(windowesAngle > 0)windowesAngle -=4; ;
                  }
    if(key=='f'){   
                 xDir+=.01;
                 bikeAnglef-=10;  ;
    
                 }
    if(key=='b'){   
           xDir -=.01;
           bikeAngleb +=10;  ;
                 }
 
    if(key=='r'){   
                 bikeAngle-=.4; ;
                  }
    if(key=='l'){   
                 bikeAngle+=.4; ;
                  }
     if(key=='a'){   
                 cameraAngle1 -=2; ;
                  }
     if(key=='d'){   
                 cameraAngle1 +=2; ;
                  }
     if(key=='w'){   
                 cameraAngle2-=2; ;
                  }
     if(key=='s'){   
                 cameraAngle2+=2; ;
     }
                                                            
	theShow();
}
void update2(int value) {

 	if(value == 1){
         cameraAngle3 = 0;
          return ;
     }
 else{
	 cameraAngle3 += 2.0f;
	if (cameraAngle3 > 360) {
		cameraAngle3 -= 360;
    }
			glutPostRedisplay();
			glutTimerFunc(25, update2, 10);
	 }
 //Tell GLUT that the display has changed
	
	//Tell GLUT to call update again in 25 milliseconds
	
    

}
void update1(int value){
     stop = 0;
     cameraAngle3 = -100;
     	glutPostRedisplay();
			glutTimerFunc(25, update1, 0);
     return;
     }
void mouse(int btn, int state, int x, int y)
{
 if(btn == GLUT_LEFT_BUTTON   )
 { update2(2) ;
 
 }
 if(btn==GLUT_RIGHT_BUTTON  ) {
              update1(1);
 }
	theShow();
}




int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	
	//Create the window
	glutCreateWindow("My Home");
	initRendering();
	
	//Set handler functions
	glutReshapeFunc(handleResize);
    glutDisplayFunc(theShow);
	glutKeyboardFunc(keys);
	
	glutMouseFunc(mouse);
//	glutTimerFunc(25, update, 0); //Add a timer
//	update(2);
	glutMainLoop();
	return 0;
}

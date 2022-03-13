#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <stdio.h>
#include <math.h>
GLfloat a=0,b=0,c=0,d=0,e=0;
void runway();

void update(int value)
{
	a+=30.0;	//Plane position takeoff on x axis
	b-=0.0;	//Road Strip backward movement
	c+=15;	//take off at certain angle on y axis
	if(b<=-80.0)// moving of run way
		b=0.0;
	glutPostRedisplay();
	glutTimerFunc(100,update,0);//delay
}


void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
runway();
glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,0.0);// plane color
glBegin(GL_POLYGON);//rectangular body
glVertex2f(0.0,30.0);
glVertex2f(0.0,55.0);
glVertex2f(135.0,55.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//upper triangle construction plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);//outline of upper triangle plane
glVertex2f(135.0,55.0);
glVertex2f(150.0,50.0);
glVertex2f(155.0,45.0);
glVertex2f(160.0,40.0);
glVertex2f(135.0,40.0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//lower triangle
glVertex2f(135.0,40.0);
glVertex2f(160.0,40.0);
glVertex2f(160.0,37.0);
glVertex2f(145.0,30.0);
glVertex2f(135.0,30.0);
glEnd();
glPopMatrix();


glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//back wing
glVertex2f(0.0,55.0);
glVertex2f(0.0,80.0);
glVertex2f(10.0,80.0);
glVertex2f(40.0,55.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//left side wing
glVertex2f(65.0,55.0);
glVertex2f(50.0,70.0);
glVertex2f(75.0,70.0);
glVertex2f(90.0,55.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(a,c,0.0);
glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);//rightside wing
glVertex2f(70.0,40.0);
glVertex2f(100.0,40.0);
glVertex2f(80.0,15.0);
glVertex2f(50.0,15.0);

glEnd();

glPopMatrix();
if(a>500.0)//window position during take off
{
	a=0.0;
	b=0.0;
}
glFlush();
glutSwapBuffers();
}



void runway()
{

glColor3f(0.0,0.0,0.0); //black road
glBegin(GL_POLYGON);
glVertex2f(0.0,0.0);
glVertex2f(0.0,100.0);
glVertex2f(500.0,100.0);
glVertex2f(500.0,0.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);//white strips on road
glVertex2f(0.0,40.0);
glVertex2f(8.0,60.0);
glVertex2f(58.0,60.0);
glVertex2f(50.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(100.0,40.0);
glVertex2f(108.0,60.0);
glVertex2f(158.0,60.0);
glVertex2f(150.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(200.0,40.0);
glVertex2f(208.0,60.0);
glVertex2f(258.0,60.0);
glVertex2f(250.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(300.0,40.0);
glVertex2f(308.0,60.0);
glVertex2f(358.0,60.0);
glVertex2f(350.0,40.0);
glEnd();
glPopMatrix();

glPushMatrix();
glTranslated(b,0.0,0.0);
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(400.0,40.0);
glVertex2f(408.0,60.0);
glVertex2f(458.0,60.0);
glVertex2f(450.0,40.0);
glEnd();
glPopMatrix();
}



void myinit()
{

glClearColor(0.0f,0.0f,1.0f,0.0f);
glColor3f(1.0,1.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);

}


int main(int argc, char* argv[])
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(500.0,500.0);
glutInitWindowPosition(0,0);
glutCreateWindow("Airplane Takeoff computer graphics projects");
// Tell GLUT that whenever the main window needs to be repainted that it
// should call the function display().
glutDisplayFunc(display);
myinit();
glutTimerFunc(100,update,0);
glutMainLoop();
return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>
#include <GL/glut.h>


#define pi (2*acos(0.0))


double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle=20;
double incx=50, incy;
double cbx=10, cby;
int state;
double limit = 0.0;
struct point
{
	double x,y,z;
};

void push_pop(void)
{
    glPushMatrix();
        glRotatef(45, 0, 0, 1);
        glPushMatrix(); // Furthest Triangle, Draw first


            //glRotatef(45, 0, 0, 1);
            glTranslatef(-20, 0, 0);
            //glScaled(2, 1, 0);
            glColor3f(0.0, 0.0, 1.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Middle Triangle, Draw 2nd
            glColor3f(0.0, 1.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();

        glPushMatrix(); // Nearest Triangle, Draw last
            glTranslatef(20, 0, 0);
            glColor3f(1.0, 0.0, 0.0);
            glBegin(GL_POLYGON);
                glVertex2f(10, 10);
                glVertex2f(10, 0);
                glVertex2f(-10, 0);
            glEnd();
        glPopMatrix();



    glPopMatrix();

}


void pointsMany(int num)
{
    int max_value = 100, min_value = 1;
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(3.5);
    glBegin(GL_POINTS);
    for(int i = 1;i<num;i++)
    {
        glVertex2f((i*13)%110,(i*1)%100);
        glVertex2f((-i*1)%100,(i*13)%110);
        glVertex2f((-i*13)%110,(-i*1)%100);
        glVertex2f((i*1)%100,(-i*31)%110);
    }
    
    glEnd();
}

void drawAxes()
{

		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();

}


void drawGrid()
{
	int i;

    glColor3f(0.6, 0.6, 0.6);	//grey
    glBegin(GL_LINES);{
        for(i=-8;i<=8;i++){

            if(i==0)
                continue;	//SKIP the MAIN axes

            //lines parallel to Y-axis
            glVertex3f(i*10, -90, 0);
            glVertex3f(i*10,  90, 0);

            //lines parallel to X-axis
            glVertex3f(-90, i*10, 0);
            glVertex3f( 90, i*10, 0);
        }
    }glEnd();

}

void drawSquare(double a)
{
    //glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,2);
		glVertex3f( a,-a,2);
		glVertex3f(-a,-a,2);
		glVertex3f(-a, a,2);
	}glEnd();
}

void pCurve()
{

}
void drawCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    // glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    {
		for(i = 0; i < int(1000); i++)
		{
			angle = 2 * 3.1416 * i / 1000;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}

void drawShadedCircle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;
    // glColor3f(0,0,0);
	glBegin(GL_POLYGON);
    {
        // int j = 256;
		for(i = 0; i < int(1000); i++)
		{
            // j--;
            glColor3f((float)(i)/256,(float)(i)/256,1);
			angle = 2 * 3.1416 * i / 1000;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

    }

	glEnd();
}


void rec_animation()
{
    glColor3f(.6,1,.8);
    //glRotatef(angle,0,0,1);

    //glRotatef(10*angle,0,0,1);
    // glTranslatef(incx,incy,0);
    // glRotatef(20*angle,0,0,1);
    drawSquare(10);
    /*glRotatef(30,0,0,1);
    glPushMatrix();

        glTranslatef(-20,0,0);

        drawSquare(5);


        glColor3f(1,0,0);

        glTranslatef(0,20,0);

        drawSquare(5);

    glPopMatrix();

    glColor3f(0,0,1);

    glTranslatef(20,0,0);

    drawSquare(5);*/

}
void draw_rec()
{
    //glColor3f(0,1,0);

    drawSquare(5);

}
void drawSS()
{
    glColor3f(1,0,0);
    drawSquare(20);

    glRotatef(angle,0,0,1);
    glTranslatef(110,0,0);
    glRotatef(2*angle,0,0,1);
    glColor3f(0,1,0);
    drawSquare(15);
    //glPopMatrix();
    glRotatef(4*angle,0,0,1);
    glTranslatef(60,0,0);
    glRotatef(7*angle,0,0,1);
    glColor3f(0,0,1);
    drawSquare(10);




}

void trans()
{
    glRotatef(40,0,0,1);

    glTranslatef(30,0,0);
    glScaled(7,1,1);
    drawSquare(2);
}
void simple_trans()
{
    // glPushMatrix();
    // glRotatef(40, 0, 0, 1);
    // glTranslatef(-20, 0, 0);
    // glColor3f(0.0, 1.0, 0.0);
    // draw_rec();
    // glPopMatrix();

    // glTranslatef(20, 0, 0);
    // glColor3f(0.0, 0.0, 1.0);
    draw_rec();
}
// double curve_by_points()
// {
//     ///
// }
double func(double x)
{
    return x*sin(1.0)/cos(1.0)*(1- x/100);
}
void curve()
{
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    for(double i =-180; i<180;i+=.1)
    {
        glVertex2d(i,func(i));
        glVertex2d(i+.1, func(i+.1));
    }
     // It can be any type Gl_POINT,_LINE
    glEnd();

}

void drawCanon() {
    // circle
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(0,7,0);
    drawCircle(7,7);
    glPopMatrix();

    //tip
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(-2,13,0);
    drawSquare(1);
    glPopMatrix();

    //tunnel
    glPushMatrix();
    glTranslatef(18,16.5,0);
    glRotatef(30, 0, 0, 1);
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( -20, 7,2);
		glVertex3f( 20,4.5,2);
		glVertex3f(20,-4.5,2);
		glVertex3f(-20, -7,2);
	}glEnd();
    glPopMatrix();
}

void drawCanonBall() {
    // circle
    glPushMatrix();
    glColor3f(0.0,0.0,0.0);
    glTranslatef(cbx,cby,0);
    drawCircle(4,4);
    glPopMatrix();
}

void drawCanonBase(double a, double b)
{
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f(-b, a,2);
		glVertex3f(b, a,2);
		glVertex3f(b, -a,2);
		glVertex3f(-b, -a,2);
	}glEnd();
}
void bigBlueSea(int a, int b) {
    glColor3f(0.60,0.46,0.90);
    glTranslatef(0, -70, 0);
    glBegin(GL_QUADS);{
		glVertex3f(-b, a,0);
		glVertex3f(b, a,0);
		glVertex3f(b, -a,0);
		glVertex3f(-b, -a,0);
	}glEnd();
}

void clouds() {
    glPushMatrix();
    glTranslatef(-5,30,0);
    glColor3f(1.0,1.0,1.0);
    drawCircle(3,3);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,32,0);
    glColor3f(1.0,1.0,1.0);
    drawCircle(5,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5,32,0);
    glColor3f(1.0,1.0,1.0);
    drawCircle(3,3);
    glPopMatrix();
}

void ractangle(double a, double b) {
    glBegin(GL_QUADS);{
		glVertex3f(-a, b,0);
		glVertex3f(a, b,0);
		glVertex3f(a, -b,0);
		glVertex3f(-a, -b,0);
	}glEnd();
}

void woods(double a, double b) {
    glColor3f(0.54, 0.27, 0.04);
    glBegin(GL_QUADS);{
		glVertex3f(-a, b,0);
		glVertex3f(a, b,0);
		glVertex3f(a, -b,0);
		glVertex3f(-a, -b,0);
	}glEnd();
}

void woodsLight(double a, double b) {
    glColor3f(0.79, 0.55, 0.0);
    glBegin(GL_QUADS);{
		glVertex3f(-a, b,0);
		glVertex3f(a, b,0);
		glVertex3f(a, -b,0);
		glVertex3f(-a, -b,0);
	}glEnd();
}

void trees(double x, double y) {
    glColor3f(0.05,0.61,0.34);
    drawCircle(x,y);
    glPushMatrix();

    glPushMatrix();
    glTranslatef(0,-y,0);
    woods(x/3,y/2);
    glPopMatrix(); 
}




void drawNight() {

    //leaf
    glPushMatrix();
    glTranslatef(-60, 0, 0);
    glColor3f(0.06,0.70,0.33);
    drawCircle(6,12);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-50, -15, 0);
    glColor3f(0.06,0.70,0.33);
    drawCircle(6,6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-75, -10, 0);
    glColor3f(0.06,0.70,0.33);
    drawCircle(6,6);
    glPopMatrix();


    //woodLight
    glPushMatrix();
    glTranslatef(-60, -25, 0);
    woodsLight(1, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-55, -25, 0);
    glRotatef(330, 0, 0, 1);
    woodsLight(1, 10);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-68, -15, 0);
    glRotatef(-120, 0, 0, 1);
    woodsLight(1, 10);
    glPopMatrix();


    // shadow of the mountain

    glPushMatrix();
    glTranslatef(-50, -48, 0);
    glColor3f(0.48,0.0,0.63);
    ractangle(50,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48, -53, 0);
    glColor3f(0.48,0.0,0.63);
    ractangle(50,0.5);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-43, -58, 0);
    glColor3f(0.48,0.0,0.63);
    ractangle(50,0.5);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-38, -63, 0);
    glColor3f(0.48,0.0,0.63);
    ractangle(50,0.5);
    glPopMatrix();

    //sea
    glPushMatrix();
    bigBlueSea(25, 100);
    glPopMatrix();

    //mountain3
    glPushMatrix();
    glColor3f(0.66,0.0,0.56);
    glTranslatef(-50, -50, 0);
    drawCircle(50,30);
    glPopMatrix();

    //tree2
    glPushMatrix();
    glTranslatef(-5, -10, 0);
    trees(5,13);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-25, -10, 0);
    trees(7,7);
    glPopMatrix();

    //shadow of the moon

    glPushMatrix();
    glTranslatef(30, -31, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(11,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(24, -33, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(14,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18, -35, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(17,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(5, -37, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(27, 0.75);
    glPopMatrix();

    //sea
    glPushMatrix();
    bigBlueSea(40, 100);
    glPopMatrix();

    //mountain2
    glPushMatrix();
    glColor3f(0.71,0.0,0.61);
    glTranslatef(-10, -45, 0);
    drawCircle(35,35);
    glPopMatrix();

    // shadow of the moon

    glPushMatrix();
    glTranslatef(30, -22, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(18,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -24, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(16,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -26, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(14,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -28, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(13,0.5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -30, 0);
    glColor3f(0.86,0.92,0.98);
    ractangle(12,0.5);
    glPopMatrix();


    //sea
    glPushMatrix();
    bigBlueSea(50, 100);
    glPopMatrix();

    //tree1
    glPushMatrix();
    glTranslatef(17, -8, 0);
    trees(2,5);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(12, -13, 0);
    trees(1,2);
    glPopMatrix();
  

    

    // mountains1
    glPushMatrix();
    glTranslatef(35, -27, 0);
    glColor3f(0.54,0.0,0.46);
    drawCircle(13,17);
    glPopMatrix();

    
    glPushMatrix();
    glTranslatef(17, -30, 0);
    glColor3f(0.54,0.0,0.46);
    drawCircle(15,15);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(53, -30, 0);
    glColor3f(0.54,0.0,0.46);
    drawCircle(15,15);
    glPopMatrix();


    // cloud
    glPushMatrix();
    glScalef(4,2,0);
    clouds();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-30, 15, 0);
    glScalef(4,2,0);
    clouds();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(50, 13, 0);
    glRotatef(-20,0,0,1);
    glScalef(2,2,0);
    clouds();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-30, -21, 0);
    glScalef(4,2,0);
    clouds();
    glPopMatrix();

    // moon
    glPushMatrix();
    glTranslatef(30, -10, 0);
    glColor3f(1.0,1.0,1.0);
    drawCircle(20,20);
    glPopMatrix();


    // stars
    pointsMany(200);

    // sky
    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
    glRotatef(90,0,0,1);
    drawShadedCircle(75,75);
    glPopMatrix();

    // glPushMatrix();
    // glColor3f(0.0,0.0,1.0);
    // drawCircle(75.15,75.15);
    // glPopMatrix();
    
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// glClearColor(0,0,0,0);	//color black
    glClearColor(1,1,1,0);	//color white
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	gluLookAt(0,0,100,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);



	//add objects

	// drawAxes();
	// drawGrid();

    // glTranslatef(-40,0,0);
    // drawCanonBall();
    // drawCanon();
    // drawCanonBase(1.5,25);
    // glEnable(GL_STENCIL_TEST);
    // glStencilFunc(GL_ALWAYS, 1, 1); 
    // glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);  

    // glDisable(GL_DEPTH_TEST); 
    drawNight();
    // glEnable(GL_DEPTH_TEST);





	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){

    if(cbx < 80) cbx += 0.65;
    else cbx = 10;

    cby = 4 + 2*cbx/3;


	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);


	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//glutKeyboardFunc(keyboardListener);
	//glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
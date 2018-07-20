//============================================================================
//student name : Muhammad Ibrahim Khan Balooch
//Roll No      : 13i-1821
//============================================================================
// Name        : brickSlayerITC.cpp
// Author      : Sibt ul Hussain
// Version     : latest
// Copyright   : (c) Reserved
// Description : Basic 2D game of Brick Slayer...
//============================================================================

#ifndef BSLAYER_CPP_
#define BSLAYER_CPP_
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;
#define MAX(A,B) ((A) > (B) ? (A):(B)) // finds max of two numbers
#define MIN(A,B) ((A) < (B) ? (A):(B)) // find min of two numbers
#define ABS(A) ((A) < (0) ? -(A):(A))  // find ABS of a given number
#define FPS 80 // frame per seconds
#define KEY_ESC 27 // A

/*******************************************************************************************/
/*                           defining colors                                               */
/*******************************************************************************************/

float colors[5][3] = { { 1 / 255.0, 164 / 255.0, 164 / 255.0 }, { 215 / 255.0, 0
		/ 255.0, 96 / 255.0 }, { 208 / 255.0, 209 / 255.0, 2 / 255.0 }, { 0
		/ 255.0, 161 / 255.0, 203 / 255.0 }, { 50 / 255.0, 116 / 255.0, 44
		/ 255.0 } };
/*****************************************************************************************/
/*      introducing global variables for specific use                                    */
/*****************************************************************************************/
				int a=0;
				int b=0;
				int c=40;
				int d=40;

/*******************************************************************************************/
/*                         pre defined useful functions                                    */
/*******************************************************************************************/
 
float Deg2rad(float degree) {
	return (degree / 180.0) * M_PI;
}

void InitRandomizer() {
	srand((unsigned int) time(0)); // time(0) returns number of seconds elapsed since January 1, 1970.
}
//This function returns a random value within the specified range of [rmin, rmax] ...
long GetRandInRange(const long &rmin, const long &rmax) {
	long range = rmax - rmin; // find the range
	long value = (rand() % (long) range) + rmin; // translate the generated number ...
//	cout << value << endl << flush;
	return value;
}


/********************************************************************************************/
/*             defining Triangle function                                                   */
/********************************************************************************************/ 


void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3,
		float color[]) {
	glColor3fv(color); // Set the triangle colour
	// ask library to draw triangle at given position...

	glBegin(GL_TRIANGLES);
	/*Draw triangle using given three vertices...*/
	glVertex4i(x1, y1, 0, 1);
	glVertex4i(x2, y2, 0, 1);
	glVertex4i(x3, y3, 0, 1);
	glEnd();}


/**********************************************************************************************/
/*                defining sphere function                                                    */
/**********************************************************************************************/


		void  DrawSphere(){
		for(float i=90 ; i<361; i+=41) 
		{for(float j=90; j<361; j+=41){
		//float theta2 = Deg2rad(i);
		//float theta = Deg2rad(j);
		DrawTriangle(c, d,  c+9 * cos(i),
				 d+9 * sin(i), c + 9 * cos(j),
				d + 9 * sin(j), colors[4]);}}}


/*********************************************************************************************/
/*                 defining board function                                                   */
/*********************************************************************************************/


	void DrawBoard(){
	DrawTriangle(a, b , a, b+15, a+200,b+15, colors[5]);
	DrawTriangle(a,b,a+ 200, b, a+200 ,b+15 , colors[5]);}


/*********************************************************************************************/
/*                                defining bricks function                                   */
/*********************************************************************************************/	


	void DrawBrick(){
	for (int midx = 100; midx < 650; midx += 91) {
	for(int midy = 200; midy <600; midy +=50){
	
		
		DrawTriangle( midx , midy , midx+90 , midy , midx , midy+50 , colors[1]);
		DrawTriangle( midx+90, midy ,midx , midy +50,midx +90, midy +50, colors[1]);midy=midy+1;}}}

		
	
/*********************************************************************************************/
/*                   displaying functions                                                    */
/*********************************************************************************************/

	void Display(){
	glClearColor(1,1,1,1); 
	glClear(GL_COLOR_BUFFER_BIT); //Update the colors


/**********************************************************************************************/
/*                      Bricks drawing                                                        */
/**********************************************************************************************/                       
	
			DrawBrick();

/**********************************************************************************************/
/*                       sphere  drawing                                                      */
/**********************************************************************************************/

			DrawSphere();

/**********************************************************************************************/
/*                       pad drawing                                                          */
/**********************************************************************************************/		
	
			DrawBoard();
			glutSwapBuffers(); // do not modify this line..
					}
/***********************************************************************************************/
/*                       setting screen size                                                   */
/***********************************************************************************************/
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 700, -1, 1); // set the screen size to given width and height.
}
/***********************************************************************************************/
/*                         all drawings completed                                              */
/***********************************************************************************************/


/***********************************************************************************************/
/*                        movement of board                                                    */
/***********************************************************************************************/

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		if(a>10){
		a=a-100;
		 glutPostRedisplay();
		}

	} else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if(a<600){
			a=a+100;
		 glutPostRedisplay();
}			
	} else if (key == GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {

			
	}

	else if (key == GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {

	}}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == KEY_ESC/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}}

/*************************************************************************************************/
/*                                      ball movement                                            */
/*************************************************************************************************/
int sx=2,sy=2;
int t1=685,t2=685,t3=685,s1=785,s2=785,s3=785;
	void Timer(int m) {
		
		Display();
		if(d<t1  && c<s1){d=d+sy;c=c+sx;}
		else if(d>0 && c==0){d=d+sy;c=c+sx;}
		else if(d>0 && c<s1){t1=0;d=d-sy;c=c+sx;}
		else if(d>0 && c!=0){s1=0;d=d-sy;c=c-sx;}
		else if(d<= 0){d=d-sy;}
		else if((d<=b+15)||(c>=a && c<=a+200)){d=d-sy;}
	
	glutTimerFunc(1.0 / FPS, Timer, 0);
}

/*****************************************************************************************/
/*                                      main function                                    */
/*****************************************************************************************/
int main(int argc, char*argv[]) {
	int width = 800, height = 700; // i have set my window size to be 800 x 600
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Muhammad Ibrahim Khan Balooch"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0 / FPS, Timer, 0);

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* BSLAYER_CPP_ */

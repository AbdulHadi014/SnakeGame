//============================================================================
// Name        : Tetris.cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Tetris...
//============================================================================
#ifndef TETRIS_CPP_
#define TETRIS_CPP_
#include "util.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<string>
//#include<sys/wait.h>
//#include<stdlib.h>
//#include<stdio.h>
#include<unistd.h>
#include<sstream>
#include<cmath>  // for basic math functions such as cos, sin, sqrt
#include <time.h> 
using namespace std;


int foody[5]={250,180,80,350,520};
int foodx[5]={200,370,300,490,40};
int mainveiw=0;
int snakefood=80;
int button=0;
float dist=0;
float dist2=0;
int arr_x[650]={200};
int arr_y[650]={200};
int bonusx=rand() %600 ;
int bonusy=rand()%600;
int snakelength=3;
int score=0;
int stage=1;
int game = 1;
bool programend=false;


//Score on screen//
template <typename T>
string NumberToString(T pNumber)
{

 ostringstream oOStrStream;
 oOStrStream << pNumber;
 return oOStrStream.str();

}

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
    glMatrixMode( GL_MODELVIEW);
    glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */

	//Distance Function //
void eatfood()
{


for(int a=0;a<5;a++)
{
    dist=pow(foodx[a] - arr_x[0], 2) +  pow(foody[a] - arr_y[0], 2) ;
    dist=sqrt(dist); 
if(dist<=15)
    {

    foodx[a]=(rand()%631) + 10;
    foody[a]=rand()%600;
    score+=5;
    snakelength++;
   
    }
}

}


	//Move left check Function//
void moveleft()
{

arr_x[0]-=20;

if(arr_x[0]<=0)
arr_x[0]=650;


int tempy=arr_y[0];
int tempx=arr_x[0];

int tempy2;
int tempx2;


for(int a=1;a<snakelength;a++)
 {

	//for Y swapping
	tempy2=arr_y[a];
	arr_y[a]=tempy;
	tempy=tempy2;

	//for X swapping
	tempx2=arr_x[a];
	arr_x[a]=tempx;
	tempx=tempx2;

 }

}


	//Move right check//
void moveright()
{

arr_x[0]+=20;

if(arr_x[0]>650)
arr_x[0]=0;

int tempy=arr_y[0];
int tempx=arr_x[0];

int tempy2;
int tempx2;


for(int a=1;a<snakelength;a++)
 {

	//for Y swapping
	tempy2=arr_y[a];
	arr_y[a]=tempy;
	tempy=tempy2;

	//for X swapping
	tempx2=arr_x[a];
	arr_x[a]=tempx;
	tempx=tempx2;

 }

}

	//Move up check//
void moveup()
{

arr_y[0]+=20;

if(arr_y[0]>=650)
arr_y[0]=0;

int tempy=arr_y[0];
int tempx=arr_x[0];

int tempy2;
int tempx2;

{
for(int a=1;a<snakelength;a++)
 {

	//for Y swapping
	tempy2=arr_y[a];
	arr_y[a]=tempy;
	tempy=tempy2;

	//for X swapping
	tempx2=arr_x[a];
	arr_x[a]=tempx;
	tempx=tempx2;

}

}


}

	//Move down check//
void movedown()
{

arr_y[0]-=20;

if(arr_y[0]<=0)
arr_y[0]=650;

int tempy=arr_y[0];
int tempx=arr_x[0];

int tempy2;
int tempx2;

{
for(int a=1;a<snakelength;a++)
 {

	//for Y swapping
	tempy2=arr_y[a];
	arr_y[a]=tempy;
	tempy=tempy2;

	//for X swapping
	tempx2=arr_x[a];
	arr_x[a]=tempx;
	tempx=tempx2;


 }


}


}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

	//Display function//
void Display()
{

if(game == 1)
{
	glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors 
	
        DrawString(250, 350, "Start Game (S)", colors[RED]);

	DrawString(250,	 300, "Exit Game (E)", colors[RED]);

}	
else if(game == 2)
{
if(programend==false)
{

snakefood--;
if (score>=50 && score<100)
stage=2;


if (score>=150)
stage=3;



if (button==1)
{


moveleft();

eatfood();   

}




if (button==2)
{

moveright();

eatfood();  
}

if (button==3)
{

moveup();

eatfood(); 
}




if (button==4)
{

movedown();

eatfood(); 
}

//--------------------------------------//

    // set the background color using function glClearColotgr.
    // to change the background play with the red, green and blue values below.
    // Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

    glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors 
    

	DrawString( 10, 630, "Score =  ", colors[MISTY_ROSE]); 	
	DrawString( 110, 630, NumberToString(score) , colors[MISTY_ROSE]);
	DrawString( 150, 630, "Stage : ", colors[MISTY_ROSE]);	
	DrawString( 220, 630, NumberToString(stage) , colors[MISTY_ROSE]);

	DrawCircle( arr_x[0] ,  arr_y[0], 10 , colors[5]);  

for(int a=0;a<snakelength;a++)
	{       	
 	DrawSquare( arr_x[a]-5 , arr_y[a]-5 ,10,colors[10]);  
	}	

for(int a=0;a<5;a++)
	{
	DrawCircle( foodx[a] ,  foody[a], 5, colors[8]);
	}



//--------------------------------------------------------------//
	

for(int a = 3 ; a <snakelength; a++)
{
	if(arr_x[0] == arr_x[a] && arr_y[0] == arr_y[a])
	{			
	programend=true;
	}

}

	//-------------------------------//
	
	//Lines for Boundary//
	if (stage>=2)
{	DrawLine(10, 5, 640, 5, 5,colors[WHITE]);
	DrawLine(640, 5, 640, 600, 5,colors[WHITE]); 
	DrawLine(10, 600, 640, 600, 5,colors[WHITE]); 
	DrawLine(10, 5, 10, 600, 5,colors[WHITE]);

for(int a=0;a<5;a++)
{
if (arr_y[a]-10<=6)
programend=true;
}

for(int a=0;a<5;a++)
{
if (arr_y[a]+10>=598)
programend=true;
}

for(int a=0;a<5;a++)
{
if (arr_x[a]-10<=11)
programend=true;
}
 

for(int a=0;a<5;a++)
{
if (arr_x[a]+10>=639)
 programend=true;
}



}	//-------------------------------//


	//Bottom Left corner hurdle//

if (stage>=3)

{
int xarr[]={100,120,140,100,100};
int yarr[]={100,100,100,120,140};
int D[5]={};

for(int a=0;a<5;a++)
{

	DrawCircle( xarr[a] , yarr[a] ,10,colors[10]);

	int distancehurdel3 = pow(arr_x[0] - xarr[a],2)+pow(arr_y[0] - yarr[a],2);
	 distancehurdel3=sqrt(distancehurdel3);

         D[a]=distancehurdel3;


	 if(D[a]<=21)
	 programend=true;  
        
}

	//---------------------------------//


	//Top Right corner Hurdle//
int xarr1[]={550,530,510,550,550};
int yarr1[]={550,550,550,530,510};
int D1[5]={};
for(int a=0;a<5;a++)
{

	DrawCircle( xarr1[a] , yarr1[a] ,10,colors[10]);  

	int distancehurdel4 = pow(arr_x[0] - xarr1[a],2)+pow(arr_y[0] - yarr1[a],2);
	   distancehurdel4=sqrt(distancehurdel4);
	
         D1[a]=distancehurdel4;


	if(D1[a]<=21)
	programend=true;
      
}
	//----------------------------------//


	//Middle Lines Hurdle//
int xarr2[]={240,260,280,300,320};
int yarr2[]={240,240,240,240,240};
int D2[5]={};
for(int a=0;a<5;a++)
{

	DrawCircle( xarr2[a] , yarr2[a] ,10,colors[10]); 

	int distancehurdel5 = pow(arr_x[0] - xarr2[a],2)+pow(arr_y[0] - yarr2[a],2);
	   distancehurdel5=sqrt(distancehurdel5);
 
		
         D2[a]=distancehurdel5;


	if(D2[a]<=21)
	programend=true;
}

	//---------------------------//

	//Middel lines Hurdle//

int xarr3[]={240,260,280,300,320};
int yarr3[5]={300,300,300,300,300};
int D3[5]={};
for(int a=0;a<5;a++)
{

	DrawCircle( xarr3[a] , yarr3[a] ,10,colors[10]);  

	int distancehurdel6 = pow(arr_x[0] - xarr3[a],2)+pow(arr_y[0] - yarr3[a],2);
	   distancehurdel6=sqrt(distancehurdel6);
		
         D3[a]=distancehurdel6;


	if(D3[a]<=21)
	programend=true;
}

	//-------------------------------//



       //Bottom Right corner Hurdle//
int xarr4[]={500,520,540,540,540};
int yarr4[]={100,100,100,120,140};
int D4[5]={};
for(int a=0;a<5;a++)
{

	DrawCircle( xarr4[a] , yarr4[a] ,10,colors[10]);  

	int distancehurdel7 = pow(arr_x[0] - xarr4[a],2)+pow(arr_y[0] - yarr4[a],2);
	   distancehurdel7=sqrt(distancehurdel7);
		
         D4[a]=distancehurdel7;


	if(D4[a]<=21)
	programend=true;
}

	//--------------------------------//

	//Top Right corner Hurdle//
int xarr5[]={100,120,140,100,100};
int yarr5[]={550,550,550,530,510};
int D5[5]={};
for(int a=0;a<5;a++)
{

	DrawCircle( xarr5[a] , yarr5[a] ,10,colors[10]);  

	int distancehurdel8 = pow(arr_x[0] - xarr5[a],2)+pow(arr_y[0] - yarr5[a],2);
	   distancehurdel8=sqrt(distancehurdel8);
		
         D5[a]=distancehurdel8;


	if(D5[a]<=21)
	programend=true;
}

}
	//----------------------------------//

if (snakefood==0)
{ 

for(int a=0;a<5;a++) 
{ 
	foodx[a]=(rand() %631) + 10;
	foody[a]=rand()%600; 
	DrawCircle( foodx[a] ,  foody[a], 5, colors[8]);
}

  
	snakefood=80;
}
}
}
else if(game == 3)
	{
		exit(1);
	}
else
{ 

	glClearColor(0/*Red Component*/, 0.0/*Green Component*/,
            0.0/*Blue Component*/, 0 /*Alpha component*/);// Red==Green==Blue==1 --> White Colour
    glClear(GL_COLOR_BUFFER_BIT);   //Update the colors 
DrawString( 100, 300, "Game is over", colors[MISTY_ROSE]);
  

}
    
   glutSwapBuffers(); // do not modify this line..
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */


/*Keys check*/

void NonPrintableKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT)
    {snakefood++;
		
	if(button != 2)
         button=1;
    } 
	
    
    else if (key == GLUT_KEY_RIGHT) 
  
     {snakefood++;
	if(button != 1)     
	{
      button=2;
 
     } 
	}

    else if (key == GLUT_KEY_UP)  
      
    {snakefood++;
      if (button != 4)
	{
      button=3;
      
    }
	}

    else if (key == GLUT_KEY_DOWN)   
   
    {snakefood++;
   
	if(button != 3)
	{
      button=4;
        
    }    
}
    /* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
     * this function*/
     glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
    if (key == KEY_ESC/* Escape key ASCII*/) {
        exit(1); // exit the program when escape key is pressed.
    }
    if (key == 'R' || key=='r'/* Escape key ASCII*/) {
        //exit(1); // exit the program when escape key is pressed.
    	//aswangle+=90;
    }
    
    else if (int(key) == 13)
    {  
	}
    
	if(key == 101 || key == 69)
	{
		game = 3;
	}
	if(key == 19|| key == 115)
	{
		game = 2;
	}
   glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {


// implement your functionality here
	glutPostRedisplay();
// once again we tell the library to call our Timer function after next 1000/FPS
    glutTimerFunc(1000.0 / FPS, Timer, 0);

}



/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
    int width = 650, height = 650; // i have set my window size to be 800 x 600
    InitRandomizer(); // seed the random number generator...
    glutInit(&argc, argv); // initialize the graphics library...

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
    glutInitWindowPosition(50, 50); // set the initial position of our window
    glutInitWindowSize(width, height); // set the size of our window
    glutCreateWindow("PF's Snake Game"); // set the title of our game window
    SetCanvasSize(width, height); // set the number of pixels...

// Register your functions to the library,
// you are telling the library names of function to call for different tasks.
//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.
    
   
glutDisplayFunc(Display); // tell library which function to call for drawing Canvas.
 glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
    glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
    glutTimerFunc(5.0 / FPS, Timer, 0);

// now handle the control to library and it will call our registered functions when
// it deems necessary...
    glutMainLoop();
    return 1;
}
#endif /* Snake Game */

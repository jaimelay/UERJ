#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include "RgbImage.h"
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

fs::path currentPath = fs::current_path();
string currentPathWithSrcDirectory = currentPath.string() + "\\src\\";

string filenameEarth = currentPathWithSrcDirectory + "earthmap1k.bmp";
string filenameMoon = currentPathWithSrcDirectory + "moonmap1k.bmp";
string filenameSun = currentPathWithSrcDirectory + "sun.bmp";
string filenameMars = currentPathWithSrcDirectory + "mars.bmp";
string filenamePhobos = currentPathWithSrcDirectory + "phobos.bmp";
string filenameDeimos = currentPathWithSrcDirectory + "deimos.bmp";
string filenameJupiter = currentPathWithSrcDirectory + "jupiter.bmp";

GLuint _textureIdEarth;
GLuint _textureIdMoon;
GLuint _textureIdSun;
GLuint _textureIdMars;
GLuint _textureIdPhobos;
GLuint _textureIdDeimos;
GLuint _textureIdJupiter;

GLUquadric* quadEarth;
GLUquadric* quadMoon;
GLUquadric* quadSun;
GLUquadric* quadMars;
GLUquadric* quadPhobos;
GLUquadric* quadDeimos;
GLUquadric* quadJupiter;

float view = 0;

float moonYear = 0, moonMonth = 0, moonDay = 0;
float earthYear = 0, earthMonth = 0, earthDay = 0;
float marsYear = 1.0f;
float jupiterYear = 1.0f;

float pan_x = 0.0f, pan_y = 0.0f;
float zoom = 1.0f;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
		case 'w': //Top view
			view = 0;
			glutPostRedisplay();
			break;
		case 'a': //Side view
			view = -90;
			glutPostRedisplay();
			break;
		case 'z': //Bottom view
			view = 180;
			glutPostRedisplay();
			break;
	}
}

void handleSpecialFunc(int key, int xx, int yy) {
	switch (key) {
		case GLUT_KEY_RIGHT:
			pan_x = pan_x + 0.1f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			pan_x = pan_x - 0.1f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_UP:
			pan_y = pan_y + 0.1f;
			glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
			pan_y = pan_y - 0.1f;
			glutPostRedisplay();
			break;
	}
}

void handleMouse(int button, int state, int x, int y) {
	switch (button) {
		case GLUT_LEFT_BUTTON:
			if (zoom > 0.2f) {
				zoom = zoom - 0.1f;
			}
			glutPostRedisplay();
			break;
		case GLUT_RIGHT_BUTTON:
			if (zoom < 100) {
				zoom = zoom + 0.1f;
			}
			glutPostRedisplay();
			break;
		case 3:
			break;
		case 4:
			break;
	}

}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(string filenameStr) {
	const char* filename = filenameStr.c_str();
	GLuint textureId;

	RgbImage theTexMap(filename); //Image with texture

	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);	//Tell OpenGL which texture to edit
												//Map the image to the texture
	glTexImage2D(
		GL_TEXTURE_2D,	//Always GL_TEXTURE_2D
		0,						//0 for now
		GL_RGB,					//Format OpenGL uses for image
		theTexMap.GetNumCols(),	//Width 
		theTexMap.GetNumRows(),	//Height
		0,						//The border of the image
		GL_RGB,					//GL_RGB, because pixels are stored in RGB format
		GL_UNSIGNED_BYTE,		//GL_UNSIGNED_BYTE, because pixels are stored as unsigned numbers
		theTexMap.ImageData()
	);	//The actual pixel data
	return textureId; //Returns the id of the texture
}

// define a fonte de luz (LIGHT0)
void initLighting(void) {
	GLfloat lightposition[4] = { -15.0f, 0.0f, 0.0f, 1.0 };
	GLfloat luzAmbiente[4] = { 0.09, 0.09, 0.09, 1.0 };
	GLfloat luzDifusa[4] = { 1.0, 1.0, 1.0, 1.0 };		// "cor" 
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };	// "brilho" 

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	// Especifica que a cor de fundo da janela ser� preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, lightposition);

}

void initRendering() {
	quadEarth = gluNewQuadric();
	_textureIdEarth = loadTexture(filenameEarth);

	quadMoon = gluNewQuadric();
	_textureIdMoon = loadTexture(filenameMoon);

	quadSun = gluNewQuadric();
	_textureIdSun = loadTexture(filenameSun);

	quadMars = gluNewQuadric();
	_textureIdMars = loadTexture(filenameMars);

	quadPhobos = gluNewQuadric();
	_textureIdPhobos = loadTexture(filenamePhobos);

	quadDeimos = gluNewQuadric();
	_textureIdDeimos = loadTexture(filenameDeimos);

	quadJupiter = gluNewQuadric();
	_textureIdJupiter = loadTexture(filenameJupiter);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(pan_x, pan_y, -15.0f);
	glScalef(zoom, zoom, 1.0f);
	glRotatef(view, 1.0f, 0.0f, 0.0f);

	glPushMatrix();
		glDisable(GL_LIGHTING);
		glRotatef((GLfloat)earthYear, 0.0f, 1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdSun);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadSun, 1);
		gluSphere(quadSun, 0.7, 20, 15);
		glEnable(GL_LIGHTING);
		initLighting();
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat)earthYear, 0.0f, 1.0f, 0.0f);
		glTranslatef(3.0f, 0.0f, 0.0f);
		glRotatef((GLfloat)earthDay, 0.0f, 1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdEarth);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadEarth, 1);
		gluSphere(quadEarth, 0.2, 10, 8);

		glTranslatef(1.0f, 0.0f, 0.0f);
		glRotatef((GLfloat)earthMonth, 0.0f, 1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdMoon);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadMoon, 1);
		gluSphere(quadMoon, 0.07, 10, 5);
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat)marsYear, 0.0f, 1.0f, 0.0f);
		glTranslatef(6.0f, 0.0f, 0.0f);
		glRotatef((GLfloat)earthDay, 0.0f, 1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdMars);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadMars, 1);
		gluSphere(quadMars, 0.2, 10, 8);

		glPushMatrix();
			glRotatef((GLfloat)earthMonth + 2, 0.0f, 1.0f, 0.0f);
			glTranslatef(0.6f, 0.0f, 0.0f);
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, _textureIdDeimos);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			gluQuadricTexture(quadDeimos, 1);
			gluSphere(quadDeimos, 0.05, 10, 5);

			glPushMatrix();
				glTranslatef(1.2f, 0.0f, 0.0f);
				glRotatef((GLfloat)earthMonth + 3, 0.0f, 1.0f, 0.0f);
				glEnable(GL_TEXTURE_2D);
				glBindTexture(GL_TEXTURE_2D, _textureIdPhobos);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				gluQuadricTexture(quadPhobos, 1);
				gluSphere(quadPhobos, 0.12, 10, 5);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();

	glPushMatrix();
		glRotatef((GLfloat)jupiterYear, 0.0f, 1.0f, 0.0f);
		glTranslatef(8.0f, 0.0f, 0.0f);
		glRotatef((GLfloat)earthDay, 0.0f, 1.0f, 0.0f);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureIdJupiter);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		gluQuadricTexture(quadJupiter, 1);
		gluSphere(quadJupiter, 0.4, 10, 8);
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	earthYear += 0.6;

	if (earthYear > 360.f) {
		earthYear -= 360;
	}

	earthMonth += 3.0;

	if (earthMonth > 360.f) {
		earthMonth -= 360;
	}

	earthDay += 1.0;

	if (earthDay > 360.f) {
		earthDay -= 360;
	}

	marsYear += 0.5;

	if (marsYear > 360.f) {
		marsYear -= 360;
	}

	jupiterYear += 0.4;

	if (jupiterYear > 360.f) {
		jupiterYear -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Solar System by Jaime Lay & Leonardo Andrade");

	initLighting();
	initRendering();
	glutTimerFunc(25, update, 0);
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutSpecialFunc(handleSpecialFunc);
	glutMouseFunc(handleMouse);
	glutReshapeFunc(handleResize);

	glutMainLoop();
	return 0;
}

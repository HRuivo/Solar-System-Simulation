// Main

#include <iostream>
#include <gl\glut.h>
#include "Planet.h"
#include "Camera.h"
#include "Star.h"

# pragma comment (lib, "GlU32.Lib")
# pragma comment (lib, "OpenGL32.Lib")
# pragma comment (lib, "glut32.lib")
# pragma comment (lib, "SOIL.lib")


using namespace std;


int const SCREEN_WIDTH = 800;
int const SCREEN_HEIGHT = 600;
char const *WINDOW_TITLE = "Solar System Simulation";
int const NUM_PLANETS = 3;

float deltaTime = 0.0f;
float TimeScale = 100.0f;

Camera* camera1;
Star* sun;
Planet* planets[NUM_PLANETS];


void initOpenGL(int argc, char **argv);
void onIdle(void);
void onDraw(void);
void onResize(int w, int h);
void KeyboardDownCallback(unsigned char key, int x, int y);
void KeyboardUpCallback(unsigned char key, int x, int y);

void initPlanets(void);

GLuint LoadTexture(char* filename) {
	GLuint returnTex = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y);

	if(returnTex == 0)
		return 0;

	glBindTexture(GL_TEXTURE_2D, returnTex);

	return returnTex;
}


int main(int argc, char **argv) {
	initOpenGL(argc, argv);

	// Init camera
	camera1 = new Camera();

	initPlanets();

	glutMainLoop();

	return 0;
}

void initOpenGL(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH  |
						GLUT_DOUBLE |
						GLUT_RGBA   |
						GLUT_ALPHA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow(WINDOW_TITLE);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glutIdleFunc(onIdle);
	glutDisplayFunc(onDraw);
	glutReshapeFunc(onResize);
	glutKeyboardFunc(KeyboardDownCallback);
	glutKeyboardUpFunc(KeyboardUpCallback);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0f);
}

void initPlanets(void) {
	// init Sun
	sun = new Star(10.0f, LoadTexture("Textures\\sun.tga"));

	planets[0] = new Planet(1.0f, LoadTexture("Textures\\mars.tga"));
	planets[0]->GetOrbit()->SetDistance(50.0f);
	planets[0]->GetOrbit()->SetMinDistance(0.5f);
	planets[0]->GetOrbit()->SetMaxDistance(1.5f);
	planets[1] = new Planet(1.0f, LoadTexture("Textures\\earth.tga"));
	planets[1]->GetOrbit()->SetDistance(100.0f);	
	planets[2] = new Planet(1.0f, LoadTexture("Textures\\venus.tga"));
	planets[2]->GetOrbit()->SetDistance(250.0f);
}

void onIdle(void) {
	deltaTime = 0.016666667f * TimeScale;

	camera1->Update(deltaTime);
	
	for(int i = 0; i < NUM_PLANETS; i++) {
		planets[i]->Update(deltaTime);
	}
}

void onDraw(void) {
	// Clear backbuffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Draw planets
	for (int i = 0;i < NUM_PLANETS; i++) {
		planets[i]->Draw();
	}

	// Draw Star
	sun->Draw();

	// Display Frame
	glutSwapBuffers();
	glutPostRedisplay();
}

void onResize(int w, int h) {
	float ratio = 1.0 * w / h;
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0) h = 1;
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	// Set the correct perspective.
	gluPerspective(45,ratio,1,1000);
	//glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
}

void KeyboardDownCallback(unsigned char key, int x, int y) {
	if(key == 'W' || key == 'w') {
		camera1->DeltaMove = 1.0f;
	}
	else if(key == 'S' || key == 's') {
		camera1->DeltaMove = -1.0f;
	}
	else if(key == 'A' || key == 'a') {
		camera1->Yaw -= 0.1f;
	}
	else if(key == 'D' || key == 'd') {
		camera1->Yaw += 0.1f;
	}
	else if(key == 'N' || key == 'n') {
		TimeScale -= 10.0f;
	}
	else if(key == 'M' || key == 'm') {
		TimeScale += 10.0f;
	}
}

void KeyboardUpCallback(unsigned char key, int x, int y) {
	if(key == 27)
		exit(0);

	else if( key == 'W' || key == 'w' || key == 'S' || key == 's') {
		camera1->DeltaMove = 0.0f;
	}
}

// Planet

#ifndef H_PLANET
#define H_PLANET

#include <iostream>
#include <gl\glut.h>
#include "SOIL.h"
#include "Orbit.h"

#endif

class Planet {
private:
	GLfloat *position;
	GLfloat radius;

	GLuint texture;
	GLUquadric *solid;

	Orbit* orbit;

public:
	Planet(GLfloat radius, GLuint texture);

	void Update(float dt);
	void Draw(void);

	GLfloat* GetPosition() { return position; }
	void SetPosition(GLfloat* position) { this->position = position; }
	void SetPosition(GLfloat x, GLfloat y, GLfloat z) {
		position[0] = x;
		position[1] = y;
		position[2] = z;
	}

	GLfloat GetRadius() { return radius; }
	void SetRadius(GLfloat radius) { this->radius = radius; }

	GLuint GetTexture() { return texture; }
	void SetTexture(GLuint texture);

	Orbit* GetOrbit() { return orbit; }
};

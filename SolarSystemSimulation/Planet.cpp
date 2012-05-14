// Planet
#include <iostream>
#include "Planet.h"

Planet::Planet(GLfloat radius, GLuint texture) {
	this->radius = radius;
	position = new GLfloat[3];
	
	SetPosition(0,0,0);
	SetTexture(texture);

	orbit = new Orbit();
	orbit->SetDistance(15);
}

void Planet::SetTexture(GLuint texture) {
	this->texture = texture;
		
	solid = gluNewQuadric();
	gluQuadricDrawStyle(solid, GLU_FILL);

	gluQuadricTexture(solid, GL_TRUE);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Planet::Update(float dt) {
	orbit->Update(dt);
	
	orbit->UpdatePosition(position);
}

void Planet::Draw(void) {
	orbit->Draw();

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, texture);
		glTranslatef(position[0], position[1], position[2]);
		gluSphere(solid, radius, 32, 32);
	glPopMatrix();
}

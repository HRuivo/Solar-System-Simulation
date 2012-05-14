// Star

#include "Star.h"

Star::Star(float radius, GLuint texture) {
	this->radius = radius;
	position = new float[3];
	SetPosition(0.0f, 0.0f, 0.0f);
	SetTexture(texture);
}

void Star::SetTexture(GLuint texture) {
	this->texture = texture;
		
	solid = gluNewQuadric();
	gluQuadricDrawStyle(solid, GLU_FILL);

	gluQuadricTexture(solid, GL_TRUE);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Star::Draw(void) {
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, texture);
	glTranslatef(position[0], position[1], position[2]);
	gluSphere(solid, radius, 32, 32);
	glPopMatrix();
}

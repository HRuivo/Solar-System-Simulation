// Orbit

#include "Orbit.h"

Orbit::Orbit() {
	minDistance = 1.0f;
	maxDistance = 1.0f;
	distance    = 1.0f;

	origin = new float[3];
	origin[0] = 0;
	origin[1] = 0;
	origin[2] = 0;

	lifetime = 0.0f;
}

void Orbit::Update(float dt) {
	lifetime += dt;
}

void Orbit::Draw() {
	float x;
	float z;
	
	glBegin(GL_LINE_LOOP);

	for (float i = 0; i < (3.14 * 2); i += 3.14 / 180) {
		glVertex3fv(GetPosition(i));
	}

	glEnd();
}

float* Orbit::GetPosition(float time) {
	float p[3] = { 0, 0, 0 };
	
	p[1] = 0.0f;
	p[0] = (cos(time) / minDistance) * distance;
	p[2] = (sin(time) / maxDistance) * distance;

	return p;
}

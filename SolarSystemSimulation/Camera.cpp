#include <math.h>
#include "Camera.h"

void Camera::Update(float dt) {
	lookX = sin(Yaw) * cos(Pitch);
	lookY = sin(Pitch);
	lookZ = -cos(Yaw) * cos(Pitch);

	posX = posX + DeltaMove * lookX * speed;
	posY = posY + DeltaMove * lookY * speed;
	posZ = posZ + DeltaMove * lookZ * speed;	

	if(cos(Pitch) < 0.0f)
		upY = -1.0f;
	else
		upY = 1.0f;


	glLoadIdentity();
	gluLookAt(
		posX, posY, posZ,
		posX + lookX, posY + lookY, posZ + lookZ,
		upX, upY, upZ);
}

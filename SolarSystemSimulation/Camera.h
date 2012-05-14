#ifndef H_CAMERA
#define H_CAMERA

#include <gl\glut.h>

#endif

class Camera {
private:
	float posX, posY, posZ;
	float lookX, lookY, lookZ;
	float upX, upY, upZ;

	float speed;

public:
	float DeltaMove;
	float Pitch, Yaw;

	Camera() {
		Yaw = 0.0f;
		Pitch = 0.0f;

		posX = 0.0f; posY = 1.75f; posZ = 10.0f;
		lookX = 0.0f; lookY = 0.0f; lookZ = -1.0f;
		upX = 0.0f; upY = 1.0f; upZ = 0.0f;
		
		speed = 1.0f;

		DeltaMove = 0.0f;
	}

	void Update(float dt);
};

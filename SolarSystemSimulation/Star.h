#ifndef H_STAR
#define H_STAR

#include <gl\glut.h>

#endif

class Star {
private:
	float *position;
	float radius;

	GLuint texture;
	GLUquadric *solid;

public:
	Star(float radius, GLuint texture);

	void Draw(void);

	float* GetPosition() { return position; }
	void SetPosition(float* position) { this->position = position; }
	void SetPosition(float x, float y, float z) {
		position[0] = x;
		position[1] = y;
		position[2] = z;
	}

	float GetRadius() { return radius; }
	void SetRadius(float radius) { this->radius = radius; }

	GLuint GetTexture() { return texture; }
	void SetTexture(GLuint texture);
};

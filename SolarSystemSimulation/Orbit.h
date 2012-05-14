// Orbit

#ifndef H_ORBIT
#define H_ORBIT

#include <gl\glut.h>
#include <math.h>

#endif

class Orbit {
private:
	float* origin;
	float distance;

	float minDistance, maxDistance;

	float lifetime;

public:
	Orbit();

	void Update(float dt);
	void Draw();
	
	float* GetPosition(float time);

	float GetDistance() { return distance; }
	void SetDistance(float distance) { this->distance = distance; }

	float* GetOrigin() { return origin; }
	void SetOrigin(float* origin) { this->origin = origin; }

	float GetMinDistance() { return minDistance; }
	void SetMinDistance(float minDistance) { this->minDistance = minDistance; }

	float GetMaxDistance() { return maxDistance; }
	void SetMaxDistance(float maxDistance) { this->maxDistance = maxDistance; }

	float* GetCurrentPosition() {
		float newPos[3] = { origin[0], origin[1], origin[2] };
		float* orbitPos = (float*)GetPosition(lifetime);
		newPos[0] += orbitPos[0];
		newPos[1] += orbitPos[1];
		newPos[2] += orbitPos[2];

		return newPos;
	}

	void UpdatePosition(float* planetPosition) {
		float* orbitPos = (float*)GetPosition(lifetime / distance);

		planetPosition[0] = origin[0] + orbitPos[0];
		planetPosition[1] = origin[1] + orbitPos[1];
		planetPosition[2] = origin[2] + orbitPos[2];
	}
};

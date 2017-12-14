#include "cvec.h"
#include "matrix4.h"
#include "mesh.h"

#define PARTICLE_SIZE (float)0.1

class Particle {
	
public:

	Cvec3 position;
	BoundingBox bbox;
	Mesh::Vertex *vertex;
	bool active;

	Particle() {
		active = false;
	}
};
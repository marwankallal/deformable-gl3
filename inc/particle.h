#include "cvec.h"
#include "matrix4.h"
#include "mesh.h"

#define PARTICLE_SIZE (float)0.1

class Particle {
	Cvec3 position;
	BoundingBox bbox;
	Mesh::Vertex vertex;
};
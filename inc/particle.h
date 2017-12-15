#include "cvec.h"
#include "matrix4.h"
#include "mesh.h"
#include "boundingbox.h"

#define PARTICLE_SIZE (float)0.1

class Region;

class Particle {
	
public:

	Cvec3 position;
	Cvec3 displacement = Cvec3();
	Cvec3 force = Cvec3();
	Cvec3 velocity = Cvec3();
	BoundingBox bbox;
	std::vector<Mesh::Vertex*>  vertices;
	std::vector<Region*> regions;
	int mass;

	Particle() {
		mass = 1;
	}

	void setPosition(Cvec3 pos, Mesh mesh) {
		position = pos;
		bbox.x_max = pos[0] + PARTICLE_SIZE / 2;
		bbox.x_min = pos[0] - PARTICLE_SIZE / 2;
		bbox.y_max = pos[1] + PARTICLE_SIZE / 2;
		bbox.y_min = pos[1] - PARTICLE_SIZE / 2;
		bbox.z_max = pos[2] + PARTICLE_SIZE / 2;
		bbox.z_min = pos[2] - PARTICLE_SIZE / 2;

		for (int i = 0; i < mesh.getNumVertices(); i++) {
			if (mesh.getVertex(i).getPosition()[0] < bbox.x_max && mesh.getVertex(i).getPosition()[0] > bbox.x_min &&
				mesh.getVertex(i).getPosition()[1] < bbox.y_max && mesh.getVertex(i).getPosition()[1] > bbox.y_min &&
				mesh.getVertex(i).getPosition()[2] < bbox.z_max && mesh.getVertex(i).getPosition()[2] > bbox.z_min) {
				vertices.push_back(&mesh.getVertex(i));
			}
		}
	}
};

class Region {

public:

	Matrix4 displacement;
	Cvec3 center_idx;
	int w = 1;

	Region(Cvec3 cen_idx, std::vector<std::vector<std::vector<Particle> > > *particles) {
		center_idx = cen_idx;

		//add self to relevent particles
		for (int i = center_idx[0] - 1; i < center_idx[0] + 2; i++) {
			for (int j = center_idx[1] - 1; j < center_idx[1] + 2; j++) {
				for (int k = center_idx[2] - 1; k < center_idx[2] + 2; k++) {
					(*particles)[i][j][k].regions.push_back(this);
				}
			}
		}

	}
};
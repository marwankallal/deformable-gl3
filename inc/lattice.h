#include <vector>
#include <cmath>

#include "particle.h"
#include "mesh.h"
#include "boundingbox.h"

class Lattice {

	std::vector<std::vector<std::vector<Particle> > > particles;
	Mesh orig_mesh;

public:

	Lattice(Mesh mesh) {
		create_lattice(mesh);
	}

	void create_lattice(Mesh mesh) {
		orig_mesh = mesh;
		BoundingBox bbox = get_lattice_bounds(mesh);

		// resize vectors for easy access
		particles.resize((bbox.x_max - bbox.x_min) / PARTICLE_SIZE);
		for (int i = 0; i < (bbox.y_max - bbox.y_min) / PARTICLE_SIZE; i++) {
			particles[i].resize((bbox.y_max - bbox.y_min) / PARTICLE_SIZE);
			for (int j = 0; j < (bbox.z_max - bbox.z_min) / PARTICLE_SIZE; j++) {
				particles[i][j].resize((bbox.z_max - bbox.z_min) / PARTICLE_SIZE);
			}
		}

		//initialize positions
		for (int i = 0; i < particles.size(); i++) {
			for (int j = 0; j < particles[0].size(); j++) {
				for (int k = 0; k < particles[0][0].size(); k++) {
					particles[i][j][k].position = Cvec3(i - ((bbox.x_max - bbox.x_min) / 2) * PARTICLE_SIZE,
						j - ((bbox.y_max - bbox.y_min) / 2) * PARTICLE_SIZE,
						k - ((bbox.z_max - bbox.z_min) / 2) * PARTICLE_SIZE);
				}
			}
		}

	}

private:
	BoundingBox get_lattice_bounds(Mesh mesh) {
		BoundingBox bbox = { 0 };
		for (int i = 0; i < mesh.getNumVertices(); i++) {
			if (mesh.getVertex(i).getPosition()[0] > bbox.x_max) {
				bbox.x_max = mesh.getVertex(i).getPosition()[0];
			}
			if (mesh.getVertex(i).getPosition()[0] < bbox.x_min) {
				bbox.x_min = mesh.getVertex(i).getPosition()[0];
			}
			if (mesh.getVertex(i).getPosition()[1] > bbox.y_max) {
				bbox.y_max = mesh.getVertex(i).getPosition()[1];
			}
			if (mesh.getVertex(i).getPosition()[1] < bbox.y_min) {
				bbox.y_min = mesh.getVertex(i).getPosition()[1];
			}
			if (mesh.getVertex(i).getPosition()[2] > bbox.z_max) {
				bbox.z_max = mesh.getVertex(i).getPosition()[2];
			}
			if (mesh.getVertex(i).getPosition()[2] < bbox.z_min) {
				bbox.z_min = mesh.getVertex(i).getPosition()[2];
			}
		}

		//round up to allow proper cube voxels
		bbox.x_max = ceil((bbox.x_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.y_max = ceil((bbox.y_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.z_max = ceil((bbox.z_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.x_min = floor((bbox.x_min / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.y_min = floor((bbox.y_min / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.z_min = floor((bbox.z_min / PARTICLE_SIZE)) * PARTICLE_SIZE;

		return bbox;
	}

};
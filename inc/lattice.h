#include <vector>
#include <cmath>

#include "particle.h"
#include "mesh.h"

class Lattice {

	std::vector<Particle> particles;
	Mesh orig_mesh;

public:

	Lattice(Mesh mesh) {
		create_lattice(mesh);
	}

	void create_lattice(Mesh mesh) {
		orig_mesh = mesh;
		bounding_box_t bbox = get_lattice_bounds(mesh);
	}

private:
	bounding_box_t get_lattice_bounds(Mesh mesh) {
		bounding_box_t bbox = { 0 };
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

		bbox.x_max = ceil((bbox.x_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.y_max = ceil((bbox.y_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.z_max = ceil((bbox.z_max / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.x_min = floor((bbox.x_min / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.y_min = floor((bbox.y_min / PARTICLE_SIZE)) * PARTICLE_SIZE;
		bbox.z_min = floor((bbox.z_min / PARTICLE_SIZE)) * PARTICLE_SIZE;

		return bbox;
	}

};

#include "mesh.h"

class BoundingBox {

public:

	float x_max = 0;
	float x_min = 0;
	float y_max = 0;
	float y_min = 0;
	float z_max = 0;
	float z_min = 0;

	static bool face_in_bounds(Mesh::Face face, BoundingBox bbox) {

		BoundingBox face_bbox;
		//calculate face bounding box
		for (int i = 0; i < face.getNumVertices(); i++) {
			if (face.getVertex(i).getPosition()[0] > bbox.x_max) {
				face_bbox.x_max = face.getVertex(i).getPosition()[0];
			}
			if (face.getVertex(i).getPosition()[0] < bbox.x_min) {
				face_bbox.x_min = face.getVertex(i).getPosition()[0];
			}
			if (face.getVertex(i).getPosition()[1] > bbox.y_max) {
				face_bbox.y_max = face.getVertex(i).getPosition()[1];
			}
			if (face.getVertex(i).getPosition()[1] < bbox.y_min) {
				face_bbox.y_min = face.getVertex(i).getPosition()[1];
			}
			if (face.getVertex(i).getPosition()[2] > bbox.z_max) {
				face_bbox.z_max = face.getVertex(i).getPosition()[2];
			}
			if (face.getVertex(i).getPosition()[2] < bbox.z_min) {
				face_bbox.z_min = face.getVertex(i).getPosition()[2];
			}
		}

		//check if boxes collide
		return boxes_collide(face_bbox, bbox);
	}

	static bool boxes_collide(BoundingBox box1, BoundingBox box2) {
		if ((box1.x_max > box2.x_min || box1.x_min < box2.x_max) &&
			(box1.y_max > box2.y_max || box1.y_min < box2.y_max) &&
			(box1.z_max > box2.z_min || box1.z_min < box2.z_max)) {
			return true;
		}
		else {
			return false;
		}
	}

};
#include "Swarm.h"


Swarm::Swarm()
{
	for (unsigned int i=0 ; i<1000 ; ++i) {
		positions.push_back(ofVec3f(ofRandom(-100, 100), ofRandom(-100, 100), ofRandom(-100, 100)));
		velocities.push_back(ofVec3f(ofRandom(-2,2), 0.0, 0.0));
		accelerations.push_back(ofVec3f(0.0, 0.0, 0.0));
		forces.push_back(ofVec3f(0.0, 0.0, 0.0));
		sizes.push_back(ofVec3f(ofRandom(10, 60)));
		attributes.push_back(Attributes());
		parameters.push_back(ParticleParameter());
	}
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		attributes[i].BorderCircle = true;
		attributes[i].Collision = true;
	}
	positions[0] = ofVec3f(-100,0,0);
	positions[1] = ofVec3f(100,1,0);
	velocities[0] = ofVec3f(0.3,0,0);
	velocities[1] = ofVec3f(-0.33,0,0);

}

Swarm::~Swarm()
{

}

void Swarm::update()
{
	
	updateAttributes();
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		accelerations[i] += forces[i] / parameters[i].mass;
		velocities[i] += accelerations[i];
		positions[i] += velocities[i];
		forces[i] = ofVec3f(0,0,0);
	}
}

void Swarm::updateAttributes()
{
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		if (attributes[i].BorderXYZ) {
			if (positions[i].x < -parameters[i].border_range) {
				velocities[i].x += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].x);
			}
			if (positions[i].x > parameters[i].border_range) {
				velocities[i].x += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].x);
			}
			if (positions[i].y < -parameters[i].border_range) {
				velocities[i].y += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].y);
			}
			if (positions[i].y > parameters[i].border_range) {
				velocities[i].y += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].y);
			}
			if (positions[i].z < -parameters[i].border_range) {
				velocities[i].z += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].z);
			}
			if (positions[i].z > parameters[i].border_range) {
				velocities[i].z += BORDER_MULTIPLIER * (parameters[i].border_range - positions[i].z);
			}
		}

		if (attributes[i].BorderCircle) {
			float dist = positions[i].distance(ofVec3f(0.0, 0.0, 0.0));
			if (dist > parameters[i].border_range) {
				velocities[i] += BORDER_MULTIPLIER * 
								(parameters[i].border_range - dist) *
								positions[i].getNormalized();
			}
		}

		if (attributes[i].Collision) {
			for (unsigned int j=i+1 ; j<positions.size() ; ++j) {
				if (attributes[j].Collision) {
					float dist = positions[i].squareDistance(positions[j]);
					if (8*dist < sizes[i].x + sizes[j].x) {
						velocities[i] -= COLLISION_MULTIPLIER * dist;
						velocities[j] += COLLISION_MULTIPLIER * dist;
					}
				}
			}
		}
	}
}

void Swarm::drawTextures()
{
	

}


#include "Swarm.h"


Swarm::Swarm()
{
	for (unsigned int i=0 ; i<2000 ; ++i) {
		positions.push_back(ofVec3f(ofRandom(-300, 300), ofRandom(-300, 300), 0));
		velocities.push_back(ofVec3f(ofRandom(-1.0,1.0), 0.0, 1.0));
		accelerations.push_back(ofVec3f(0.0, 0.0, 0.0));
		forces.push_back(ofVec3f(0.0, 0.0, 0.0));
		sizes.push_back(ofVec3f(ofRandom(30, 30)));
		attributes.push_back(Attributes());
		parameters.push_back(ParticleParameter());
	}
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		attributes[i].BorderCircle = true;
		attributes[i].BorderXYZ = false;
		attributes[i].Collision = true;
	}

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
		//forces[i] = ofVec3f(0,0,0);
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
					float dist = positions[i].distance(positions[j]);
					if (4*dist < sizes[i].x + sizes[j].x) {
						velocities[i].x += COLLISION_MULTIPLIER * (positions[i].x-positions[j].x);
						velocities[i].y += COLLISION_MULTIPLIER * (positions[i].y-positions[j].y);
						velocities[j].x += COLLISION_MULTIPLIER * (positions[j].x-positions[i].x);
						velocities[j].y += COLLISION_MULTIPLIER * (positions[j].y-positions[i].y);
					}
				}
			}
			velocities[i].limit(5);
		}
	}
}

void Swarm::draw()
{
	ofSetColor(255);
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		ofDrawCircle(positions[i],10);
	}

}


#pragma once

#include "ofMain.h"
#include "Attributes.h"
#include "ParticleParameter.h"
#include "ofParameter.h"

class Swarm{
	public:

		Swarm();
		~Swarm();
		void update();
		void updateAttributes();
		void draw();


		vector <ofVec3f> forces;
		vector <ofVec3f> accelerations;
		vector <ofVec3f> velocities;
		vector <ofVec3f> positions;


		vector <ofVec3f> sizes;

		vector <ParticleParameter> parameters;
		vector <Attributes> attributes;

	private:


};
#pragma once

#include "ofParameter.h"


class ParticleParameter{
	public:
		ParticleParameter();
		
		ofParameterGroup group;
		ofParameter<float> color_diff_mult;
		ofParameter<float> collision_mult;
		
		ofParameter<float> border_range;
		
		ofParameter<float> drag;
		ofParameter<float> mass;
		
		ofParameter<float> spring_stiffness;
		ofParameter<float> spring_damping;
		
	private:

		

	
};
#pragma once

#include "ofMain.h"


class Chain{
	public:

		Chain(int numLinks, float segLen);

		void positionSegment(int a, int b);

		void reachSegment(int i, ofVec3f posIn);

		void update();

		void draw();


		vector <ofVec3f> positions;
		vector <double> angle1;
		vector <double> angle2;
		ofVec3f target;

	private:
		float segLength = 50.0;

};
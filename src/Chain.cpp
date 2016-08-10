#include "Chain.h"

Chain::Chain(int numLinks, float segLen)
{
	segLength = segLen;
	positions.assign(numLinks, ofVec3f(0,0,0));
	angle1.assign(numLinks, 0.0);
	angle2.assign(numLinks, 0.0);
	positions[positions.size()-1] = ofVec3f(0,0, 0);
}

void Chain::positionSegment(int a, int b) 
{
	positions[b].x =positions[a].x + cos(angle1[a]) * cos(angle2[a]) * segLength;
	positions[b].y = positions[a].y + sin(angle1[a]) * cos(angle2[a]) * segLength; 
	positions[b].z = positions[a].z + sin(angle2[a]) * segLength; 
}

void Chain::reachSegment(int i, ofVec3f posIn) 
{

	ofVec3f dx = posIn - positions[i];

	angle1[i] = atan2(dx.y, dx.x);  
	angle2[i] = atan2(dx.z, dx.x);  
	target.x = posIn.x - cos(angle1[i]) * cos(angle2[i]) * segLength;
	target.y = posIn.y - sin(angle1[i]) * cos(angle2[i]) * segLength;
	target.z = posIn.z - sin(angle2[i]) * segLength;
}

void Chain::update()
{
	ofVec3f tar0 (cos(ofGetElapsedTimef()) + sin(ofGetElapsedTimef()*0.01), 0.5, 0.0);
	tar0 *= 600;	
	reachSegment(0, tar0);
	for(int i=1; i<positions.size(); i++) {
		reachSegment(i, target);
		}
	for(int i=positions.size()-1; i>=1; i--) {
		positionSegment(i, i-1);  
	} 
}

void Chain::draw()
{
	for (unsigned int i=0 ; i<positions.size() ; ++i) {
		ofPushMatrix();
		ofTranslate(positions[i]);
		ofRotateZ(ofRadToDeg(angle1[i]));
		ofRotateY(ofRadToDeg(angle2[i]));
		ofDrawLine(ofVec3f(0,0,0), ofVec3f(segLength,0,0));
		ofPopMatrix();
	}
}
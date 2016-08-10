#pragma once

#include "ofMain.h"
#include "Swarm.h"
#include "Chain.h"
#include "Beat.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void drawSwarmTexture();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);


		Swarm swarm;

		Chain chain = Chain(200, 10.0);


		ofEasyCam camera;

		ofTexture texture;
		ofVbo vbo;

		ofShader shader;

		Beat beat;
		
};

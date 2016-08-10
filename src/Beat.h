#pragma once

#include "ofMain.h"

#define TIME_RESET_TAP	2.0

class Beat{
	public:
		Beat()
		{
			bpm = 0.0;
			tsLastTap = 0.0;
			tapCounter = 0;
		}
		void tap()
		{

			if (ofGetElapsedTimef()-tsLastTap > TIME_RESET_TAP) {
				tapCounter = 0;
				bpm = 0.0;
			}
			tsLastTap = ofGetElapsedTimef();

			if (tapCounter) {
				bpm = 60.0 / (tsLastTap - tsFirstTap) * tapCounter;		//bpm = 60sec / time_between_beats
				tsLastBeat = ofGetElapsedTimef();
			} else {
				tsFirstTap = ofGetElapsedTimef();
			}
			tapCounter++;
		}

		double getBpm()
		{
			return bpm;
		}

		bool isBeat()
		{
			if (ofGetElapsedTimef()-tsLastBeat > 1.0/bpm*60.0) {
				tsLastBeat = ofGetElapsedTimef();
				return true;
			}
			return false;
		}


	private:
		double bpm;
		double tsLastTap;
		double tsFirstTap;
		double tsLastBeat;
		int tapCounter;


};
#pragma once

#include "ofMain.h"
#include "ofxKeyboardSettings.h"
class Greyscale { //just to show how to handle properties controled by getters/setters
public:
    Greyscale(){grey = 0;};
    void	setGrey(int grey){this->grey = grey;};
    int		getGrey(){return grey;};
    int		getGreyMin(){return 0;};
    int		getGreyMax(){return 255;};
    int		getGreyStep(){return 10;};
    
    void	setToBlack(){setGrey(getGreyMin());};
    int		setToWhite(){setGrey(getGreyMax()); return 5;};
    
private:
    int		grey;
};

class Movement { //just to show how to handle properties controled by getters/setters
public:
    Movement(){stopped = false;};
    int		getX(){return x;};
    void	update(){if(!stopped) x = sin(ofGetElapsedTimef())*100.f;};
    void	stop(bool value = true){stopped = value;};
    bool	isStopped(){return stopped;};
private:
    int		x;
    bool	stopped;
    
};
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
   
    ofxKeyboardSettings settings;
    
    float		circleRadius;
    bool		drawFill;
    Greyscale	greyscale;
    Movement	movement;
};

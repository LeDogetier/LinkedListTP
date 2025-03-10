#pragma once

#include "ofMain.h"
#include "SinglyLinkedList.h"





class ofApp : public ofBaseApp {

public:
	float positionX = 100.f;
	float positionY = 100.f;
	float amplitude = 100.f;

	int data = 0;
	int position = 0;
	SinglyLinkedList* llist;

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void augmenterAmplitude();
	void diminuerAmplitude();
	void bougerGauche();
	void bougerDroite();
	void trierCroissant();
};

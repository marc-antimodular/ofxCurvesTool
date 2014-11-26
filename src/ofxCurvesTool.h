#pragma once

#include "CurveLut.h"
#include "ofMain.h"

class ofxCurvesTool : public CurveLut {
public:
	void draw(int x = 0, int y = 0);
	void save(string filename);
	void load(string filename);
	void setCurrentHover(int i);
	int getCurrentHover();
	void clear();
	void setLabelPosition();
	void setLabelPosition(int x, int y);
	void useMouse(bool b);
	void useKey(bool b);
	
	// these are only used internally
	ofxCurvesTool();
	void mouseMoved(ofMouseEventArgs& args);
	void mousePressed(ofMouseEventArgs& args);
	void mouseDragged(ofMouseEventArgs& args);
	void mouseReleased(ofMouseEventArgs& args);
	void keyPressed(ofKeyEventArgs& args);
	void keyReleased(ofKeyEventArgs& args) {}
	void drawEvent(ofEventArgs& args);

	void nextPoint();
	void prevPoint();

	bool mouseAddsPoint;
	bool mouseMovesPoint;
	bool keepFocus;

	ofEvent<ofVec3f> curHoverChange;
	ofEvent<ofVec3f> curHoverUpdate;


protected:
	ofVec2f drawPosition;
	ofPoint labelPosition;

	void updateMouse(ofMouseEventArgs& args);
	int mouseX, mouseY;
	bool focus;
	
	static const int minDistance = 10;
	bool hoverState;
	bool dragState;
	int curHover;
	bool drawing, drawn;
	bool bMouse;
	bool bKey;

};

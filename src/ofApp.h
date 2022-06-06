/* Refer to the README.md in the example's root folder for more information on usage */

#pragma once

#ifndef CODE_ANALYSIS
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxXmlSettings.h"
#endif

#include "thumbobj.h"

extern Vector2D appsize;

struct m_col {
	float red;
	float green;
	float blue;
};

class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void loadDirectory(string directory);
	void GenerateMetadata(ofxXmlSettings* metadata, ThumbObject* img);

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
	float calculateLuminance(ofPixels* imagePixels);
	m_col calculateColor(ofPixels* imagePixels);
	double* calculateGabor(int image, double* avgArray);
	double* ofApp::calculateEdges(ofImage currentImage, double* avgArray);
	int haarFaces(ofImage currentImage, ofxCvHaarFinder* hF);
	bool ofApp::detectMatchingFeatures(int image1, int image2);
	void ofApp::match(cv::Mat& desc1, cv::Mat& desc2, vector<cv::DMatch>& matches);
	void ofApp::detectAndCompute(cv::Mat& img, vector<cv::KeyPoint>& kpts, cv::Mat& desc);
	void ofApp::vidThumb(ofVideoPlayer* vid, double* array);
	double ofApp::vidDetectCut(ofVideoPlayer* vid);
	double ofApp::detectCut(ofPixels image1Of, ofPixels image2Of);

	// we will have a dynamic number of images, based on the content of a directory:
	ofxCvHaarFinder hF;
	ofDirectory dir;
	vector<ThumbObject*> images;
	int imagecount;

	ThumbObject* selectedImage;
	ThumbObject* highlightedImage;

	// Video player
	float   vidplayer_alpha;
	ofImage vidplayer_playbutton;
	ofImage vidplayer_pausebutton;
	ofImage vidplayer_forwardbutton;
	ofImage vidplayer_backwardbutton;
	ofImage vidplayer_soundbutton;
	ofImage vidplayer_mutebutton;
};
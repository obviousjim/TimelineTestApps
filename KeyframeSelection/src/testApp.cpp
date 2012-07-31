#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	timeline.setup();
    timeline.setFrameRate(24);
	timeline.setDurationInSeconds(500);
    
    
    timeline.addBangs("Bangs 1");
    timeline.addSwitcher("switches");
    
    ofAddListener(timeline.events().bangFired, this, &testApp::bangFired);

    subline.setup();
    subline.setDurationInFrames(2000);
    subline.setFrameRate(24);
    subline.addKeyframes("subkeys");
    subline.addFlags("flags");
    
    for(int i = 0; i < 10; i++){
        ofxTimeline* t = new ofxTimeline();
		t->setup();
        t->setDurationInFrames(400);
        t->addKeyframes("Subkeys");
        sublines.push_back(t);	
//        t.setDurationInFrames(100);
//        t.addKeyframes("Subkeys");
//        sublines.push_back(t);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
	ofBackground(.15*255);
	timeline.draw(); 
    
	subline.setOffset(ofVec2f(0,timeline.getDrawRect().y+timeline.getDrawRect().height));
    subline.draw();
    sublines[0]->setOffset(ofVec2f(0, subline.getDrawRect().y+subline.getDrawRect().height));
    for(int i = 0; i < sublines.size(); i++){
        if(i != 0){
            sublines[i]->setOffset(ofVec2f(0, sublines[i-1]->getDrawRect().y+sublines[i-1]->getDrawRect().height));
        }
        sublines[i]->draw();
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 30, ofGetHeight()-50);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(timeline.isModal()){
        return;
    }
    
	if(key ==  ' '){
        timeline.togglePlay();
        
        for(int i = 0; i < sublines.size(); i++){
            sublines[i]->togglePlay();
        }
    }
    

}

//--------------------------------------------------------------
void testApp::bangFired(ofxTLBangEventArgs& bang){
	cout << "BANG!" << bang.flag << endl;    
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	timeline.setWidth(w);
    subline.setWidth(w);
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}

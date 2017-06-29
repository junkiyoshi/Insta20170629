#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofEnableDepthTest();
	//ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetWindowTitle("Insta");
		
	this->icoSphere.setRadius(300);
	this->icoSphere.setResolution(3);

	ofSetLineWidth(0.3);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	cam.begin();

	ofRotateY(ofGetFrameNum() % 360);
	
	vector<ofMeshFace> triangles = icoSphere.getMesh().getUniqueFaces();
	
	for (int i = 0; i < triangles.size(); i++) {

		ofVec3f avg = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
		float noise_value = ofNoise(avg.x * 0.0025, avg.y * 0.0025, avg.z * 0.0025, ofGetFrameNum() * 0.025);

		ofColor color;
		color.setHsb(ofMap(avg.x, -300, 300, 0, 255), 255, 255);
		ofSetColor(color);
		ofMesh mesh;

		if (noise_value > 0.55) {

			mesh.addVertex(triangles[i].getVertex(0) * ofMap(noise_value, 0.55, 1, 1, 3));
			mesh.addVertex(triangles[i].getVertex(1) * ofMap(noise_value, 0.55, 1, 1, 3));
			mesh.addVertex(triangles[i].getVertex(2) * ofMap(noise_value, 0.55, 1, 1, 3));

			mesh.addVertex(triangles[i].getVertex(0));
			mesh.addVertex(triangles[i].getVertex(1));
			mesh.addVertex(triangles[i].getVertex(2));

			mesh.addIndex(0);
			mesh.addIndex(1);
			mesh.addIndex(2);

			mesh.addIndex(3);
			mesh.addIndex(4);
			mesh.addIndex(5);

			mesh.addIndex(0);
			mesh.addIndex(3);
			mesh.addIndex(4);

			mesh.addIndex(0);
			mesh.addIndex(1);
			mesh.addIndex(4);

			mesh.addIndex(1);
			mesh.addIndex(2);
			mesh.addIndex(4);

			mesh.addIndex(2);
			mesh.addIndex(5);
			mesh.addIndex(4);

			mesh.addIndex(0);
			mesh.addIndex(2);
			mesh.addIndex(3);

			mesh.addIndex(2);
			mesh.addIndex(3);
			mesh.addIndex(5);

			mesh.drawWireframe();
		}
		else {

			mesh.addVertex(triangles[i].getVertex(0));
			mesh.addVertex(triangles[i].getVertex(1));
			mesh.addVertex(triangles[i].getVertex(2));

			mesh.addIndex(0);
			mesh.addIndex(1);
			mesh.addIndex(2);

			mesh.drawWireframe();
		}
	}

	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

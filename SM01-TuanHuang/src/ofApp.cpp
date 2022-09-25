#include "ofApp.h"

bool values[800][400];
int w = 800;
int h=400;
ofPixels ImgPix;

//--------------------------------------------------------------
void ofApp::setup(){
    
    Img.allocate(w, h, OF_IMAGE_GRAYSCALE);
    ofSetWindowShape(Img.getWidth(), Img.getHeight());
    
    ImgPix = Img.getPixels();
    
    for(int y=0; y<h;y++){
        for(int x=0; x< w; x++ ){
            
            if(ofRandomuf()<0.9){
                ImgPix.setColor(x,y,ofColor(0));
                values[x][y]=0;
                
            }else{
                ImgPix.setColor(x,y,ofColor(255));
                values[x][y]=1;
            }
        }
    }
    Img.setFromPixels(ImgPix);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofPixels newImgPix;
    newImgPix = Img.getPixels();
    
    for(int y=0; y<h; y++){
        for(int x=0; x<w;x++){
            
            
            //if cell is live
            if(values[x][y]>0){
                if(countLiveCells(x,y)<2 || countLiveCells(x,y)>3){
                    values[x][y]=0;
                    newImgPix.setColor(x,y,ofColor(0));

                }
            }else{
                if(countLiveCells(x,y) ==3){
                    values[x][y]=1;
                    newImgPix.setColor(x,y,ofColor(255));
                }
            }
        }
    
    }
    //cout << values[100][100] << endl;
    Img.setFromPixels(newImgPix);
}

//--------------------------------------------------------------
void ofApp::draw(){
    Img.draw(0,0);
    
}

int ofApp:: countLiveCells(int x,int y){
    int live=0;
    
    if(x>0 && y>0 && x<w && y< h){
        //count live neighbors
        live = values[x-1][y-1] + values[x][y-1] + values[x+1][y-1] + values[x-1][y]+values[x+1][y]+values[x-1][y+1]+values[x][y+1]+values[x+1][y+1];
    }

    //left edge
    else if(x==0 && y!= 0 && y!=h){
        live = values[w][y-1] + values[x][y-1] + values[x+1][y-1] + values[w][y-1]+values[x+1][y]+values[w][y+1]+values[x][y+1]+values[x+1][y+1];
    }
    //right edge
    else if(x==w && y!=0 && y!=h){
        live =  values[x-1][y-1] + values[x][y-1] + values[0][y-1] + values[x-1][y]+values[0][y]+values[x-1][y+1]+values[x][y+1]+values[0][y+1];
    }
    //upper edge
    else if(y==0 && x!=0 && x!=h){
        live = values[x-1][h] + values[x][h]+ values[x+1][h] + values[x-1][y]+values[x+1][y]+values[x-1][y+1]+values[x][y+1]+values[x+1][y+1];
    }
    //bottom edge
    else if(y==h && x!=0 && x!=h){
        live = values[x-1][y-1] + values[x][y-1] + values[x+1][y-1] + values[x-1][y]+values[x+1][y]+values[x-1][0]+values[x][0]+values[x+1][0];
    }
    //top left corner
    else if(x==0 && y==0){
        live = values[w-1][h-1] + values[w][h-1] + values[x+1][h-1] + values[w-1][h-1]+values[x+1][y]+values[w-1][y+1]+values[x][y+1]+values[x+1][y+1];
    }
    //bottom left corner
    else if(x==0 && y==h){
        live = values[w-1][y-1]+ values[x][y-1] + values[x+1][y-1] + values[w-1][y]+values[x+1][y]+values[w-1][1]+values[x][1]+values[x+1][1];
    }
    //top right corner
    else if(x==w && y==0){
        live = values[x-1][h-1] + values[x][h-1] + values[1][h-1] + values[x-1][y]+values[1][y]+values[x-1][y+1]+values[x][y+1]+values[1][y+1];
    }
    //bottom right corner
    else if(x==w && y==h){
        live = values[x-1][y-1] + values[x][y-1] + values[1][y-1] + values[x-1][y]+values[1][0]+values[w-1][1]+values[0][1]+values[1][1];
    }
    //cout << live <<endl;
    return live;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key=='r'){
        ofPixels resetPix;
    resetPix = Img.getPixels();
    
    for(int y=0; y<h;y++){
        for(int x=0; x< w; x++ ){
            
            if(ofRandomuf()<0.9){
                resetPix.setColor(x,y,ofColor(0));
                values[x][y]=0;
                
            }else{
                resetPix.setColor(x,y,ofColor(255));
                values[x][y]=1;
            }
        }
    }
    Img.setFromPixels(resetPix);
    }
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


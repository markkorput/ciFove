// cinder
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Log.h"
// #include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MainApp : public App {
public:
  // MainApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(KeyEvent event) override;
};

void MainApp::setup(){
  setWindowSize( 1000, 500 );
}

void MainApp::update(){

}

void MainApp::draw(){
  gl::clear(Color(0,0,0));
}

void MainApp::keyDown(KeyEvent event){
  // switch(event.getChar()){
  //   case 'l': {
  //     size = vec2(size.x*1.1f, size.y*1.1f);
  //     step = vec2(size.x, size.x*0.5f);
  //     return;
  //   }
  //   case 's': {
  //     size = vec2(size.x*0.9f, size.y*0.9f);
  //     step = vec2(size.x, size.x*0.5f);
  //     return;
  //   }
  // }
}

CINDER_APP( MainApp, RendererGl )

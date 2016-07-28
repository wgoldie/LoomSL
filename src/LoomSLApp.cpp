#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LoomSLApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void LoomSLApp::setup()
{
}

void LoomSLApp::mouseDown( MouseEvent event )
{
}

void LoomSLApp::update()
{
}

void LoomSLApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( LoomSLApp, RendererGl )

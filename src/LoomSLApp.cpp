#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "Loom.h"
#include "cinder/ip/Fill.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class LoomSLApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
private:
	Surface cloth;
	TextureRef clothT;
};

static bool simpleWeavePP(ivec2 p) {
	return (p.x + p.y) % 8 == 0;
}


void LoomSLApp::setup()
{
	Surface warp(500, 1, false);
	ip::fill(&warp, Color8u(255, 255, 255));
	Surface weft(1, 500, false);
	ip::fill(&weft, Color8u(255, 0, 0));
	Loom loom(warp, *simpleWeavePP);
	this->cloth = loom.Weave(weft);
	this->clothT = Texture::create(cloth);
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
	gl::draw(clothT);
}

CINDER_APP( LoomSLApp, RendererGl )

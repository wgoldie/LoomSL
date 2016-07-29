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
	return (p.x + p.y) % 2 == 0;
}

void LoomSLApp::setup()
{
	int warpWidth = 20;
	int weftWidth = 30;
	int warpThreads = 50;
	int weftThreads = 50;

	Surface warp(warpThreads * warpWidth, weftWidth, false);
	ip::fill(&warp, Color8u(255, 255, 255));
	Surface weft(warpWidth, weftThreads * weftWidth, false);
	ip::fill(&weft, Color8u(255, 0, 0));
	Loom loom(warp, warpWidth, *simpleWeavePP);

	this->cloth = loom.Weave(weft, weftWidth);
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

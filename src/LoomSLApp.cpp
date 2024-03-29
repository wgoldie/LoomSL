#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "TreadleLoom.h"
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
	int warpWidth = 30;
	int weftWidth = 30;
	int warpThreads = 5;
	int weftThreads = 30;

	vector<vector<int>> treadles = {
		{ 2 },
		{ 1, 3 },
		{ 0, 4 },
	};

	vector<vector<int>> treadleSequence = {
		{ 0 },
		{ 0, 1 },
		{ 0, 1, 2 },
		{ 0, 1 },
	};

	vector<vector<bool>> cards = {
		{ 0, 0, 1, 0, 0 },
		{ 0, 1, 1, 1, 0 },
		{ 1, 1, 1, 1, 1 },
		{ 0, 1, 1, 1, 0 },
	};


	Surface warp(warpThreads * warpWidth, weftWidth, false);
	ip::fill(&warp, Color8u(255, 255, 255));
	Surface weft(warpWidth, weftThreads * weftWidth, false);
	ip::fill(&weft, Color8u(255, 0, 0));

	TreadleLoom loom(warp, warpWidth, treadles);

	// Loom loom(warp, warpWidth, *simpleWeavePP);

	this->cloth = loom.Weave(weft, weftWidth, treadleSequence);
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

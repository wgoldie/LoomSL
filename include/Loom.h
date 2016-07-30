#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

using namespace std;
using namespace ci;
using namespace ci::gl;

class Loom {
public:
	Loom(Surface _warp, int _warpWidth, std::function<bool(ivec2)> _pushPick);
	Surface Weave(Surface weft, int weftWidth);
private:
	std::function<bool(ivec2)> pushPick;
	Surface warp;
	int warpWidth;
};
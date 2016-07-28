#pragma once

#include "cinder/app/App.h"
#include "cinder/gl/gl.h"

using namespace std;
using namespace ci;
using namespace ci::gl;

class Loom {
public:
	Loom(Surface warp, bool(*_pushPick)(ivec2));
	Surface Weave(Surface weft);
private:
	bool(*pushPick)(ivec2);
	Surface warp;
};
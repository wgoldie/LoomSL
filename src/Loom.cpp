#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "Loom.h"

using namespace std;
using namespace ci;
using namespace ci::gl;

Loom::Loom(Surface _warp, bool(*_pushPick)(ivec2))
{
	this->warp = _warp;
	this->pushPick = _pushPick;
}

Surface Loom::Weave(Surface weft)	
{
	Surface r(this->warp.getWidth(), weft.getHeight(), false);
	Surface::Iter iter = r.getIter();
	while (iter.line()) {
		while (iter.pixel()) {
			vec2 p = iter.getPos();
			auto pick = this->pushPick(p) ? this->warp.getPixel(vec2(p.x, 0)) : weft.getPixel(vec2(0, p.y));
			iter.r() = pick.r;
			iter.g() = pick.g;
			iter.b() = pick.b;
		}
	}

	return r;
}
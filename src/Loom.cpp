#include "cinder/app/App.h"
#include "cinder/gl/gl.h"
#include "Loom.h"

using namespace std;
using namespace ci;
using namespace ci::gl;

Loom::Loom(Surface _warp, int _warpWidth, std::function<bool(ivec2)> _pushPick)
{
	warp = _warp;
	pushPick = _pushPick;
	warpWidth = _warpWidth;
}

Surface Loom::Weave(Surface weft, int weftWidth)
{
	Surface r(warp.getWidth(), weft.getHeight(), false);
	int warpThreads = warp.getWidth() / warpWidth;
	int weftThreads = weft.getHeight() / weftWidth;

	for (int y = 0; y < weftThreads; y++) {
		for (int x = 0; x < warpThreads; x++) {
			vec2 p(x * warpWidth, y * weftWidth);

			if (pushPick(vec2(x, y))) {
				r.copyFrom(warp, Area(p.x, 0, p.x + warpWidth, weftWidth), vec2(0, p.y));
			}
			else {
				r.copyFrom(weft, Area(0, p.y, warpWidth, p.y + weftWidth), vec2(p.x, 0));
			}
		}
	}

	return r;
}
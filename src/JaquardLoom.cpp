#include "JaquardLoom.h"

bool JaquardLoom::pushPick(const ivec2 pos)
{
	int d = dobbies.size();
	int y = pos.y % d;

	return dobbies[y][pos.x];
}

JaquardLoom::JaquardLoom(Surface _warp, int _warpWidth, vector<vector<bool>> _dobbies)
{
	int warpThreads = _warp.getWidth() / _warpWidth;
	for (auto d : _dobbies) {
		int w = d.size();
		for (int i = 0; i < warpThreads - w; i++) {
			d.push_back(false);
		}
	}

	warp = _warp;
	warpWidth = _warpWidth;
	dobbies = _dobbies;
}

Surface JaquardLoom::Weave(Surface weft, int weftWidth)
{
	int l = dobbies.size();

	Loom mLoom = Loom(warp, warpWidth, std::bind(&JaquardLoom::pushPick, this, std::placeholders::_1));
	return mLoom.Weave(weft, weftWidth);
}
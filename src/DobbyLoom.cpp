#include "DobbyLoom.h"

bool DobbyLoom::pushPick(vector<int> dobbySequence, const ivec2 pos)
{
	int d = dobbySequence.size();
	int y = pos.y % d;

	return dobbies[dobbySequence[y]][pos.x];
}

DobbyLoom::DobbyLoom(Surface _warp, int _warpWidth, vector<vector<bool>> _dobbies)
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

Surface DobbyLoom::Weave(Surface weft, int weftWidth, vector<int> dobbySequence)
{
	int l = dobbies.size();
	for (auto d : dobbySequence) {
		if (d >= l) {
			d = l - 1;
		}
	}

	Loom mLoom = Loom(warp, warpWidth, std::bind(&DobbyLoom::pushPick, this, dobbySequence, std::placeholders::_1));
	return mLoom.Weave(weft, weftWidth);
}
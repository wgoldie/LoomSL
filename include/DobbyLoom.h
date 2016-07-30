#pragma once

#include "Loom.h"
class DobbyLoom {
public:
	DobbyLoom(Surface warp, int warpWidth, vector<vector<bool>> dobbies);
	Surface Weave(Surface weft, int weftWidth, vector<int> dobbySequence);
private:
	vector<vector<bool>> dobbies;
	bool pushPick(vector<int> dobbySequence, const ivec2 pos);
	Surface warp;
	int warpWidth;
};
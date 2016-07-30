#pragma once

#include "Loom.h"
class JaquardLoom {
public:
	JaquardLoom(Surface warp, int warpWidth, vector<vector<bool>> cards);
	Surface Weave(Surface weft, int weftWidth);
private:
	vector<vector<bool>> dobbies;
	bool pushPick(const ivec2 pos);
	Surface warp;
	int warpWidth;
};
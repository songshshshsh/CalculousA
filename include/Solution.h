#ifndef SOLUTION_H
#define SOLUTION_H

#include "Board.h"
#include "Tree.h"
#include "global.h"

class Solution
{
private:
public:
	const Board *board;
	Vector<Tree*> solution;
	Matrix<int> map;
	
};

#endif
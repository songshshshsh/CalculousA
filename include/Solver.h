#ifndef SOLVER_H
#define SOLVER_H

#include "global.h"

class Solver
{
public:
	Solver(Board board_)
	{
		this->board = board_;
	}
private:
	const Board *board;
	SolveStrategy *strategy;
};

#endif
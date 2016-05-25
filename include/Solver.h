#ifndef SOLVER_H
#define SOLVER_H

#include "global.h"

class Solver
{
private:
	const Board *board;
	SolveStrategy *strategy;
};

#endif
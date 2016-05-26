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
	void run()
	{
		assert(solve);
		assert(check);
		assert(optimize);
	}
	void setSolveStrategy(SolveStrategy *solve_)
	{
		if(solve)
			delete solve;
		solve = solve_;
	}
	void setCheckStrategy(CheckStrategy *check_)
	{
		if(check)
			delete check;
		check = check_;
	}
	void setOptimizeStrategy(OptimizeStrategy *optimize_)
	{
		if(optimize)
			delete optimize;
		optimize = optimize_;
	}
private:
	const Board *board;
	SolveStrategy *solve;
	CheckStrategy *check;
	OptimizeStrategy *optimize;
};

#endif
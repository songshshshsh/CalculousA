#ifndef SOLVER_H
#define SOLVER_H

#include "global.h"
#include "Solution.h"
#include "SolveStrategy.h"
#include "Board.h"

class Solver
{
public:
	const Board *board;
	Solver(const Board *board_)
	{
		board = board_;
		solve = NULL;
		check = NULL;
		optimize = NULL;
	}
	~Solver()
	{
		delete solve;
		delete check;
		delete optimize;
	}
	Solution run();
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
	SolveStrategy *solve;
	CheckStrategy *check;
	OptimizeStrategy *optimize;
};

#endif
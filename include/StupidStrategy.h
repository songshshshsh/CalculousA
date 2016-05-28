#ifndef STUPIDSTRATEGY_H
#define STUPIDSTRATEGY_H

#include "SolveStrategy.h"

class StupidSolve: public SolveStrategy
{
public:
	StupidSolve(Solver *solver_): SolveStrategy(solver_){}
	virtual ~StupidSolve(){}
	virtual Solution solve() const;
};

class StupidCheck: public CheckStrategy
{
public:
	StupidCheck(Solver *solver_): CheckStrategy(solver_){}
	virtual ~StupidCheck(){}
	virtual bool check(const Solution &solution) const
	{
		NOT_USED(solution);
		return true;
	}
};

class StupidOptimize: public OptimizeStrategy
{
public:
	StupidOptimize(Solver *solver_): OptimizeStrategy(solver_){}
	virtual ~StupidOptimize(){}
	virtual Solution optimize(const Solution &solution) const
	{
		return solution;
	}
};

#endif // STUPIDSTRATEGY_H

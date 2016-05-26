#ifndef SOLVESTRATEGY_H
#define SOLVESTRATEGY_H

#include "global.h"
#include "Solution.h"

class SolveStrategy
{
protected:
	Solver *solver;
public:
	SolveStrategy(Solver *solver_)
	{
		solver = solver_;
	}
	virtual ~SolveStrategy(){}
	virtual Solution solve() const = 0;
};

class CheckStrategy
{
protected:
	Solver *solver;
public:
	CheckStrategy(Solver *solver_)
	{
		solver = solver_;
	}
	virtual ~CheckStrategy(){}
	virtual bool check(const Solution &solution) const = 0;
};

class OptimizeStrategy
{
protected:
	Solver *solver;
public:
	OptimizeStrategy(Solver *solver_)
	{
		solver = solver_;
	}
	virtual ~OptimizeStrategy(){}
	virtual Solution optimize(const Solution &solution) const = 0;
};

#endif
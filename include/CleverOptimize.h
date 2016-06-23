#ifndef CLEVEROPTIMIZE_H
#define CLEVEROPTIMIZE_H

#include "SolveStrategy.h"

class CleverOptimize : public OptimizeStrategy
{
private:
	void bfs(const Point& start,BitMatrix& _map) const; 
	void backtrace(const Point& start,BitMatrix& map,Matrix<int>& visited,const Point& end,int step) const;
	int getLastDirection(const int k) const;
public:
	Solution optimize(const Solution &solution) const;
	CleverOptimize(Solver *solver_): OptimizeStrategy(solver_){}
};

#endif
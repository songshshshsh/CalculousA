#ifndef COLUMNGENSOLVE_H
#define COLUMNGENSOLVE_H

#include "SolveStrategy.h"

class ColumnGenSolve: public SolveStrategy
{
public:
	ColumnGenSolve(Solver *solver_): SolveStrategy(solver_){}
	virtual ~ColumnGenSolve(){}
	virtual Solution solve() const;
};

#endif // COLUMNGENSOLVE_H

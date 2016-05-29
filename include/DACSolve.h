#ifndef DACSOLVE_H
#define DACSOLVE_H

#include "SolveStrategy.h"

class DACSolve: public SolveStrategy
{
protected:
	SolveStrategy *subSolve;
public:
	DACSolve(Solver *solver_, SolveStrategy *subsolve_)
		: SolveStrategy(solver_), subsolve(subsolve_){}
	virtual ~SolveStrategy()
	{
		delete subSolve;
	}
	virtual Solution solve() const;
};

#endif // DACSOLVE_H

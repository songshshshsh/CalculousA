#ifndef SOLVESTRATEGY_H
#define SOLVESTRATEGY_H

#include "global.h"
#include "Solution.h"

class SolveStrategy
{
private:
	bool check(Solution&);
	void optimize(Solution&);
	void solve();
};

#endif
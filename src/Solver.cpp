#include "../include/Solver.h"

Solution Solver::run(){
	assert(solve != NULL);
	assert(check != NULL);
	assert(optimize != NULL);
	Solution solution = solve->solve();
	assert(check->check(solution));
	/*if(board->width * board->height >= 500)
	{
		board->output();
		cout << solution;
		cout.flush();
	}*/
	return optimize->optimize(solution);
}

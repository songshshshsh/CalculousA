#include "../include/DACSolve.h"

Solution DACSolve::solve() const
{
	subSolve->solver = solver;
	const Board *board = solver->board;
	int n = board->height, m = board->width;
	// cout << "solve " << n << " " << m << endl;
	if(n < 10 || m < 10)
		return subSolve->solve();
	// int n1 = n / 2, n2 = n - n1, m1 = m / 2, m2 = m - m1;
	Matrix<int> newMap = board->map;
	divide(newMap, 0, n / 2, 0, m / 2);
	divide(newMap, 0, n / 2, m / 2, m);
	divide(newMap, n / 2, n, 0, m / 2);
	divide(newMap, n / 2, n, m / 2, m);
	StringStream sstr;
	sstr << n << ' ' << m << ' ';
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			sstr << newMap[i][j] << ' ';
	Board newBoard;
	newBoard.input(0, sstr);
	Solver *newSolver = solver->clone();
	newSolver->board = &newBoard;
	newSolver->setSolveStrategy(subSolve->clone());
	Solution solution = newSolver->run();
	solution.board = board;
	delete newSolver;
	return solution;
}

// [x1, x2) * [y1, y2)
void DACSolve::divide(Matrix<int> &map, int x1, int x2, int y1, int y2) const
{
	// cout << "divide " << x1 << ' ' << x2 << ' ' << y1 << ' ' << y2 << ' ' << endl;
	StringStream sstr;
	sstr << x2 - x1 << ' ' << y2 - y1 << ' ';
	for(int i = x1; i < x2; i++)
		for(int j = y1; j < y2; j++)
			sstr << map[i][j] << ' ';
	Board board;
	board.input(0, sstr);
	Solver *newSolver = solver->clone();
	// board.output();
	newSolver->board = &board;
	Solution solution = newSolver->run();
	for(int i = x1; i < x2; i++)
		for(int j = y1; j < y2; j++)
			if(map[i][j] == 0)
				map[i][j] = solution.map[i - x1][j - y1];
	delete newSolver;
}

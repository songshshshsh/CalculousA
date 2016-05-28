#ifndef COLUMNGENSOLVE_H
#define COLUMNGENSOLVE_H

#include "SolveStrategy.h"
#include "Tree.h"
#include "gurobi_c++.h"

class ColumnGenSolve: public SolveStrategy
{
public:
	static const double M;
	ColumnGenSolve(Solver *solver_): SolveStrategy(solver_){}
	virtual ~ColumnGenSolve(){}
	virtual Solution solve() const;
protected:
	struct expandFinished{};
	
	Vector<Tree *> ColumnGenSolve::route(int tim) const;
	
	double ColumnGenSolve::solveLP(
		Vector<Vector<Pair<Tree, GRBVar>>> &treesets,
		int mode, Matrix<double> *mapPi = NULL,
		Vector<double> *vecLambda = NULL, int ignoreIdx = -1
	) const;
	
	void ColumnGenSolve::expand(
		const Matrix<double> &mapPi, double lambda,
		Vector<Pair<Tree, GRBVar>> &treeset, int n, int m, int idx, int &r
	) const;
	
	void ColumnGenSolve::expand(
		const Matrix<double> &mapPi, double lambda,
		Vector<Pair<Tree, GRBVar>> &treeset, const Tree &tree,
		int n, int m, int idx, int &r
	) const;
	
	void ColumnGenSolve::expand(
		const Matrix<double> &mapPi, double lambda,
		Vector<Pair<Tree, GRBVar>> &treeset, const BitMatrix &base,
		int n, int m, int idx, int &r
	) const;
	
	Matrix<Pair<double, BitMatrix>> dijkstra(
		const BitMatrix &base, const Matrix<double> &mapW, int n, int m
	) const;

	bool suggestTree(
		const Vector<TerminalSet *> &termsets,
		Vector<Vector<Pair<Tree, GRBVar>>> &treesets,
		const Matrix<double> &mapW, int n, int m, int idx
	) const;

	Tree suggestTree(
		const TerminalSet *terminalSet, const Matrix<double> &mapW, int n, int m
	) const;

	void removeNonCuts(
	const Matrix<int> &map, int idx, BitMatrix &tree,
		int n, int m, int exx = -1, int exy = -1
	) const;

	double removeNonCuts(
		Matrix<bool> &visited, const Matrix<int> &map, int idx,
		const Matrix<double> &mapW, BitMatrix &tree, int n, int m
	) const;

	bool pushTreeSet(
		Vector<Pair<Tree, GRBVar>> &treeset, Tree &tree
	) const;
	
	int treeBranches(BitMatrix tree, int n, int m) const;
	void treeDFSBranches(BitMatrix &tree, int i, int j, int n, int m) const;
	Vector<BitMatrix> treeGetBranches(BitMatrix tree, int n, int m) const;
	void treeDFSGetBranches(
		BitMatrix &tree, BitMatrix &res, int i, int j, int n, int m
	) const;
	bool treeIsCut(BitMatrix tree, int i, int j, int n, int m) const;
};

#endif // COLUMNGENSOLVE_H

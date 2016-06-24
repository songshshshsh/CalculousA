#include "../include/ColumnGenSolve.h"
#include "../include/GRBFactory.h"

const double ColumnGenSolve::M = 100000;

double ColumnGenSolve::solveLP(
	Vector<Vector<Pair<Tree, GRBVar>>> &treesets,
	int mode, Matrix<double> *mapPi, Vector<double> *vecLambda, int ignoreIdx
) const
{
	int t = (int) treesets.size();
	const Board *board = solver->board;
	int n = board->height;
	int m = board->width;
	GRBModel &model = GRBFactory::createModel();
	
	// Create variables for trees
	for(int i = 0; i < t; i++)
		if(i != ignoreIdx - 1)
			for(auto &treeVar: treesets[i])
				treeVar.second = model.addVar(
					0, 1, 0, mode ? GRB_BINARY : GRB_CONTINUOUS
				);
	
	// Create variables for sets
	Vector<GRBVar> varCanRoute;
	for(int i = 0; i < t; i++)
		varCanRoute.push_back(model.addVar(
			0, 1, 0, mode ? GRB_BINARY : GRB_CONTINUOUS
		));
	model.update();
	
	// Create target
	GRBLinExpr target;
	for(int i = 0; i < t; i++)
	{
		target += M * varCanRoute[i];
		if(i != ignoreIdx - 1)
			for(const auto &treeVar: treesets[i])
				target += treeVar.first.length * treeVar.second;
	}
	model.setObjective(target, GRB_MINIMIZE);
	
	// Create constraints for sets
	Vector<GRBConstr> constrCanRoute;
	for(int i = 0; i < t; i++)
	{
		GRBLinExpr consLeft;
		consLeft += varCanRoute[i];
		if(i != ignoreIdx - 1)
			for(const auto &treeVar: treesets[i])
				consLeft += treeVar.second;
		constrCanRoute.push_back(model.addConstr(consLeft == 1));
	}
	
	// Create constraints for grids
	Matrix<GRBConstr> constrNode;
	constrNode.resize(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			GRBLinExpr consLeft;
			for(int idx = 0; idx < t; idx++)
				if(idx != ignoreIdx - 1)
					for(const auto &treeVar: treesets[idx])
						if(treeVar.first.map.get(i, j))
							consLeft += treeVar.second;
			if(board->map[i][j] == -1)
				constrNode[i][j] = model.addConstr(consLeft == 0);
			else
				constrNode[i][j] = model.addConstr(consLeft <= 1);
		}
	
	// Optimize!
	model.optimize();
	
	double ans = model.get(GRB_DoubleAttr_ObjVal);
	
	// If mode is binary, dual values are not calculated,
	// we only return the answer.
	// if(mode)
		// return ans;
	
	// Get dual values of each grid
	if(mapPi != NULL)
	{
		mapPi->resize(n, m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				(*mapPi)[i][j] = constrNode[i][j].get(GRB_DoubleAttr_Pi);
	}
	
	// Get dual values of each set
	if(vecLambda != NULL)
	{
		vecLambda->clear();
		for(const auto &cons: constrCanRoute)
			vecLambda->push_back(cons.get(GRB_DoubleAttr_Pi));
	}
	
	return ans;
}

Vector<Tree *> ColumnGenSolve::route(int tim) const
{
	// Open a console for output
	OFStream con("con");
	auto clkStart = clock();
	
	// Constant definition
	const Board *board = solver->board;
	const Vector<TerminalSet *> &termsets = board->terminalSets;
	const Matrix<int> &map = board->map;
	const int t = termsets.size() - 1;
	const int n = board->height;
	const int m = board->width;
	
	// Two useful Vectors
	/*
	Vector<Point> allPoints;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			allPoints.push_back(Point(i, j));
	*/
	
	Matrix<double> all1;
	all1.resize(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			all1[i][j] = 1;
	
	// The tree set, initially empty
	Vector<Vector<Pair<Tree, GRBVar>>> treesets;
	
	for(int idx = 1; idx <= t; idx++)
	{
		// Current tree set
		Vector<Pair<Tree, GRBVar>> vec;
		/*
		// If "Precise", all points can be joint
		if(this->m_mode == "Precise")
			for(auto joint: allPoints){
				// Call Dijkstra
				Matrix<bool> base;
				base.resize(n, m);
				base[joint.first][joint.second] = 1;
				Matrix<Pair<double, Matrix<bool>>> dijRes
					= this->dijkstra(base, all1, n, m);
				// Generate a tree with Dijkstra
				// result
				Tree tree(this->m_board, idx);
				tree.m_tree[joint.first][joint.second] = 1;
				for(auto term: termsets[idx])
				{
					tree.m_tree[term.first][term.second] = 1;
					for(int i = 0; i < n; i++)
						for(int j = 0; j < m; j++)
							if(dijRes[term].second[i][j])
								tree.m_tree[i][j] = 1;
				}
				this->removeNonCuts(
					map, idx, tree.m_tree, n, m, joint.first, joint.second
				);
				// Add the tree to the set
				vec.push_back(tree);
			}
		*/
		// Add the set to the set list
		treesets.push_back(vec);
	}
	
	// Answer history
	Vector<double> tarAns;
	for(int T = 0;; T++){
		cout << "LP " << T << endl;
		// Solve the integer (binary) programming problem
		double curAns = solveLP(treesets, 1);
		cout << "curAns " << curAns << endl;
		con << "curAns " << curAns << endl;
		tarAns.push_back(curAns);
		
		// Construct current best answer
		Vector<Tree *> ans;
		for(const auto &treeset: treesets)
		{
			for(const auto &treeVar: treeset)
				if(treeVar.second.get(GRB_DoubleAttr_X) > 0.5)
				{
					ans.push_back(new Tree(treeVar.first));
					goto found;
				}
			ans.push_back(NULL);
			found:;
		}
		
		// if(T >= 3)
			// return ans;
		// output(ans, con);
		// output(ans, cout);
		
		bool updated = false;
		// Build weight map for unrouted set
		Matrix<double> mapObs;
		mapObs.resize(n, m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if(map[i][j] == -1)
					mapObs[i][j] = M;
				else
					mapObs[i][j] = 1;
		
		for(int idx = 1; idx <= t; idx++)
			if(ans[idx - 1])
				for(int i = 0; i < n; i++)
					for(int j = 0; j < m; j++)
						if(ans[idx - 1]->map.get(i, j))
							mapObs[i][j] = M;
		// Try to generate from each set
		for(int idx = 1; idx <= t; idx++)
		{
			if(termsets[idx]->points.empty())
				continue;
			if(!ans[idx - 1]){
				// If unrouted, try to generate from the map above
				if(suggestTree(termsets, treesets, mapObs, n, m, idx))
					updated = true;
			}else{
				// If routed
				{
					// Try to reroute current set
					Matrix<double> mapObs2 = mapObs;
					for(int i = 0; i < n; i++)
						for(int j = 0; j < m; j++)
							if(
								mapObs2[i][j] >= M / 2
								&& ans[idx - 1]->map.get(i, j)
							)
								mapObs2[i][j] = 1;
					if(suggestTree(termsets, treesets, mapObs2, n, m, idx))
						updated = true;
				}
				{
					/*
						Try to reroute current set and try to route another tree
						rather than current tree
					*/
					Matrix<double> mapObs2 = mapObs;
					for(int i = 0; i < n; i++)
						for(int j = 0; j < m; j++)
							if(
								mapObs2[i][j] >= M / 2 &&
								!ans[idx - 1]->map.get(i, j)
							) mapObs2[i][j] = M * M;
					if(suggestTree(termsets, treesets, mapObs2, n, m, idx))
						updated = true;
				}
				{
					/*
						Try to solve integer programming without current set and
						try to avoid overlap between current tree and the
						solution above
					*/
					solveLP(treesets, 1, NULL, NULL, idx);
					
					Vector<Tree *> tmpAns;
					
					for(int i = 0; i < t; i++)
						if(i != idx - 1)
						{
							for(const auto &treeVar: treesets[i])
								if(treeVar.second.get(GRB_DoubleAttr_X) > 0.5)
								{
									tmpAns.push_back(new Tree(treeVar.first));
									goto found2;
								}
							tmpAns.push_back(NULL);
							found2:;
						}
						else
							tmpAns.push_back(NULL);
					
					// OK, let's construct weight map
					Matrix<double> mapObs2;
					mapObs2.resize(n, m);
					for(int i = 0; i < n; i++)
						for(int j = 0; j < m; j++)
							if(map[i][j] == -1)
								mapObs2[i][j] = M * M;
							else
								mapObs2[i][j] = 1;
					
					for(int nidx = 1; nidx <= t; nidx++)
						if(tmpAns[nidx - 1])
							for(int i = 0; i < n; i++)
								for(int j = 0; j < m; j++)
									if(tmpAns[nidx - 1]->map.get(i, j))
										mapObs2[i][j] = M;
					
					if(suggestTree(termsets, treesets, mapObs2, n, m, idx))
						updated = true;
					
					// clean up
					for(auto tree: tmpAns)
						delete tree;
				}
			}
		}
		
		auto clkNow = clock();
		if((int) ((clkNow - clkStart) / CLOCKS_PER_SEC) > tim)
		{
			con << "time up, aborting\n";
			con << (int) ((clkNow - clkStart) / CLOCKS_PER_SEC)
				<< " seconds passed\n";
			return ans;
		}
		
		// If solution didn't improve recently,
		// cut!
		if(T >= 1 && fabs(tarAns[T - 1] - tarAns[T]) < 0.5)
			return ans;
		
		// Output current colution info
		cout << "iteration " << T << "\n";
		con << "current time: "
			<< (int) ((clkNow - clkStart) / CLOCKS_PER_SEC) << " seconds\n";
		con << "iteration " << T << "\ncolumn sizes: ";
		for(const auto &treeset: treesets)
		{
			cout << "size " << treeset.size() << "\n";
			con << treeset.size() << " ";
		}
		con << "\n";
		con.flush();
		fflush(stdout);
		/*
		// Solve LP
		Matrix<double> mapPi;
		Vector<double> vecLambda;
		
		tarAns.push_back(solveLP(treesets, 0, &mapPi, &vecLambda));
		
		// Only try to expand when Dijkstra cannot find any solution
		if(!updated)
			for(int i = 0; i < t; i++){
				if(termsets[i + 1]->points.empty())
					continue;
				int oldSize = treesets[i].size();
				sort(
					treesets[i].begin(), treesets[i].end(),
					[](const Pair<Tree, GRBVar> &l, const Pair<Tree, GRBVar> &r)
					{
						return l.second.get(GRB_DoubleAttr_X)
							> r.second.get(GRB_DoubleAttr_X);
					}
				);
				try
				{
					// int r = 10;
					// expand(mapPi, vecLambda[i], treesets[i], n, m, i + 1, r);
				}
				catch(expandFinished){}
				if((int) treesets[i].size() != oldSize)
					updated = true;
			}
			
		*/
		
		// Still cannot generate, cut
		if(!updated)
			return ans;
		
		// Clean up
		for(auto tree: ans)
			delete tree;
	}
}
/*
void ColumnGenSolve::expand(
	const Matrix<double> &mapPi, double lambda,
	Vector<Pair<Tree, GRBVar>> &treeset, int n, int m, int idx, int &r
) const
{
	for(int i = 0; i < (int) treeset.size(); i++)
		expand(mapPi, lambda, treeset, treeset[i].first, n, m, idx, r);
}

void ColumnGenSolve::expand(
	const Matrix<double> &mapPi, double lambda,
	Vector<Pair<Tree, GRBVar>> &treeset, const Tree &tree,
	int n, int m, int idx, int &r
) const
{
	const Matrix<int> &map = solver->board->map;
	
	Matrix<bool> visited, fakeVisited;
	visited.resize(n, m);
	fakeVisited.resize(n, m);
	Matrix<double> mapW;
	mapW.resize(n, m);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			mapW[i][j] = 1 - mapPi[i][j];
	
	// base with weight
	Vector<Pair<double, BitMatrix>> wbases;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tree.map.get(i, j) && !visited[i][j])
			{
				visited[i][j] = 1;
				int pos = map[i][j];
				// can't remove a terminal
				if(pos == idx)
					continue;
				// calculate current degree
				int deg = 0;
				if(i > 0 && tree.map.get(i - 1, j))
					++deg;
				if(i + 1 < n && tree.map.get(i + 1, j))
					++deg;
				if(j > 0 && tree.map.get(i, j - 1))
					++deg;
				if(j + 1 < m && tree.map.get(i, j + 1))
					++deg;
				// remove current grid
				BitMatrix newTree = tree.map;
				newTree.reset(i, j);
				double cw = mapW[i][j];
				// remove non-cut grids
				if(deg == 2)
					cw += removeNonCuts(visited, map, idx, mapW, newTree, n, m);
				else
					cw += removeNonCuts(
						fakeVisited, map, idx, mapW, newTree, n, m
					);
				wbases.push_back(Pair<double, BitMatrix>(cw, newTree));
			}
	
	sort(
		wbases.begin(), wbases.end(),
		[](const Pair<double, BitMatrix> &l, const Pair<double, BitMatrix> &r)
		{
			return l.first > r.first;
		}
	);
	// reverse(wbases.begin(), wbases.end());
	
	// for each remove solution, try it
	for(const auto &wbase: wbases)
		expand(mapW, lambda, treeset, wbase.second, n, m, idx, r);
}

void ColumnGenSolve::expand(
	const Matrix<double> &mapW, double lambda,
	Vector<Pair<Tree, GRBVar>> &treeset, const BitMatrix &base,
	int n, int m, int idx, int &r
) const
{
	// split the branch
	Vector<BitMatrix> branches = treeGetBranches(base, n, m);
	// Dijkstra from each branch
	Vector<Matrix<Pair<double, BitMatrix>>> dijMatrices;
	for(const auto &branch: branches)
		dijMatrices.push_back(dijkstra(branch, mapW, n, m));
	
	double bestw = 1e40;
	TerminalSet *termset = solver->board->terminalSets[idx];
	Tree btree(termset);
	// enumerate the joint
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			double cw = 0;
			// construct the tree
			Tree tree(termset);
			tree.map = base;
			for(const auto &dijMatrix: dijMatrices)
			{
				if(dijMatrix[i][j].first >= 1e20)
					goto fail;
				tree.map |= dijMatrix[i][j].second;
			}
			tree.map.set(i, j);
			removeNonCuts(solver->board->map, idx, tree.map, n, m);
			for(int i1 = 0; i1 < n; i1++)
				for(int j1 = 0; j1 < m; j1++)
					if(tree.map.get(i1, j1))
						cw += mapW[i1][j1];
			if(cw < bestw)
			{
				bestw = cw; btree = tree;
			}
			fail:;
		}
	// if the tree is sufficiently good, add it!
	if(bestw < lambda && pushTreeSet(treeset, btree) && (--r) <= 0)
		throw expandFinished();
}
*/
Matrix<Pair<double, Point>> ColumnGenSolve::dijkstra(
	const BitMatrix &base, const Matrix<double> &mapW, int n, int m
) const
{
	// simple Dijkstra algorithm
	Matrix<Pair<double, Point>> dist;
	dist.resize(n, m);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(base.get(i, j))
				dist[i][j].second = Point(-1, -1);
			else
				dist[i][j].first = 1e30;
	// Matrix<bool> visited;
	// visited.resize(n, m);
	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};
	int EX = 1;
	while(n * m > EX)
		EX <<= 1;
	vector<double> sgt;
	sgt.resize(EX << 1, 1e30);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(base.get(i, j))
				sgt[EX + i * m + j] = 0;
	for(int i = EX - 1; i >= 1; i--)
		sgt[i] = min(sgt[i << 1], sgt[i << 1 | 1]);
	// cout << "core dij begin\n";
	for(;;)
	{
		// cout << "cur " << sgt[1] << endl;
		if(sgt[1] >= 1e25) break;
		int sgtIdx = 1;
		while(sgtIdx < EX)
			if(sgt[sgtIdx] == sgt[sgtIdx << 1])
				sgtIdx <<= 1;
			else
				sgtIdx = (sgtIdx << 1 | 1);
		sgtIdx -= EX;
		int cx = sgtIdx / m, cy = sgtIdx % m;
		sgt[sgtIdx += EX] = 1e30;
		for(sgtIdx >>= 1; sgtIdx; sgtIdx >>= 1)
			sgt[sgtIdx] = min(sgt[sgtIdx << 1], sgt[sgtIdx << 1 | 1]);
		// visited[cx][cy] = 1;
		const Pair<double, Point> &cd = dist[cx][cy];
		for(int d = 0; d < 4; d++)
		{
			int tx = cx + dx[d], ty = cy + dy[d];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m)
				continue;
			double tdFirst = cd.first + mapW[tx][ty];
			if(tdFirst < dist[tx][ty].first)
			{
				dist[tx][ty].first = tdFirst;
				dist[tx][ty].second = Point(cx, cy);
				sgt[sgtIdx = EX + tx * m + ty] = tdFirst;
				for(sgtIdx >>= 1; sgtIdx; sgtIdx >>= 1)
					sgt[sgtIdx] = min(sgt[sgtIdx << 1], sgt[sgtIdx << 1 | 1]);
			}
		}
	}
	// cout << "core dij end\n";
	Matrix<Pair<double, Point>> ans = dist;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			for(int d = 3; d >= 0; d--)
			{
				int tx = i + dx[d], ty = j + dy[d];
				if(tx < 0 || tx >= n || ty < 0 || ty >= m)
					continue;
				if(dist[tx][ty].first < ans[i][j].first)
				{
					ans[i][j].first = dist[tx][ty].first;
					ans[i][j].second = Point(tx, ty);
				}
			}
		}
	return ans;
}

bool ColumnGenSolve::suggestTree(
	const Vector<TerminalSet *> &termsets,
	Vector<Vector<Pair<Tree, GRBVar>>> &treesets,
	const Matrix<double> &mapW, int n, int m, int idx
) const
{
	auto &treeset = treesets[idx - 1];
	Tree tree = suggestTree(termsets[idx], mapW, n, m);
	removeNonCuts(solver->board->map, idx, tree.map, n, m, &mapW);
	// The tree may have some useless grids
	return pushTreeSet(treeset, tree);
}

Tree ColumnGenSolve::suggestTree(
	const TerminalSet *terminalSet, const Matrix<double> &mapW, int n, int m
) const
{
	// similar but different to the expand process
	BitMatrix base;
	base.resize(n, m);
	for(const auto &term: terminalSet->points)
		base.set(term);
	Vector<BitMatrix> branches = treeGetBranches(base, n, m);
	Vector<Matrix<Pair<double, Point>>> dijMatrices;
	for(const auto &branch: branches)
		dijMatrices.push_back(dijkstra(branch, mapW, n, m));
	double bestw = 1e40;
	Tree btree(terminalSet);
	int T = max(n, m);
	while(T--)
	// for(int i = 0; i < n; i++)
		// for(int j = 0; j < m; j++)
		{
			int i = rand() % n, j = rand() % m;
			double cw = 0;
			Tree tree(terminalSet);
			tree.map = base;
			for(const auto &dijMatrix: dijMatrices)
			{
				if(dijMatrix[i][j].first >= 1e20)
					goto fail;
				for(Point cp(i, j); cp.x != -1 && cp.y != -1; cp = dijMatrix[cp].second)
					tree.map.set(cp);
				// tree.map |= dijMatrix[i][j].second;
			}
			// tree.map.set(i, j);
			removeNonCuts(solver->board->map, terminalSet->id, tree.map, n, m);
			for(int i1 = 0; i1 < n; i1++)
				for(int j1 = 0; j1 < m; j1++)
					if(tree.map.get(i1, j1))
						cw += mapW[i1][j1];
			if(cw < bestw){
				bestw = cw; btree = tree;
			}
			fail:;
		}
	return btree;
}
	
void ColumnGenSolve::dfsEdge(
	BitMatrix &tree, const Matrix<int> &id, Vector<Point> &points,
	int x, int y, int n, int m, int &s, int &t
) const
{
	if(x < 0 || x >= n || y < 0 || y >= m || !tree.get(x, y))
		return;
	if(id[x][y])
	{
		if(s)
		{
			assert(!t);
			t = id[x][y];
		}
		else
			s = id[x][y];
		return;
	}
	points.push_back(Point(x, y));
	tree.reset(x, y);
	dfsEdge(tree, id, points, x - 1, y, n, m, s, t);
	dfsEdge(tree, id, points, x + 1, y, n, m, s, t);
	dfsEdge(tree, id, points, x, y - 1, n, m, s, t);
	dfsEdge(tree, id, points, x, y + 1, n, m, s, t);
}

int ColumnGenSolve::dfsFather(Vector<int> &father, int x) const
{
	if(father[x] == x)
		return x;
	else
		return father[x] = dfsFather(father, father[x]);
}

void ColumnGenSolve::removeNonCuts(
	const Matrix<int> &map, int idx, BitMatrix &tree, int n, int m,
	const Matrix<double> *mapW
) const
{
	// cout << "Begin Removal\n" << tree;
	struct TreeEdge
	{
		int s, t;
		bool enabled;
		Vector<Point> points;
	};
	Vector<TreeEdge *> edges;
	Matrix<int> id; int totId = 0;
	id.resize(n, m);
	Vector<bool> isKey; isKey.push_back(false);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(!tree.get(i, j))
				continue;
			int deg = 0;
			if(i && tree.get(i - 1, j))
				++deg;
			if(i + 1 < n && tree.get(i + 1, j))
				++deg;
			if(j && tree.get(i, j - 1))
				++deg;
			if(j + 1 < m && tree.get(i, j + 1))
				++deg;
			if(deg == 2 && map[i][j] != idx)
				continue;
			id[i][j] = ++totId;
			isKey.push_back(map[i][j] == idx);
			if(i && id[i - 1][j])
			{
				TreeEdge *edge = new TreeEdge;
				edge->s = totId; edge->t = id[i - 1][j];
				edge->enabled = false;
				edges.push_back(edge);
			}
			if(j && id[i][j - 1])
			{
				TreeEdge *edge = new TreeEdge;
				edge->s = totId; edge->t = id[i][j - 1];
				edge->enabled = false;
				edges.push_back(edge);
			}
		}
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			if(!tree.get(i, j) || id[i][j])
				continue;
			TreeEdge *edge = new TreeEdge;
			edge->s = 0; edge->t = 0;
			edge->enabled = false;
			dfsEdge(tree, id, edge->points, i, j, n, m, edge->s, edge->t);
			assert(edge->s); assert(edge->t);
			edges.push_back(edge);
		}
	
	sort(
		edges.begin(), edges.end(),
		[](TreeEdge *x, TreeEdge *y)
		{
			return x->points.size() < y->points.size();
		}
	);
	
	Vector<int> father;
	father.resize(totId + 1);
	Vector<int> deg;
	deg.resize(totId + 1);
	Vector<Vector<TreeEdge *>> graphEdges;
	graphEdges.resize(totId + 1);
	
	for(int i = 1; i <= totId; i++)
		father[i] = i;
	for(auto edge: edges)
	{
		int fatherS = dfsFather(father, edge->s);
		int fatherT = dfsFather(father, edge->t);
		if(fatherS == fatherT)
			continue;
		father[fatherS] = fatherT;
		graphEdges[edge->s].push_back(edge);
		graphEdges[edge->t].push_back(edge);
		++deg[edge->s];
		++deg[edge->t];
		edge->enabled = true;
	}
	
	Vector<int> queue;
	queue.resize(totId + 1);
	int queueHead = 1, queueTail = 0;
	Vector<bool> disposed;
	disposed.resize(totId + 1);
	for(int i = 1; i <= totId; i++)
		if(deg[i] == 1 && !isKey[i])
			queue[++queueTail] = i;
	while(queueHead <= queueTail)
	{
		int curId = queue[queueHead++];
		disposed[curId] = true;
		for(auto edge: graphEdges[curId])
		{
			if(!edge->enabled)
				continue;
			int otherId = (edge->s ^ edge->t ^ curId);
			assert(!disposed[otherId]);
			if((--deg[otherId]) == 1 && !isKey[otherId])
				queue[++queueTail] = otherId;
			edge->enabled = false;
		}
	}
	
	for(auto edge: edges)
		if(edge->enabled)
			for(auto &point: edge->points)
				tree.set(point);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(id[i][j] && disposed[id[i][j]])
				tree.reset(i, j);
	
	if(mapW == NULL)
		goto funcend;
	
	// cout << "optimizing tree\n";
	// cout << tree;
	
	for(auto edge: edges)
		if(edge->enabled)
		{
			BitMatrix newTree = tree;
			for(auto point: edge->points)
				newTree.reset(point);
			Vector<BitMatrix> branches = treeGetBranches(newTree, n, m);
			// cout << "branchsize " << (int) branches.size() << '\n';
			if((int) branches.size() != 2) continue;
			Matrix<Pair<double, Point>> dijResult
				= dijkstra(branches[0], *mapW, n, m);
			Point bestPoint1(-1, -1); double dist = 1e30;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
					if(branches[1].get(i, j) && dijResult[i][j].first < dist)
					{
						dist = dijResult[i][j].first;
						bestPoint1.x = i; bestPoint1.y = j;
					}
			// cout << "dist " << dist << '\n';
			for(auto point: edge->points)
				dist -= (*mapW)[point];
			// cout << "dist " << dist << '\n';
			if(dist >= 0)
				continue;
			while(bestPoint1 != Point(-1, -1))
			{
				newTree.set(bestPoint1);
				bestPoint1 = dijResult[bestPoint1].second;
			}
			removeNonCuts(map, idx, newTree, n, m, mapW);
			tree = newTree;
			goto funcend;
		}
	
	funcend:;
	for(auto edge: edges)
		delete edge;
	
	// if(mapW != NULL)
	// {
		// cout << "optimize finished\n";
		// cout << tree;
	// }

	// cout << "End Removal\n" << tree;
}

double ColumnGenSolve::removeNonCuts(
	Matrix<bool> &visited, const Matrix<int> &map, int idx,
	const Matrix<double> &mapW, BitMatrix &tree, int n, int m
) const
{
	double ans = 0;
	begin:
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(
				tree.get(i, j) && map[i][j] != idx
				&& !treeIsCut(tree, i, j, n, m)
			)
			{
				visited[i][j] = 1;
				tree.reset(i, j);
				ans += mapW[i][j];
				goto begin;
			}
	return ans;
}

bool ColumnGenSolve::pushTreeSet(
	Vector<Pair<Tree, GRBVar>> &treeset, Tree &tree
) const
{
	for(const auto &treeVar: treeset)
		if(treeVar.first == tree)
			return false;
	tree.computeLength();
	treeset.push_back(Pair<Tree, GRBVar>(tree, GRBVar()));
	return true;
}

int ColumnGenSolve::treeBranches(BitMatrix tree, int n, int m) const
{
	// Simple method finding how many branches
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tree.get(i, j))
			{
				treeDFSBranches(tree, i, j, n, m);
				++ans;
			}
	return ans;
}

void ColumnGenSolve::treeDFSBranches(
	BitMatrix &tree, int i, int j, int n, int m
) const
{
	// Simple DFS
	if(i < 0 || i >= n || j < 0 || j >= m || !tree.get(i, j)) 
		return;
	tree.reset(i, j);
	treeDFSBranches(tree, i - 1, j, n, m);
	treeDFSBranches(tree, i + 1, j, n, m);
	treeDFSBranches(tree, i, j - 1, n, m);
	treeDFSBranches(tree, i, j + 1, n, m);
}

Vector<BitMatrix> ColumnGenSolve::treeGetBranches(
	BitMatrix tree, int n, int m
) const
{
	// Simple method finding every branch
	Vector<BitMatrix> ans;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(tree.get(i, j))
			{
				BitMatrix res;
				res.resize(n, m);
				treeDFSGetBranches(tree, res, i, j, n, m);
				ans.push_back(res);
			}
	return ans;
}

void ColumnGenSolve::treeDFSGetBranches(
	BitMatrix &tree, BitMatrix &res, int i, int j, int n, int m
) const
{
	// Simple DFS
	if(i < 0 || i >= n || j < 0 || j >= m || !tree.get(i, j)) 
		return;
	tree.reset(i, j); res.set(i, j);
	treeDFSGetBranches(tree, res, i - 1, j, n, m);
	treeDFSGetBranches(tree, res, i + 1, j, n, m);
	treeDFSGetBranches(tree, res, i, j - 1, n, m);
	treeDFSGetBranches(tree, res, i, j + 1, n, m);
}

bool ColumnGenSolve::treeIsCut(BitMatrix tree, int i, int j, int n, int m) const
{
	// A simple method judging a cut-grid
	int b0 = treeBranches(tree, n, m);
	tree.reset(i, j);
	return treeBranches(tree, n, m) != b0;
}

Solution ColumnGenSolve::solve() const
{
	Solution solution;
	solution.board = solver->board;
	Vector<Tree *> res = route(solver->board->width * solver->board->height / 100 + 1);
	solution.trees.push_back(NULL);
	for(auto tree: res)
		solution.trees.push_back(tree);
	solution.computeMap();
	return solution;
}

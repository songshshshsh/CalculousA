#include "../include/CleverOptimize.h"
#include <list>
#include "../include/global.h"

using namespace std;

static const int X[] = {0,-1,0,1,0};
static const int Y[] = {0,0,1,0,-1};

Solution CleverOptimize::optimize(const Solution& solution) const 
{
	Solution temp(solution);
	for (unsigned i = 0;i < temp.trees.size();++i)
	{
		for (unsigned j = 1;j < temp.trees[i]->terminalSet->points.size();++j)
		{
			int degree = 0,lastDirection = 0;
			bool noNeedToChange = true;
			Point currentPoint(temp.trees[i]->terminalSet->points[j].x,temp.trees[i]->terminalSet->points[j].y);
			while (degree <= 2)
			{
				for (int k = 1;k <= 4; ++k)
				{
					int currentx = X[k] + currentPoint.x;
					int currenty = Y[k] + currentPoint.y;
					if (currenty >= 0 && currenty < temp.trees[i]->map.width && currentx >= 0 && currentx < temp.trees[i]->map.height)
					{
						if (temp.trees[i]->map.get(currentx,currenty) == 1) 
						{
							if (k != getLastDirection(lastDirection)) lastDirection = k;
							degree++;
						}
					}
				}
				if (degree >= 3)
				{
					noNeedToChange = false;
					break;
				}
				else
				{
					temp.trees[i]->map.reset(currentPoint.x,currentPoint.y);
					degree = 0;
					currentPoint.x += X[lastDirection];
					currentPoint.y += Y[lastDirection];
				}
			}
			if (!noNeedToChange)
			{
				bfs(temp.trees[i]->terminalSet->points[j],temp.trees[i]->map);
			}
		}
	}
	return temp;
}

int CleverOptimize::getLastDirection(const int k) const
{
	if (k == 1) return 2;
	if (k == 2) return 1;
	if (k == 3) return 4;
	if (k == 4) return 3;
	return 0;
}

void CleverOptimize::bfs(const Point& start,BitMatrix& _map) const
{
	Matrix<int> visited;
	list<Point> waitingPoints;
	waitingPoints.push_back(start);
	visited.resize(_map.height,_map.width);
	visited[start.x][start.y] = 1;
	bool find = false;
	int step = 1;
	while (!find)
	{
		step++;
		Point currentPoint = waitingPoints.front();
		waitingPoints.pop_front();
		for (int i = 1;i <= 4;++i)
		{
			int currentx = X[i] + currentPoint.x;
			int currenty = Y[i] + currentPoint.y;
				if (currenty >= 0 && currenty < 
					_map.width && currentx >= 0 && currentx < _map.height)
				if (!visited[currentx][currenty])
				{
					visited[currentx][currenty] = step;
					waitingPoints.push_back(Point(currentx,currenty));
					if (_map.get(currentx,currenty) == 1)
					{
						find  = true;
						backtrace(start,_map,visited,Point(currentx,currenty),step);
						break;
					}
				}
		}
	}
}

void CleverOptimize::backtrace(const Point& start,BitMatrix& map,Matrix<int>& visited,const Point& end,int step) const
{
	Point currentPoint = end;
	while (currentPoint != start)
	{
		for (int i = 1;i <= 4;++i)
		{
			int currentx = X[i] + currentPoint.x;
			int currenty = Y[i] + currentPoint.y;
			if (currenty >= 0 && currenty < map.width && currentx >= 0 && currentx < map.height)
			{
				if (visited[currentx][currenty] == --step)
				{
					currentPoint = Point(currentx,currenty);
					map.set(currentx,currenty);
					break;
				}
			}
		}
	}
}




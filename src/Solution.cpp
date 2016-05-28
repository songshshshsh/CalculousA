#include "../include/Solution.h"

OStream &operator <<(OStream &ost, const Solution &solution)
{
	ost << "Solution\n";
	for(auto &row: solution.map)
	{
		for(auto col: row)
			ost << col << " ";
		ost << "\n";
	}
	return ost;
}
#include "../include/BitMatrix.h"

OStream &operator <<(OStream &ost, const BitMatrix &bmx)
{
	ost << "BitMatrix " << bmx.height << " * " << bmx.width << "\n";
	for(int i = 0; i < bmx.height; i++)
	{
		for(int j = 0; j < bmx.width; j++)
			ost << (int) bmx.get(i, j);
		ost << "\n";
	}
	return ost;
}

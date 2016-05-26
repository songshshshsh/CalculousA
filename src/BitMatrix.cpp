#include "../include/BitMatrix.h"

OStream &operator <<(OStream &ost, const BitMatrix &bmx)
{
	cout << "BitMatrix " << bmx.height << " * " << bmx.width << "\n";
	for(int i = 0; i < bmx.height; i++)
	{
		for(int j = 0; j < bmx.width; j++)
			cout << (int) bmx.get(i, j);
		cout << "\n";
	}
	return ost;
}

#ifndef BITMATRIX_H
#define BITMATRIX_H

#include "global.h"

class BitMatrix
{
private:
	Vector<unsigned int> data;
public:
	int height, width;
	BitMatrix(int h = 0, int w = 0)
	{
		resize(h, w);
	}
	void resize(int h, int w)
	{
		height = h; width = w;
		data.resize((h * w + 31) >> 5);
	}
	void set(int x, int y)
	{
		x = x * width + y;
		data[x >> 5] |= (1u << (x & 31));
	}
	void reset(int x, int y)
	{
		x = x * width + y;
		data[x >> 5] &= ~(1u << (x & 31));
	}
	bool get(int x, int y) const
	{
		x = x * width + y;
		return data[x >> 5] >> (x & 31) & 1;
	}
	friend OStream &operator <<(OStream &ost, const BitMatrix &bmx);
};

#endif // BITMATRIX_H

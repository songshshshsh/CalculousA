#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
using std::cin;
using std::cout;
typedef std::istream IStream;
typedef std::ostream OStream;

#include <fstream>
typedef std::ostream OStream;
typedef std::ifstream IFStream;
typedef std::ofstream OFStream;

#include <sstream>
typedef std::stringstream StringStream;

#include <vector>
// #define Vector std::vector
template <class T>
class Vector: public std::vector<T>
{
public:
};

#include <utility>
template <class T1, class T2>
class Pair: public std::pair<T1, T2>
{
public:
};

#include <algorithm>
using std::sort;
using std::reverse;
using std::min;
using std::max;

#include <string>
typedef std::string String;

#include "BitMatrix.h"

template <class T>
class Matrix: public Vector<Vector<T>>{
public:
	using Vector<Vector<T>>::resize;
	using Vector<Vector<T>>::operator[];

	void resize(int n, int m)
	{
		this->resize(n);
		for(auto &row: *this)
			row.resize(m);
	}
	T &operator[](Pair<int, int> pii)
	{
		return (*this)[pii.first][pii.second];
	}
	const T &operator[](Pair<int, int> pii) const
	{
		return (*this)[pii.first][pii.second];
	}
};

class Point
{
public:
	int x, y;
	Point(int x_,int y_):x(x_),y(y_){};
	Point():x(0),y(0){};
};

#endif // GLOBAL_H

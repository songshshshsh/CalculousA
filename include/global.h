#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
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
	Pair(){}
	Pair(const T1 &t1, const T2 &t2)
	{
		first = t1; second = t2;
	}
};

#include <algorithm>
using std::sort;
using std::reverse;
using std::min;
using std::max;

#include <string>
typedef std::string String;

#include <cstdlib>
#include <ctime>

int doAssert(bool, const char *file, int line);
#ifdef ENABLE_ASSERT
#define assert(x) doAssert((x), __FILE__, __LINE__)
#else
#define assert(x) 0
#endif // ENABLE_ASSERT

#define NOT_USED(x) ((void) (x))

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

#include "BitMatrix.h"

#endif // GLOBAL_H

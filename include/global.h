
#include <iostream>
using std::cin;
using std::cout;
using std::istream;
using std::ostream;

#include <fstream>
typedef std::ostream OStream;
typedef std::ifstream IFStream;
typedef std::ofstream OFStream;

#include <vector>
using std::vector;
#define Vector vector

#include <utility>
using std::pair;
#define Pair pair

#include <algorithm>
using std::sort;
using std::reverse;
using std::min;
using std::max;

#include <string>
typedef std::string String;
using std::ifstream;
using std::ofstream;
using std::vector;

#ifndef _MATRIX_H
#define _MATRIX_H

template <class T>

class Matrix: public Vector<Vector<T>>{
public:
	using Vector<Vector<T>>::resize;
	using Vector<Vector<T>>::operator[];

	void resize(int n, int m){
		this->resize(n);
		for(auto &row: *this)
			row.resize(m);
	}
	T &operator[](Pair<int, int> pii){
		return (*this)[pii.first][pii.second];
	}
	const T &operator[](
		Pair<int, int> pii
	) const{
		return (*this)[pii.first][pii.second];
	}
};

class Point
{
	#define x first
	#define y second
public:
	Point(int x_,int y_):x(x_),y(y_){};
	int getx(){return x;}
	int gety(){return y;}
private:
	int x;
	int y;
	#undef x
	#undef y
};

#endif // _MATRIX_H
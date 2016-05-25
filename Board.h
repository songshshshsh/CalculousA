#ifndef BOARD_H
#define BOARD_H

#include "Vector.h"
#include "Matrix.h"
#include "Point.h"

class Board
{
	private:
		int height, width;
		Vector<TerminalSet *> terminalSets;
		Matrix<int> map;
	public:
		void input(int mode=0, ifstream &ifs=cin);
		void output(int mode=0, ofstream &ofs=cout);
};

#endif
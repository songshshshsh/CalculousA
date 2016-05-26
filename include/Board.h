#ifndef BOARD_H
#define BOARD_H

#include "global.h"

class TerminalSet;

class Board
{
	private:
		int height, width;
		Vector<TerminalSet *> terminalSets;
		Matrix<int> map;
		Vector<Point> block;
	public:
		void input(int mode=0, IStream &ifs=cin);
		void output(int mode=0, OStream &ofs=cout);
};

#endif
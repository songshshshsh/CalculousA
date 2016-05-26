#ifndef TREE_H
#define TREE_H

#include "global.h"
#include "TerminalSet.h"

class Tree
{
public:
	Tree();

private:
	const TerminalSet *terminalSet;
	BitMatrix map;
	int length;
};

#endif
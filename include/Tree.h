#ifndef TREE_H
#define TREE_H

#include "global.h"
#include "TerminalSet.h"

class Tree
{
public:
	Tree(TerminalSet *);
	const TerminalSet *terminalSet;
	BitMatrix map;
	int length;
};

#endif
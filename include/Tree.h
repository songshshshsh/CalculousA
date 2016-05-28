#ifndef TREE_H
#define TREE_H

#include "global.h"
#include "TerminalSet.h"

class Tree
{
public:
	Tree(const TerminalSet *);
	const TerminalSet *terminalSet;
	BitMatrix map;
	int length;
	friend bool operator ==(const Tree &lhs, const Tree &rhs);
};

#endif
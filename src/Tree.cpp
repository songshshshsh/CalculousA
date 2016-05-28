#include "../include/Tree.h"

Tree::Tree(const TerminalSet* terminalSet_)
{
	terminalSet = terminalSet_;
	map.resize(terminalSet->board->height, terminalSet->board->width);
	length = 0;
}

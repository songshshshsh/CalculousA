#include "global.h"
#include "../include/TerminalSet.h"

TerminalSet::TerminalSet(int id_,int n_)
{
	this->id = id_;
	this->points.resize(n_);
}

#include "Issue.h"



Issue::Issue()
{
}


Issue::~Issue()
{
}

string Issue::toString()
{
	stringstream ss;
	ss << this->description << "|" << this->status << "|" << this->reporter << "|" << this->solver;
	return ss.str();
}

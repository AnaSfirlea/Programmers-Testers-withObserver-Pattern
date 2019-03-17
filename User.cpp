#include "User.h"



User::User()
{
}


User::~User()
{
}

string User::toString()
{
	stringstream ss;
	ss << this->name << '|' << this->type;
	return ss.str();
}

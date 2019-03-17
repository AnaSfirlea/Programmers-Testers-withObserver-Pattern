#pragma once
#include <string>
#include <sstream>
using namespace std;

class User
{
private:
	string name;
	string type;
public:
	User();
	User(string n, string t) :name(n), type(t) {}
	~User();
	string getName() { return name; }
	string getType() { return type; }

	string toString();
};


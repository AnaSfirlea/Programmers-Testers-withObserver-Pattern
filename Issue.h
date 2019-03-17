#pragma once
#include <string>
#include <sstream>
using namespace std;
class Issue
{
private:
	string description;
	string status;
	string reporter;
	string solver;
public:
	Issue(string descr, string stat, string rep, string solv) :
		description(descr), status(stat), reporter(rep), solver(solv) {}
	Issue();
	~Issue();

	string getDescription() { return this->description; }
	string getStatus() { return this->status; }
	string getReporter() { return this->reporter; }
	string getSolver() { return this->solver; }

	void setSolver(string solver) { this->solver = solver; }
	void setStatus() { this->status = "closed"; }
	string toString();
};


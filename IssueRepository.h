#pragma once
#include "Issue.h"
#include "User.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <assert.h>

using namespace std;
class IssueRepository
{
private:
	vector<Issue> issues;
	vector<User> users;
public:
	IssueRepository();
	~IssueRepository();

	void readIssues();
	void readUsers();
	int addIssue(string descr,string reporterName);
	void removeIssue(int idx);
	vector<Issue> getIssues() { return issues; }
	vector<User> getUsers() { return users; }

	void updateStatusAndProgr(int idx, string name);
	void sortByStatusAndDescr();

	void writeToFile();
};
void testAdd();
void testRemove();
void testUpdate();


#pragma once
#include "IssueRepository.h"
class IssuesController
{
private:
	IssueRepository repo;
public:
	IssuesController(const IssueRepository& _repo) : repo(_repo) {}
	IssuesController();
	~IssuesController();
	vector<Issue> getIssues() { return this->repo.getIssues(); }
	vector<User> getUsers() { return this->repo.getUsers(); }

	int addIssueCtrl(string descr, string reporterName) { return this->repo.addIssue(descr, reporterName); }
	void removeIssueCtrl(int idx) { this->repo.removeIssue(idx); }
	void updateStatusAndProgrCtrl(int idx, string name) { this->repo.updateStatusAndProgr(idx, name); }
	
};


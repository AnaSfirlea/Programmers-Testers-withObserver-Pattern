#include "IssueRepository.h"


IssueRepository::IssueRepository()
{
	this->readUsers();
	this->readIssues();
	this->sortByStatusAndDescr();
}


IssueRepository::~IssueRepository()
{
}
vector<string> tokenize(string str, char delimiter)
{
	stringstream ss(str);
	string token;
	vector<string> result;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}
void IssueRepository::readIssues()
{
	ifstream f{ "Issues.txt" };
	if (!f.is_open())
		return;

	string line;
	while (getline(f, line))
	{
		vector<string> tokens = tokenize(line, '|');
		if (tokens.size() != 4)
			return;

		Issue i{ tokens[0],tokens[1] ,tokens[2] ,tokens[3] };
		this->issues.push_back(i);
	}
	f.close();
}

void IssueRepository::readUsers()
{
	ifstream f{ "Users.txt" };
	if (!f.is_open())
		return;

	string line;
	while (getline(f, line))
	{
		vector<string> tokens = tokenize(line, '|');
		if (tokens.size() != 2)
			return;

		User u{ tokens[0],tokens[1] };
		this->users.push_back(u);
	}
	f.close();
}
/*
	description: adds a new issue, sets the description and the reported name
	input: descr-string,
	reporterName- string

	output:return 1 if the operation was made successfully 
	0 - otherwise
*/
int IssueRepository::addIssue(string descr, string reporterName)
{
	if (descr == "")
		return 0;
	for (auto i : this->issues)
		if (i.getDescription() == descr)
			return 0;
	Issue i{ descr,"open",reporterName,"" };
	this->issues.push_back(i);
	this->writeToFile();
	return 1;
}
/*
	description:  removes the issue from index idx
	input: idx-int
	output: -
	the operation fails if the index is out of range
*/
void IssueRepository::removeIssue(int idx)
{
	if (idx < 0 || idx > this->issues.size())
		return;
	this->issues.erase(this->issues.begin() + idx);
	this->writeToFile();

}
/*
	description: updates the status and the name of the programmer from the given index
	input: idx-int 
		string-name
	output: -
*/
void IssueRepository::updateStatusAndProgr(int idx, string name)
{
	if (idx < 0 || idx > this->issues.size())
		return;

	this->issues[idx].setSolver(name);
	this->issues[idx].setStatus();
	this->writeToFile();

}

void IssueRepository::sortByStatusAndDescr()
{
	sort(this->issues.begin(), this->issues.end(), 
		[](Issue i1, Issue i2) {return i1.getStatus() < i2.getStatus(); });

	sort(this->issues.begin(), this->issues.end(),
		[](Issue i1, Issue i2) {return i1.getDescription() < i2.getDescription(); });

	
}

void IssueRepository::writeToFile()
{
	ofstream f{ "Issues.txt" };
	
	f.clear();
	for (auto i : this->issues)
		f << i.toString() << endl;
}

void testAdd()
{
	IssueRepository repo{};
	

	assert(repo.addIssue("Fire wall breaks", "John Legend") == 1);
	assert(repo.addIssue("Errors ", "Smith Janes") == 1);
	assert(repo.addIssue("Bugs", "Rosie") == 1);



}
void testRemove()
{
	IssueRepository repo{};
	

	assert(repo.addIssue("Fire wall breaks", "John Legend") ==1);
	assert(repo.addIssue("Errors ", "Smith Janes")==1);
	assert(repo.addIssue("Bugs", "Rosie") ==1);

	
	repo.removeIssue(0);
	repo.removeIssue(1);
	
	assert(repo.getIssues().size() == 3);


}
void testUpdate()
{
	IssueRepository repo{};

	assert(repo.addIssue("Fire wall breaks", "John Legend") == 1);
	repo.addIssue("Errors ", "Smith Janes");
	repo.addIssue("Bugs", "Rosie");

	repo.updateStatusAndProgr(0, "Raul");
	assert(repo.getIssues()[0].getSolver() == "Raul");
}
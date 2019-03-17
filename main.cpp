#include "QtPracticalExam.h"
#include <QtWidgets/QApplication>
#include "userWindow.h"
#include "programmerWindow.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	IssueRepository repo{};
	IssuesController ctrl{};

	string name1 = repo.getUsers()[0].getName();
	UserWindow user2{ name1,&ctrl };
	user2.show();

	string name2 = repo.getUsers()[1].getName();
	ProgrammerWindow user1{name2, &user2  };
	user1.show();

	string name3 = repo.getUsers()[2].getName();
	ProgrammerWindow user3{ name3, &user2 };
	user3.show();



	//testAdd();
	//testRemove();
	//testUpdate();
	return a.exec();
}

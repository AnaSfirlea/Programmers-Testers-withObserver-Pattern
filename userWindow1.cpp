#include "userWindow.h"



UserWindow::UserWindow(string name, IssuesController* _ctrl, QWidget *parent) :QWidget(parent), ctrl(_ctrl)
{
	ui.setupUi(this);

	this->userName = name;
	
	this->setMinimumHeight(200);
	this->setMinimumWidth(200);

	string nameAndType = name + "-" +"tester";

	QString str = QString::fromStdString(nameAndType);

	this->setWindowTitle(str);
	this->populateList();

	QObject::connect(this->ui.addButton, &QPushButton::clicked, [&]()
	{
		this->addButtonHandler();
	});

	QObject::connect(this->ui.removeButton, &QPushButton::clicked, [&]()
	{
		this->removeButtonHandler();
	});

	

}


UserWindow::~UserWindow()
{
}

void UserWindow::populateList()
{
	if (this->ui.issuesList->count() > 0)
		this->ui.issuesList->clear();

	for (auto i : this->ctrl->getIssues())
	{
		QString itemInList = QString::fromStdString(i.toString());
		QFont f{ "Courier",10 };
		this->ui.issuesList->setFont(f);

		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->ui.issuesList->addItem(item);
	}

	if (this->ctrl->getIssues().size() > 0)
		this->ui.issuesList->setCurrentRow(0);
}

int UserWindow::getSelectedIndex()
{
	if (this->ui.issuesList->count() == 0)
		return -1;

	QModelIndexList index = this->ui.issuesList->selectionModel()->selectedIndexes();
	if (index.count() == 0)
		return -1;

	int idx = index.at(0).row();
	return idx;
}

void UserWindow::addButtonHandler()
{
	int idx = this->getSelectedIndex();
	if (idx < 0 || idx > this->ui.issuesList->count())
		return;

	QString description = this->ui.issueEdit->text();
	string descr = description.toStdString();
	
	string reporter = this->userName;

	int res = this->ctrl->addIssueCtrl(descr, reporter);
		
	if (descr == "" || res == 0)
		this->mess.show();
	this->notify();

}

void UserWindow::removeButtonHandler()
{
	int idx = this->getSelectedIndex();
	if (idx < 0 || idx > this->ctrl->getIssues().size())
		return;

	Issue i = this->ctrl->getIssues()[idx];

	if (i.getStatus() == "closed")
		this->ctrl->removeIssueCtrl(idx);

	this->notify();
}

void UserWindow::solveIssue(int idx,string solver)
{
	if (idx < 0 || idx > this->ctrl->getIssues().size())
		return;

	this->ctrl->updateStatusAndProgrCtrl(idx, solver);
	this->notify();
}

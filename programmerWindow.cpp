#include "programmerWindow.h"



ProgrammerWindow::ProgrammerWindow(string name,UserWindow* _user, QWidget *parent):QWidget(parent),user(_user)
{
	ui.setupUi(this);
	this->programmerName = name;

	this->setWindowTitle(QString::fromStdString(name +"-" +"programmer"));
	this->user->addObserver(this);
	this->populateList();

	QObject::connect(this->ui.removeButton, &QPushButton::clicked, [&]()
	{
		this->removeButtonHandler();
	});

	QObject::connect(this->ui.solveButton, &QPushButton::clicked, [&]()
	{
		this->solveButtonHandler();
	});

}


ProgrammerWindow::~ProgrammerWindow()
{
	this->user->removeObserver(this);
}

void ProgrammerWindow::populateList()
{

	if (this->ui.allIssues->count() > 0)
		this->ui.allIssues->clear();

	for (auto i : this->user->getCtrl()->getIssues())
	{
		QString itemInList = QString::fromStdString(i.toString());
		QFont f{ "Courier",10 };
		this->ui.allIssues->setFont(f);

		QListWidgetItem* item = new QListWidgetItem{ itemInList };
		this->ui.allIssues->addItem(item);
	}

	if (this->user->getCtrl()->getIssues().size() > 0)
		this->ui.allIssues->setCurrentRow(0);
}
int ProgrammerWindow::getSelectedIndex()
{
	if (this->ui.allIssues->count() == 0)
		return -1;

	QModelIndexList index = this->ui.allIssues->selectionModel()->selectedIndexes();
	if (index.count() == 0)
		return -1;

	int idx = index.at(0).row();
	return idx;
}

void ProgrammerWindow::removeButtonHandler()
{
	this->user->removeButtonHandler();
}

void ProgrammerWindow::solveButtonHandler()
{
	int idx = this->getSelectedIndex();
	if (idx < 0 || idx > this->user->getCtrl()->getIssues().size())
		return;
	Issue i = this->user->getCtrl()->getIssues()[idx];
	if (i.getStatus() == "open")
	{
		this->user->solveIssue(idx, this->programmerName);
	}

}

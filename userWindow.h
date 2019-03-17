#pragma once
#include "ui_UserWindow.h"
#include <qwidget.h>
#include "IssuesController.h"
#include "Observer.h"
#include "Message.h"
class UserWindow:public QWidget, public Observable
{
public:
	UserWindow(string name,IssuesController* _ctrl, QWidget *parent = Q_NULLPTR);
	~UserWindow();
	void update() { this->populateList(); }
	void populateList();
	int getSelectedIndex();
	void addButtonHandler();
	void removeButtonHandler();
	void solveIssue(int idx,string solver);
	IssuesController* getCtrl() { return this->ctrl; }
private:
	string userName;
	Ui::UserWindow ui;
	IssuesController* ctrl;
	Message mess;
};


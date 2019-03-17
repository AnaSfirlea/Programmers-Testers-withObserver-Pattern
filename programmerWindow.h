#pragma once
#include <qwidget.h>
#include "Observer.h"
#include "userWindow.h"
#include"ui_ProgrammerWindow.h"
class ProgrammerWindow:public QWidget ,public Observer
{
	Q_OBJECT
private:
	UserWindow* user;

public:
	ProgrammerWindow(string name,UserWindow* _user, QWidget *parent = Q_NULLPTR);
	~ProgrammerWindow();
	void update() { this->populateList(); }

	void populateList();
	void removeButtonHandler();
	void solveButtonHandler();
	int getSelectedIndex();
private:
	Ui::ProgrammerWindow ui;
	string programmerName;
};


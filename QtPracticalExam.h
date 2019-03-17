#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtPracticalExam.h"

class QtPracticalExam : public QMainWindow
{
	Q_OBJECT

public:
	QtPracticalExam(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtPracticalExamClass ui;
};

#pragma once
#include <qwidget.h>
#include "ui_message.h"
class Message :public QWidget
{
	Q_OBJECT

public:
	Message(QWidget * parent = Q_NULLPTR);
	~Message();
	Ui::message ui;
};


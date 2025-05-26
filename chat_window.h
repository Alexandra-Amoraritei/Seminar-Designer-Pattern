#pragma once

#include <qwidget.h>
#include <qboxlayout.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>

#include "session.h"



class ChatWindow :public QWidget, public Observer {
public:
	ChatWindow(ChatSession* session, User user);
	
	~ChatWindow() {};

	void initializer();
	void connector();
	void load_gui();

public:
	User user;
	ChatSession* chat_session;
	

	void update() override;
	void sendMessage();


	//widgets
	QListWidget* list=new QListWidget;
	QLineEdit* user_message_input = new QLineEdit;
	QPushButton* send_message_button = new QPushButton("Send");
};
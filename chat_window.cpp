#include "chat_window.h"

ChatWindow::ChatWindow(ChatSession* session,User user)
{
	this->user = user;
	chat_session = session;
	initializer();
	connector();
	load_gui();
}

void ChatWindow::initializer()
{
	QVBoxLayout* main_layout=new QVBoxLayout(this);
	QVBoxLayout* read_layout=new QVBoxLayout;
	QHBoxLayout* write_layout=new QHBoxLayout;
	main_layout->addLayout(read_layout);
	main_layout->addLayout(write_layout);
	this->setLayout(main_layout);

	read_layout->addWidget(list);
	write_layout->addWidget(user_message_input);
	write_layout->addWidget(send_message_button);

}

void ChatWindow::connector()
{
	connect(send_message_button, &QPushButton::clicked, [&]() {sendMessage();});
}

void ChatWindow::load_gui()
{
	this->update();
}

void ChatWindow::update()
{
	list->clear();
	for (auto& el : chat_session->getMessages())
		list->addItem(QString::fromStdString("User "+el.getUser()+": " + el.getMessage()));
	

	
}

void ChatWindow::sendMessage()
{
	std::string msg = user_message_input->text().toStdString();
	Message my_msg(msg);
	chat_session->addMessage(user, my_msg);
}

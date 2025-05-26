#include "session.h"

Subject::~Subject()
{
	for (auto& el : observers)
		delete el;
}



void ChatSession::addMessage(User u, Message m)
{
	UserMessage message(u, m);
	this->user_messages.push_back(message);
	notify();

}

std::vector<UserMessage> ChatSession::getMessages()
{
	return this->user_messages;
}

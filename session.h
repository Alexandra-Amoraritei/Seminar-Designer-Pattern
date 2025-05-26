#pragma once
//#include "chat_window.h"
#include <vector>
#include <string>

class Observer {
public:
	virtual void update() = 0;
	Observer() {};
	virtual ~Observer() {};
};

class Subject {
protected:
	std::vector <Observer*> observers;
public:
	Subject() {};
	~Subject();
	void registerObserver(Observer* obs) { observers.push_back(obs); };
	void notify() {
		for (auto& el : observers)
			el->update();
	};

};




class Message {
private:
	std::string message;
public:
	Message() {};
	Message(std::string message) :message(message) {};
	~Message() {};

	std::string getMessage() {
		return message;
	}
};

class User {
private:
	std::string unique_user_name;
	std::string name;
public:
	User() {};
	User(std::string unique_user_name, std::string name) :unique_user_name(unique_user_name), name(name) {};
	~User() {};

	std::string getName() {
		return name;
	}

};

class UserMessage {
private:
	Message message;
	User user;
public:
	UserMessage() {};
	UserMessage(User user, Message message) :message(message), user(user) {};
	~UserMessage() {};

	std::string getMessage() {
		return message.getMessage();
	}
	std::string getUser() {
		return user.getName();
	}
};




class ChatSession :public Subject {
private:
	std::vector<UserMessage> user_messages;
public:
	ChatSession() {};
	~ChatSession() {};

	void addMessage(User u, Message M);
	std::vector<UserMessage> getMessages();
};


#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "Message.h"
#include "User.h"

// defining exceptions
struct Login_creature : public std::exception 
{
	const char* what() const noexcept override { return "login is busy"; }
};
struct Password_creature : public std::exception 
{
	const char* what() const noexcept override { return "the password is not correct"; }
};

class IChat 
{
private:
	const std::string				_nameChat;

public:
	IChat(std::string nameChat = "head room") 
		: _nameChat(nameChat)		{}
	virtual ~IChat()				{}
	const auto& get_nameChat()		{ return _nameChat; }
};

class Chat :public IChat 
{
private:
	std::vector<User>				_boxUsers;
	std::vector<Message>			_boxMessages;
	std::shared_ptr<User>			_currentUser{ nullptr };

	std::string get_name_for_id(const long long id);
	const long long get_id_for_name(const std::string name);
	const std::string enter_login();
	const std::string enter_password();
	const bool check_login(const std::string& loginForCheck);
	const bool check_password(const std::string& passwordForCheck);
	const bool check_name(const std::string& nameForCheck); //for next versions
	void creat_user(std::string login, std::string password);
	void set_currentUser(const User& authorizer); //for authorization
	auto verification(); //authorization
	const long long& counter_new_message();
	void view_messages();
	void sending_public_message();
	void new_privat_message(long long addressee = 0);

public:
	Chat(std::string nameChat)
		: IChat(nameChat)			{}
	~Chat()							{}
	auto& get_boxUsers()			{ return _boxUsers; }
	auto& get_boxMessages()			{ return _boxMessages; }

	void strart_menu();
	void registration();
	void working_session();
};

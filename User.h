#pragma once
#include <string>
#include <ctime>
static long long					idUser{}; //metric

class IUser
{
private:
	const std::string				_login;
	const std::time_t				_date{};
	const long long					_idUser{};

public:
	IUser(std::string login) 
		: _login(login), _date(time(nullptr)), _idUser(++idUser) {}
	virtual ~IUser()				{}
	const auto& get_login()			{ return _login; }
	const auto& get_date()			{ return _date; }
	const auto& get_idUser()		{ return _idUser; }
};

class User : public IUser
{
private:
	std::string						_name;
	std::string						_password;
	long long						_indicatorMessage{}; //for method show

public:
	User(std::string login, std::string password) 
		: IUser(login), _name(login), _password(password), _indicatorMessage(idMessage) {}
	~User()							{}

	void set_name(std::string name) { _name = name; }
	const auto& get_name()			{ return _name; }

	auto set_password(std::string password) 
									{ _password = password; }
	const auto& get_password()		{ return _password; }

	void set_indicatorMessage(const long long indicatorMessage) //for method show
									{ _indicatorMessage = indicatorMessage; }
	const auto get_indicatorMessage()		
									{ return _indicatorMessage; }
};

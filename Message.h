#pragma once
#include <string>
#include <ctime>
static long long					idMessage{ 0 }; //metric long long - double

class IMessage
{
protected:
	const std::time_t				_date{};
	const long long					_idMessage{};

public:
	IMessage() 
		: _date(time(nullptr)), _idMessage(++idMessage) {}
	virtual ~IMessage()				{};
	const auto& get_date()			{ return _date; }
	const auto& get_idMessage()		{ return _idMessage; }
};

class Message : public IMessage
{
protected:
	const std::string		        _text;
	const long long					_sender{};  //id User sender (sistem = 0) // отправитель
	const long long					_recipient{};  //id User sender (ALL = 0) // получатель
	const bool				        _flagPrivacy{};


public:
	Message(const std::string text = "", const long long sender = 0, const long long recipient = 0, const bool Privat = false)
		: _text(text), _sender(sender), _recipient(recipient), _flagPrivacy(Privat) {}
	~Message() {}
	const auto& get_text()			{ return _text; }
	const auto& get_sender()		{ return _sender; }
	const auto& get_recipient()		{ return _recipient; }
	const bool get_flagPrivacy()	{ return _flagPrivacy; }
};


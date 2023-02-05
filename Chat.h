#include "Chat.h"

void Chat::creat_user(std::string login, std::string password)
{
	User newUser(login, password);
	_boxUsers.push_back(newUser);
	_currentUser = std::make_shared<User>(newUser);
}
std::string Chat::get_name_for_id(const long long id)
{
	if (id == 0) return ""; //NO NAME

	for (auto& element : _boxUsers)
	{
		if (element.get_idUser() == id)
		{
			return element.get_name();
		}
	}
	return ""; //NO NAME
}
const long long Chat::get_id_for_name(const std::string name)
{
	if (name == "0") return 0; //NO NAME

	for (auto& element : _boxUsers)
	{
		if (element.get_name() == name)
		{
			return element.get_idUser();
		}
	}
	return 0; //NO NAME
}
void Chat::set_currentUser(const User& authorizer) //for authorization
{
	_currentUser = std::make_shared<User>(authorizer);
	std::cout << "Authorization passed \n";
}
const bool Chat::check_login(const std::string& loginForCheck)
{
	for (auto& element : _boxUsers)
	{
		if (element.get_login() == loginForCheck)
		{
			return true;
		}
	}
	return false;
}
const bool Chat::check_password(const std::string& passwordForCheck)
{
	return false;
}
const bool Chat::check_name(const std::string& nameForCheck)
{
	for (auto& element : _boxUsers)
	{
		if (element.get_name() == nameForCheck)
		{
			return true;
		}
	}
	return false;
}
auto Chat::verification() //authorization
{
	std::string login;
	std::string password;
	std::cout
		<< "Log in to your account \n"
		<< "Login: ";
	std::cin.ignore();
	getline(std::cin, login);
	std::cout
		<< "Password: ";
	std::cin >> password;
	
	for (auto& element : _boxUsers)
	{
		if (login == element.get_login() && password == element.get_password())
		{
			set_currentUser(element);
			return true;
		}
	}
	std::cout << "Erorr login/password invalid \n";
	return false;
}
const std::string Chat::enter_login()
{
	std::cout << "Please enter your login for registration: ";
	std::string buferLogin;
	std::cin.ignore();
	getline(std::cin, buferLogin);

	if (buferLogin == "0") //0 breaks the program logic
	{
		std::cout << "0 not available \n";
		throw Login_creature();
	}

	if (check_login(buferLogin))
	{
		throw Login_creature(); //invalid login
	}

	std::cout << "Login heck! \n";
	return buferLogin;
}
const std::string Chat::enter_password()
{
	std::cout << "Set a password: ";
	std::string buferPassword;
	std::cin >> buferPassword;

	if (check_password(buferPassword))
	{
		throw Password_creature(); //invalid password
	}
	std::cout
		<< "Password heck! \n"
		<< "   *   *   *   *   *   *\n";
	return buferPassword;
}
void Chat::view_messages()
{
	for (auto element : _boxMessages)
	{
		if (element.get_idMessage() < _boxUsers.at(_currentUser->get_idUser()-1).get_indicatorMessage()) // view only new messages (+ always last)
		{
			continue;
		}

		//_boxUsers.at(_currentUser->get_idUser()-1).set_indicatorMessage(element.get_idMessage()); // for view only new messages

		if (element.get_flagPrivacy()) // check private
		{
			if (element.get_recipient() != _currentUser->get_idUser())
			{
				continue;
			}
		}

		std::string separator = element.get_flagPrivacy() ? "(Private): \n" : ": \n";

		std::cout
			<< get_name_for_id(element.get_sender())
			<< separator
			<< element.get_text() << "\n";
		std::cout << "__________________________________________________\n";

		if (element.get_flagPrivacy()) //reply to a private message
		{
			std::cout << "Reply to a private message? \n 0: NO \n 1: YES \n";
			bool answer{ false };
			std::cin >> answer;
			if (answer)
			{
				new_privat_message(element.get_sender());
			}
		}
		//_boxUsers.at(_currentUser->get_idUser()-1).set_indicatorMessage(element.get_idMessage());// тут пишем переместить указатель
	}
	_boxUsers.at(_currentUser->get_idUser() - 1).set_indicatorMessage(idMessage); // for view only new messages
}
void Chat::sending_public_message()
{
	std::cout << "Enter a message \n";
	std::string textMessage;
	std::cin.ignore();
	getline(std::cin, textMessage);
	Message newMessage{ textMessage, _currentUser->get_idUser() };
	_boxMessages.push_back(newMessage);
}
void Chat::new_privat_message(long long addressee) /////////////////////////ответ не доходит
{
	if (addressee == 0)
	{
		bool off{ true };
		std::string recipientMessage; //addressee
		do
		{
			std::cout << "Введите имя получателя: \n";
			std::cin >> recipientMessage;

			if (recipientMessage == "0") {
				off = false; break;
			}

			if (!check_name(recipientMessage)) {
				std::cout << "Пользователь с именем " << recipientMessage << " не найден \n для выхода введите имя получателя: 0 \n";
				continue;
			}
			else {
				off = false;
			}

		} while (off);
	}

	std::string textMessage;
	std::cout << "Введите текст приватного сообщения: \n";
	std::cin >> textMessage;

	Message newMessage{ textMessage, _currentUser->get_idUser(), addressee, true };
	//Message newMessage{ textMessage, _currentUser->get_id(), get_id_for_name(recipientMessage), true };

	_boxMessages.push_back(newMessage);
}
const long long Chat::counter_new_message()
{
	long long counter{};
	for (auto& element : _boxMessages)
	{	//we don't count the old ones
		if (element.get_idMessage() <= _boxUsers.at(_currentUser->get_idUser() - 1).get_indicatorMessage())
		{
			continue;
		}
		//we do not consider private strangers
		if (element.get_flagPrivacy() && (element.get_recipient() != _currentUser->get_idUser() ) )
		{
			continue;
		}
		++counter;
	}
	return counter;
}
void Chat::registration()
{
	std::string buferLogin = enter_login();
	std::string buferPassword = enter_password();
	creat_user(buferLogin, buferPassword);
}
void Chat::working_session()
{
	if (_currentUser == nullptr) //erorr
	{
		std::cout << "Authorization error, contact the developer \n";
		return;
	}

	std::cout << "Authorized: " << _currentUser->get_login() << "\n";
	bool offWorkingSession{ true };
	char action{};
	do
	{
		std::cout
			<< "1 Show NEW ("
			<< counter_new_message()
			<< ") Messages \n"
			<< "2 Show ALL Messages (history) \n"
			<< "3 New Messages \n"
			<< "4 New private Messages \n"
			<< "0 Exit to the main menu \n";
		std::cin >> action;

		switch (action)
		{
		case '1':
			view_messages();
			break;

		case '2':
			_boxUsers.at(_currentUser->get_idUser() - 1).set_indicatorMessage(0);
			view_messages();
			break;

		case '3':
			sending_public_message();
			break;

		case '4':
			new_privat_message();
			break;

		case '0':
			system("cls");
			offWorkingSession = false;
			break;

		default:
			break;
		}
	} while (offWorkingSession);
}
void Chat::strart_menu()
{
	std::cout << "Welcome to the Chat! \n";
	bool offChat{ true };
	do
	{
		std::cout
			<< "1 - Log in to your account \n"
			<< "2 - Registration \n"
			<< "0 - Output (to the desktop) \n"
			<< "select: \n";
		char mode{};
		std::cin >> mode;
		system("cls");

		switch (mode)
		{
		case '1':
		{
			if (verification() )
			{
				system("cls");
				working_session();
			}
			break;
		}

		case '2':
			try
			{
				registration();
			}
			catch (const std::exception & e)
			{
				std::cout << e.what() << "\n";
			}
			break;

		case '0':
			offChat = false;
			std::cout << "Exit the program, see U later! \n";
			break;

		default:
			std::cout << "Input error. Repeat \n";
			break;
		}
	} while (offChat);
}

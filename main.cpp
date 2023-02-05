//Chat version 1.0 (05/02/2023)
//Evgeny Volkov for SkillFactory 
//Final project for the first training block
#include "Chat.h"
#include "Script.h"

int main()
{
	setlocale(0, ""); 
	
	Chat chat{ "Chat version 1.0" };
	
	test_Chat(chat); //test script (generated content)

	chat.strart_menu();

	return 0;
}

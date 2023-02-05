#pragma once

void test_Chat(Chat& chatRef)
{
	//generated content
	User Torvalds{ "1",	"1" };		//01 Linus Torvalds
	User Gates{ "Bill Gates",			"123" };		//02
	User Jobs{ "Steven Jobs",			"123" };		//03
	User Kaspersky{ "Eugene Kaspersky",	"J@#ua_0Rx" };	//04
	User Durov{ "Pavel Durov",			"123" };		//05
	User Volkov{ "Evgeny Volkov",		"123" };		//06 Evgeny Volkov
	chatRef.get_boxUsers().push_back(Torvalds);
	chatRef.get_boxUsers().push_back(Gates);
	chatRef.get_boxUsers().push_back(Jobs);
	chatRef.get_boxUsers().push_back(Kaspersky);
	chatRef.get_boxUsers().push_back(Durov);
	chatRef.get_boxUsers().push_back(Volkov);
	Message message_001("В чат добавлен Linus Torvalds.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_001);
	Message message_002("В чат добавлен Bill Gates.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_002);
	Message message_003("В чат добавлен Steven Jobss.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_003);
	Message message_004("В чат добавлен Eugene Kaspersky.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_004);
	Message message_005("В чат добавлен Pavel Durov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_005);
	Message message_006("В чат добавлен Evgeny Volkov.", 0, 0, false);
	chatRef.get_boxMessages().push_back(message_006);
	Message message_007("Привет парни! Вы уже слышали новость?", 1, 0, false);
	chatRef.get_boxMessages().push_back(message_007);
	Message message_008("Это про выход новой программы чат SF?", 2, 0, false);
	chatRef.get_boxMessages().push_back(message_008);
	Message message_009("Смотрел исходники на гитхабе, там кучя багов.", 4, 0, false);
	chatRef.get_boxMessages().push_back(message_009);
	Message message_010("Да, он очень сырой!", 5, 0, false);
	chatRef.get_boxMessages().push_back(message_010);
	Message message_011("Народ вообще то это учебный проект, и я еще только учусь!", 6, 0, false);
	chatRef.get_boxMessages().push_back(message_011);
	Message message_012("В этом чате даже нет сетевого протокола и базы данных", 1, 2, true);
	chatRef.get_boxMessages().push_back(message_012);
	Message message_013("Эти русские могут только тапочки делать, да водку пить.", 2, 1, true);
	chatRef.get_boxMessages().push_back(message_013);
	Message message_014("Я чую что разработчик чата SF далеко пойдет.", 4, 5, true);
	chatRef.get_boxMessages().push_back(message_014);
	Message message_015("Да у парня явно талант.", 5, 4, true);
	chatRef.get_boxMessages().push_back(message_015);
	Message message_016("Желаю успехов в учебе, товарищ!", 1, 6, true);
	chatRef.get_boxMessages().push_back(message_016);
	Message message_017("Если что, обращайся за помощью!", 2, 6, true);
	chatRef.get_boxMessages().push_back(message_017);
	Message message_018("Главное не забудь встроить защиту данных, безопасноть в приоритете!", 4, 6, true);
	chatRef.get_boxMessages().push_back(message_018);
	Message message_019("У тебя все получится!", 5, 6, true);
	chatRef.get_boxMessages().push_back(message_019);
	Message message_020("Всем кто потдержал в личку, спасибо!", 6, 0, false);
	chatRef.get_boxMessages().push_back(message_020);
}

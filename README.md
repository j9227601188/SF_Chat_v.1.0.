# SF_Chat_v.1.0.
RUSSIAN:
Итоговый проект по первому блоку обучения «Разработчик С++»  05/02/2023
Программа чат версия 1.0
Список разработчиков(1): Evgeny Volkov.
Реализованы классы Message, User, Chat, все с родительскими классами (для гибкости дальнейшего развития программы).
    Класс Message, интерфейс:
    get_text() – текст сообщения
    get_sender() - отправитель
    get_recipient() - получатель
    get_flagPrivacy() – флаг приватности сообщения
    кроме того, родительские методы:
    get_date() – дата создания
    get_idMessage() – уникальный id сообщения 
        Класс User, интерфейс:
        set/get_name() – имя
        set/get_password() – пароль
        set/get_indicatorMessage – указатель на последнее открытое сообщение (для счетчика новых сообщений)
        кроме того, родительские методы:
        get_login() - логин
        get_date() - пароль
        get_idUser() - уникальный id юзера
            Класс Chat, интерфейс:
            strart_menu() – стартовое меню
            registration() – регистрация нового аккаунта
            working_session() – рабочая сессия чата
Для отладки программы реализован скрипт (Script.h) загружающий в чат небольшой контент.
main.cpp 
    Генерирует объект Chat
    Запускает скрипт (Script.h) по наполнению контентом чата
    Запускает главное меню программы.
По всем вопросам обращайтесь к разработчику j9227601188@yandex.ru

ENGLISH(translated from Russian : Yandex translator):

Final project for the first block of training "C++ Developer" 05/02/2023
Chat program version 1.0
List of developers(1): Evgeny Volkov.
Implemented classes Message, User, Chat, all with parent classes (for flexibility of further development of the program).
    Message class, interface:
    get_text() – message text
    get_sender() - sender
    get_recipient() - recipient
    get_flagPrivacy() – message privacy flag
    in addition, parent methods:
    get_date() – creation date
    get_idMessage() – unique message id 
        User class, interface:
        set/get_name() – name
        set/get_password() – password
        set/get_indicatorMessage – pointer to the last opened message (for the counter of new messages)
        in addition, parent methods:
        get_login() - login
        get_date() - password
        get_idUser() - unique user id
            Chat class, interface:
            strart_menu() – start menu
            registration() – registration of a new account
            working_session() – chat working session
To debug the program, a script is implemented (Script.h) uploading small content to the chat.
main.cpp 
    Generates a Chat object
    Runs a script (Script.h) to fill the chat with content
    Launches the main menu of the program.
If you have any questions, please contact the developer j9227601188@yandex.ru

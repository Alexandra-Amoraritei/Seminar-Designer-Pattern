#include <QtWidgets/QApplication>
#include "chat_window.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ChatSession* session=new ChatSession();

    User user1{ "u1","Mara" };
    User user2{ "u2","Alina" };

    ChatWindow chat_window_1(session,user1);
    ChatWindow chat_window_2(session,user2);

    session->registerObserver(&chat_window_1);
    session->registerObserver(&chat_window_2);

    chat_window_1.show();
    chat_window_2.show();

    return a.exec();
}

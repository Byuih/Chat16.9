#include "Chat169.h"
int main() {
    int choice;

    while (true) {
        std::cout << "1. Регистрация\n";
        std::cout << "2. Логин\n";
        std::cout << "3. Отправить сообщение пользователю\n";
        std::cout << "4. Отправьте сообщение всем\n";
        std::cout << "5. Выход\n";
        std::cout << "Введите свой выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            RegisterUser();
            break;
        case 2: {
            std::string username, password;
            std::cout << "Введите имя пользователя: ";
            std::cin >> username;
            std::cout << "Введите пароль: ";
            std::cin >> password;

            bool authenticated = AuthenticateUser(username, password);

            if (authenticated) {
                std::cout << "Вход в систему успешен!\n";
            }
            else {
                std::cout << "Неверное имя пользователя или пароль!\n";
            }

            break;
        }
        case 3: {
            std::string sender, recipient, message;
            std::cout << "Введите имя пользователя отправителя: ";
            std::cin >> sender;
            std::cout << "Введите имя пользователя получателя: ";
            std::cin >> recipient;
            std::cout << "Введите сообщение: ";
            std::cin.ignore(); // ignore any remaining newline character
            std::getline(std::cin, message);

            SendMessageToUser(sender, recipient, message);
            break;
        }
        case 4: {
            std::string sender, message;
            std::cout << "Введите имя пользователя отправителя:";
            std::cin >> sender;
            std::cout << "Введите сообщение: ";
            std::cin.ignore(); // ignore any remaining newline character
            std::getline(std::cin, message);

            SendMessageToAllUsers(sender, message);
            break;
        }
        case 5:
            std::cout << "Выхожу...\n";
            return 0;
        default:
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
            break;
        }

        std::cout << std::endl;
    }
}
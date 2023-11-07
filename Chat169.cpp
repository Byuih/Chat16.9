#include "Chat169.h"
int main() {
    int choice;

    while (true) {
        std::cout << "1. �����������\n";
        std::cout << "2. �����\n";
        std::cout << "3. ��������� ��������� ������������\n";
        std::cout << "4. ��������� ��������� ����\n";
        std::cout << "5. �����\n";
        std::cout << "������� ���� �����: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            RegisterUser();
            break;
        case 2: {
            std::string username, password;
            std::cout << "������� ��� ������������: ";
            std::cin >> username;
            std::cout << "������� ������: ";
            std::cin >> password;

            bool authenticated = AuthenticateUser(username, password);

            if (authenticated) {
                std::cout << "���� � ������� �������!\n";
            }
            else {
                std::cout << "�������� ��� ������������ ��� ������!\n";
            }

            break;
        }
        case 3: {
            std::string sender, recipient, message;
            std::cout << "������� ��� ������������ �����������: ";
            std::cin >> sender;
            std::cout << "������� ��� ������������ ����������: ";
            std::cin >> recipient;
            std::cout << "������� ���������: ";
            std::cin.ignore(); // ignore any remaining newline character
            std::getline(std::cin, message);

            SendMessageToUser(sender, recipient, message);
            break;
        }
        case 4: {
            std::string sender, message;
            std::cout << "������� ��� ������������ �����������:";
            std::cin >> sender;
            std::cout << "������� ���������: ";
            std::cin.ignore(); // ignore any remaining newline character
            std::getline(std::cin, message);

            SendMessageToAllUsers(sender, message);
            break;
        }
        case 5:
            std::cout << "������...\n";
            return 0;
        default:
            std::cout << "�������� �����! ����������, ���������� �����.\n";
            break;
        }

        std::cout << std::endl;
    }
}
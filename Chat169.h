#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct User {
    std::string username;
    std::string password;
    std::string name;
};

std::vector<User> users;
std::vector<std::string> messages;

void RegisterUser() {
    User user;

    std::cout << "Введите имя пользователя: ";
    std::cin >> user.username;

    std::cout << "Введите пароль: ";
    std::cin >> user.password;

    std::cout << "Введите имя: ";
    std::cin >> user.name;

    users.push_back(user);

    std::cout << "Пользователь зарегистрирован успешно!\n";
}

bool AuthenticateUser(const std::string& username, const std::string& password) {
    auto it = std::find_if(users.begin(), users.end(), [&](const User& user) {
        return user.username == username && user.password == password;
        });

    return it != users.end();
}

void SendMessageToUser(const std::string& sender, const std::string& recipient, const std::string& message) {
    messages.push_back(sender + " -> " + recipient + ": " + message);
}

void SendMessageToAllUsers(const std::string& sender, const std::string& message) {
    for (const User& user : users) {
        messages.push_back(sender + " -> " + user.username + ": " + message);
    }
}

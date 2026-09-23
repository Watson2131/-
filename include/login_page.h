#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "page.h"
#include "pages.h"
#include "appstate.h"

// вход: логин/пароль сверяет с textpassword (1 строка пароль, 2 логин)
// итог: меню юзера, админка или перерисовка (return this), Y/y - выход со страницы
class LoginPage : public Page {
    AppState& s;
    Pages& p;
public:
    LoginPage(AppState& st, Pages& pp) : s(st), p(pp) {}

    void render() override {
        std::cout << "=== ВХОД ===\n";
        std::cout << "Для выхода введите Y/y\n\n";
        std::cout << "Введите логин: ";
    }

    Page* next() override {
        std::string nam;
        if (!(std::cin >> nam)) {             // ввод закрылся или сломался
            if (std::cin.eof()) return nullptr; // всё, конец
            return this;
        }
        if (nam == "Y" || nam == "y") {
            return p.menu;
        }

        std::ifstream in("textpassword");
        if (!in.is_open()) {
            std::cout << "Ошибка: не удалось открыть файл для чтения!\n";
            return this;
        }
        std::string passFile, nameFile;
        std::getline(in, passFile);   // сначала пароль
        std::getline(in, nameFile);   // потом логин
        in.close();

        if (nam != nameFile) {
            std::cout << "Такого пользователя не существует!\n";
            return this;
        }

        std::cout << "Введите пароль: ";
        std::string pas;
        std::cin >> pas;
        if (pas == "Y" || pas == "y") {
            return p.menu;
        }
        if (pas != passFile) {
            std::cout << "Неверный пароль!\n";
            return this;
        }

        std::cout << "Вход успешный!\n";
        s.currentUser.name = nam;
        s.currentUser.pass = pas;

        if (pas == "12344321" && nam == "admin") {
            return p.admin;   // это админ, шлём в админку
        }
        return p.userMenu;
    }
};
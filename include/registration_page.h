#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include "page.h"
#include "pages.h"
#include "appstate.h"
#include "coolproject.h"

// регистрация: имя, пароль и возраст, пишет в textpassword (пароль, потом имя)
// Y/y на первых двух этапах - выход обратно в меню
class RegistrationPage : public Page {
    AppState& s;
    Pages& p;
public:
    RegistrationPage(AppState& st, Pages& pp) : s(st), p(pp) {}

    void render() override {
        std::cout << "===== РЕГИСТРАЦИЯ =====\n";
        std::cout << "== Для выхода введите Y/y ==\n";
        std::cout << "== на первых двух этапах ==\n\n";
        std::cout << "Придумайте имя: ";
    }

    Page* next() override {
        std::string name;
        if (!(std::cin >> name)) {            // ввод закрылся или сломался
            if (std::cin.eof()) return nullptr; // всё, конец
            return this;
        }
        if (name == "Y" || name == "y") {
            return p.menu;
        }

        std::cout << "Придумайте пароль: ";
        std::string pass;
        std::cin >> pass;
        if (pass == "Y" || pass == "y") {
            return p.menu;
        }

        std::cout << "Введите возраст: ";
        int age;
        std::cin >> age;
        if (std::cin.fail()) {
            std::cout << "Возраст введен неверно. Повторите попытку!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return this;
        }

        s.nextId++;
        s.users.push_back(User(s.nextId, name, age, pass));

        std::ofstream wes("textpassword", std::ios_base::out);   // это пишет учётку в файл
        if (!wes.is_open()) {
            std::cout << "Ошибка: не удалось открыть файл для записи!\n";
        }
        wes << pass << "\n";
        wes << name << "\n";
        wes.close();

        std::cout << "Регистрация успешна!\n";
        return p.menu;
    }
};
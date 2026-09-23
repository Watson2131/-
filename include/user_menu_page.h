#pragma once
#include <iostream>
#include <limits>
#include "page.h"
#include "pages.h"
#include "appstate.h"

// меню залогиненного юзера. работает пока только выход (пункт 8),
// остальное - просто перерисовка
class UserMenuPage : public Page {
    AppState& s;
    Pages& p;
public:
    UserMenuPage(AppState& st, Pages& pp) : s(st), p(pp) {}

    void render() override {
        std::cout << "\n=== MINI SOCIAL ===\n";
        std::cout << "Привет, " << s.currentUser.name << "!\n\n";

        std::cout << "1. 📰 Лента\n";
        std::cout << "2. 👤 Мой профиль\n";
        std::cout << "3. 🔎 Найти пользователя\n";
        std::cout << "4. 👥 Друзья\n";
        std::cout << "5. 📝 Создать пост\n";
        std::cout << "6. 🔔 Уведомления\n";
        std::cout << "7. ⚙ Настройки\n";
        std::cout << "8. 🚪 Выйти\n";
        std::cout << "\nВвод: ";
    }

    Page* next() override {
        int choice2;
        if (!(std::cin >> choice2)) {         // ввод сломался или не число
            if (std::cin.eof()) return nullptr; // всё, конец
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return this;
        }

        switch (choice2) {
            case 8:
                return p.menu;   // выход из аккаунта
            default:
                return this;     // остальное не доделано, просто перерисовка
        }
    }
};
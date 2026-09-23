#pragma once
#include <iostream>
#include <limits>
#include "page.h"
#include "pages.h"

// главное меню: регистрация, вход, выход
class MainMenuPage : public Page {
    Pages& p;
public:
    MainMenuPage(Pages& pp) : p(pp) {}

    void render() override {
        std::cout << "=== MINI SOCIAL ===\n";
        std::cout << "\n1. Регистрация\n";
        std::cout << "2. Вход\n";
        std::cout << "3. Выйти\n";
        std::cout << "\nВвод: ";
    }

    Page* next() override {
        int choice;
        if (!(std::cin >> choice)) {          // ввод сломался или не число
            if (std::cin.eof()) return nullptr; // всё, конец
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return this;
        }

        switch (choice) {
            case 1:
                return p.registration;
            case 2:
                return p.login;
            case 3: {
                char y_n;
                std::cout << "Вы уверены?(y/n): ";
                std::cin >> y_n;

                if (y_n == 'y') {
                    std::cout << "Пока!";
                    return nullptr;   // ну всё, приложение закрывается
                }
                return this;
            }
            default:
                std::cout << "Неверный ввод!\n\n";
                return this;
        }
    }
};
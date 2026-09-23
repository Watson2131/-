#pragma once
#include <iostream>
#include "page.h"
#include "pages.h"

// админка, пока не доделана: рисует заголовок и валит в меню юзера
class AdminPage : public Page {
    Pages& p;
public:
    AdminPage(Pages& pp) : p(pp) {}

    void render() override {
        std::cout << "=== АДМИН ПАНЕЛЬ ===\n\n";
    }

    Page* next() override {
        return p.userMenu;   // это уводит в меню юзера
    }
};
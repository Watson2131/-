#include "appstate.h"
#include "pages.h"
#include "admin_page.h"
#include "login_page.h"
#include "registration_page.h"
#include "main_menu_page.h"
#include "user_menu_page.h"
#ifdef _WIN32
#include <windows.h>
#endif

// тут только main: создаёт страницы, связывает их и запускает цикл

int main() {
#ifdef _WIN32
    // это переключает консоль в UTF-8, иначе русские строки в винде хреново видны
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif

    AppState state;   // общие данные, висят между страницами

    // создание страниц один раз
    Pages pages;
    MainMenuPage menuPage(pages);
    LoginPage loginPage(state, pages);
    RegistrationPage registrationPage(state, pages);
    AdminPage adminPage(pages);
    UserMenuPage userMenuPage(state, pages);

    // связывание страниц
    pages.menu = &menuPage;
    pages.login = &loginPage;
    pages.registration = &registrationPage;
    pages.admin = &adminPage;
    pages.userMenu = &userMenuPage;

    runPages(&menuPage); // эта строчка запускает цикл страниц

    return 0;
}
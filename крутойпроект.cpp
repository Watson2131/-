#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

struct User {
    int id;
    string name;
    int age;
    string pass;

    User(int i, string n, int a, string p) {
        id = i;
        name = n;
        age = a;
        pass = p;
    }
};

void admin() {

}

void registration(vector<User>& users, int& nextId) {
    string name;
    int age;
    string pass;
    
    while(true) {
        cout << "===== РЕГИСТРАЦИЯ =====\n";
        cout << "== Для выхода введите Y ==\n";
        cout << "== на первых двух этапах ==\n\n";

        cout << "Придумайте имя: ";
        cin >> name;
        if(name == "Y") {
            break;
        }
        cout << "Придумайте пароль: ";
        cin >> pass;
        if(pass == "Y") {
            break;
        }
        cout << "Введите возраст: ";
        cin >> age;
        
        if (cin.fail()) {
            cout << "Возраст введен неверно. Повторите попытку!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        nextId++;

        cout << "Регистрация успешна!\n";
        users.push_back(User(nextId, name, age, pass));
        break;
    }
}

void menu(vector<User>& users, int& nextId) {
    int choice;

    // -------АВТОРИЗАЦИЯ-------

    cout << "=== MINI SOCIAL ===\n";
    cout << "\n1. Регистрация\n";
    cout << "2. Вход\n";
    cout << "3. Выйти\n";
    cout << "\nВвод: ";

    cin >> choice;

    // ---Система меню авторизации---
    switch(choice) {
        case 1:
            registration(users, nextId);
            break;
        case 2:
            break;
        case 3:
           char y_n;
           cout << "Вы уверены?(y/n): ";
           cin >> y_n;
           
           if(y_n == 'y') {
                cout << "Пока!";
                exit(0);
           } else if (y_n == 'n') {
                break;
           } else {
                cout << "Неверный ввод!\n\n";
                break;
           }
    // ---------------------------

    // ------------------
    }
}

void menu2() {
    cout << "меню\n";
}

int main() {
    vector<User> users;
    int nextId = 0;

    menu(users, nextId);

    return 0;
}
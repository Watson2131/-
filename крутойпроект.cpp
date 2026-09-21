#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
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
    cout << "=== АДМИН ПАНЕЛЬ ===\n\n";
}

bool login(vector<User>& users, int& nextId, User& currentUser) {
    ifstream in("textpassword");
    if (!in.is_open()) {
        cout << "Ошибка: не удалось открыть файл для чтения!\n";
    }
    string passFile, nameFile;
    getline(in, passFile);   // первая строка — пароль
    getline(in, nameFile);   // вторая строка — имя
    in.close();

    string pas, nam;
    while(true) {
        cout << "=== ВХОД ===\n";
        cout << "Для выхода введите Y/y\n\n";

        cout << "Введите логин: ";
        cin >> nam;
        if (nam == "Y" || nam == "y") {
            return false;
        }
        if(nam != nameFile) {
            cout << "Такого пользователя не сущевствует!\n";
            continue;
        }

        cout << "Введите пароль: ";
        cin >> pas;
        if (nam == "Y" || nam == "y") {
            return false;
        }
        if (pas != passFile) {
            cout << "Неверный пароль!\n";
            continue;
        }
        break;
    }
    cout << "Вход успешный!\n";
    currentUser.name = nam;
    currentUser.pass = pas;

    if (pas == "12344321" && nam == "admin") {
        admin();
    }
    return true;
}

void registration(vector<User>& users, int& nextId) {
    string name;
    int age;
    string pass;

    while (true) {
        cout << "===== РЕГИСТРАЦИЯ =====\n";
        cout << "== Для выхода введите Y/y ==\n";
        cout << "== на первых двух этапах ==\n\n";

        cout << "Придумайте имя: ";
        cin >> name;
        if (name == "Y" || name == "y") {
            break;
        }
        cout << "Придумайте пароль: ";
        cin >> pass;
        if (pass == "Y" || pass == "y") {
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
        users.push_back(User(nextId, name, age, pass));
        //wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww
        ofstream wes("textpassword", ios_base::out);
        if (!wes.is_open()) {
            cout << "Ошибка: не удалось открыть файл для записи!\n";
        }
        wes << pass << "\n";
        wes << name << "\n";
        wes.close();

        cout << "Регистрация успешна!\n";
        return;
    }
}

bool menu(vector<User>& users, int& nextId, User& currentUser) {
    int choice;

    cout << "=== MINI SOCIAL ===\n";
    cout << "\n1. Регистрация\n";
    cout << "2. Вход\n";
    cout << "3. Выйти\n";
    cout << "\nВвод: ";

    cin >> choice;

    switch (choice) {
        case 1:
            registration(users, nextId);
            break;
        case 2:
            if(login(users, nextId, currentUser)) {
                return true;
            }
            break;
        case 3: {
            char y_n;
            cout << "Вы уверены?(y/n): ";
            cin >> y_n;

            if (y_n == 'y') {
                cout << "Пока!";
                exit(0);
            }
            else if (y_n == 'n') {
                break;
            }
            else {
                cout << "Неверный ввод!\n\n";
                break;
            }
        }
    }
    return false;
}

void menu2(vector<User>& users, User& user) {
    int choice2;

    cout << "\n=== MINI SOCIAL ===\n";
    cout << "Привет, " << user.name << "!\n\n";

    cout << "1. 📰 Лента\n";
    cout << "2. 👤 Мой профиль\n";
    cout << "3. 🔎 Найти пользователя\n";
    cout << "4. 👥 Друзья\n";
    cout << "5. 📝 Создать пост\n";
    cout << "6. 🔔 Уведомления\n";
    cout << "7. ⚙ Настройки\n";
    cout << "8. 🚪 Выйти\n";
    cout << "\nВвод: ";
    cin >> choice2;
}



int main() {

    vector<User> users;
    User currentUser(0, "", 0, "");
    int nextId = 0;

    while (true) {
        if(menu(users, nextId, currentUser)) {
            break;
        }
    }
    menu2(users, currentUser);
    return 0;
}
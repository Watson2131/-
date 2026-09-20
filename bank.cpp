#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct BankUser {
    int id;
    string name;
    int balance;
    int age;
    string pass;

    BankUser(int i, string n, int b, int a, string p) {
        id = i;
        name = n;
        balance = b;
        age = a;
        pass = p;
    }
};

void registration(vector<BankUser>& users, int& nextId) {
    string reglogin;
    string regpass;
    int regage;

    cout << "Введите логин и пароль\n\n";
    cout << "Логин: ";
    cin >> reglogin;
    cout << "Пароль: ";
    cin >> regpass;
    cout << "Возраст: ";
    cin >> regage;
    nextId++;

    users.push_back(BankUser(nextId, reglogin, 0, regage, regpass));
}

void showUsers(vector<BankUser>& users) {
    for(int i = 0; i < users.size(); i++) {
        cout << "ID: " << users[i].id << endl;
        cout << "Логин: " << users[i].name << endl;
        cout << "Возраст: " << users[i].age << endl;
        cout << "Баланс: " << users[i].balance << endl;
        cout << "---------------------\n";
    }
}

void findUser(vector<BankUser>& users) {
    int findId;
    bool found = false;

    cout << "Введите ID: ";
    cin >> findId;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].id == findId) {
            found = true;
            cout << "Пользователь найден!\n\n";
            cout << "ID: " << users[i].id << endl;
            cout << "Логин: " << users[i].name << endl;
            cout << "Возраст: " << users[i].age << endl;
            cout << "Баланс: " << users[i].balance << endl;
        }
    }
    if (!found) {
        cout << "Пользователь не найден!\n\n";
    }
}

void pause() {
    string exit;

    cout << "\n\nЧтобы выйти введите любую клавишу: ";
    cin >> exit;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void deposit(vector<BankUser>& users) {
    int findId;
    int replenishment;
    string message;
    bool found = false;

    cout << "Введите ID: ";
    cin >> findId;

    cout << "Поиск...\n";

    for (int i = 0; i < users.size(); i++) {
        if (users[i].id == findId) {
            found = true;
            cout << "Пользователь найден!\n\n";
            cout << "Укажите причину пополнения: ";
            cin >> message;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "На сколько вы хотите пополнить баланс пользователя?\n";
            cout << "Ввод: ";
            cin >> replenishment;

            cout << "Процесс...\n";
            users[i].balance += replenishment;
            cout << "Успешно!\n";
            cout << "Новый баланс: " << users[i].balance << endl;
            cout << "Причина: " << message << endl;

            return;
        }
    }
    if (!found) {
        cout << "Пользователь не найден!\n";
    }
}

void withdraw(vector<BankUser>& users) {
    int findId;
    int withdrawal;
    string message;
    bool found = false;

    cout << "Введите ID: ";
    cin >> findId;

    cout << "Поиск...\n";

    for (int i = 0; i < users.size(); i++) {
        if (users[i].id == findId) {
            found = true;
            cout << "Пользователь найден!\n";
            cout << "ID: " << users[i].id << endl;
            cout << "Имя: " << users[i].name << endl;
            cout << "Баланс: " << users[i].balance << endl;
            cout << "Укажите причину снятия: ";
            cin >> message;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Сколько вы хотите снять с счета пользователя?\n";
            cout << "Ввод: ";
            cin >> withdrawal;
            if (users[i].balance >= withdrawal && withdrawal > 0) {
                cout << "Процесс...\n";
                users[i].balance -= withdrawal;
                cout << "Успешно!\n";
                cout << "Новый баланс пользователя: " << users[i].balance << endl;
                cout << "Причина: " << message << endl;
            } else if (users[i].balance < withdrawal) {
                cout << "Недостаточно средств!\n";
            } else {
                cout << "Неверный ввод!\n";
            }

            return;
        }
    }
    if (!found) {
        cout << "Пользователь не найден!\n";
        return;
    }
}

void transfer(vector<BankUser>& users) {
    int findId1;
    int findId2;
    int senderIndex = -1;
    int receiverIndex = -1;

    cout << "Введите ID отправителя: ";
    cin >> findId1;
    cout << "Введите ID получателя: ";
    cin >> findId2;

    for (int i = 0; i < users.size(); i++) {
        if (findId1 == users[i].id && findId2 == users[i].id) {
            cout << "Пользователи найдены\n";
            cout << users[i].name;
            cout << users[i].name;
        }
    }
}

int main() {
    int choice;
    int nextId = 0;
    vector<BankUser> users;
    
    while(true) {
        cout << "=== BANK ===\n\n";
        cout << "1. Создать пользователя\n";
        cout << "2. Найти пользователя по ID\n";
        cout << "3. Показать всех пользователей\n";
        cout << "4. Пополнить баланс\n";
        cout << "5. Снять деньги\n";
        cout << "6. Перевод\n";
        cout << "7. Выход\n\n";
        cout << "Ввод: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                registration(users, nextId);
                break;
            }
            case 2: {
                findUser(users);
                pause();
                break;
            }
            case 3: {
                cout << "=== Все пользователи ===\n\n";
                showUsers(users);
                pause();
                break;
            }
            case 4: {
                deposit(users);
                pause();
                break;
            }
            case 5: {
                withdraw(users);
                pause();
                break;
            }
            case 6: {
                transfer(users);
                pause();
                break;
            }
            case 7: {
                char y_n;
                cout << "Вы уверены(y/n)?: ";
                cin >> y_n;

                if (y_n == 'y') {
                    cout << "Пока!";
                    return 0;
                } else if (y_n == 'n') {
                    break;
                } else {
                    cout << "Неверный ввод!\n\n";
                }
            }
            default: {
                cout << "Неверный ввод!\n";
            }
        }
    }

    return 0;
}
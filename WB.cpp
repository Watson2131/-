#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Player {
    int money = 1000;

    Player(int m) {
        money = m;
    }
};

struct Tovar {
    string name;
    int price;

    Tovar(string n, int p) {
        name = n;
        price = p;
    }
};

void goods(vector<Tovar>& tovars, vector<Tovar>& shop, vector<Tovar>& inventory, Player& player) {
    int choice;
    shop.clear();

    for (int i = 0; i < 3; i++) {
        int random = rand() % tovars.size();
        shop.push_back(tovars[random]);
        cout << i + 1 << ". " << shop[i].name << ". Цена: " << shop[i].price << endl;
    }
    cout << "4. Выход\n";
    cout << "\nКакой товар хотите купить?\n";
    cout << "Ввод: ";
    cin >> choice;

    if (choice == 4) {
        return;
    }
    
    if (player.money >= shop[choice - 1].price) {
        cout << "Процесс...\n";
        player.money -= shop[choice - 1].price;
        inventory.push_back(shop[choice - 1]);
        cout << "Успешно!\n";
    } else if (player.money <= shop[choice - 1].price) {
        cout << "Процесс...\n";
        cout << "Недостаточно средств!\n";
    } else {
        cout << "Неверный ввод!\n";
    }
}

void pause() {
    string exit;

    cout << "\n\nЧтобы выйти введите любую клавишу: ";
    cin >> exit;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void guessing(Player& player) {
    int choice;

    cout << "=== Угадай число ===\n\n";
    cout << "Выберите сложность\n";
    cout << "1. Легкая\n";
    cout << "2. Средняя\n";
    cout << "3. Сложная\n";
    cout << "\nВвод: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int random1 = rand() % 10 + 1;
            int att1;
            bool guess = false;

            for (int i = 2; i >= 0; i--) {
                cout << "Напишите число от 1 до 10\n";
                cout << "Ввод: ";
                cin >> att1;

                if (att1 == random1) {
                    cout << "Победа! Число угадано!\n";
                    guess = true;
                    player.money += 1000;
                    cout << "Вам зачислено 1000Р!\n";
                    return;
                } else if (att1 > 10 || att1 < 1) {
                    cout << "Неверный ввод!\n";
                    i++;
                } else {
                    cout << "Неверно! Осталось " << i << " попыток!\n";
                    if (random1 > att1) {
                        cout << "Загаданное число больше!\n";
                    } else {
                        cout << "Загаданное число меньше!\n";
                    }
                }
            }
            if (!guess) {
                cout << "Вы проиграли 10Р!";
                player.money -= 10;
                cout << "Загаданное число: " << random1 << endl;
            }
            break;
        }
        case 2: {
            int random2 = rand() % 50 + 1;
            int att2;
            bool guess = false;

            for (int i = 4; i >= 0; i--) {
                cout << "Напишите число от 1 до 50\n";
                cout << "Ввод: ";
                cin >> att2;

                if (att2 == random2) {
                    cout << "Победа! Число угадано!\n";
                    guess = true;
                    player.money += 5000;
                    cout << "Вам зачислено 5000Р!";
                    return;
                } else if (att2 > 50 || att2 < 1) {
                    cout << "Неверный ввод!\n";
                    i++;
                } else {
                    cout << "Неверно! Осталось " << i << " попыток!\n";
                    if (random2 > att2) {
                        cout << "Загаданное число больше!\n";
                    } else {
                        cout << "Загаданное число меньше!\n";
                    }
                }
            }
            if (!guess) {
                cout << "Вы проиграли 10Р!";
                player.money -= 10;
                cout << "Загаданное число: " << random2 << endl;
            }
            break;
        }
        case 3: {
            int random3 = rand() % 100 + 1;
            int att3;
            bool guess = false;

            for (int i = 9; i >= 0; i--) {
                cout << "Напишите число от 1 до 100\n";
                cout << "Ввод: ";
                cin >> att3;

                if (att3 == random3) {
                    cout << "Победа! Число угадано!\n";
                    guess = true;
                    player.money += 10000;
                    cout << "Вам зачислено 10000Р!";
                    return;
                } else if (att3 > 100 || att3 < 1) {
                    cout << "Неверный ввод!\n";
                    i++;
                } else {
                    cout << "Неверно! Осталось " << i << " попыток!\n";
                    if (random3 > att3) {
                        cout << "Загаданное число больше!\n";
                    } else {
                        cout << "Загаданное число меньше!\n";
                    }
                }
            }
            if (!guess) {
                cout << "Вы проиграли 10Р!";
                player.money -= 10;
                cout << "Загаданное число: " << random3 << endl;
            }
            break;
        }
        default: {
            cout << "Неверный ввод!\n";
            break;
        }
    }
}

int main() {
    srand(time(0));
    char ch;

    //-------------------ТОВАРЫ-----------------------
    vector<Tovar> tovars;
    tovars.push_back(Tovar("Компьютер", 90900));
    tovars.push_back(Tovar("Телефон", 5590));
    tovars.push_back(Tovar("Штаны", 2990));
    tovars.push_back(Tovar("Рубашка", 2790));
    tovars.push_back(Tovar("Стул деревянный", 6690));
    tovars.push_back(Tovar("Дом", 770990));
    tovars.push_back(Tovar("Трусы", 590));
    tovars.push_back(Tovar("Фембой", 11990));
    tovars.push_back(Tovar("Коврик для мыши", 1990));
    tovars.push_back(Tovar("Компьютерная мышь", 3990));
    tovars.push_back(Tovar("Клавиатура", 4190));
    tovars.push_back(Tovar("Зарядка", 499));
    tovars.push_back(Tovar("Шторы", 9990));
    tovars.push_back(Tovar("Микрофон", 4990));
    tovars.push_back(Tovar("Кока-кола. Ящик (10 штук)", 1990));
    //------------------МЕНЮ------------------------------
    vector<Tovar> shop;
    vector<Tovar> inventory;

    Player player(1000);

    while(true) {
        int choice;

        cout << "=== WILDBERRIES ===\n";
        cout << "Баланс: " << player.money << "\n\n";
        cout << "1. Товары\n";
        cout << "2. Инвентарь\n";
        cout << "3. Мини игры\n";
        cout << "4. Выход\n\n";
        cout << "Ввод: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                goods(tovars, shop, inventory, player);
                pause();
                break;
            }
            case 2: {
                for (int i = 0; i < inventory.size(); i++) {
                    cout << inventory[i].name << ". Цена: " << inventory[i].price << endl;
                }
                pause();
                break;
            }
            case 3: {
                guessing(player);
                pause();
                break;
            }
            case 4: {
                cout << "Уверены что хотите выйти?\n\n";
                cout << "Ввод(y/n): ";
                cin >> ch;

                if (ch == 'y') {
                    cout << "Пока!";
                    return 0;
                } else if (ch == 'n') {
                    break;
                } else {
                    cout << "Неверный ввод!\n";
                    continue;
                }
            }
        }
    }

    return 0;
}
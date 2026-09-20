#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

struct Planet
{
    string name;
    int danger;
    int reward;

    Planet(string n, int d, int r)
    {
        name = n;
        danger = d;
        reward = r;
    }
};

struct Player
{
    string name;
    int money = 500;
    int fuel = 100;
    int energy = 80;
    int crew = 5;
    int level = 1;

    void stats()
    {
        cout << "Имя: " << name << endl;
        cout << "Деньги: " << money << endl;
        cout << "Топливо: " << fuel << endl;
        cout << "Энергия: " << energy << endl;
        cout << "Экипаж: " << crew << endl;
        cout << "Уровень: " << level << endl;
    }

    void dangerPlanet(Planet planet)
    {
        cout << "Проверка опасности...\n";
        int randDanger = rand() % 100 + 1;

        if (100 - planet.danger >= randDanger)
        {
            cout << "Успех!\n";
            cout << "Вы нашли " << planet.reward << " денег!\n";

            money += planet.reward;
        }
        else
        {
            cout << "Вы разрушили корабль!\n";
            cout << "- 30 топлива\n";
            cout << "- 20 энергия\n\n";

            fuel -= 30;
            energy -= 20;
        }
    }

    void fly(vector<Planet> &planets, Player& player)
    {
        int choicePlanet;

        cout << "Куда вы хотите полететь?\n";
        cout << "1. Марс. Опасность 30, заработок 100\n";
        cout << "2. Юпитер. Опасность 70, заработок 300\n";
        cout << "3. Земля. Опасность 10, заработок 50\n";
        cout << "Ввод: ";
        cin >> choicePlanet;

        switch (choicePlanet)
        {
            case 1:
            {
                if (player.fuel >= 0 && player.energy >= 0) {
                    cout << "Отправляемся на " << planets[0].name << endl;
                    dangerPlanet(planets[0]);
                } else {
                    cout << "В взлете отказано! Нету энергии или бензина!\n";
                }
                break;
            }
            case 2: 
            {
                if (player.fuel >= 0 && player.energy >= 0) {
                    cout << "Отправляемся на " << planets[1].name << endl;
                    dangerPlanet(planets[1]);
                } else {
                    cout << "В взлете отказано! Нету энергии или бензина!\n";
                }
                break;
            }
            case 3: 
            {
                if (player.fuel >= 0 && player.energy >= 0) {
                    cout << "Отправляемся на " << planets[2].name << endl;
                    dangerPlanet(planets[2]);
                } else {
                    cout << "В взлете отказано! Нету энергии или бензина!\n";
                }
                break;
            }
        }
    }
};

struct Station {
    int stLevel;

    Station(int l) {
        stLevel = l;
    }
};

void upgrade(Player& player, Station& station) {
    char upgrade;
    int price = 0;
    int addEnergy = 0;
    int addCrew = 0;

    cout << "Баланс: " << player.money << endl;
    if (price > 0) {
        cout << "Цена улучшения: " << price << endl;
    } else {
        cout << "Цена улучшения: 500\n";
    }

    cout << "Купить(y/n)?: ";
    cin >> upgrade;
    
    if (upgrade == 'y' && player.money >= 500) {
        station.stLevel++;
        price += 500;
        addEnergy += 50;
        addCrew += 3;

        cout << "Вы купили улучшение!\n";
        cout << "Ваш уровень: " << station.stLevel << endl;

        player.money -= price;
        player.energy += addEnergy;
        player.crew += addCrew;
    } else if (upgrade == 'n') {
        cout << "Выход...\n";
    } else if (player.money < 500) {
        cout << "Недостаточно средств!\n";
    } else {
        cout << "Ошибка!\n";
    }
}

void hello(Player &player)
{
    cout << "Привет юнный летчик! Как тебя зовут?\n";
    cin >> player.name;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Приветствую, " << player.name << "! Вот твоя космическая станция\n\n";
}

int main()
{

    srand(time(0));

    Player player;
    Station station(1);

    hello(player);

    vector<Planet> planets;
    planets.push_back(Planet("Марс", 30, 100));
    planets.push_back(Planet("Юпитер", 70, 300));
    planets.push_back(Planet("Земля", 10, 50));

    while (true)
    {
        int choice;

        cout << "=== Космическая станция ===\n\n";
        cout << "1. Полететь на планету\n";
        cout << "2. Купить ресурсы\n";
        cout << "3. Улучшить станцию\n";
        cout << "4. Посмотреть характеристики\n";
        cout << "5. Выход\n\n";
        cout << "Ввод: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            player.fly(planets, player);
            break;
        }
        case 2:
        {
            int shop;

            cout << "Ваш баланс: " << player.money << endl;

            cout << "=== МАГАЗИН ===\n\n";
            cout << "1. Топливо +50. 100 денег\n";
            cout << "2. Энергия +50. 80 денег\n";
            cout << "3. Нанять экипаж +1. 200 денег\n";
            cout << "4. Выйти\n\n";
            cout << "Ввод: ";
            cin >> shop;

            switch (shop)
            {
                case 1:
                {
                    if (player.money >= 100)
                    {
                        cout << "Покупка совершена успешно!\n";
                        player.fuel += 50;
                    } else {
                        cout << "Недостаточно средств!\n\n";
                    }
                    break;
                }
                case 2: {
                    if (player.money >= 80) {
                        cout << "Покупка совершена успешно!\n";
                        player.energy += 50;
                    } else {
                        cout << "Недостаточно средств!\n\n";
                    }
                    break;
                }
                case 3: {
                    if (player.money >= 200) {
                        cout << "Покупка совершена успешно!\n";
                        player.crew += 1;
                    } else {
                        cout << "Недостаточно средств!\n";
                    }
                    break;
                } 
                case 4: {
                    break;
                }
            }
            break;
        }
        case 3:
        {
            upgrade(player, station);
            break;
        }
        case 4:
        {
            char exit;
            player.stats();

            cout << "Введите любой символ для выхода\n";
            cout << "Ввод: ";
            cin >> exit;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            break;
        }
        case 5:
        {
            char choice2;

            cout << "Ты уверен?\n\n";
            cout << "Ввод(y/n): ";
            cin >> choice2;

            if (choice2 == 'y')
            {
                cout << "Пока!";
                return 0;
            }
            else if (choice2 == 'n')
            {
                continue;
            }
            else
            {
                cout << "Неверный ввод!\n";
            }
        }
        }
    }
    return 0;
}
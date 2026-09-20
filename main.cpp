#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Hero;

struct Monster
{
    string name;
    int hp;
    int damage;
    int rewardGold;
    int rewardXP;

    Monster(string n, int h, int d, int g, int xp)
    {
        name = n;
        hp = h;
        damage = d;
        rewardGold = g;
        rewardXP = xp;
    }

    void showStats()
    {
        cout << "== Монстр ==\n";
        cout << "Имя: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl;
    }

    void takeDamage(int damage)
    {
        hp -= damage;

        if (hp <= 0)
        {
            hp = 0;
            cout << name << " побежден!\n";
        }

        cout << "У " << name << " осталось " << hp << " HP!\n";
    }

    void attack(Hero &hero);
};

struct Hero
{
    string name;
    int hp;
    int damage;
    int potions;
    int gold;
    int level;
    int xp;

    Hero(string n, int h, int d, int p, int g)
    {
        name = n;
        hp = h;
        damage = d;
        potions = p;
        gold = g;
        level = 1;
        xp = 0;
    }

    void showStats()
    {
        cout << "== Герой ==\n";
        cout << "Имя: " << name << endl;
        cout << "HP: " << hp << endl;
        cout << "Damage: " << damage << endl;
        cout << "Gold: " << gold << endl;
        cout << "Level: " << level << endl;
        cout << "XP: " << xp << endl;
    }

    void attack(Monster &monster)
    {
        int attackDamage = rand() % 11 + 25;

        cout << name << " наносит " << attackDamage << " урона!\n";

        monster.takeDamage(attackDamage);

        if (monster.hp == 0)
        {
            gold += monster.rewardGold;
            xp += monster.rewardXP;

            cout << "Вы получили " << monster.rewardGold  << " золота!\n";

            cout << "Вы получили " << monster.rewardXP << " опыта!\n";
    }
    }

    void takeDamage(int damage)
    {
        hp -= damage;

        if (hp <= 0)
        {
            hp = 0;
            cout << name << " побежден!\n";
        }

        cout << "У " << name << " осталось " << hp << " HP!\n";
    }

    void drinkPotion()
    {
        if (hp == 100)
        {
            cout << "У вас уже полное здоровье!\n";
        }
        else if (potions <= 0)
        {
            cout << "У вас нету зелий!\n";
        }
        else
        {
            hp += 30;
            potions--;

            if (hp > 100)
            {
                hp = 100;
            }

            cout << "Зелий осталось: " << potions << endl;
            cout << "У вас " << hp << " HP\n";
        }
    }

    void checkLevelUp()
    {
        if (xp >= 100)
        {
            level++;
            xp = 0;

            hp += 20;
            damage += 5;

            cout << "Вы повысили уровень!\n";
            cout << "Теперь ваш уровень: " << level << endl;
            cout << "HP увеличено!\n";
            cout << "Урон увеличен!\n";
        }
    }
};

void Monster::attack(Hero &hero)
{
    if (hp > 0)
    {
        hero.takeDamage(damage);
    }
}

int main()
{
    srand(time(0));

    Hero hero("Watson", 100, 30, 3, 0);
    Monster monster("Орк", 80, 20, 20, 50);

    while (hero.hp > 0 && monster.hp > 0)
    {
        int choice;

        cout << "=== БОЙ ===\n";
        cout << "1. Атаковать\n";
        cout << "2. Выпить зелье\n";
        cout << "3. Показать характеристики\n";
        cout << "4. Магазин\n";
        cout << "5. Выход\n\n";
        cout << "Выбор: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            hero.attack(monster);

            if (monster.hp > 0)
            {
                monster.attack(hero);
            }

            if (monster.hp == 0)
            {
                int randomMonster = rand() % 3 + 1;

                switch (randomMonster)
                {
                case 1:
                {
                    monster = Monster("Орк", 80, 20, 20, 50);
                    break;
                }

                case 2:
                {
                    monster = Monster("Скелет", 60, 25, 30, 70);
                    break;
                }

                case 3:
                {
                    monster = Monster("Волк", 50, 30, 40, 100);
                    break;
                }
                }

                cout << "Появился " << monster.name << "!\n";
            }

            break;
        }

        case 2:
        {
            hero.drinkPotion();
            break;
        }

        case 3:
        {
            int choice2;

            cout << "1. Герой\n";
            cout << "2. Монстр\n\n";
            cout << "Выбор: ";
            cin >> choice2;

            switch (choice2)
            {
            case 1:
            {
                hero.showStats();
                break;
            }

            case 2:
            {
                monster.showStats();
                break;
            }

            default:
            {
                cout << "Неверный выбор!\n";
                break;
            }
            }

            break;
        }

        case 4:
        {
            int shop;

            cout << "=== МАГАЗИН ===\n";
            cout << "1. Купить зелье (+1) - 30 золота\n";
            cout << "2. Улучшить урон (+5) - 100 золота\n\n";
            cout << "Выбор: ";

            cin >> shop;

            switch (shop)
            {
            case 1:
            {
                if (hero.gold >= 30)
                {
                    hero.gold -= 30;
                    hero.potions++;
                    cout << "Зелье успешно куплено!";
                }
                else
                {
                    cout << "Недостаточно средств!";
                }

                break;
            }

            case 2:
            {
                if (hero.gold >= 100)
                {
                    hero.gold -= 100;
                    hero.damage += 5;
                    cout << "Урон увеличен до " << hero.damage << "!";
                }
                else
                {
                    cout << "Недостаточно средств!";
                }

                break;
            }

            default:
            {
                cout << "Неверный выбор!\n";
                break;
            }
            }

            break;
        }

        case 5:
        {
            cout << "Пока!";
            return 0;
        }

        default:
        {
            cout << "Неверный выбор!\n";
            break;
        }
        }
    }

    return 0;
}
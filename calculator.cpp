#include <iostream>

using namespace std;

int main()
{
    int n1;
    int n2;
    char znak;

    while (true)
    {
        cout << "Какой пример хотите решить?\n";
        cin >> n1 >> znak >> n2;

        if (znak == '+')
        {
            cout << n1 + n2;
        }
        else if (znak == '-')
        {
            cout << n1 - n2;
        }
        else if (znak == '*')
        {
            cout << n1 * n2;
        }
        else if (znak == '/')
        {
            cout << n1 / n2;
        }
        else
        {
            cout << "Неверное выражение!";
        }
    }
    return 0;
}
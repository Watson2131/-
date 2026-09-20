#include <iostream>
#include <string>
#include <vector>

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

    cout << "Придумайте имя: ";
    cin >> name;
    cout << "Придумайте пароль: ";
    cin >> pass;
    cout << "Введите возраст: ";
    cin >> age;

    nextId++;

    users.push_back(User(nextId, name, age, pass));
}

int main() {
    int choice;
    vector<User> users;
    int nextId = 0;
    
    return 0;
}
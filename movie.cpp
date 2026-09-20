#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Movie {
    int id;
    string name;
    string genre;
    int duration;
    int age;
    int seats;
    int price;

    Movie(int i, string n, string g, int d, int a, int s, int p) {
        id = i;
        name = n;
        genre = g;
        duration = d;
        age = a;
        seats = s;
        price = p;
    }
};

struct User {
    int id;
    string name;
    int age;

    User(int i, string n, int a) {
        id = i;
        name = n;
        age = a;
    }
};

struct Ticket
{
    int id;
    int userId;
    int movieId;
};

void addMovie(vector<Movie>& movies, int& nextId) {
    int id;
    string name;
    string genre;
    int duration;
    int age;
    int seats;
    int price;

    nextId++;
    cout << "Введите название фильма: ";
    cin >> name;
    cout << "Введите жанр: ";
    cin >> genre;
    cout << "Введите длительность: ";
    cin >> duration;
    cout << "Введите возрастное ограничение: ";
    cin >> age;
    cout << "Введите кол-во мест: ";
    cin >> seats;
    cout << "Введите цену билета: ";
    cin >> price;

    movies.push_back(Movie(nextId, name, genre, duration, age, seats, price));
}

int main() {

    int nextId = 0;

    vector<Movie> movies;
    vector<User> users;
    vector<Ticket> tickets;

    return 0;
}
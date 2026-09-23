#pragma once
#include <string>
struct User {
    int id;
    std::string name;
    int age;
    std::string pass;

    User(int i, std::string n, int a, std::string p) {
        id = i;
        name = n;
        age = a;
        pass = p;
    }
};
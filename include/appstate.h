#pragma once
#include <vector>
#include "coolproject.h"

// общие данные, которые таскают все страницы: юзеры, счётчик id и кто залогинен
struct AppState {
    std::vector<User> users;                     // все юзеры
    int nextId = 0;                              // счётчик для id нового юзера
    User currentUser = User(0, "", 0, "");       // кто залогинен
};
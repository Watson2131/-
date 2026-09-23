#pragma once
#include "page.h"

// все страницы, main заполняет эти поля,
// а страницы по указателям переключаются между экранами
struct Pages {
    Page* menu = nullptr;
    Page* login = nullptr;
    Page* registration = nullptr;
    Page* admin = nullptr;
    Page* userMenu = nullptr;
};
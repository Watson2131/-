# CoolProject — MINI SOCIAL

Консольная мини‑социальная сеть на C++: регистрация, вход и меню
пользователя. Учебный проект для отработки работы с консолью, файлами,
`std::vector` и пользовательской структурой данных.

## Возможности

- **Регистрация** — имя, пароль и возраст; учётные данные сохраняются в файл `textpassword`.
- **Вход** — проверка логина и пароля по данным из файла.
- **Админ‑панель** — открывается при входе под `admin` / `12344321`.
- **Меню пользователя** — лента, профиль, поиск, друзья, посты, уведомления, настройки и выход.
- **Русский текст в консоли Windows** — приложение переключает консоль в кодировку UTF‑8 (`SetConsoleOutputCP`).
- **Абстракция страниц** — каждый экран (меню, вход, регистрация, админ‑панель) — это класс‑наследник `Page` из `include/page.h`; переходы между экранами делаются через `next()`, цикл страниц запускается функцией `runPages()`.

## Требования

| Компонент  | Версия                              |
|------------|-------------------------------------|
| Windows    | 10/11                               |
| Компилятор | MSYS2 UCRT64 `g++` (GCC 16.1.0+)    |
| Отладчик   | MSYS2 UCRT64 `gdb` (17.2+)          |
| VS Code    | актуальная + расширение «C/C++» (cpptools) |

## Сборка

Клавиша **Ctrl+Shift+B** в VS Code (задача «Сборка coolproject (static)»):

```
C:\msys64\ucrt64\bin\g++.exe -fdiagnostics-color=always -static -g -I include src\coolproject.cpp -o coolproject.exe
```

Вручную из терминала:

```
C:\msys64\ucrt64\bin\g++.exe -std=c++17 -g -static -I include src\coolproject.cpp -o coolproject.exe
```

> Флаг `-static` делает exe автономным — ему не нужны DLL из `C:\msys64\ucrt64\bin`.

## Запуск

```
.\coolproject.exe
```

Учётные данные хранятся в `textpassword` (первая строка — пароль, вторая — логин).
По умолчанию: логин **Anen**, пароль **root**. Это учебный пример, поэтому
пароли хранятся в открытом виде (не используйте так в реальных проектах).

## Отладка в VS Code

1. Откройте `src/coolproject.cpp`.
2. Поставьте точку останова.
3. Нажмите **F5** — сначала выполнится задача сборки, затем стартует gdb
   с pretty-printing (`-enable-pretty-printing`).

Конфигурации: `.vscode/launch.json` (запуск), `.vscode/tasks.json` (сборка),
`.vscode/c_cpp_properties.json` (IntelliSense).

> **Важно:** имена файлов — только латиницей. Отладчик (cppdbg + gdb) под
> русской локалью Windows некорректно обрабатывает пути с кириллицей.

## Структура проекта

```
src/coolproject.cpp        — точка входа: main() (создание и связка страниц)
include/page.h             — абстракция страницы (Page) и цикл runPages()
include/appstate.h         — общие данные приложения (AppState)
include/pages.h            — связка всех страниц (Pages)
include/admin_page.h       — страница «Админ-панель»
include/login_page.h       — страница «Вход»
include/registration_page.h — страница «Регистрация»
include/main_menu_page.h   — страница «Главное меню»
include/user_menu_page.h   — страница «Меню пользователя»
include/coolproject.h      — структура User
textpassword               — хранилище логина и пароля
.vscode/                   — настройки IntelliSense, сборки и отладки
README.md                  — описание проекта
CHANGELOG.md               — история изменений
```
#include "Menu.hpp"
#include <iostream>
#include <limits>

Menu::Menu(const std::vector<MenuItem>& items) : items(items) {}

void Menu::display() {
    if (items.empty()) {
        std::cout << "Меню пусто. Нет доступных действий.\n";
        return;
    }

    bool running = true;
    while (running) {
        std::cout << "\nВыберите действие:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << i << " - " << items[i].name << "\n";
        }

        int choice = getUserChoice();
        if (choice >= 0 && choice < items.size()) {
            items[choice].action();
        } else {
            std::cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }
}

int Menu::getUserChoice() {
    int choice;
    while (true) {
        std::cout << "Введите номер действия (0-" << items.size() - 1 << "): ";
        if (std::cin >> choice) {
            return choice;
        } else {
            std::cout << "Неверный ввод. Пожалуйста, введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void mainMenu() {
    Menu menu({
        {"Изучать программирование", studyProgrammingMenu},
        {"Пойти играть в футбол", []() { std::cout << "Вы выбрали пойти играть в футбол. Программа завершена.\n"; std::exit(0); }}
    });
    menu.display();
}

void studyProgrammingMenu() {
    Menu menu({
        {"Изучать языки программирования", []() { std::cout << "Изучаем языки программирования...\n"; }},
        {"Алгоритмы и структуры", []() { std::cout << "Изучаем алгоритмы и структуры...\n"; }},
        {"Другие технологии", otherTechnologiesMenu},
        {"Выйти в главное меню", mainMenu}
    });
    menu.display();
}

void otherTechnologiesMenu() {
    Menu menu({
        {"Базы данных", []() { std::cout << "Изучаем базы данных...\n"; }},
        {"Многопоточное программирование", []() { std::cout << "Изучаем многопоточное программирование...\n"; }},
        {"Сетевые технологии", []() { std::cout << "Изучаем сетевые технологии...\n"; }},
        {"Выйти в предыдущее меню", studyProgrammingMenu}
    });
    menu.display();
}
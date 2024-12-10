#ifndef MENU_HPP
#define MENU_HPP

#include <functional>
#include <string>
#include <vector>

struct MenuItem {
    std::string name;
    std::function<void()> action;
};

class Menu {
public:
    Menu(const std::vector<MenuItem>& items);
    void display();

private:
    std::vector<MenuItem> items;
    int getUserChoice();
};

void mainMenu();
void studyProgrammingMenu();
void otherTechnologiesMenu();

#endif // MENU_HPP
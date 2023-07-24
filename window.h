#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include "Hospital_Management.h"

class Window {
public:
    Window();
    void run();

private:
    void drawText(const std::string& text, int size, float x, float y, const sf::Color& color = sf::Color::Black);
    void drawButton(const std::string& label, int size, float x, float y, bool isSelected);
    void handleEvents();
    void update();
    void render();

    sf::RenderWindow window;
    Hospital_Management manage;
    bool isAddStaffSelected;
    bool isShowStaffListSelected;
    bool isEditStaffInfoSelected;
    bool isSearchStaffSelected;
    bool isCalculateSalarySelected;
};

#endif // WINDOW_H
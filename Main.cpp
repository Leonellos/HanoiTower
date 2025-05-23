// main.cpp
#include "Hanoi.h"
#include <iostream>


int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Введите число дисков: ";
    std::cin >> n;
    Hanoi game(n);
    game.setDelay(1000);
    game.display();       // начальное состояние
    game.solve();         // решить задачу
    return 0;
}

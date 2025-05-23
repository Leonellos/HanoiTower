// main.cpp
#include "Hanoi.h"
#include <iostream>
#include <chrono>
#include <thread>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "������� ����� ������: ";
    std::cin >> n;
    Hanoi game(n);
    game.setDelay(1000);
    game.display();       // ��������� ���������
    game.solve();         // ������ ������
    return 0;
}

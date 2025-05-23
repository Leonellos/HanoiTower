// Hanoi.cpp
#include "Hanoi.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>

Hanoi::Hanoi(int numDisks)
    : numDisks_(numDisks), pegs_(3), numSteps_(0), numRecSteps_(0), delay_(1000)
{
    for (int i = numDisks_; i >= 1; --i) {
        pegs_[0].push(i);
    }
}

void Hanoi::setDelay(int delay) { delay_ = delay; }

void Hanoi::moveDisk(int from, int to) {
    // Проверка индексов
    if (from < 0 || from > 2 || to < 0 || to > 2) {
        throw std::out_of_range("Индекс штыря должен быть от 0 до 2");
    }
    // Проверка наличия диска на 'from'
    if (pegs_[from].empty()) {
        throw std::logic_error("Нечего перемещать: штык 'from' пуст");
    }
    // Правило: нельзя класть больший на меньший
    int moving = pegs_[from].top();
    if (!pegs_[to].empty() && pegs_[to].top() < moving) {
        throw std::logic_error("Нельзя класть больший диск на меньший");
    }
    // Выполнить перемещение
    moveDisk_(from, to);
    numSteps_++;
    display();
}

void Hanoi::moveDisk_(int from, int to) {
    int disk = pegs_[from].top();
    pegs_[from].pop();
    pegs_[to].push(disk);
}

void Hanoi::display() const {
    // Очистить экран и установить курсор в начало
    std::cout << "\033[2J\033[H";

    int width = numDisks_ * 2 - 1;      // максимальная ширина диска
    int spacing = 2;                    // промежуток между штырями

    // Подготовить для каждого штыка вектор дисков от нижнего к верхнему
    std::vector<std::vector<int>> levels(3);
    for (int p = 0; p < 3; ++p) {
        std::stack<int> tmp = pegs_[p];
        std::vector<int> disks;
        while (!tmp.empty()) {
            disks.push_back(tmp.top());
            tmp.pop();
        }
        levels[p] = disks;
    }

    // Для каждого строкового уровня (0 — сверху, numDisks_-1 — снизу)
    for (int row = 0; row < numDisks_; ++row) {
        for (int p = 0; p < 3; ++p) {
            int diskSize = 0;
            int pegHeight = levels[p].size();
            int emptyRows = numDisks_ - pegHeight;
            if (row >= emptyRows) {
                // соответствующий индекс в levels[p]
                diskSize = levels[p][row - emptyRows];
            }
            if (diskSize > 0) {
                int dwidth = diskSize * 2 - 1;
                int pad = (width - dwidth) / 2;
                std::cout << std::string(pad, ' ')
                    << std::string(dwidth, '=')
                    << std::string(width - pad - dwidth, ' ');
            }
            else {
                int pad = (width - 1) / 2;
                std::cout << std::string(pad, ' ')
                    << '|'
                    << std::string(width - pad - 1, ' ');
            }
            if (p < 2) std::cout << std::string(spacing, ' ');
        }
        std::cout << '\n';
    }

    // Основание
    for (int p = 0; p < 3; ++p) {
        std::cout << std::string(width, '-');
        if (p < 2) std::cout << std::string(spacing, ' ');
    }
    std::cout << "\n";
    if (numSteps_ > 0) {
        std::cout << "Количество шагов:\t" << numSteps_ << std::endl;
    }
    if (numRecSteps_ > 0) {
        std::cout << "Количество шагов эталонным решением:\t" << numRecSteps_ << std::endl;
    }
    std::cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_));
}

void Hanoi::solve(int delay) {
    solveRecursive(numDisks_, 0, 1, 2);
}

void Hanoi::solveRecursive(int n, int from, int aux, int to) {
    if (n <= 0) return;
    solveRecursive(n - 1, from, to, aux);
    moveDisk_(from, to);
    numRecSteps_++;
    display();
    solveRecursive(n - 1, aux, from, to);
}
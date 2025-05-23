// Hanoi.h
#ifndef HANOI_H
#define HANOI_H

#include <vector>
#include <stack>

class Hanoi {
public:
    explicit Hanoi(int numDisks);
    // Перенести один диск с штыка 'from' на штык 'to'
    void moveDisk(int from, int to);
    // Рекурсивно решить задачу
    void solve(int delay = 1000);
    // Отобразить текущее состояние в консоль
    void display() const;
    // Задержка отрисовки в милисекундах
    void setDelay(int delay);

private:
    std::vector<std::stack<int>> pegs_;  // три штыка
    int numDisks_;                       // общее число дисков
    size_t numSteps_;                   // число шагов
    size_t numRecSteps_;                // число шагов рекурсивным методом
    int delay_;
    // передвинуть диск
    void moveDisk_(int from, int to);
    // Вспомогательный рекурсивный метод
    void solveRecursive(int n, int from, int aux, int to);
};

#endif // HANOI_H
// Hanoi.h
#ifndef HANOI_H
#define HANOI_H

#include <vector>
#include <stack>

class Hanoi {
public:
    explicit Hanoi(int numDisks);
    // ��������� ���� ���� � ����� 'from' �� ���� 'to'
    void moveDisk(int from, int to);
    // ���������� ������ ������
    void solve(int delay = 1000);
    // ���������� ������� ��������� � �������
    void display() const;
    // �������� ��������� � ������������
    void setDelay(int delay);

private:
    std::vector<std::stack<int>> pegs_;  // ��� �����
    int numDisks_;                       // ����� ����� ������
    size_t numSteps_;                   // ����� �����
    size_t numRecSteps_;                // ����� ����� ����������� �������
    int delay_;
    // ����������� ����
    void moveDisk_(int from, int to);
    // ��������������� ����������� �����
    void solveRecursive(int n, int from, int aux, int to);
};

#endif // HANOI_H
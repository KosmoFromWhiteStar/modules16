#include <iostream>
#include <bitset>


enum note
{
    DO = 1,   // 00000001
    RE = 2,   // 00000010
    MI = 4,   // 00000100
    FA = 8,   // 00001000
    SOL = 16, // 00010000
    LA = 32,  // 00100000
    SI = 64   // 01000000
};

int main() {
    std::cout << "Ex 4\n";
    std::cout << "Input songs";
    int melody[12] = { 0 }, temp = 0;
    for (int i = 0; i < 12; i++) std::cin >> melody[i];
    for (int i = 0; i < 12; i++)
    {
        if (melody[i] &note::DO)
        {
            std::cout << "DO ";
        }
        if (melody[i] & note::RE)
        {
            std::cout << "RE ";
        }
        if (melody[i] & note::MI)
        {
            std::cout << "MI ";
        }
        if (melody[i] & note::FA)
        {
            std::cout << "FA ";
        }
        if (melody[i] & note::SOL)
        {
            std::cout << "SOl ";
        }
        if (melody[i] & note::LA)
        {
            std::cout << "LA ";
        }
        if (melody[i] & note::SI)
        {
            std::cout << "SI ";
        }
        std::cout << " ";
    }
}
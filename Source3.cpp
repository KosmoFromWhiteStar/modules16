#include <iostream>
#include <bitset>

int corrector_inputing(int allowed_values_from, int allowed_values_up_to)
{
    bool chek = false;
    int temp_ = 0;
    do {
        std::cin >> temp_;
        chek = (allowed_values_from <= temp_ && temp_ <= allowed_values_up_to); // if num between allowed values true
        if (!chek)
        {
            std::cerr << "Invalid numeber\nTry again\n";

        }
    }
    while (!chek);
    return temp_;
}

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
    std::cout << "Input songs\nEvery num space num\n12 notes";

    int _shift_[12] = { 0 };
    int melody[12] = { 0 };
    
    int _size_arr = sizeof(_shift_) / sizeof(int);

    for (int i = 0; i < _size_arr; i++)
    {
        _shift_[i] = corrector_inputing (1, 7);
        _shift_[i]--;
        melody[i]++;

        melody[i] = melody[i] << _shift_[i]; // shift 1 to needed position
    }

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
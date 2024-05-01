#include <iostream>
#include <stdio.h>
#include <map>
#include <windows.h>

#include "samp/samp.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    samp smpl(samp::MODE::Small);

    size_t n = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> smpl;
    }
    std::cout << "n= " << smpl.Count() << std::endl;
    std::cout << smpl << std::endl;

    std::cout << "Частоты" << std::endl;
    smpl.PrintFreq();
    std::cout << std::endl;
    std::cout << "Выборочное среднее (X): " << smpl.SampAverage() << std::endl;
    std::cout << "Дисперсия: " << smpl.Dispersion() << std::endl;
    std::cout << "Испрасленная дисперсия: " << smpl.FixDispersion() << std::endl;
    std::cout << "Среднее квадратическое откланение: " << smpl.AverageSQRTDev() << std::endl;
    std::cout << "Исправленное среднее квадратическое откланение: " << smpl.FixAverageSQRTDev() << std::endl;
    std::cout << "Коэффициент ассиметрии: " << smpl.AsymmetryFactor() << std::endl;
    std::cout << "Эксцесса: " << smpl.ExcessFactor() << std::endl;
    std::cout << "Центральный момент 3 порядка: " << smpl.Order3CentralMoment() << std::endl;
    std::cout << "Центральный момент 4 порядка: " << smpl.Order4CentralMoment() << std::endl;
    std::cout << "Математическое ожидание: " << smpl.MathExpect() << std::endl;

    std::system("pause");

    return 0;
}
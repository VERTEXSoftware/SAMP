#include <iostream>
#include <stdio.h>
#include <map>
#include <windows.h>

#include "samp/samp.h"

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "SAMP" << std::endl;
    std::cout << "https://github.com/VERTEXSoftware/SAMP" << std::endl;
    std::cout << "Copyright (C) 2024 VERTEX Software by Sleptsov Vladimir" << std::endl;
    std::cout << "SPDX-License-Identifier: MIT" << std::endl;
    std::cout << "Version: 1.1.0-Release" << std::endl << std::endl;

    int mode = 0;

    while (mode!=1 && mode != 2) {
        std::cout << "1) Малая выборка" << std::endl;
        std::cout << "2) Большая выборка" << std::endl;
        std::cout << "Режим выборки: ";
        std::cin >> mode;
    }

    samp::MODE md = samp::MODE::Big;

    if (mode==1) {
        md = samp::MODE::Small;
    }else  if (mode == 2) {
        md = samp::MODE::Big;
    }

    samp smpl(md);


    size_t n = 0;
    std::cout << "Количество элементов (n=): ";
    std::cin >> n;
    std::cout << "Введите элементы:" << std::endl;

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
    std::cout << "Испрасленная дисперсия: " << smpl.Dispersion(samp::Fix) << std::endl;
    std::cout << "Среднее квадратическое откланение: " << smpl.AverageSQRTDev() << std::endl;
    std::cout << "Исправленное среднее квадратическое откланение: " << smpl.AverageSQRTDev(samp::Fix) << std::endl;
    std::cout << "Коэффициент ассиметрии: " << smpl.AsymmetryFactor() << std::endl;
    std::cout << "Эксцесса: " << smpl.ExcessFactor() << std::endl;
    std::cout << "Центральный момент 3 порядка: " << smpl.Order3CentralMoment() << std::endl;
    std::cout << "Центральный момент 4 порядка: " << smpl.Order4CentralMoment() << std::endl;
    std::cout << "Математическое ожидание: " << smpl.MathExpect() << std::endl;

    std::system("pause");

    return 0;
}
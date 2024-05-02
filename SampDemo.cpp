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
        std::cout << "1) ����� �������" << std::endl;
        std::cout << "2) ������� �������" << std::endl;
        std::cout << "����� �������: ";
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
    std::cout << "���������� ��������� (n=): ";
    std::cin >> n;
    std::cout << "������� ��������:" << std::endl;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> smpl;
    }
    std::cout << "n= " << smpl.Count() << std::endl;
    std::cout << smpl << std::endl;

    std::cout << "�������" << std::endl;
    smpl.PrintFreq();
    std::cout << std::endl;
    std::cout << "���������� ������� (X): " << smpl.SampAverage() << std::endl;
    std::cout << "���������: " << smpl.Dispersion() << std::endl;
    std::cout << "������������ ���������: " << smpl.Dispersion(samp::Fix) << std::endl;
    std::cout << "������� �������������� ����������: " << smpl.AverageSQRTDev() << std::endl;
    std::cout << "������������ ������� �������������� ����������: " << smpl.AverageSQRTDev(samp::Fix) << std::endl;
    std::cout << "����������� ����������: " << smpl.AsymmetryFactor() << std::endl;
    std::cout << "��������: " << smpl.ExcessFactor() << std::endl;
    std::cout << "����������� ������ 3 �������: " << smpl.Order3CentralMoment() << std::endl;
    std::cout << "����������� ������ 4 �������: " << smpl.Order4CentralMoment() << std::endl;
    std::cout << "�������������� ��������: " << smpl.MathExpect() << std::endl;

    std::system("pause");

    return 0;
}
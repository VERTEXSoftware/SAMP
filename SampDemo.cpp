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

    std::cout << "�������" << std::endl;
    smpl.PrintFreq();
    std::cout << std::endl;
    std::cout << "���������� ������� (X): " << smpl.SampAverage() << std::endl;
    std::cout << "���������: " << smpl.Dispersion() << std::endl;
    std::cout << "������������ ���������: " << smpl.FixDispersion() << std::endl;
    std::cout << "������� �������������� ����������: " << smpl.AverageSQRTDev() << std::endl;
    std::cout << "������������ ������� �������������� ����������: " << smpl.FixAverageSQRTDev() << std::endl;
    std::cout << "����������� ����������: " << smpl.AsymmetryFactor() << std::endl;
    std::cout << "��������: " << smpl.ExcessFactor() << std::endl;
    std::cout << "����������� ������ 3 �������: " << smpl.Order3CentralMoment() << std::endl;
    std::cout << "����������� ������ 4 �������: " << smpl.Order4CentralMoment() << std::endl;
    std::cout << "�������������� ��������: " << smpl.MathExpect() << std::endl;

    std::system("pause");

    return 0;
}
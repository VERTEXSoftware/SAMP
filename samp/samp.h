// https://github.com/VERTEXSoftware/SAMP
// Copyright (C) 2024 VERTEX Software by Sleptsov Vladimir
// SPDX-License-Identifier: MIT
// Version: 1.2.0-Release


#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

class samp {

public:
    enum MODE
    {
        Small = 0,
        Big = 1
    };

    enum Disp {
        Default=0,
        Fix=1,
    };

private:
	std::vector<double> arr;
    std::map<double, size_t> freq;
    MODE _md;

public:

    samp() {
        _md = MODE::Big;
    }
  
	samp(MODE md) {
        _md = md;
	}

    samp(MODE md,std::vector<double> input) {
        _md = md;
        arr = input;
        for (size_t i = 0; i < arr.size(); ++i) {
            if (freq.find(arr[i]) != freq.end()) {
                freq[arr[i]] ++;
            }
            else {
                freq[arr[i]] = 1;
            }
        }
    }

	~samp() {
        arr.clear();
        freq.clear();
	}

    MODE GetMode() {
        return _md;
    }

    size_t Count() {
        return arr.size();
    }


    void Clear() {
        arr.clear();
        freq.clear();
    }

    double MaxElement() {
        size_t max_index = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[max_index] < arr[i]) {
                max_index = i;
            }
        }
        return max_index;
    }

    double MinElement() {
        size_t min_index = 0;
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[min_index] > arr[i]) {
                min_index = i;
            }
        }
        return min_index;
    }



    size_t MaxFreq() {
        std::map<double, size_t>::iterator max_element = std::max_element(freq.begin(), freq.end(),[](const auto& a, const auto& b) {return a.second < b.second;});
        return max_element != freq.end() ? max_element->second : 0;
    }

    size_t MinFreq() {
        std::map<double, size_t>::iterator min_element = std::min_element(freq.begin(), freq.end(), [](const auto& a, const auto& b) {return a.second > b.second; });
        return min_element != freq.end() ? min_element->second : 0;
    }

    std::map<double, size_t>::iterator MaxElementFreq() {
        auto max_element = std::max_element(freq.begin(), freq.end(), [](const auto& a, const auto& b) {return a.second < b.second; });
        return max_element;
    }

    std::map<double, size_t>::iterator MinElementFreq() {
        auto min_element = std::min_element(freq.begin(), freq.end(), [](const auto& a, const auto& b) {return a.second > b.second; });
        return min_element;
    }

    //Выборочное среднее значение
    double SampAverage() {
        double accum = 0;

        if (_md == MODE::Small) {
            for (size_t i = 0; i < arr.size(); ++i) {
                accum += arr[i];
            }
        }
        else  if (_md == MODE::Big) {
            for (const auto& [num, count] : freq) {
                accum += num * count;
            }
           
        }
        return accum / arr.size();
    }

    //Дисперсия
    double Dispersion(Disp dism = Disp::Default) {
        double accum = 0;
        double sa = this->SampAverage();

        if (_md == MODE::Small) {
            for (size_t i = 0; i < arr.size(); ++i) {
                double tmp = (arr[i] - sa);
                accum += (tmp * tmp);
            }
         
        }
        else  if (_md == MODE::Big) {
            for (const auto& [num, count] : freq) {
                double tmp = (num - sa);
                accum += (tmp * tmp)* count;
            }
           
        }
        return accum / (arr.size() - (dism == Disp::Fix ? 1 : 0));
    }



    double Order3CentralMoment() {
        double accum = 0;
        double sa = this->SampAverage();
        if (_md == MODE::Small) {
            for (size_t i = 0; i < arr.size(); ++i) {
                double tmp = (arr[i] - sa);
                accum += (tmp * tmp * tmp);
            }
        }
        else  if (_md == MODE::Big) {
            for (const auto& [num, count] : freq) {
                double tmp = (num - sa);
                accum += (tmp * tmp * tmp) * count;
            }
        }
        return accum / arr.size();
    }

    double AverageSQRTDev(Disp dism = Disp::Default) {
        return sqrt(this->Dispersion(dism));
    }


    double Order4CentralMoment() {
        double accum = 0;
        double sa = this->SampAverage();
        if (_md == MODE::Small) {
            for (size_t i = 0; i < arr.size(); ++i) {
                double tmp = (arr[i] - sa);
                accum += (tmp * tmp * tmp * tmp);
            }
        }
        else  if (_md == MODE::Big) {
            for (const auto& [num, count] : freq) {
                double tmp = (num - sa);
                accum += (tmp * tmp * tmp * tmp) * count;
            }
        }

        return accum / arr.size();
    }

    double AsymmetryFactor(Disp dism= Disp::Default) {
        double fd = this->Dispersion(dism);
        return this->Order3CentralMoment() / (fd * fd * fd);
    }

    double ExcessFactor(Disp dism = Disp::Default) {
        double fd = this->Dispersion(dism);
        return (this->Order4CentralMoment() / (fd * fd * fd * fd))-3;
    }

    //?
    double MathExpect() {
        double accum = 0;
        for (const auto& [num, count] : freq) {
            accum += num * count;
        }
        return accum/ arr.size();
    }

    void AddElement(double d) {
        arr.push_back(d);

        if (freq.find(d) != freq.end()) {
            freq[d] ++;
        }
        else {
            freq[d] = 1;
        }

    }

    void DelElement(size_t i) {
        if (i < 0 && i >= arr.size()) { return; }
        double elm = arr[i];
        arr.erase(arr.begin() + i);

        if (freq.find(elm) != freq.end()) {
            freq[elm] --;
        }
    }

    void SetElement(size_t i, double d) {
        if (i<0 && i >= arr.size()) { return; }
        arr[i]=d;
        if (freq.find(d) != freq.end()) {
            freq[d]++;
        }
        else {
            freq[d] = 1;
        }
    }

    double GetElement(size_t i) {
        if (i < 0 && i >= arr.size()) { return 0; }
        return arr[i];
    }

    friend std::istream& operator>>(std::istream& input, samp& obj) {
        double tmp = 0;
        input >> tmp;
        obj.arr.push_back(tmp);
        if (obj.freq.find(tmp) != obj.freq.end()) {
            obj.freq[tmp] ++;
        }
        else {
            obj.freq[tmp] = 1;
        }
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const samp& obj) {
        for (size_t i = 0; i < obj.arr.size();++i) {
            output << obj.arr[i]<<" ";
        }
        return output;
    }

    void PrintAll() {
        for (size_t i = 0; i < arr.size(); ++i) {
            std::cout << arr[i] << " ";
        }
    }

    void PrintFreq() {
        for (const auto& [num, count] : freq) {
            std::cout <<"["<< num <<":"<< count<< "]";
        }
    }

    void PrintMulLines() {
        for (size_t i = 0;i< arr.size(); ++i) {
            std::cout << arr[i] << " ";
            if ((i + 1) % 15 == 0) 
                std::cout << std::endl;
        }
    }


};
/*
 * Genetic Algorithm 
 * Differential Evolution 
 * lgruelas@hotmail.com
 * 
 * to compile please une c++11 flags
 * /*
 * Copyright 2016 Germán Ruelas
 * Author: Germán Ruelas Luna
 * Licence: GPL version 3
 * 
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include "Ind.h"

using namespace std;

template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
    os << "[ ";
    for (unsigned int i = 0; i < rhs.size(); ++i)
        os << rhs[i] << " ";
    os << "]";
    return os;
}

int main()
{
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<float> distr(0.0, 1.0);
    
    int lambda = 200;
    int max_iter = 20000;
    
    vector<Ind> poblacion;
    
    for (int i = 0; i < lambda; i++)
    {
        Ind nuevo_individuo(distr(eng), distr(eng), distr(eng));
        poblacion.push_back(nuevo_individuo);
    }
    
    for (auto x : poblacion)
    {
        cout << x.getVariables() << endl;
    }
    
    vector<int> data;
    ifstream input;
    input.open("data2.csv");
    int dato;
    while (input >> dato)
    {
        data.push_back(dato);
    }
    
    cout << data << endl;
    
    return 0;
}

/*
 * Genetic Algorithm 
 * Differential Evolution 
 * Germán Ruelas Luna
 * lgruelas@hotmail.com
 * 
 * to compile please une c++11 flags
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include "Ind.h"


template <class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& rhs)
{
    os << "[ ";
    for (unsigned int i = 0; i < rhs.size(); ++i)
        os << rhs[i] << " ";
    os << "]";
    return os;
}

template <class T> std::vector<T> range (T n)
{
        std::vector<T> toReturn(n, 0);
        for (T i = 1; i < n ; ++i)
            toReturn[i] = i;
        return toReturn;
}
    
using namespace std;

double getError(vector<int> v1, vector<float> v2)
{
    vector<float> c(v1.size(), 0);
    
    for(int i = 0; i < v1.size(); i++)
    {
        c[i]=pow((v1[i]-v2[i]),2);
    }
    
    double suma = 0;
    for (auto x: c)
        suma+=x;
    
    return log(suma);
}

double holtWinters(vector<float> parametros, int p, vector<int> datos)
{
    float a = parametros[0];
    float b = parametros[1];
    float g = parametros[2];
    
    auto L = [a](float lvl, float trd, float sea, float dato) -> float {return a*(dato/sea)+(1-a)*(lvl-trd);};
    auto T = [b](float l, float lvl, float trd) -> float {return b*(l-lvl)+(1-b)*trd;};
    auto S = [g](float dato, float lvl, float sea2) -> float {return g*(dato/lvl) + (1-g)*(sea2);};
    auto Y = [](float l, float t, float s) -> float {return(l+t)*s;};
    
    vector<float> level = {(float) datos[0]};
    vector<float> trend = {(float) datos[0]};
    vector<float> seasonal (p, g+(datos[0]*(1-g)));
    vector<float> forecast;
    for (int i = 0; i < datos.size(); i++)
    {
        level.push_back(L(level[i], trend[i], seasonal[i], datos[i]));
        trend.push_back(T(level.back(), level[i], trend[i]));
        seasonal.push_back(S(datos[i], level[i], seasonal[i]));
        forecast.push_back(Y(level.back(), trend.back(), seasonal.back()));
    }
    return getError(datos, forecast);
    
}

vector<int> seleccionar(int tamanho, int usado)
{
    /*aquí implementé un algoritmo de Fisher-Yates*/
    vector<int> indices = range(tamanho);
    random_device rd;
    mt19937 eng(rd());
    for (int i = 0; i < 3; i++)
    {
        uniform_int_distribution<int> distr(i, tamanho-1);
        do{
            int j = distr(eng);
        } while j == usado;
        int tmp = indices[i];
        indices[i] = indices[j];
        indices[j] = tmp;
    }
    
    vector<int> to_return(indices.begin(), indices.begin()+tamanho);
    return to_return;
}

int main()
{
    vector<int> data;
    ifstream input;
    input.open("data2.csv");
    int dato;
    while (input >> dato)
    {
        data.push_back(dato);
    }
    
    random_device rd;
    mt19937 eng(rd());
    uniform_real_distribution<float> distr(0.0, 1.0);
    
    int lambda = 200;
    int max_iter = 200;
    int p = 12;
    float f = 0.8;
    
    vector<Ind> poblacion;
    
    for (int i = 0; i < lambda; i++)
    {
        Ind nuevo_individuo(distr(eng), distr(eng), distr(eng));
        poblacion.push_back(nuevo_individuo);
    }
    
    for (auto x : poblacion)
        x.setAptitud(holtWinters(x.getVariables(), p, data));
    
    for (int i = 0; i < max_iter; i++)
    {
        for (int j = 0; j < lambda; j++)
        {
            vector<int> elementos = seleccionar(lambda, j);
            double direccion = getDirection()
        }
    }
    return 0;
}

#include "Ind.h"

#include <iostream>
#include <vector>

using namespace std;

Ind::Ind(float alpha, float beta, float gamma)
{
    setVariables(alpha, beta, gamma);
}

bool operator<(Ind const & L, Ind const & R) { 
    return L.getAptitud() < R.getAptitud();
}

void Ind::setAptitud(double apt)
{
    aptitud = apt;
}

void Ind::setVariables(float a, float b, float g)
{
    variables = {a, b, g};
}

void Ind::setVariables(vector<float> entrada)
{
    variables = entrada;
}

double Ind::getAptitud() const
{
    return aptitud;
}

vector<float> Ind::getVariables()
{
    return variables;
}

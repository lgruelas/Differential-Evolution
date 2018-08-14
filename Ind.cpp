#include "Ind.h"

#include <iostream>
#include <vector>

using namespace std;

Ind::Ind(const float& alpha, const float& beta, const float& gamma)
{
    setVariables(alpha, beta, gamma);
}

bool operator<(Ind const & L, Ind const & R) {
    return L.getAptitud() < R.getAptitud();
}

void Ind::setAptitud(const double& apt)
{
    aptitud = apt;
}

void Ind::setVariables(const float& a, const float& b, const float& g)
{
    variables = {a, b, g};
}

void Ind::setVariables(const vector<float>& entrada)
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

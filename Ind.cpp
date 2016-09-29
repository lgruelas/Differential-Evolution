#include "Ind.h"

#include <iostream>
#include <vector>

using namespace std;

Ind::Ind(float alpha, float beta, float gamma)
{
    setVariables(alpha, beta, gamma);
}

void Ind::setAptitud(float apt)
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

float Ind::getAptitud()
{
    return aptitud;
}

vector<float> Ind::getVariables()
{
    return variables;
}

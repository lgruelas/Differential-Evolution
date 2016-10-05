#ifndef IND_H
#define IND_H

#include <vector>

using namespace std;

class Ind
{
    public:
        Ind(float alpha, float beta, float gamma);
        void setAptitud(double apt);
        void setVariables(float a, float b, float g);
        void setVariables(vector<float> entrada);
        double getAptitud();
        vector<float> getVariables();
    private:
        vector<float> variables;
        float aptitud;
};

#endif // IND_H

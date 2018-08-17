#ifndef IND_H
#define IND_H

#include <vector>

using namespace std;

class Ind
{
    public:
        Ind(const float& alpha, const float& beta, const float& gamma);
        void setAptitud(const double& apt);
	      void setVariables(const float& a, const float& b, const float& g);
        void setVariables(const vector<float>& entrada);
        double getAptitud() const;
        vector<float> getVariables();
        friend bool operator<(Ind const & L, Ind const & R);
    private:
        vector<float> variables;
        float aptitud;
};

#endif // IND_H

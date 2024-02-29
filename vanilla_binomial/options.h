#ifndef options_h
#define options_h

#include <iostream>
#include <algorithm>    // max()
#include "binModel.h"

using namespace std;

class EuroOption{
    private: 
        int T;                                        // time to maturity
    public:
        void setT(const int& T_){T = T_;}
        virtual double Payoff(const double& S){return 0;}
        double priceBinomial(binModel model);
};
// calculate factorial
int nChoosek(const int& n, const int& k);

// call option class
class callEuroOption: public EuroOption{
    private:
        double K;      // stirke price
    public:
        void setK(const double& K_){K = K_;}
        void getOptionParams();
        double Payoff(const double& S){return max(S-K,0.0);}
};

// put option class
class putEuroOption: public EuroOption{
    private:
        double K;       // stirke price
    public:
        void setK(const double& K_){K = K_;}
        void getOptionParams();
        double Payoff(const double& S){return max(K-S,0.0);}
};

#endif
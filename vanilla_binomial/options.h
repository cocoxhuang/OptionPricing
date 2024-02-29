#ifndef options_h
#define options_h

#include "binModel.h"

class EuroOption{
    private: 
        int T;                                                         // time to maturity
        double (*payoff)(const double& S, const double& K);            // payoff function
    public:
        void setT(const int& T_){T = T_;}
        void setPayoff(double (*payoff_)(const double& S, const double& K)){payoff = payoff_;}
        double priceBinomial(binModel model, const double& K);
};
// calculate factorial
int nChoosek(const int& n, const int& k);

// call option class
double callPayoff(const double& S, const double& K);
class callEruoOption: public EuroOption{
    private:
        double K;      // stirke price
    public:
        callEruoOption(){setPayoff(callPayoff);}
        double getK(){return K;}
        void getOptionParams();
};

// put option class
double putPayoff(const double& S, const double& K);
class putEruoOption: public EuroOption{
    private:
        double K;       // stirke price
    public:
        putEruoOption(){setPayoff(putPayoff);}
        double getK(){return K;}
        void getOptionParams();
};

#endif
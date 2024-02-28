#ifndef options_h
#define options_h

#include "binModel.h"

// calculate factorial
int nChoosek(const int& n, const int& k);
// get the parameters of the option
void getOptionParams(int& T, double& K);
// calculate eurupean call price with lattice model
double priceBinomial(binModel model, const int& T, const double& K, double (*payoff)(const double& S, const double& K));
// calculate payoff of call 
double callPayoff(const double& S, const double& K);
// calculate payoff of put
double putPayoff(const double& S, const double& K);
#endif
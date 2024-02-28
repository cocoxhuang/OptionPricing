#ifndef options_h
#define options_h

// calculate factorial
int nChoosek(const int& n, const int& k);
// get the parameters of the option
void getOptionParams(int& T, double& K);
// calculate eurupean call price with lattice model
double callPrice(const double& S0, const double& u, const double& d, const int& T, const double& r, const double& K);
// calculate eurupean put price with lattice model
double putPrice(const double& S0, const double& u, const double& d, const int& T, const double& r, const double& K);

#endif
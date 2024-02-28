#ifndef binModel_h
#define binModel_h

// compute risk-neutral probability
double riskNeutralProb(const double& u,const  double& d,const  double& r);
// compute the stock price at time T with i times up
double get_St(const double& S0, const  double& u,const  double& d, const int& T,const  int& i);
// get parameters input
void getParams(double& S0, double& u, double& d, double& r);

#endif
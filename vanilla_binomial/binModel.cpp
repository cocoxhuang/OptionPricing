#include <iostream>
#include <cmath>

// compute risk-neutral probability
double riskNeutralProb(const double& u,const double& d,const double& r){
    return (r-d)/(u-d);
}

// compute the stock price at time T with i times up
double get_St(const double& S0,const  double& u,const  double& d,const  int& T,const  int& i){
    /*
    input: ..
    i: number of ups i in the length T binomial lattice
    T: number of total periods
    */
   return S0 * pow((1+u), i) * pow((1+d), T-i);
}

// get parameters input
void getParams(double& S0, double& u, double& d, double& r){
    std::cout << "Enter S0: "; std::cin >> S0;
    std::cout << "Enter u:  "; std::cin >> u;
    std::cout << "Enter d:  "; std::cin >> d;
    std::cout << "Enter r:  "; std::cin >> r;
}
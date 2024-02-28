#include "binModel.h"
#include <iostream>
#include <cmath>
using namespace std;

// compute risk-neutral probability
double binModel::riskNeutralProb(){
    return (r-d)/(u-d);
}

// compute the stock price at time T with i times up
double binModel::get_St(const int& T,const  int& i){
    /*
    input: ..
    i: number of ups i in the length T binomial lattice
    T: number of total periods
    */
   return S0 * pow((1+u), i) * pow((1+d), T-i);
}

// get parameters input
void binModel::getParams(){
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter u:  "; cin >> u;
    cout << "Enter d:  "; cin >> d;
    cout << "Enter r:  "; cin >> r;
}

double binModel::getR(){
    return r;
}
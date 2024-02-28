#include "options.h"
#include "binModel.h"
#include <iostream>
#include <cmath>
#include <algorithm>    // max()
#include <bits/stdc++.h>
using namespace std;

// calculate factorial
int nChoosek(const int& n, const int& k){
    int res = 1;
    for(int i = 1; i <= k; i++){
        res = res * (n - k + i) / i;
    }
    return res;
}


// get the parameters of the option
void getOptionParams(int& T, double& K){
    cout << "Time to maturity: "; cin >> T;
    cout << "Strike price: "; cin >> K;
}

// calculate eurupean call price with lattice model
double callPrice(const double& S0, const double& u, const double& d, const int& T, const double& r, const double& K){
    double q = riskNeutralProb(u,d,r);
    double price = 0;
    for (int i = 0; i <= T; i++){
        price = price + nChoosek(T,i) * pow(q, i) * pow(q, T-i) * max(get_St(S0, u, d, T, i) - K, 0.0);
    }
    price = price / pow((1+r),T);
    return price;
}

// calculate eurupean put price with lattice model
double putPrice(const double& S0, const double& u, const double& d, const int& T, const double& r, const double& K){
    double q = riskNeutralProb(u,d,r);
    double price = 0;
    for (int i = 0; i <= T; i++){
        price = price + nChoosek(T,i) * pow(q, i) * pow(q, T-i) * max(K - get_St(S0, u, d, T, i), 0.0);
    }
    price = price / pow((1+r),T);
    return price;
}
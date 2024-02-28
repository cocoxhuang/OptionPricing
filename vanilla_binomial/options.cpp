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

// calculate eurupean option price with lattice model
double priceBinomial(binModel model, const int& T, const double& K, double (*payoff)(const double& S, const double& K)){
    double q = model.riskNeutralProb();
    double price = 0;
    for (int i = 0; i <= T; i++){
        price = price + nChoosek(T,i) * pow(q, i) * pow(q, T-i) * payoff(model.get_St(T, i) - K, 0.0);
    }
    price = price / pow((1+model.getR()),T);
    return price;
}

// calculate payoff of call 
double callPayoff(const double& S, const double& K){
    return max(S-K,0.0);
}

// calculate payoff of put
double putPayoff(const double& S, const double& K){
    return max(K-S,0.0);
}
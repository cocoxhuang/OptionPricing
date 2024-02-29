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

// calculate payoff of call 
double callPayoff(const double& S, const double& K){
    return max(S-K,0.0);
}

// calculate payoff of put
double putPayoff(const double& S, const double& K){
    return max(K-S,0.0);
}

// calculate eurupean option price with lattice model
double EuroOption::priceBinomial(binModel model, const double& K){
    double q = model.riskNeutralProb();
    double price = 0;
    for (int i = 0; i <= T; i++){
        price = price + nChoosek(T,i) * pow(q, i) * pow(q, T-i) * payoff(model.get_St(T, i) - K, 0.0);
    }
    price = price / pow((1+model.getR()),T);
    return price;
}

// get params for call option
void callEruoOption::getOptionParams(){
    int T;
    cout << "Time to maturity: "; cin >> T;
    setT(T);
    cout << "Call strike price: "; cin >> K;
}

// get params for put option
void putEruoOption::getOptionParams(){
    int T;
    cout << "Time to maturity: "; cin >> T;
    setT(T);
    cout << "Put strike price: "; cin >> K;
}
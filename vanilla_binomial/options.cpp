#include "options.h"
#include "binModel.h"
#include <iostream>
#include <cmath>
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

// calculate eurupean option price with lattice model
double EuroOption::priceBinomial(binModel model){
    double q = model.riskNeutralProb();
    double price = 0;
    for (int i = 0; i <= T; i++){
        price = price + nChoosek(T,i) * pow(q, i) * pow(q, T-i) * Payoff(model.get_St(T, i));
    }
    price = price / pow((1+model.getR()),T);
    return price;
}

// get params for call option
void callEuroOption::getOptionParams(){
    int T;
    cout << "Call time to maturity: "; cin >> T;
    setT(T);
    cout << "Call strike price: "; cin >> K;
}

// get params for put option
void putEuroOption::getOptionParams(){
    int T;
    cout << "Put time to maturity: "; cin >> T;
    setT(T);
    cout << "Put strike price: "; cin >> K;
}
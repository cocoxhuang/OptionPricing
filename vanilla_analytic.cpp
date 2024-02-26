#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>


double stdNormal_cdf(const double& x){
    return 0.5 * erfc(-x * M_SQRT1_2);
}

double d1_calc(const double& S, const double& K, const double& r, const double& T, const double& sigma){
    return (log(S/K) + (r + sigma * sigma * 0.5)*T) / (sigma * pow(T,0.5));
}

double d2_calc(const double& d1, const double& T, const double& sigma){
    return d1 - sigma*pow(T,0.5); 
}

double callOption_price(const double& S, const double& K, const double& r, const double& T, const double& sigma){
    double d1 = d1_calc(S,K,r,T,sigma);
    double d2 = d2_calc(d1,T,sigma);
    double N_d1 = stdNormal_cdf(d1);
    double N_d2 = stdNormal_cdf(d2);
    return S*N_d1 - K*exp(-r*T)*N_d2;
}

double putOption_price(const double& S, const double& K, const double& r, const double& T, const double& sigma){
    double d1 = d1_calc(S,K,r,T,sigma);
    double d2 = d2_calc(d1,T,sigma);
    double N_minusd1 = stdNormal_cdf(-d1);
    double N_minusd2 = stdNormal_cdf(-d2);
    return K*exp(-r*T)*N_minusd2 - S*N_minusd1;
}

int main(){
    double S = 100.0;    // stock price
    double K = 100.0;    // strike price
    double r = 0.05;   // risk-free rate
    double sigma = 0.2;  // volatility of the stock price (20% annum)
    double T = 1.0;        // time to maturity (1 year)

    double callPrice = callOption_price(S,K,r,T,sigma);
    double putPrice = putOption_price(S,K,r,T,sigma);

    std::cout << "Initial stock price:      " << S << std::endl;
    std::cout << "Strike:                   " << K << std::endl;
    std::cout << "Risk-free rate:           " << r << std::endl;
    std::cout << "Volatility:               " << sigma << std::endl;
    std::cout << "Time to maturity:         " << T << std::endl;

    std::cout << "Call price:               " << callPrice << std::endl;
    std::cout << "Put price:                " << putPrice << std::endl;

    return 0;
}
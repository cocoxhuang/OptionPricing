#include <algorithm>
#include <cmath>
#include <random>
#include <iostream>
#include <string>

std::default_random_engine generator;
std::uniform_real_distribution<double> uniformDist(1.0, 2.0);

double generateStockPrice(const double& S_0, const int& T, const double& p, const double& u){
    double S_T = S_0;
    for (int i = 0; i < T; i++){
        if (uniformDist(generator) > p){
            S_T = S_0 * u;
            printf("");
        } else {
            S_T = S_0 / u;
        }
    }
}

double callOption_price(const int& n_sims, const double& S, const double& K, const double& r, const double& p, const double& u, const int& T, const std::string& type){
    double S_T = S;                                     // stock price at time T
    double payoff = 0;                                  // payoff of the option
    double total_payoff = 0;                            // total sum of payoffs of all simulations

    for (int i = 0; i < T; i++){
        if (uniformDist(generator) > p){
            S_T = S_T * u;
            if 
        } else {
            S_T = S_T / u;
        }
    }

    return total_payoff/static_cast<double>(n_sims) * exp(-r * T);
}

// double putOption_price(const int& n_sims, const double& S, const double& K, const double& r, const double& p, const double& u, const int& T){
//     double S_T = 0;                                     // stock price at time T
//     double payoff = 0;                                  // payoff of the option
//     double total_payoff = 0;                            // total sum of payoffs of all simulations

//     for (int i = 0; i < n_sims; i++){
//         S_T = ES_T * exp(sigma * pow(T,0.5) * distribution(generator));
//         payoff = std::max(K-S_T,0.0);
//         total_payoff = total_payoff + payoff;
//     }

//     return total_payoff/static_cast<double>(n_sims) * exp(-r * T);
// }

int main(){
    int n_sims = pow(10,5);
    double S = 100.0;  // Option price                                                                                  
    double K = 100.0;  // Strike price                                                                                  
    double r = 0.05;   // Risk-free rate (5%)                                                                           
    double sigma = 0.2;    // Volatility of the stock (20%)                                                            
    double T = 1.0;    // Time to maturity             

    double call = callOption_price(n_sims, S, K , r, sigma, T);
    double put = putOption_price(n_sims, S, K , r, sigma, T);

    std::cout << "Number of Paths: " << n_sims << std::endl;
    std::cout << "Underlying:      " << S << std::endl;
    std::cout << "Strike:          " << K << std::endl;
    std::cout << "Risk-Free Rate:  " << r << std::endl;
    std::cout << "Volatility:      " << sigma << std::endl;
    std::cout << "Maturity:        " << T << std::endl;


    std::cout << "Call price:      " << call << std::endl;
    std::cout << "Put price:       " << put << std::endl;

    return 0;
}
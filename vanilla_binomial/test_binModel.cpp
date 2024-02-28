#include "binModel01.h"
#include <iostream>
#include <cmath>


int main(){
    double S0,u,d,r;    
    getParams(S0,u,d,r);
    std::cout << "Risk-neutral probabiliy is: " << riskNeutralProb(u,d,r) << std::endl;

    int T,i;
    std::cout << "Input T:  "; std::cin >> T;
    std::cout << "Input i:  ";  std::cin >> i;
    std::cout << "S(T,i): " << get_St(S0,u,d,T,i) << std::endl;

    return 0;
}
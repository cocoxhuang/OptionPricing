#include "options.h"
#include "binModel.h"
#include <iostream>
using namespace std;

int main(){
    int T;
    double K;
    double S0,u,d,r;
    getParams(S0,u,d,r);
    getOptionParams(T,K);
    cout << "Call price:    " << callPrice(S0, u, d, T, r, K) << endl;
    cout << "Put price:     " << putPrice(S0, u, d, T, r, K) << endl;
    return 0;
}
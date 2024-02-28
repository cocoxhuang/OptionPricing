#include "options.h"
#include "binModel.h"
#include <iostream>
using namespace std;

int main(){
    binModel model;
    int T;
    double K;

    model.getParams();
    getOptionParams(T,K);
    cout << "Call price:    " << priceBinomial(model, T, K, callPayoff) << endl;
    cout << "Put price:     " << priceBinomial(model, T, K, putPayoff)  << endl;
    return 0;
}
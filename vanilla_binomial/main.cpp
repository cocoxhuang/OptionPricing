#include "options.h"
#include "binModel.h"
#include <iostream>
using namespace std;

int main(){
    binModel model;
    callEuroOption call;
    putEuroOption put;

    model.getParams();
    call.getOptionParams();
    put.getOptionParams();
    cout << "Call price:    " << call.priceBinomial(model) << endl;
    cout << "Put price:     " << put.priceBinomial(model)  << endl;
    return 0;
}
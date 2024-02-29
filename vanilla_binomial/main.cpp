#include "options.h"
#include "binModel.h"
#include <iostream>
using namespace std;

int main(){
    binModel model;
    callEruoOption call;
    putEruoOption put;

    model.getParams();
    call.getOptionParams();
    put.getOptionParams();
    cout << "Call price:    " << call.priceBinomial(model,call.getK()) << endl;
    cout << "Put price:     " << put.priceBinomial(model,call.getK())  << endl;
    return 0;
}
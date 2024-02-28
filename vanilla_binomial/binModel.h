#ifndef binModel_h
#define binModel_h

class binModel{
    private:
        double S0;
        double u;
        double d;
        double r;
    public:
        // compute risk-neutral probability
        double riskNeutralProb();
        // compute the stock price at time T with i times up
        double get_St(const int& T,const  int& i);
        // get parameters input
        void getParams();
        // get risk free rate
        double getR();
};

#endif
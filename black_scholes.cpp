#include <iostream>
#include <cmath>

double normalCDF(double x) {
    return 0.5 * (1.0 + std::erf(x / std::sqrt(2.0)));
}

double blackScholesCall(double spot, double strike, double riskFreeRate, double timeToExpiry, double volatility) {
    double d1 = (std::log(spot / strike) + (riskFreeRate + 0.5 * volatility * volatility) * timeToExpiry)
                / (volatility * std::sqrt(timeToExpiry));
    double d2 = d1 - volatility * std::sqrt(timeToExpiry);
    return spot * normalCDF(d1) - strike * std::exp(-riskFreeRate * timeToExpiry) * normalCDF(d2);
}

double blackScholesPut(double spot, double strike, double riskFreeRate, double timeToExpiry, double volatility) {
    double callPrice = blackScholesCall(spot, strike, riskFreeRate, timeToExpiry, volatility);
    return callPrice - spot + strike * std::exp(-riskFreeRate * timeToExpiry);
}

double callDelta(double spot, double strike, double riskFreeRate, double timeToExpiry, double volatility) {
    double d1 = (std::log(spot / strike) + (riskFreeRate + 0.5 * volatility * volatility) * timeToExpiry)
                / (volatility * std::sqrt(timeToExpiry));
    return normalCDF(d1);
}

double putDelta(double spot, double strike, double riskFreeRate, double timeToExpiry, double volatility) {
    return callDelta(spot, strike, riskFreeRate, timeToExpiry, volatility) - 1.0;
}

 

int main() {

    double spot = 100.0;
    double strike = 100.0;
    double riskFreeRate = 0.05;
    double timeToExpiry = 1.0;
    double volatility = 0.2;

    double callPrice = blackScholesCall(spot, strike, riskFreeRate, timeToExpiry, volatility);
    double putPrice = blackScholesPut(spot, strike, riskFreeRate, timeToExpiry, volatility);

    std::cout << "Call price: " << callPrice << std::endl;
    std::cout << "Put price: " << putPrice << std::endl;


    double callDeltaValue = callDelta(spot, strike, riskFreeRate, timeToExpiry, volatility);
    double putDeltaValue = putDelta(spot, strike, riskFreeRate, timeToExpiry, volatility);

    std::cout << "Call delta: " << callDeltaValue << std::endl;
    std::cout << "Put delta: " << putDeltaValue << std::endl;
    return 0;
}

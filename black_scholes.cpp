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

int main() {
    double spot = 100.0;
    double strike = 100.0;
    double riskFreeRate = 0.05;
    double timeToExpiry = 1.0;
    double volatility = 0.2;

    double price = blackScholesCall(spot, strike, riskFreeRate, timeToExpiry, volatility);
    std::cout << "Call price: " << price << std::endl;

    return 0;
}

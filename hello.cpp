#include <iostream>

bool isInTheMoneyPut (double spotPrice, double strikePrice) {
    return spotPrice < strikePrice;
}

int main() {
    double spotPrice = 105.0;
    double strikePrice = 100.0;

    if (isInTheMoneyPut(spotPrice, strikePrice)) {
       std::cout << "This put option is in the money." << std::endl;
    } else {
       std::cout << "This put option is out of money." << std::endl;
    } 

    return 0;

}


# Black-Scholes Option Pricer

A C++ implementation of the Black-Scholes model, built from first principles and verified against known textbook values, as part of a transition from a data/analytics background into quantitative research.

## What it does

- Determines whether a call or put option is in or out of the money, given a spot and strike price
- Prices a European call option using the closed-form Black-Scholes formula
- Computes the standard normal cumulative distribution function the model needs directly, via the C++ standard library's `erf`

## The model

The Black-Scholes price for a European call is:

    C = S * N(d1) - K * e^(-rT) * N(d2)

where:

    d1 = [ln(S/K) + (r + 0.5*sigma^2)*T] / (sigma*sqrt(T))
    d2 = d1 - sigma*sqrt(T)

- `S` — spot price
- `K` — strike price
- `r` — risk-free interest rate
- `T` — time to expiry, in years
- `sigma` — volatility (annualised)
- `N(x)` — the standard normal cumulative distribution function

## Requirements

A C++17-compatible compiler (developed and tested with Apple clang 17).

## Build and run

    clang++ black_scholes.cpp -o black_scholes
    ./black_scholes

## Verification

Priced against a standard textbook example (S = 100, K = 100, r = 5%, T = 1 year, sigma = 20%):

    Call price: 10.4506

The known reference value for this input set is 10.45, confirming the implementation is correct.

## Roadmap

- [ ] Put option pricing
- [ ] Greeks (delta, gamma, vega, theta, rho)
- [ ] Monte Carlo pricing
- [ ] Binomial tree pricing
- [ ] American option pricing
- [ ] Python bindings via pybind11
- [ ] Unit tests (Catch2) and CI

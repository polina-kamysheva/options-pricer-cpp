# Black-Scholes Option Pricer

A C++ implementation of the Black-Scholes model, built from first principles and verified against known textbook values, as part of a transition from a data/analytics background into quantitative research.

## What it does

- Determines whether a call or put option is in or out of the money, given a spot and strike price
- Prices European call and put options using the closed-form Black-Scholes formula, with the put derived via put-call parity
- Computes delta (price sensitivity to the underlying) for both calls and puts
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

The put price is derived from the call via put-call parity rather than recomputed from scratch:

    P = C - S + K * e^(-rT)

Delta measures how much the option price moves per $1 move in the underlying:

    Call delta = N(d1)
    Put delta  = N(d1) - 1

## Requirements

A C++17-compatible compiler (developed and tested with Apple clang 17).

## Build and run

    clang++ black_scholes.cpp -o black_scholes
    ./black_scholes

## Verification

Priced against a standard textbook example (S = 100, K = 100, r = 5%, T = 1 year, sigma = 20%):

    Call price: 10.4506
    Put price: 5.57353
    Call delta: 0.636831
    Put delta: -0.363169

Reference values for this input set are 10.45 / 5.57 for price and 0.637 / -0.363 for delta, confirming both implementations are correct.

## Roadmap

- [x] Put option pricing
- [x] Delta
- [ ] Gamma, vega, theta, rho
- [ ] Monte Carlo pricing
- [ ] Binomial tree pricing
- [ ] American option pricing
- [ ] Python bindings via pybind11
- [ ] Unit tests (Catch2) and CI

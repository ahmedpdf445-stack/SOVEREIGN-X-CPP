#pragma once
#include <vector>
#include <cmath>
class StochasticEngine {
private: double mu=0, sigma=0, lastPrice=0;
public:
 void update(double price);
 double predictNext(double dt);
 double getMu(){return mu;} double getSigma(){return sigma;}
};

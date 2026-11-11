#include "StochasticEngine.h"
#include <random>
using namespace std;
void StochasticEngine::update(double price){
 if(lastPrice==0){lastPrice=price;return;}
 double ret=(price-lastPrice)/lastPrice;
 mu=mu*0.95+ret*0.05; sigma=sigma*0.95+fabs(ret)*0.05; lastPrice=price;
}
double StochasticEngine::predictNext(double dt){
 random_device rd; mt19937 gen(rd()); normal_distribution<> dW(0,sqrt(dt));
 return lastPrice*(1+mu*dt+sigma*dW(gen));
}

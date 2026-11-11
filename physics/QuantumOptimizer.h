#pragma once
#include <vector>
#include <cmath>
class QuantumOptimizer {
public:
 std::vector<double> qaoa(std::vector<double>& returns, std::vector<double>& risks){
  std::vector<double> w(returns.size(), 0); double sum=0;
  for(size_t i=0;i<returns.size();i++){ double score=returns[i]/(risks[i]+1e-9); w[i]=exp(score); sum+=w[i]; }
  for(auto &v:w) v/=sum; return w;
 }
};

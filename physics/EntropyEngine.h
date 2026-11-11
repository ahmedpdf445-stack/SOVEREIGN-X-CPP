#pragma once
#include <vector>
#include <cmath>
class EntropyEngine {
public:
 double shannon(std::vector<double>& p){
  if(p.size()<2) return 0; double e=0;
  for(size_t i=1;i<p.size();i++){ double r=fabs(p[i]-p[i-1])/p[i-1]+1e-9; e += -r*log(r); }
  return e / p.size();
 }
};

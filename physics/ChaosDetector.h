#pragma once
#include <vector>
#include <cmath>
class ChaosDetector {
public:
 double lyapunov(std::vector<double>& p){
  if(p.size()<2) return 0; double s=0; int n=0;
  for(size_t i=1;i<p.size();i++){ double d=fabs(p[i]-p[i-1]); if(d>1e-9){s+=log(d); n++;} }
  return n==0?0:s/n;
 }
};

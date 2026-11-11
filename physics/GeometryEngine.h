#pragma once
#include <vector>
#include <cmath>
class GeometryEngine {
public:
 double curvature(std::vector<double>& p){
  if(p.size()<3) return 0; size_t n=p.size()-1;
  double d1=p[n]-p[n-1], d2=p[n-1]-p[n-2];
  return fabs(d1-d2)/(fabs(d1)+fabs(d2)+1e-9);
 }
};

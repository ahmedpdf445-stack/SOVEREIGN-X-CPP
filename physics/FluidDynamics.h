#pragma once
#include <vector>
#include <cmath>
class FluidDynamics {
public:
 double flowPressure(std::vector<double>& vol, std::vector<double>& price){
  if(vol.size()<2) return 0; double press=0;
  for(size_t i=1;i<vol.size();i++){ double dv=vol[i]-vol[i-1]; double dp=price[i]-price[i-1]; press += dv*(dp+1e-9); }
  return press / vol.size();
 }
};

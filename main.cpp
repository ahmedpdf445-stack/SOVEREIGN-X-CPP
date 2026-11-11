#include "physics/StochasticEngine.h"
#include "physics/ChaosDetector.h"
#include "physics/EntropyEngine.h"
#include "physics/FluidDynamics.h"
#include "physics/ControlSystem.h"
#include "physics/GeometryEngine.h"
#include "physics/QuantumOptimizer.h"
#include "core/MatchingEngine.h"
#include <iostream>
#include <vector>
using namespace std;
int main(){
 cout<<"=== SOVEREIGN-X-CPP - PHYSICS LAB - ALL ENGINES ALIVE ==="<<endl;
 StochasticEngine st; ChaosDetector ch; EntropyEngine en; FluidDynamics fl;
 ControlSystem ct; GeometryEngine geo; QuantumOptimizer q; MatchingEngine me;
 vector<double> prices, vols;
 double price=95000;
 for(int i=0;i<1000;i++){
  if(i==500) price*=1.08; else price*=(1+(rand()%100-50)/100000.0);
  st.update(price); prices.push_back(price); vols.push_back(100+rand()%50);
  if(i%200==0){
   double lyap=ch.lyapunov(prices);
   double entr=en.shannon(prices);
   double press=fl.flowPressure(vols, prices);
   double curv=geo.curvature(prices);
   double filt=ct.kalman(price);
   cout<<"Bar "<<i<<" | Price "<<price<<" | Mu "<<st.getMu()<<" | Sigma "<<st.getSigma()
       <<" | Lyapunov "<<lyap<<(lyap>0?" CHAOS!":" STABLE")
       <<" | Entropy "<<entr<<" | Fluid "<<press<<" | Curvature "<<curv<<" | Kalman "<<filt<<endl;
  }
 }
 vector<double> rets={0.05,0.08,0.03}, risks={0.02,0.04,0.01};
 auto w=q.qaoa(rets, risks);
 cout<<"\nQAOA Weights: "; for(auto v:w) cout<<v<<" ";
 cout<<"\nPredict Next: "<<st.predictNext(1.0)<<endl;
 cout<<"\nALL 9 FILES BUILT - SOVEREIGN IS ALIVE!"<<endl;
 return 0;
}

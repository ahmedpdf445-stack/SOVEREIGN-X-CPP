#pragma once
class ControlSystem {
private: double x=0, P=1, K=0, integral=0, prevErr=0;
public:
 double kalman(double meas){ double R=0.01; K=P/(P+R); x=x+K*(meas-x); P=(1-K)*P+0.001; return x; }
 double pid(double target, double current){ double err=target-current; integral+=err; double d=err-prevErr; prevErr=err; return err*0.5+integral*0.01+d*0.1; }
};

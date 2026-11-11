#pragma once
#include "LockFreeQueue.h"
struct Order{ double price; double qty; int side; };
class MatchingEngine {
public: LockFreeQueue<Order> q;
 void submit(Order o){ q.push(o); }
};

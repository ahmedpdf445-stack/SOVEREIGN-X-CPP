#pragma once
#include <atomic>
#include <vector>
template<typename T>
class LockFreeQueue {
private: std::vector<T> buf; std::atomic<size_t> head{0}, tail{0};
public:
 LockFreeQueue(size_t n=1024):buf(n){}
 bool push(T v){ size_t t=tail.load(); buf[t%buf.size()]=v; tail.store(t+1); return true; }
 bool pop(T &out){ size_t h=head.load(); if(h>=tail.load()) return false; out=buf[h%buf.size()]; head.store(h+1); return true; }
};

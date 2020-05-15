#ifndef PROG3_H
#define PROG3_H
#include<iostream>
#include<set>
#include<iomanip>
using namespace std;

const int NO_ITEMS = 16;
const int ITEM_W = 4;

void sieve(set<int>& s, int n);
void print_primes(const set<int>& s);

#endif // !PROG_3


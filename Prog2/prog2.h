
#include<iostream>
#include <vector>
using namespace std;

#ifndef PROG2_H
#define PROG_H

const int ARR_SIZE = 200;
const int TEST_ARR_SIZE = 100;
const int SEED1 = 1;
const int SEED2 = 3;
const int LOW = 1;
const int HIGH = 1000;
const int NO_ITEMS = 16;
const int ITEM_W = 1;
void Vectors(vector <int>& v1, vector<int>&v2, int s1, int s2);
bool binarySearch(const vector <int>&v, int x);
bool linearSearch(const vector <int>&v, int x);
int search(const vector <int>&v1, const vector <int>&v2, bool(*p)(const vector <int>&, int));
void sortVector(vector <int> &v);
void printVector(const vector<int> &v);
void printStat(int totalSecCnt, int vectorSz);

#endif // !PROG2_H

/*
Edgar Villagran
Z1861047
9/06/2018
Section 3 
CSCI340
*/

#include<algorithm>
#include<iostream>
#include <vector>
using namespace std;

#ifndef PROG1_H
#define PROG1_H

//Defining all the constant variables to use
const int VEC_SIZE = 250; //Vector Size
const int NO_ITEMS = 12;  
const int ITEM_W = 5;     //Width of table to print
const int LOW = 1;        //Lowest generated number
const int HIGH = 10000;   //Highest generated number

//Functions we will use
void genRndNums(vector<int>&v);   //Generate random numbers to fill vector
void printVec(const vector<int>& v); //Print out vector as table


#endif // !PROGRAM1_H


/*
Edgar Villagran
Assignment #4
10/2/2018
z1861047
*/
#ifndef PROG4_H
#define PROG4_H
#define NO_ITEMS 13
#define ITEM_W 16
#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include<algorithm>
using namespace std;

typedef map < string, int > M;
void get_words(M&);
void print_words(const M&);
void clean_entry(const string&, string&);
void to_lower(char&);
void get_words(map <string, int>&);
void print_words(const map <string, int>&);
void clean_entry(const string&, string&);

#endif

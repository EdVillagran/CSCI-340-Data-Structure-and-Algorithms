#include <iostream>
#include <vector>
#include <iomanip>
#include "prog2.h"
#include <algorithm>
using namespace std;

void Vectors(vector <int>& v1, vector<int>&v2, int s1, int s2) 
{	
	v1.reserve(ARR_SIZE);
	v2.reserve(TEST_ARR_SIZE);
	srand(s1);
	int temp = 0;

	for (unsigned count = 0; count < ARR_SIZE; count++) {
		temp = rand() % (HIGH - LOW) + LOW;
		v1.push_back(temp);
	}

	srand(s2);
	int temp2 = 0;

	for (unsigned count = 0; count < TEST_ARR_SIZE; count++) {
		temp = rand() % (HIGH - LOW) + LOW;
		v2.push_back(temp);
	}
}
bool binarySearch(const vector<int>& sortV, int x) {
	int mid, left = 0;
	int right = sortV.size();
	while (left < right) {
		mid = left + (right - left) / 2;

		if (x > sortV[mid]) {
			left = mid + 1;
		}
		else if (x < sortV[mid]) {
			right = mid;
		}
		else {
			return true;
		}
	}

	return false;
}

bool linearSearch(const vector <int>&v, const int x) {

	return find(v.begin(), v.end(), x) != v.end();
}

int search(const vector <int>&v1, const vector <int>&v2, bool(*p)(const vector <int>&, int)) {
	vector<int>::const_iterator i;
	int count = 0;
	for (i = v2.begin(); i != v2.end(); i++) {
		if (p(v1, *i)) 
			count++;

	}
	return count;
}

void sortVector(vector <int> &v) {
	std::sort(v.begin(), v.end());
}
void printVector(const vector<int> &v) {

	setprecision(2);
	int flag = 0;
	for (auto i = v.begin(); i != v.end(); ++i)
	{
		if (flag == NO_ITEMS)
		{
			cout << endl;
			flag = 0;
		}
		cout << setw(4) << left << *i;
		for (int j = 0; j<ITEM_W; j++)
			cout << " ";
		flag++;

	}
}
void printStat(int totalSecCnt, int vectorSz) {
	cout << setprecision(2) <<"\nPercent of Successful Searches = " 
		<< ((double)totalSecCnt / vectorSz) * 100 << "%\n\n";
}
int main() {
	int num;
	vector<int>v1;
	vector<int>v2;

	Vectors(v1, v2, 1, 2);
	
	cout << "Random Numbers Before Sorting: \n\n";
	printVector(v1);

	cout << "\n\nRandom Numbers After Sorting: \n\n";
	sortVector(v1);
	printVector(v1);
	cout << "\n\n";


	cout << "\n\nRandom Numbers Searched: \n\n";
	printVector(v2);
	cout << "\n\n";

	cout << "Linear Search: ";
	int pstat = search(v1, v2, linearSearch);
	printStat(pstat, TEST_ARR_SIZE);
	cout << "Binary Search: ";
	int count = search(v1, v2, binarySearch);
	printStat(count, TEST_ARR_SIZE);

	return 0;
} 

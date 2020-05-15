/*
Edgar Villagran
Z1861047
9/06/2018
Section 3
Csci340
*/

#include"Prog1.h"
#include <iomanip>

//Take in the vector we will generate random numbers for 
//as a paramater.
void genRndNums(vector<int>&v) {
	const int SEED = 1;
	srand(SEED);
	int temp = 0;

	for (unsigned count = 0; count < VEC_SIZE; count++) {
		temp = rand() % (HIGH - LOW) + LOW;
		v.push_back(temp);
	}
}

//Print the vector in a table format
void printVec(const vector <int>&v) {

	int flag = 0;
	cout << setprecision(5);

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

int main() {
	vector<int>v;
	genRndNums(v);
	std::sort(v.begin(), v.end());
	printVec(v);
	cout << endl;
	system("pause");
	return 0;
}

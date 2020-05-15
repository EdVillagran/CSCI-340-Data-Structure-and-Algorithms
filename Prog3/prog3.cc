#include "prog3.h"

void sieve(set<int>& s, int n)
{
	for (int m = 2; m * m <= n; m++)
	{
		//If the following m is the end of the set, continue will skip the next for
		//loop within the loop. Unlike Break which would exit the loop entirely.
		if (s.find(m) == s.end())
			continue;

		//This for loop keeps m the same while k is constantly
		//increasing and erasing every number that is a result of
		//m multiplied by k.
		for (int k = 2; m * k <= n; k++)
			s.erase(m * k);
	}
}

void print_primes(const set<int>& s)
{
	//rowCounter keepts track of how many numbers are currently being cout, in the same row
	int rowCounter = 0;
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		//if the number of displayed items equals 16 it starts a new row and resets rowCounter
		if (rowCounter == NO_ITEMS) {
			cout << endl;
			rowCounter = 0;
		}
		//displays each number while properly aligned using library iomanip functions
		//and adds 1 to the numbers displayed in the row
		cout << right << setw(ITEM_W) << *it;
		rowCounter++;
	}
	cout << endl;
}

int main()
{
	set<int> s;
	int num = 1000;
	cout << "Showing primes below number 1000: \n\n";

	//Loading set s with 1000 individual numbers by using a 
	//for loop to insert count starting at 2
	for (int count = 2; count <= num; count++)
		s.insert(count);

	//Calling function sieve and print_primes with set s and max number n
	sieve(s, num);
	print_primes(s);

	system("pause");
	return 0;
}
/*
Edgar Villagran
11/16/2018
Assignment 8
*/
#include"prog8.h"
#include <functional>
#include<iomanip>


int main()
{
	vector < int >    v1;   // heap of integers
	vector < float >  v2;   // heap of floating-pt nums
	vector < string > v3;   // heap of strings

							// print header message
	cout << "\t\t\t*** CSCI 340: Program 8 - Output ***\n\n";

	// first heap

	cout << "\nfirst heap - ascending order:\n\n";
	get_list(v1, D1);
	construct_heap(v1, less < int >());
	print_list < int > print1(v1.size(), INT_SZ, INT_LN);
	for_each(v1.begin(), v1.end(), print1);

	cout << "\n\nfirst heap - descending order:\n\n";
	get_list(v1, D1);
	construct_heap(v1, greater < int >());
	for_each(v1.begin(), v1.end(), print1);

	// second heap

	cout << "\n\nsecond heap - ascending order:\n\n";

	get_list(v2, D2);
	construct_heap(v2, less < float >());
	print_list < float > print2(v2.size(), FLT_SZ, FLT_LN);
	for_each(v2.begin(), v2.end(), print2);



	cout << "\n\nsecond heap - descending order:\n\n";
	get_list(v2, D2);
	construct_heap(v2, greater < float >());
	for_each(v2.begin(), v2.end(), print2);


	// third heap

	cout << "\n\nthird heap - ascending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, less < string >());
	print_list < string > print3(v3.size(), STR_SZ, STR_LN);
	for_each(v3.begin(), v3.end(), print3);

	cout << "\n\nthird heap - descending order:\n\n";
	get_list(v3, D3);
	construct_heap(v3, greater < string >());
	for_each(v3.begin(), v3.end(), print3);

	// print termination message
	cout << "\t\t\t*** end of program execution ***\n\n";
	system("pause");
	return 0;
}

//Building the default constructor for print_list
template < class T >
print_list<T>::print_list(const unsigned&s, const unsigned&w,
	const unsigned&l, const unsigned&c) {
	sz = s;
	wid = w;
	len = l;
	cnt = c;

}
//get_list function recieves file as paramater and inputs text into
//the vector by first opening file, cheking if theres text, then 
//inputing text one at a time into value and value into vector
template < class T >
void get_list(vector < T >&v, const char*c) {
	v.clear();
	//ifstream in opens the file
	ifstream in(c);
	if (in) {
		T value;
		while (in >> value) {
			v.push_back(value);
		}
	}
	//closing the file
	in.close();

}
//contruct heap calls make_heap and sort_heap in order
//to create appropriate data type heap
template < class T, class P >
void construct_heap(vector < T >& v, P pred) {
	make_heap(v.begin(), v.end(), pred);
	sort_heap(v.begin(), v.end(), pred);
}


//overator overloading lets us print the value passed
template<class T>
void print_list<T>::operator()(const T &x) {

	//Setting the appropriate spacing 
	cout.width(wid); cout.precision(2);
	cout << fixed << showpoint;

	//if count is smaller than heap size
	if (cnt <= sz) {

		//if cnt reaches length specified it starts a new line
		if (cnt % len == 0 && cnt != 0)
			cout << endl;

		cout << x << " ";
		cnt++;
		}
}

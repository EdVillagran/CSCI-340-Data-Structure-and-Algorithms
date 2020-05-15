/*
Edgar Villagran
Assignment #4
10/2/2018
z1861047

Takes file filled with words as input. From those wrds it removes any special
characters or punctuation, making them from a 'Dirty' word to 'Clean.'
It then counts the number of instances that word occured.
Finally, it outputs number of words taken in, and how many words outputed.
*/

#include "prog4.h"


int main()
{
	map <string, int> words;
	get_words(words);
	print_words(words);
	system("pause");
	return 0;


}
//Get words recieves input stream and removes punctuation marks
void get_words(map <string, int>& m)
{
	string dirtyWord, cleanWord;
	while (cin) // while there is input
	{
		cin >> dirtyWord; // read in word 1 at a time
		clean_entry(dirtyWord, cleanWord); // call clean method to remove punctuation
		if (cleanWord.size() > 0) m[cleanWord]++; // add to set if > 0
	}
}
//print_words displays a formated list of words and number of times used
void print_words(const map <string, int>& m)
{
	typedef map<string, int> mapType;
	mapType::const_iterator i;

	int count = 0;
	int words = 0;
	//for loop uses iterator to loop through words and uses a pointer to first and second in map
	//it then counts and displays how many times it has been used
	for (i = m.begin(); i != m.end(); i++)
	{
		cout << left << setw(20) << i->first << ": " << setw(5) << i->second;
		count++;
		words += i->second;
		if (count == 3) { cout << endl; count = 0; }
	}
	cout << endl << "Number of input words: " << words << endl;
	cout << "Number of output words: " << m.size() << endl;

}
//Have to create a void to_lower function in order to fill into for_each as a 
//third parameter to lower any Uppercase characters
void to_lower(char& d)
{
	tolower(d);
}
/*
void clean_entry's purpose is to 
takes two strings as parameters and take one word at at time
and remove any punctuation that is attatched to it.
*/
void clean_entry(const string& s1, string& s2)
{
	//iterators hold words before and after removal
	string::const_iterator before = s1.begin();
	string::const_iterator after = s1.begin();

	//find_if  uses isalnum to return true if string is alphanumeric or false if otherwise
	before = find_if(s1.begin(), s1.end(),[](char c) -> bool { return (isalnum(c) > 0); });
	after = find_if(s1.begin(), s1.end(),[](char c) -> bool { return (!isalnum(c) > 0); });

	s2 = s1.substr(before - s1.begin(), after - before);
	for_each(s2.begin(), s2.end(), to_lower);

}


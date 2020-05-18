#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

const int No_Items = 12; // const declaration for No_Items
const string Init_Val = "A1"; // const declaration for Init_Val


void init_vals(vector <string>& v, unsigned& N, unsigned& M);
void print_vector(const vector <string>& v, const unsigned& cnt);

class SEQ
{

private:
	string id; // name of soldier

public:
	SEQ(const string& x = Init_Val) : id(x) { } // default constructor

	string operator ( ) ()
	{ // overloaded function operator
		string tmp = id;
		if (id[1] < '9')
		{
			id[1]++;
		}
		else
		{
			id[0]++;
			id[1] = '1';
		}

		return tmp; // return next name in order
	}
};

/**************************************************************************************************************************************************

FUNCTION : main()


**************************************************************************************************************************************************/
int main()
{

	unsigned int x, y;
	vector<string> v;
	char ans;
	do
	{
		cout << "\t\t\tThe Josephus Problem" << endl << endl;



		init_vals(v, x, y); //calling init_vals function

		cout << "\nNumber of people : " << x << endl;
		cout << "Index for elimination : " << y << endl;

		cout << "\nInitial group of people" << endl;
		print_vector(v, x); //calling print_vector function

		cout << endl << endl;

		int cnt = 0;
		int temp = x;
		int inival = 0;
		while (cnt != temp - 1)
		{
			inival = (inival + y - 1) % v.size();
			v.erase(v.begin() + inival);
			x--;
			cout << "After elimination round No. " << cnt + 1 << endl << endl;
			print_vector(v, x);
			cout << endl << endl;
			cnt++;
		}

		cout << "Restart ? (Y/N) : ";
		cin >> ans;

	} while (ans == 'y' || ans == 'Y');

	cout << "\n\nBye! --press any key to exit." << endl;


	return 0;
}

void init_vals(vector <string>& v, unsigned& N, unsigned& M)
{
	cout << "Enter total number of soldiers (N) : ";
	cin >> N;
	cout << "Enter the lucky number (M) : ";
	cin >> M;

	v.resize(N);
	SEQ names;
	generate(v.begin(), v.end(), names); //storing the soldier names in names

}


void print_vector(const vector <string>& v, const unsigned& cnt)
{
	int No_ItemsPerLine = 0;
	for (int i = 0; i<cnt; i++)
	{
		if (No_ItemsPerLine != No_Items)
		{
			cout << " " << v[i] << " ";
			No_ItemsPerLine++;
		}
		else
		{
			cout << endl << " " << v[i] << " ";
			No_ItemsPerLine = 1;
		}
	}
}












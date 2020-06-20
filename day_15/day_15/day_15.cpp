#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int number;
	while (cin >> number)
	{
		int count = 0;
		bitset<32> bitnum(number);
		for (size_t i = 0; i < bitnum.size(); i++)
		{
			if (bitnum[i] == 1)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}
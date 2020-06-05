#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s,str;
	cin >> s;
	size_t count = 0, max = 0, pos = 0, tmp = 0, tempos = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
		}
		else
		{
			if (max < count)
			{
				max = count;
				count = 0;
			}

			if (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				
			}
		}
	}
	str = s.substr(pos, max);
	cout << str << endl;
	return 0;
}
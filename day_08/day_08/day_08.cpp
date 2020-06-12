#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<string> v(n + 1);
	string s;
	int i = 0;
	for (; i < n; i++)
	{
		cin >> s;
		v[i] = s;
	}
	i = 0;
	string str = "";
	for (i = 0; i < n; i++)
	{
		if (v[i].compare(v[i + 1]) <= 0)
		{
			if (v[i].size() <= v[i + 1].size())
				str += 'b';
			else
				str += 'd';
		}
		else if (v[i].size() <= v[i + 1].size())
		{
			str += 'l';
		}
		else
		{
			str += 'n';
		}
	}
	int count = 0,ret = 0;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (str[i] == 'n')
		{
			cout << "none" << endl;
			break;
		}
		else if (str[i] == 'd')
		{
			count++;
		}
		else if (str[i] == 'l')
		{
			ret++;
		}
	}
	if (count > 0)
		cout << "lexicographically" << endl;
	else if (ret > 0)
		cout << "lengths" << endl;
	else
		cout << "both" << endl;
	return 0;
}
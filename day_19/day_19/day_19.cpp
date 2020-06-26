//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		reverse(str.begin(), str.end());
//		cout << str << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int Max_longsubstring(string str1, string str2)
{
	int res = 0;
		for (size_t i = 0; i < str1.size(); i++)
		{
			for (size_t j = 0; j < str2.size(); j++)
			{
				int m = i;
				int n = j;
				int len = 0;
				while (str1[m] == str2[n] && m < str1.size() && n < str2.size())
				{
					len++;
					m++;
					n++;
				}
				res = max(len, res);
			}
		}
	return res;
}

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int ret = Max_longsubstring(str1, str2);
		cout << ret << endl;
	}
}
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//	string s, str;
//	getline(cin, s);
//	int count = 1;
//	int times = 0;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ')
//			count++;
//		else if (s[i] == '"')
//			times++;
//	}
//	cout << count + times / 2 << endl;
//	int start = 0;
//	int end = 0;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//
//		if (s[i] == ' ')
//		{
//			end = i;
//			str = s.substr(6, 8);
//			cout << str << endl;
//			start = i + 1;
//		}
//	}
//	return 0;
//}

#include <iostream>

using namespace std;
int min_divisor(int N)
{
	for (int i = N - 1; i > 1; i--)
	{
		if (N % i == 0)
			return i;
	}
	return 0;
}

int main()
{
	int N, M;
	while (cin >> N >> M)
	{
		int count = 0;
		while (N < M)
		{
			if (min_divisor(N))
			{
				N += min_divisor(N);
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
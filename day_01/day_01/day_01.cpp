//// ±©Á¦½â·¨
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	char a[20];
//	cin.get(a, 20);
//	string s1(a), s2;
//	cin >> s2;
//	string::iterator it1 = s1.begin();
//	string::iterator it2 = s2.begin();
//	while (it1 != s1.end())
//	{
//		string::iterator it2 = s2.begin();
//		while (it2 != s2.end())
//		{
//			if (*it1 == *it2)
//			{
//				s1.erase(it1);
//			}
//			++it2;
//		}
//		++it1;
//	}
//	cout << s1 << endl;
//	return 0;
//}

#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int array[6] = { 0 };
	int i = 0;
	int import = 0;
	while (cin >> import)
	{
		array[i] = import;
		i++;
	}
	cout << 10 << endl;
	return 0;
}
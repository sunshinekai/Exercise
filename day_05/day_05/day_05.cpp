#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
int main()
{
	char p1[15] = "abcd";
	char *p2 = "ABCD";
	char str[50] = "xyz";
	strcpy(str + 2, strcat(p1 + 2, p2 + 1));
}

//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	string a,b;
//	cin >> a;
//	cin >> b;
//	string a_start = a;
//	size_t n = a.size();
//	size_t i = 0, count = 0;
//	for (;i < n; i++)
//	{
//		a.insert(i, b);
//		string str = a;
//		reverse(a.begin(), a.end());
//
//		if (str == a)
//			count++;
//
//		a = a_start;
//	}
//	cout << count << endl;
//	return 0;
//}


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector <int> a;
//	a.resize(n + 1);
//	a[n] = 0;
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//
//	int MaxSum = a[0];
//	int CurSum = a[0];
//	for (int i = 0; i < a.size(); i++)
//	{
//		// 如果当前和小于等于0，重新计算
//		if (CurSum <= 0)
//			CurSum = a[i];
//
//		else  // 大于等于0，直接累加
//			CurSum += a[i];
//
//		// 更新最大和
//		if (CurSum >  MaxSum)
//			MaxSum = CurSum;
//	}
//	cout << MaxSum << endl;
//	return 0;
//}
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;


//#include <iostream>
//#include <vector>
//#include <climits>
//
//using namespace std;
//
//bool IsPrime(int n)
//{
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//
//}
//int main()
//{
//	int input; // (nÎªÅ¼Êý)
//	while (cin >> input)
//	{
//		vector <int> v;
//		for (int i = 2; i < input; i++)
//		{
//			if (IsPrime(i))
//				v.push_back(i);
//		}
//		int MinValue = INT_MAX;
//		size_t i = 0, j = 0;
//		size_t mini = 0, minj = 0;
//		for (size_t i = 0; i < v.size(); i++)
//		{
//			for (size_t j = 0; j < v.size(); j++)
//			{
//				if (v[i] + v[j] == input)
//				{
//					if (MinValue > abs(v[j] - v[i]))
//					{
//						MinValue = abs(v[j] - v[i]);
//						mini = i;
//						minj = j;
//					}
//				}
//			}
//		}
//		cout << v[mini] << endl;
//		cout << v[minj] << endl;
//	}
//}
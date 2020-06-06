#include <iostream>

using namespace std;
int main()
{
	//int m, n, x, y;
	//while (cin >> m >> n >> x >> y)
	//{
	//	int A = (m + x) / 2;
	//	int B = (n + y) / 2;
	//	int C = (y - n) / 2;
	//	cout << A << ' ' << B << ' ' << C << endl;
	//}

	int a[5] = { 1, 3, 5, 7, 9 };
	int *p = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(p - 1));
	return 0;

}

/*#include <iostream>
#include <vector>
#include <string>

using namespace std;
#include<iostream>
using namespace std;

void calculate(int n, int k)
{
	char num[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	int temp;
	temp = n % k;
	n /= k;
	if (n != 0)
		calculate(n, k);
	cout << num[temp];
}
int main()
{
	int M, N;
	while (cin >> M >> N)
	{
		calculate(M, N);
		cout << endl;
	}
	return 0;
}
*/
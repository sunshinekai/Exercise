/*
ѡ����

1.
����������������(D)��

#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;
#define SQR(A) A*A
void main() 
{
	int x = 6, y = 3, z = 2;
	x /= SQR(y + z) / SQR(y + z);
	cout << x << endl;
}

A 5
B 6
C 1
D 0

ע��x = 6 / (3 + 2 * 3 + 2 / 3 + 2 * 3 + 2) = 6 / 17 = 0;

2.
��һ��64λ�Ĳ���ϵͳ�ж������½ṹ�壺

struct st_task
{
	uint16_t id;
	uint32_t value;
	uint64_t timestamp;
};

ͬʱ����fool�������£�
void fool()
{
	st_task task = {};
	uint64_t a = 0x00010001;
	memcpy(&task, &a, sizeof(uint64_t));
	printf("%11u,%11u,%11u", task.id, task.value, task.timestamp);
}

����fool()�����ִ�н��Ϊ��A��
A 1��0��0
B 1��1��0
C 0��1��1
D 0��0��1

ע��Ҫ�����ڴ���룬uint16_t��unit32_t��unit64_t�ֱ�ռ2���ֽڡ�4���ֽڡ�8���ֽڣ�
    ȡ�м�4���ֽ�Ϊ���뵥λ����Ϊm��������
����unit16_tռ1�����뵥λm����4���ֽڣ�
����unit32_tռ1�����뵥λm����4���ֽڣ�
����unit64_tռ2�����뵥λ2m����8���ֽڡ�
����Ҳ���ǣ�
����id ռ 4���ֽڣ����Ǹ�2���ֽ���Ч���洢 0x0001 0001��ʵ��Ϊ 0x0000 0001��
����value ռ4���ֽڣ� �洢 0x0000 0000��ʵ��Ϊ 0x0000 0000 ��
����timestamp ռ8���ֽڣ� �洢 0x00000000 00000000 ��ʵ��Ϊ 0x00000000 00000000��
���ԣ����� 1 0 0
*/

/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ,
���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
����������int n��int m��ͬʱ����int j��int i����������������
�뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i-j+1��

����������
1024��19��2��6
���أ�1100
*/

/*
˼·��i j
m:1024��100000000 00 n:19 �� 10011 Ҫ��n�Ķ�����ֵ����m�ĵ�jλ����iλ��ֻ��Ҫ��n������jλ��Ȼ
���ٽ��л����㣨|�����ɡ�
m: 10000000000
n: 00001001100
10001001100
*/

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		m <<= j;
		return n | m;
	}
};


/*
2.
���ӣ�https://www.nowcoder.com/practice/f8538f9ae3f1484fb137789dec6eedb9?tpId=37&&tqId=21283&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
����ĿҪ��������ָ��ż��������������ֵ��С��������

����
20
���
7
13
*/

/*
����������Ҫ�ж�������������ʾ����1�ͱ������ܱ�������������ͨ��ѭ���������ж�һ�����Ƿ�Ϊ��
�����������������Ӧ�ô����м��λ�ÿ�ʼ�����߲��ҡ�
*/

#include<iostream>
#include<algorithm>
using namespace std;
//�ж�����
bool isPrime(int num)
{
	int tmp = sqrt(num);
	//ֻ�����������������ܱ�������ߵ�����������һ�����ܱ������ұߵ�������
	for (int i = 2; i <= tmp; i++)
	{
		if (num %i == 0)
			return false;
	} 
	return true;
} 
int main()
{
	int num;
	int half;
	int i;
	while (cin >> num)
	{
		half = num / 2;
		//���м���������
		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(num - i))
				break;
		} 
		cout << i << endl << num - i << endl;
	} 
	return 0;
}
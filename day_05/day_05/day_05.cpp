/*
ѡ����

1.
����������������(B)
#include <iostream>
using namespace std;
int main()
{
	int n[][3] = { 10, 20, 30, 40, 50, 60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << "," << *(p[0] + 1) << "," << (*p)[2] << endl;
	return 0;
}
A 10,30,50
B 10,20,30
C 20,40,60
D 10,30,60
ע��(*p)[3] = {10,20,30}*(p[0]+1) = p[0][1] = 20 (*p)[2] = 30

2.
int main()
{
	int a;float b,c;
	scanf("%2d%3f%4f",&a,&b,&c);
	printf("\na=%d,b=%d,c=%f\n",a,b,c);
}
������ʱ�Ӽ���������9876543210l,�����������gcc�������µ���������(B)
A a=98,b=765,c=4321.000000
B a=98,b=0,c=0.000000
C a=98,b=765.000000,c=4321.000000
D a=98,b=765.0,c=4321.0
ע������(int,float)���ڴ��еĴ洢��ʽ

3.
����˵����ȷ����(A)
A һ������Ĭ��һ�����ɹ��캯��,�������캯��,��ֵ������,���ò�����,��������
B �����ж����������
C ������������Ϊvirtual,���Ա�����
D ��Ĺ��캯�����������public��������,�����ʵ���޷�����
ע�����Ĭ��6����Ա����

4.��ѡ�����г�������н��(B)
A B0::display0 B0::display0 B0::display0
B B0::display0 B0::display0 D1::display0
C B0::display0 B1::display0 D1::display0
D B0::display0 B1::display0 B1::display0

#include<iostream>
using namespace std;
class B0 // ����BO����
{ 
public: // �ⲿ�ӿ�
	virtual void display() // ���Ա����
	{
		cout<<"B0::display0"<<endl;
	}
};

class B1:public B0 // ��������
{
public:
	void display() 
	{
		cout<<"B1::display0"<<endl;
	}
};

class D1: public B1//��������
{
public:
	void display()
	{ 
		cout<<"D1::display0"<<endl; 
	}
};

void fun(B0 ptr)//��ͨ����
{
	ptr.display();
}

int main()//������
{
	B0 b0;//������������ָ��
	B1 b1;//�������������
	D1 d1;//�������������
	fun(b0);//���û���B0������Ա
	fun(b1);//����������B1������Ա
	fun(d1);//����������D1������Ա
	return 0;
}
ע��
�麯���Ķ�̬�󶨽��ڻ���ָ������ð����������ʱ���� ��
fun���ββ���ָ�룬���Ե����ĸ��汾�ĺ�������ʱ���Ѿ�ȷ����
�����βξ�̬����ȷ������B0�ĳ�Ա��
*/

/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
�����ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B��
�������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ���������
������Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮��: "abba" �ǻ���
* ����ĸ��b��֮��: "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2
����
aba
b
���
2
*/

/*
˼·:����ʹ�ñ�����ⷽʽ���㼴�ɣ�����a����b insert��a��ÿ��λ�ã��ж��Ƿ��ǻ��ģ��Ǿ�
++count����Ҫע��������ﲻ�� a.insert(i, b)�������Ļ�a�ı��ˣ��ж���һ��λ�þͲ����ˡ�
����ÿ��ʹ��a��������һ��a_start��Ȼ��str.insert(i, b)�����ж�
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
	string a,b;
	getline(cin, a);
	getline(cin, b);
	string a_start = a;
	size_t n = a.size();
	size_t i = 0, count = 0;
	for (;i <= n; i++)
	{
		a.insert(i, b);
		string str = a;
		reverse(a.begin(), a.end()); // �ж��ַ����Ƿ����

		if (str == a)
			count++;

		a = a_start;
	}
	cout << count << endl;
	return 0;
}

/*
2.
���ӣ�
һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1,2,1]������������������Ϊ[2,1]�����Ϊ 3
��������:
����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��,ÿ����������32λint��Χ�ڡ��Կո�ָ���
�������:
���������������к�����ֵ��
ʾ��:
����
3 -1 2 1
���
3
*/

/*
˼·������sum[i-1]���������е�nums[i-1]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
sum[i]���������е�nums[i]Ϊ���һ��Ԫ�ص�һ�����������ͣ�
��ôsum[i] = max(sum[i-1], 0) + nums[i]�����������������������sum1��ʾsum[i-1]��sum2��ʾ
sum[i]�����������������������򱣴浽result�С����sum[i]����sum2��С��0�ˣ�����Ϊ0��
��Ϊ������������һ�������������������������͡�
*/

#include <iostream>
#include<vector>

using namespace std;
int main()
{
	int size;
	cin >> size;
	vector<int> nums(size);
	for (size_t i = 0; i < size; ++i)
		cin >> nums[i];
	int result = nums[0];
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		// ���㵽num[i]�������������
		sum2 = sum1 >= 0 ? sum1 + nums[i] : nums[i];
		if (sum2 > result)
			result = sum2;
		if (sum2 < 0)
			sum2 = 0;
		sum1 = sum2;
	}
	cout << result << endl;
	return 0;
}
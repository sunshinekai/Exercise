/*
ѡ����

1.
C++�й��ڶѺ�ջ��˵�����ĸ��Ǵ����(D)
A �ѵĴ�С���ܲ���ϵͳ�����ƣ�ջ�Ĵ�Сһ��һ���С
B �ڶ���Ƶ���ĵ���new/delete���ײ����ڴ���Ƭ��ջû���������
C �Ѻ�ջ�����Ծ�̬����
D �Ѻ�ջ�����Զ�̬����
ע���Ѳ����Ծ�̬����

2.�����������ʲô(B)

#include <iostream>

static int a = 1;
void fun1(void){ a = 2; }
void fun2(void){ int a = 3; }
void fun3(void){ static int a = 4;}
int main(int argc, char** args){
	printf("%d", a);
	fun1();
	printf("%d", a);
	fun2();
	printf("%d",a);
	fun3();
	printf("%d", a);

A 1 2 3 4
B 1 2 2 2
C 1 2 2 4
D 1 1 1 4
ע���ڶ�����������ʵ������Ѷ����ȫ�ֱ���i������дֵ���ڶ���Ϊ2��
������������ڲ�������һ��ͬ���ı����� ����û�з���ֵ���߱��ô�ִ�г��������κγ����ȡaֵ�����Ե����������Ȼ��a��
���Ĵ������������һ����̬�ľֲ���������̬�ֲ������ں������ý�������Ȼ���ڣ�
�������ڴ�ռ䲻�ᱻ�ͷţ������������ǲ����������ģ����ԣ�������̬������Ȼͬ�������ǲ�����һ���Ķ���

3.
In the main(C) function, after ModifyString(text) is called, what��s the value of ��text����

int FindSubString(char* pch)
{
	int count = 0;
	char * p1 = pch;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] - 1)
		{
			p1++;
			count++;
		}
		else {
			break;
		}
	} 
	
	int count2 = count;
	while (*p1 != '\0')
	{
		if (*p1 == p1[1] + 1)
		{
			p1++;
			count2--;
		}
		else {
			break;
		}
	} 
	if(count2 == 0)
		return(count);
	return(0);
} 
void ModifyString(char* pText)
{
	char * p1 = pText;
	char * p2 = p1;
	while (*p1 != '\0')
	{
		int count = FindSubString(p1);
		if (count > 0)
		{
			*p2++ = *p1;
			sprintf(p2, "%i", count);
			while (*p2 != '\0')
			{
				p2++;
			} 
			p1 += count + count + 1;
		}
		else 
		{
			*p2++ = *p1++;
		}
	}
}
void main(void)
{
	char text[32] = "XYBCDCBABABA";
	ModifyString(text);
	printf(text);
}

A XYBCDCBABABA
B XYBCBCDA1BAA
C XYBCDCBA1BAA
D XYBCDDBA1BAB


FindSubString��������"�Գ�!!!"�����������������½������Ӵ�������CDC����Ŀ�е�BCDCBA���ǣ�������count��
�����ǻ����Ӵ����߲��Գ��򷵻�0
�ַ���XYBCDCBABABA ֮ǰ�������ַ�ִ�еĶ��� ModifyString�����е�else�ӶΣ���*p2++=*p1++;
�ַ��� XYBCDCBABABA �� ��һ���Գƻ����Ӵ�ΪABA����ʱsprintf������count(��ʱΪ1)�滻B�����Զ���Ӵ���β��'\0'�ڵڶ���A��λ�ã�
���±ߵ�while��伴��p2ָ���ƶ����ڶ���A��λ�ã�p1 += count + count +1��p1�ƶ����ڶ���A�����Bλ���ϣ���p2�ĺ�һλ
��֮��û�жԳƻ����Ӵ�����ִ��*p2++=*p1++��ֱ��p1���ﴮβ�����õ����ڶ����ַ��滻�������������õ�����һ���ַ��滻�����ڶ���
���ϣ������XYBCDCB A1 BA A

4.
�������´��룬�ĸ�˵������ȷ��(B)
myClass::foo()
{
	delete this;
}
..

void func()
{
	myClass *a = new myClass();
	a->foo();
}

A ��������ջ���
B ������ȷ
C �����ܱ���
D ��������δ���

ע��
�ܽ�һ�� 
һ����foo()�е���delete this;û�����⣬���������������е����������
delete this���Զ���������������ԭ��������޵ݹ飬����ջ�����
����������delete this ֮�󣬶�����ڴ�ռ䱻�ͷ��ˣ����²����ٷ������ݳ�Ա���麯��

5.
������δ�����ӡ��ʲô(A)
class A
{ 
public :
	A()
	{
		printf("A ");
	} 

	~A()
	{
		printf("deA ");
	}
};
class B
{
	
public :
	B()
	{
		printf("B ");
	} 
	
	~B()
	{
		printf("deB ");
	}
};
class C : public A, public B
{
	
public :
	C()
	{
		printf("C ");
	} 
	
	~C()
	{
		printf("deC ");
	}
};
int main()
{
	A *a = new C();
	delete a;
	return 0;
}

A A B C deA
B C A B deA
C A B C deC
D C A B deC

ע��
���캯����ִ����ִ�и��࣬��ִ�����ࡣ����˳���෴
A B���������������麯�������Բ���ִ��������麯����
*/

/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
����һ������������������������1�ĸ�����
����
5
���
2
*/

/*
˼·1�����Խ�����תΪ2���ƣ�Ȼ��ֱ�Ӽ���ͳ�Ƴ�1�ĸ�������
*/

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	int number;
	while (cin >> number)
	{
		int count = 0;
		bitset<32> bitnum(number);
		for (size_t i = 0; i < bitnum.size(); i++)
		{
			if (bitnum[i] == 1)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

/*
˼·2�������Ǽ���һ���������Ʊ�ʾ��1�ĸ�����ͨ����n >> i) & 1���Ի�ȡ��iλ�Ķ�����ֵ��ÿ��n��
��һλ�����Ի�ȡһλ�Ķ�����ֵ������32�Σ�n���0��ѭ����ֹ��
*/

#include<iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count++;
			n >>= 1;
		}
		cout << count << endl;
	} 
	return 0;
}

/*
2.
���ӣ�https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��
A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡�
�����������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס�
���ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
������ɫ����n(1��n��13),ͬʱ������������Ϊn������left,right,�ֱ����ÿ����ɫ���������׵�������
���ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������

4,[0,7,1,6],[1,5,0,6]
���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)
*/

/*
���ڷ�0��������a1,a2...an��Ҫ������ȡֵ����ÿһ������
n = sum(a1...an) - a1 + 1��Ҳ����������ȥ��Сֵ֮���һ��
���Զ���������������ɫ�������������У���Ҫ����ÿһ����ɫ������С����leftsum = �������
�� - �����Сֵ + 1�� rightsum = �ұ������� - �ұߵ���Сֵ + 1����������0���ڵģ�����Ҫ��
�ۼӣ���֤����ÿһ����ɫ��
*/

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//����ÿһ����ɫ��������������
		for (int i = 0; i<n; i++){
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//���������ֶ��е���ɫ���ף�ִ���ۼ�-��Сֵ+1
			//�ҵ���Сֵ������
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		} 
		// ���Ϊ�����Ҷ����������������еĽ�� + ��0���ڵ������� + ����ټ�һ�϶����ܱ�֤��
			return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};
/*
ѡ����

1.
void swap_int(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

����˵����ȷ����(B)
A �������ȷ����Ϊ���������λ��ķ�ʽ��û����
B �����ȷ����ʹ�����
C �����ȷ���������
D ����ѡ�����

ע��
��ʹ�����������������㷨����Ȼ�������ٸ����ӣ�����intֻ��4bit��
��ô-8 + ��-5�� = -13�������, ʵ�ʽ��Ϊ3����3-��-8�� = 11����Ȼ�������ʵ�ʽ����-5��
���ԣ�swap�����еĵڶ��䣺 *b=*a-*b���൱��*b = *a+*b-*b�������û��Ӱ�졣


2.
���´�����ʲô����(A)
struct Test
{
	Test( int ) {}
	Test() {}
	void fun() {}
};
void main( void )
{
	Test a(1);
	a.fun();
	Test b();
	b.fun();
}
A b.fun���������
B Test�ṹ�Ķ�����Ӧ�ü���public���η�����������main�����е��ø���ķ���
C Test(int){} Ӧ�øĳ�Test(int a){}
D ����˵��������ȷ

ע��b.fun(); //b����Test��ʵ������
���ǽṹ���bai��չ,�����з�װ�˶����ݳ�duԱ�Ĳ���,ȱʡ�ĳ�ԱΪ˽�е�,
���ṹ��Ϊ����dao��,��������ǵ�����,�Թ��캯���ĵ���,���û�в���,�ǲ���Ҫ�������ŵ�,
�����������,�Ͳ��Ƕ���һ��������,����������һ������,���ظ�����,
���������Test b(),ʵ�����ǵ���һ��������Ϊb,��������ΪTest�ĺ���,�����Ǵ�����һ������b,
ȥ�����ź�,���ǵ��õ�û���βεĹ��캯����
*/



/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84?tpId=37&&tqId=21279&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
��ȫ����Perfect number�����ֳ����������걸������һЩ�������Ȼ����
�����е������ӣ����������������Լ�����ĺͣ������Ӻ�������ǡ�õ�����������
���磺28������Լ��1��2��4��7��14��28����ȥ������28�⣬����5������ӣ�1+2+4+7+14=28��
��������count(int n),���ڼ���n����(��n)��ȫ���ĸ��������㷶Χ, 0 < n <= 500000
����n������ȫ���ĸ����� �쳣�������-1
*/

/*
�������ͨ������ÿһ��Լ������ͣ��ж���ȫ����Լ��������Ա���sqrt(n)�ķ�Χ
*/
#include <iostream>
using namespace std;

bool ISPerfectNumber(int x)
{
	int sum = 0;
	int sq = sqrt(x);
	for (int i = 1; i < sq; i++)
	{

		if (x % i == 0)
			sum += i;
	}
	if (sum == x)
		return true;
	return false;
}


int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0, i = 0;
		for (int i = 1; i <= n; i++)
		{
			if (ISPerfectNumber(i))
				count++;
		}
		cout << count << endl;
	}
}


/*
2.
���ӣ�https://www.nowcoder.com/practice/0a92c75f5d6b4db28fcfa3e65e5c9b3f?tpId=49&&tqId=29277&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
�˿�����Ϸ���Ӧ�ö��Ƚ���Ϥ�ˣ�һ������54����ɣ���3~A��2��4�ţ�С��1�ţ�����1�š������С�����������ַ����ַ�����ʾ�����У�Сдjoker��ʾС������дJOKER��ʾ������:)
3 4 5 6 7 8 9 10 J Q K A 2 joker JOKER
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո��磺4 4 4 4-joker JOKER
��Ƚ������ƴ�С������ϴ���ƣ���������ڱȽϹ�ϵ�����ERROR
��������
��1������ÿ���ƿ����Ǹ��ӣ����ӣ�˳�ӣ�����5�ţ���������ը�����ĸ����Ͷ����е�һ�֣���������������������뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У�
��2������ը���Ͷ������Ժ������ƱȽ�֮�⣬�������͵���ֻ�ܸ���ͬ���͵Ĵ��ڱȽϹ�ϵ���磬���Ӹ����ӱȽϣ������������Ƚϣ��������ǲ���������磺�����Ӳ�ֳɸ��ӣ�
��3����С��������ƽʱ�˽�ĳ���������ͬ�����ӣ����ӣ������Ƚ������С��˳�ӱȽ���С�ƴ�С��ը������ǰ�����е��ƣ�ը��֮��Ƚ������С�������������ƣ�
��4������������Ʋ��������ȵ������

����ʾ��
��1������ը���Ͷ���֮�⣬��������ͬ���ͱȽϡ�
��2�������Ѿ���֤�Ϸ��ԣ����ü�������Ƿ��ǺϷ����ơ�
��3�������˳���Ѿ�������С����������˲�����������.
��������:
���������ƣ�������֮���á�-�����ӣ�ÿ���Ƶ�ÿ�����Կո�ָ�����-������û�пո���4 4 4 4-joker JOKER��
�������:
����������нϴ�����֣��������ӷ����˿���˳�򲻱䣬���Կո��������������ڱȽϹ�ϵ�����ERROR��
ʾ��1
����
4 4 4 4-joker JOKER
���
joker JOKER
*/

/*
˼·��
�������Ŀ��˼�������ֻ����Щ�����е�һ�֣����ӣ����ӣ�˳�ӣ�����5�ţ���������ը��
���ĸ����Ͷ�������ʵ�������5���ƣ�˳�ӣ�������1һ����֮��ıȽϡ����������������
�����뱣֤�����ƶ��ǺϷ��ģ�˳���Ѿ���С�������У����������������͵�ȷ���ʹ�С�ıȽ�
ֱ�ӿ���ת��Ϊ�Ƹ����ıȽ�
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string line;
	while (getline(cin, line)){
		//��ը���ֱ�����
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			//�ֿ�������
			string car1 = line.substr(0, dash);
			string car2 = line.substr(dash + 1);
			//��ȡ�ո�Ĵ���������Ϊc + 1
			int c1 = count(car1.begin(), car1.end(), ' ') + 1;
			int c2 = count(car2.begin(), car2.end(), ' ') + 1;
			//�õ���һ����
			string first1 = car1.substr(0, car1.find(' '));
			string first2 = car2.substr(0, car2.find(' '));
			string str = "345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//ֻҪ������ȣ����һ���ƴ�ļ�Ϊ��
				if (str.find(first1) > str.find(first2))
					cout << car1 << endl;
				else
					cout << car2 << endl;
			}
			else
			{
				//��������ͬ��˵�����Ͳ�ͬ,ֻ��ը�����Ժ������ƱȽ�
				//�������Ͷ��Ǵ����
				if (c1 == 4)
				cout << car1 << endl;
				else if (c2 == 4)
					cout << car2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
}
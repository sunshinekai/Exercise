/*
ѡ���⣺

1.
��Ƕ��ʹ��if���ʱ��C���Թ涨else����(C)��
A ��֮ǰ���������ͬ����λ�õ�if���
B ��֮ǰ���������if���
C ��֮ǰ����������Ҳ���else��if���
D ��֮ǰ�ĵ�һ��if���

ע��if elseʹ�ù���

2.
���³������������(C)
#include <stdio.h>
int main()
{
	int i,a[10];
	for(i=9;i>=0;i--) a[i]=10-i;
	printf("%d%d%d",a[2],a[5],a[8]);
	return 0;
}

A 258
B 741
C 852
D 369

ע��a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

3.
������벻����ȷ���hello��ѡ��Ϊ(B)

#include <stdio.h>
#include <stdlib.h>
struct str_t{
	long long len;
	char data[32];
};

struct data1_t{
	long long len;
	int data[2];
};

struct data2_t{
	long long len;
	char *data[1];
};
struct data3_t{
	long long len;
	void *data[];
};

int main(void)
{
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	str.len = sizeof(struct str_t) - sizeof(int);
	snprintf(str.data, str.len, "hello");//VS��Ϊ_snprintf
	____________________________________;
	____________________________________;
	return 0;
}

A struct data3_t *pData=(struct data3_t*)&str; printf("data:%s%s\n",str.data,(char*)(&(pData->data[0])));
B struct data2_t *pData=(struct data2_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data[0]));
C struct data1_t *pData=(struct data1_t*)&str;printf("data:%s%s\n",str.data,(char*)(pData->data));
D struct str_t *pData=(struct str_t*)&str; printf("data:%s%s\n",str.data,(char*)(pData->data));

ע��B����ɶδ���

4.
����һ����γ�������(A)
#include<iostream>
using namespace std;
class B
{
public :
	B()
	{
		cout << "default constructor" << " ";
	} 
	~B()
	{
		cout << "destructed" << " ";
	}
	B(int i) : data(i)
	{
		cout << "constructed by parameter" << data << " ";
	} 
private : int data;
};
B Play(B b)
{
	return b;
} 
int main(int argc, char *argv[])
{
	B temp = Play(5);
	return 0;
}

A constructed by parameter5 destructed destructed
B constructed by parameter5 destructed
C default constructor" constructed by parameter5 destructed
D default constructor" constructed by parameter5 destructed destructed

ע��
����ִ������Ϊ
ִ��f(5) �൱��baif((B)5)
��5������ʱ������Ϊf���� �����ù��캯��B(int i) ��ӡ
constructed by parameter 5
�˳�����f ��ʱ�������� ��ӡ
destructed
����ֵ����t1 ����Ĭ�ϸ��ƹ��캯��
ִ��f(t1)
��t1������ʱ������Ϊf���� ����Ĭ�ϸ��ƹ��캯��
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/668603dc307e4ef4bb07bcd0615ea677?tpId=37&&tqId=21297&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
�������������������
xcopy /s c:\ d:\��
�����������£�
����1��������xcopy
����2���ַ���/s
����3���ַ���c:\
����4: �ַ���d:\

���дһ��������������ʵ�ֽ������и�����������������

��������
1.�����ָ���Ϊ�ո�
2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy /s ��C:\program files�� ��d:\��ʱ��
������Ȼ��4������3������Ӧ�����ַ���C:\program files��������C:\program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
3.����������
4.������������֤��������ֲ�����Ҫ�������
*/

/*
����ͨ���Կո��˫����Ϊ�����ͳ�Ʋ�������������˫���ţ�ͨ�����flag����֤˫�����е�
�ո����
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0;
		//���ȼ����������
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
				count++;
			//�����˫���ţ���������ֱ����һ��˫���Ž���
			if (str[i] == '"')
			{
				do
				{
					i++;
				} while (str[i] != '"');
			}
		} 
		// �Կո����������ո������Ȳ���������1
			cout << count + 1 << endl;
		//��flag��ʾ�Ƿ����˫���ţ�0��ʾ��˫����
		//˫�����еĿո�Ҫ��ӡ����
		//�����ı�flag��ֵ������˫���ſ���ʹflag��ԭ
		int flag = 1;
		for (int i = 0; i < str.size(); i++)
		{
			//��˫���ţ�flagͨ������Ϊ0����һ��������˫���ţ�flag��Ϊ1
			if (str[i] == '"')
				flag ^= 1;
			//˫���ź���ͨ�ո񲻴�ӡ
			if (str[i] != ' ' && str[i] != '"')
				cout << str[i];
			//˫�����еĿո�Ҫ��ӡ
			if (str[i] == ' ' && (!flag))
				cout << str[i];
			//����˫����֮��Ŀո�ͻ���
			if (str[i] == ' ' && flag)
				cout << endl;
		}
		cout << endl;
	} 
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/practice/4284c8f466814870bae7799a07d49ec8?tpId=85&&tqId=29852&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����
������K+X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
���磺
N = 4��M = 24��
4->6->8->12->18->24
����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��

����
4 24

���
5
*/

/*��1 - M��ʯ�忴��һ���������stepNum��ÿ��stepNum[i]�����Ŵ���㵽��һ����С�Ĳ�
��������0Ϊ���ܵ��
����㿪ʼ��stepNum���б���������i������Լ��������stepNum[i]���ߵĲ�������Ȼ�����
�Ǽ����ܵ����λ�õ���С������������ܵ��������Ϊ��ʱλ�õ���С���� + 1��������ܵ���
�ľ͸���Ϊmin���Ѽ�¼����С�������˴�����С���� + 1����������һ���õ����*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// ����Լ���������1�ͱ����Լ��
void divisorNum(int n, vector<int> &divNum)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			divNum.push_back(i);
			//��ƽ����ʱ������һ����ҲҪ����
			if (n / i != i)
				divNum.push_back(n / i);
		}
	}
} 

int Jump(int N, int M)
{
	//����ĵ����stepNum��Ĳ�������ʼNΪ1������N��NΪ1��
	vector<int> stepNum(M + 1, 0);
	stepNum[N] = 1;
	for (int i = N; i < M; i++)
	{
		//N������Լ������Ϊ�ӱ�������㿪ʼ���ߵ�����
		vector<int> divNum;
		//0��������㲻�ܵ�
		if (stepNum[i] == 0)
			continue;
		//����������ߵĲ���������divNum��������
		divisorNum(i, divNum);
		for (int j = 0; j < divNum.size(); j++)
		{
			//��λ��i�����ܵ���ĵ�Ϊ stepNum[divNum[j]+i]
			if ((divNum[j] + i) <= M && stepNum[divNum[j] + i] != 0)
				stepNum[divNum[j] + i] = min(stepNum[divNum[j] + i],stepNum[i] + 1);
			else if ((divNum[j] + i) <= M)
				stepNum[divNum[j] + i] = stepNum[i] + 1;
		}
	} 
	if(stepNum[M] == 0)
		return -1;
	else
		// ��ʼ��ʱ�����һ��������Ҫ��1
		return stepNum[M] - 1;
} 

int main()
{
	int n, m;
	cin >> n >> m;
	cout << Jump(n, m) << endl;
	return 0;
}
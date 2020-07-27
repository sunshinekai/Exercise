/*
ѡ���⣺

1.
mysql���ݿ���ѡ�α�learn(student_id int,course_id int),�ֶηֱ��ʾѧ�źͿγ̱�ţ��������ȡÿ��
ѧ����ѡ�γ̵ĸ�����Ϣ���������µ�sql�����ȷ���ǣ�B��
A select student_id,sum(course_id)from learn
B select student_id,count(course_id)from learn group by student_id
C select student_id,count(course_id)from learn
D select student_id,sum(course_id)from learn group by student_id

2.
ִ������ SQL �������ĸ����ֻᱻ��ѯ������C��
SELECT FirstName FROM StaffList WHERE FirstName LIKE��_A%��
A Allen
B CLARK
C JACKSON
D David

ע��
_ȡһ���ַ���%ȡһ���ַ�

3.
�ж�����orders�������ֶ��û���Ϣuserid���ֶβ�Ʒ��Ϣproductid����������ܹ��������ٱ���������
���productid(D)
A select productid from orders where count��productid��>1
B select productid from orders where max��productid��>1
C select productid from orders where having count��productid��>1 group by productid
D select productid from orders group by productid having count��productid��>1

ע��
having��group by֮��
*/


/*
����⣺

1.
���ӣ�https://www.nowcoder.com/questionTerminal/661c49118ca241909add3a11c96408c8
�� n ��ѧ��վ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ����� n ��ѧ���а���˳��ѡȡ k ��ѧ����
Ҫ����������ѧ����λ�ñ�ŵĲ���� d��ʹ���� k ��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻���

ʾ����
����
3
7 4 7
2 50
���
49
*/


/*
����˼·��
�Ը�����ķֽ��ǹؼ��� ��n��ѧ���У�ѡ��k�������Կ����ǣ��ȴ�n��ѧ����ѡ�����1����Ȼ����ʣ�µ�
��ѡ��k - 1������������1����ǰk - 1������Լ������ �ǵ�k���˵�λ��Ϊone, ������� f[one][k] ��ʾ��n��
����ѡ��k���ķ�����Ȼ�����������⣬��Ҫ��oneǰ���left�������棬ѡ��k - 1��������left��ʾk - 1����
�����һ��������k - 1�����˵�λ�ã���ˣ���������Ա�ʾ�� f[left][k - 1] .
һ��Ķ�̬�滮��Ŀ���м�ʹ�õı�����һ��Ԫ�أ� dp[N][K] ��������Ľ���� �������Ŀ����������
��Ϊ�����������������ͳ��ˡ���ǰn��ѧ���У�ȡk����ʹ�˻���� Ȼ��������Ŀ�ж����������������
������ѧ����λ�ñ�ŵĲ����d����û�а취������ƹ�ʽ�ˣ� ��Ϊ�������б���������λ����Ϣ��
��n��ѧ���У�ѡ��k�������Կ����ǣ��ȴ�n��ѧ����ѡ�����1����Ȼ����ʣ�µ���ѡ��k - 1������������1
����ǰk - 1������Լ������ �ǵ�k���˵�λ��Ϊone, ������� f[one][k] ��ʾ��n������ѡ��k���ķ�����Ȼ
�����������⣬��Ҫ��oneǰ���left�������棬ѡ��k - 1��������left��ʾk - 1���������һ��������k - 1
�����˵�λ�ã���ˣ���������Ա�ʾ�� f[left][k - 1] .
��Σ������˻��������͵�����Ҫ������ࡣ�����͵Ļ�����������Ҳֻ��Ҫ�����;����ˡ� ����
���˻���ʱ�����������У�ÿһ����Ҫ�������������С������ ��Ϊ���ĳѧ��������ֵΪ����������
ǰ����õ���С����������������˻���
*/

#include <iostream>
#include <string>
#include <vector>
#include <climits> // �� LONG_MIN LONG_MAX
using namespace std;
// NK���ŵ��ǣ���ǰn��ѧ���У�ȡk������ȡ��n���������ȵõ���������˻�����С���˻���
long long NK_zheng[51][11];
long long NK_fu[51][11];
int main() 
{
	int N;
	cin >> N;
	vector<int> V(N + 1);
	for (int i = 1; i <= N; i++) 
	{
		cin >> V[i];
	}
	int K, D;
	cin >> K >> D;
	// �������ȳ�ʼ��
	for (int n = 1; n <= 50; n++) 
	{
		for (int k = 1; k <= 10; k++) 
		{
			NK_zheng[n][k] = LLONG_MIN; // ������Чֵ
			NK_fu[n][k] = LLONG_MAX;
		}
	}

	for(int n = 1; n <= N; n++) 
	{
		if (V[n] >= 0)
			NK_zheng[n][1] = V[n];
		else
			NK_fu[n][1] = V[n];
	}

	for(int n = 2; n <= N; n++) 
	{
		for (int k = 2; k <= K && k <= n; k++)
		{
			// �ҵ�NK[...][k-1]��������������С�ĸ�����
			long long max = LLONG_MIN, min = LLONG_MAX;
			for (int temp = (k - 1 > n - D) ? (k - 1) : (n - D); temp <= n - 1; temp++)
			{
				// ��ʼλ�ú���Ҫ
				if (max < NK_zheng[temp][k - 1])
					max = NK_zheng[temp][k - 1];
				if (min > NK_fu[temp][k - 1])
					min = NK_fu[temp][k - 1];
			}
			if (max != LLONG_MIN)
			{
				if (V[n] >= 0)
					NK_zheng[n][k] = max * V[n];
				else
					NK_fu[n][k] = max * V[n];
			}
			if (min != LLONG_MAX)
			{
				if (V[n] < 0 && NK_zheng[n][k] < min * V[n])
					NK_zheng[n][k] = min * V[n];
				else if (NK_fu[n][k] > min * V[n])
					NK_fu[n][k] = min * V[n];
			}
		}
	} 

	// ������������һ���У��ҳ����ĳ˻���
	long long max1 = LLONG_MIN, max2 = LLONG_MIN;
	for (int n = K; n <= N; n++) 
	{
		if (max1 < NK_zheng[n][K])
			max1 = NK_zheng[n][K];
		if (max2 < NK_fu[n][K] && NK_fu[n][K] != LLONG_MAX)
			max2 = NK_fu[n][K];
	}
	max1 = max1 > max2 ? max1 : max2;
	cout << max1 << endl;
}


/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/c2afcd7353f84690bb73aa6123548770

�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ��������ų����ʹ��������ǰ�������ۣ�
С�����������˽⵽�� ��Ϸ���������һ���½�Ŀ������޺�����������Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�
վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� �ų���Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬
����ͷ����ΰ�����Ա�����⡣С�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա��������أ����Һܿ��ҵ�������޺�������Ա���С�
����������Ҳ�õ�������һ��������ر����ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��

ʾ��:
����
6
1 65 100
2 75 80
3 80 100
4 60 95
5 82 101
6 81 70

���
4
*/

/*
ע��! ������ͬʱ�� ֻ�������ͬ���ܵ�. �����������У� ������ͬʱ������߽������� ���������ǰ�����
�����ݽ����������������
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct player
{
	int w;
	int h;
};

bool com_w(player p1, player p2)
{
	//�������ش�С��������
	if (p1.w != p2.w)
		return p1.w <= p2.w;
	//��������ȵ������£���߸ߵ���ǰ�����ϣ�
	else
		return p1.h>p2.h;
} 

int main(void)
{
	int N;
	int h;
	int w;
	int index;
	vector<player> p;
	while (cin >> N)
	{
		p.clear();
		// ��������
		for(int i = 0; i<N; i++)
		{
			player pt;
			cin >> index >> w >> h;
			pt.w = w;
			pt.h = h;
			p.push_back(pt);
		} 
		sort(p.begin(), p.end(), com_w);
		//����������������������(�˴�Ϊ���Ĵ���)

		int dp2[N + 1];
		int max = 0;
		dp2[0] = 1;
		for (int i = 1; i<N; i++)
		{
			dp2[i] = 1;
			for (int j = 0; j<i; j++)
			{
				if (p[j].h <= p[i].h && dp2[j] + 1 > dp2[i])
					dp2[i] = dp2[j] + 1;
			}
		} 
		// �ҳ� dp2 ����������, ��Ϊ���ս��
		for (int i = 0; i<N; i++)
		if (max < dp2[i])
			max = dp2[i];
		cout << max << endl;
	}
	return 0;
}

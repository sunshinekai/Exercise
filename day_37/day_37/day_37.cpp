/*
ѡ����

1.
A,B��̨��������������,B����δ�����κζ˿�.���A������B����80�˿ڷ���SYN��,���յ��������͵Ļذ�(D)
A ACK��
B FIN��
C �����յ��ذ�
D RST��
ע��
��ΪB����δ�����κζ˿�,A����B��80�˿ڷ��������ݰ�,����B���Ὠ������,
���쳣������������,�ᷢ�� RST ��,��������������Ļ��ͻᷢ�� FIN��,
RST �� TCP ������ ���ֲ�������, RST ��1���������ܾ�һ���Ƿ��ı��Ķλ�ܾ���һ�����ӡ�

2.
�����ĸ�ip����10.11.12.91/28����ͬһ������()
A 10.11.12.85/28
B 10.11.12.88/28
C 10.11.12.94/28
D 10.11.12.97/28
ע��
IP��ַ������ź���������ɣ�ǰ28λΪ����ţ�����ǰ28λ����ͬ���ɵ���������Ϊ��255.255.255.240����>��11111111.111111111.111111111.11110000��
������IP��ַǰ���ֶ���10.11.12�����ֻ�ù�ע���沿�֣�
10.11.12.91/28��91�ɱ�ʾΪ01011011��ǰ4λΪ����ţ�����λΪ�����ţ�
λ��ͬһ����ֻ�����������ż��ɣ��ʰ���10.11.12.91��������Χ�ǣ�01010000~01011111������80-95����
���ֻ��D������Ҫ��
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/questionTerminal/05f97d9b29944c018578d98d7f0ce56e

Webϵͳͨ����Ƶ���ط������ݿ⣬���ÿ�η��ʶ����������ӣ����ܻ�ܲ
Ϊ��������ܣ��ܹ�ʦ���������Ѿ����������ӡ����յ����󣬲������ӳ���û��ʣ����õ�����ʱ��
ϵͳ�ᴴ��һ�������ӣ������������ʱ�����ӻᱻ�������ӳ��У�����������ʹ�á�
�����ṩ�㴦���������־���������һ�����ӳ������Ҫ�������ٸ����ӡ�

����
6
A connect
A disconnect
B connect
C connect
B disconnect
C disconnect
���
2
*/


/*
[��Ŀ����]
1. ��������̨�������ݿ�ʱ����Ҫ���������ݿ⣬��Ϊ���������ݿ⣬��Ҫ���ӷ������ݿ�����ϸ��Զ�
Ҫά�����ӣ������ӱ���Ĵ���ά�����гɱ���
2. Ҫ���ٿ���������Ľ���������ǽ���ǰ��mysql���Ӹ����������Ӷ���ʡ�˴��������ٵ�ʱ��ɱ���
����Ŀ��������������㷨�������־�����㵱ǰ��ҵ����ҪԤ�ȴ����������ӣ�����������ʹ��
[����˼·]
ʹ��һ��set���������ĳ����¼��connect���ͼӵ�set��ȥ�������disconnect���Ͱ�set�ж�Ӧ��ֵɾ��
�����ڼӽ�ȥ�Ĺ����У������ж�setԪ�ص������������շ���������������ɡ�
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		set<string> pool;
		string id, con;
		int maxSize = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> id >> con;
			if (con == "connect") 
				pool.insert(id);
			else if (con == "disconnect")
				pool.erase(id);
			int size = pool.size();
			maxSize = max(maxSize, size);
		}
		cout << maxSize << endl;
	}
	return 0;
}



/*
2.
���ӣ�https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a

�����У�ÿ��Ҫ����һ̨�»�����ʱ�򣬾���ζ����һ��Ŀ¼��Ҫ����������Ҫ����Ŀ¼��/usr/local/bin����
����Ҫ�˴δ�����/usr������/usr/local���Լ���/usr/local/bin�������ڣ�Linux��mkdir�ṩ��ǿ��ġ�-p��ѡ�
ֻҪһ�����mkdir -p /usr/local/bin�������Զ�������Ҫ���ϼ�Ŀ¼��
���ڸ���һЩ��Ҫ�������ļ���Ŀ¼�������æ������Ӧ�ġ�mkdir -p�����

����
3
/a
/a/b
/a/b/c
3
/usr/local/bin
/usr/bin
/usr/local/share/bin
���
mkdir -p /a/b/c

mkdir -p /usr/bin
mkdir -p /usr/local/bin
mkdir -p /usr/local/share/bin
*/


/*
[��Ŀ����]
1. ����Ŀ��Ҫ���˽� mkdir -p �����������Եݹ鴴��Ŀ¼
2. ���Ǹ���Ŀ��ʵ�������ǽ���������ǣ�����һ�����ݣ��������Ŀ������ô�����ٵ� mkdir -p ����
��������Ҫ�Ķ��Ŀ¼
[����˼·]
ֻҪ�������棬��ǰ׺�ַ���·������ͬ·���޳���ֻmkdir ��p�����Ψһ·���Ϳ��Խ���������
*/


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end()); //�������ַ����������򣬷���һ��
		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1��������ͬ
			// 2��ǰ���Ǻ󴮵��Ӵ������Һ󴮺�һλ�� '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1]
				[list[i].size()] == '/')
				flag[i] = false;
		} 
		for(int i = 0; i < list.size(); ++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	} 
	return 0;
}
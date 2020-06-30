/*
ѡ����

��N�����Ⱦ�ΪM�������������кϲ����ϲ��Ժ������Ҳ��������ʱ�临�Ӷ�Ϊ(A)
A O(N * M * logN)
B O(N*M)
C O(N)
D O(M)

1. ��ÿһ��������ȡ����һ��ֵ��Ȼ������Ƿ���һ����СΪN�������
Ȼ���������鵱��heap����С(��)���ѡ��˲����ʱ�临�Ӷ�ΪO(N)��N��������һ���ѵĸ��Ӷ���O(N)
2. ȡ�����е���Сֵ(Ҳ������ĵ�һ��ֵ), Ȼ��Ѹ���Сֵ��������������һ��ֵ��������ĵ�һ��λ�á�
�����������һ���Ѿ�Ϊ�գ�Ԫ���Ѿ�����ȡ��������ı�heap�Ĵ�С���˲����ʱ�临�Ӷ�ΪO(lg N)��
3. ���ϵ��ظ��������ֱ�����е�������Ϊ�ա�
����ֻ��һ�Σ����Ӷ�ΪO(N)��������MN-1�Σ�������ʱ������˸���㣬ʣ�µ���Ŀ��MN-1�����������Ӷ�Ϊ(MN-1)*O(lg N)��
4.���Ӷ���O(N)+(MN-1)*O(lg N)�����Ը��Ӷ�ΪO(MN*lg N)
*/


/*
�����

1.
���ӣ�https://www.nowcoder.com/practice/72a99e28381a407991f2c96d8cb238ab?tpId=49&&tqId=29305&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking

С�����ڹ�˾Ҫ�����ս�����С��ǡ�û������߸�������Ҫ�ڹ�˾����ϲ���һ���齱��Ϸ����Ϸ��һ��6*6�������Ͻ��У�
�������36����ֵ���ȵ����ÿ��С���������������һ���������Ҫ�����Ͻǿ�ʼ��Ϸ��ÿ��ֻ�����»��������ƶ�һ����
�������½�ֹͣ��һ·�ϵĸ����������С�������õ��������һ���㷨ʹС���õ���ֵ��ߵ����
����һ��6*6�ľ���board������ÿ��Ԫ��Ϊ��Ӧ���ӵ������ֵ,���Ͻ�Ϊ[0,0],�뷵���ܻ�õ�����ֵ����֤ÿ�������ֵ����100С��1000��
*/


/*
˼·��
������Ҫʹ�ö�̬�滮��⡣
����f(i,j)��ʾ�����Ͻ��ߵ�����(i��j)���ܻ�õ��������
�������д����Ͻ��ߵ����½ǵ�·�����ҵ�����·����
f(i,j)�����������
��һ�У�f(i, 0) = f(i-1, 0) + board(i, 0)
��һ�У�f(0,j) = f(0, j - 1) + b(0, j)
����λ�ã�f(i, j) = max{f(i-1, j), f(i, j - 1)} + board(i, j)
��󷵻����½ǵ�ֵ
*/

class Bonus {
public:
	int getMost(vector<vector<int> > board) 
	{
		int length = board.size();
		int wideth = board[0].size();
		vector<vector<int>> allPrice;
		for (int i = 0; i < length; i++) 
		{
			vector<int> tmp(wideth, 0);
			allPrice.push_back(tmp);
		}
		allPrice[0][0] = board[0][0];
		for (int i = 0; i < length; i++) 
		{
			for (int j = 0; j < wideth; j++)
			{
				//�����������꣬�����κδ�����
				if (i == 0 && j == 0)
					continue;
				//��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
				//�����ߵ�ʱ��õ��Ҫ�������ֵ��������
				else if (i == 0) 
				{
					allPrice[i][j] = allPrice[i][j - 1] + board[i][j];
				}
				//��������е��ٽ�ߣ�Ҳ���ǵ�һ�У���ô��ֻ��������
				//�����ߵ�ʱ��õ��Ҫ�������ֵ��������
				else if (j == 0)
				{
					allPrice[i][j] = allPrice[i - 1][j] + board[i][j];
				}

				else
				{
					//��ȥ�����ٽ�ߣ�ʣ�µľ��Ǽ��������ߣ�Ҳ�������ߣ�
					//��ʱ���Ҫ�����ߵ���ǰ������п��ܵ������Ҳ�����ߵ���ǰ��
					//����·���ĺ��ǲ�����Щ���е���õ�·�����������ˡ�
					allPrice[i][j] = max(allPrice[i][j - 1], allPrice[i - 1][j]) + board[i][j];
				}
			}
		}
		// �������һ��������ֵ�����ͱ�ʾ�����Ͻ��ߵ����½ǵ������
		return allPrice[length - 1][wideth - 1];
	}
};


/*
2.
���ӣ�https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc?tpId=37&&tqId=21266&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
����һ����ά����N*M������2<=N<=10;2<=M<=10������5 �� 5��������ʾ��


int maze[5][5] = 
{
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

����ʾһ���Թ������е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·��ֻ�ܺ����߻������ߣ�����б���ߣ�
Ҫ�������ҳ������Ͻǵ����½ǵ����·�ߡ���ڵ�Ϊ[0,0],�ȵ�һ�ո��ǿ����ߵ�·��

Input
һ��N �� M�Ķ�ά���飬��ʾһ���Թ������ݱ�֤��Ψһ��,�������ж�����������Թ�ֻ��һ��ͨ����
Output
���Ͻǵ����½ǵ����·������ʽ��������ʾ��

Sample Input
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

Sample Output
(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)
*/


/*
������û��ݷ���� 
���岽��Ϊ��
1. ���Ƚ���ǰ�����·����������Ϊ����
2. �жϵ�ǰ���Ƿ�Ϊ���ڣ��������·��������������ת��4
3. �����жϵ�ǰ����ϡ��¡������ĸ����Ƿ���ߣ����������ݹ��߸õ�
4. ��ǰ���Ƴ�·��������Ϊ����
*/

#include<iostream>
#include<vector>
using namespace std;
int N, M; //�ֱ�����к���
vector<vector<int>> maze;//�Թ�����
vector<vector<int>> path_temp;//�洢��ǰ·������һά��ʾλ��
vector<vector<int>> path_best;//�洢���·��

void MazeTrack(int i, int j)
{
	maze[i][j] = 1;//��ʾ��ǰ�ڵ����ߣ���������
	path_temp.push_back({ i, j });//����ǰ�ڵ���뵽·����
	if (i == N - 1 && j == M - 1) //�ж��Ƿ񵽴��յ�
	if (path_best.empty() || path_temp.size() < path_best.size())
		path_best = path_temp;
	if (i - 1 >= 0 && maze[i - 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i - 1, j);
	if (i + 1 < N && maze[i + 1][j] == 0)//̽���������Ƿ����
		MazeTrack(i + 1, j);
	if (j - 1 >= 0 && maze[i][j - 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j - 1);
	if (j + 1 < M && maze[i][j + 1] == 0)//̽���������Ƿ����
		MazeTrack(i, j + 1);
	maze[i][j] = 0; //�ָ��ֳ�����Ϊδ��
	path_temp.pop_back();
} 

int main()
{
	while (cin >> N >> M)
	{
		maze = vector<vector<int>>(N, vector<int>(M, 0));
		path_temp.clear();
		path_best.clear();
		for (auto &i : maze)
		for (auto &j : i)
			cin >> j;
		MazeTrack(0, 0);//����Ѱ���Թ����ͨ·
		for (auto i : path_best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;//���ͨ·
	} 
	return 0;
}
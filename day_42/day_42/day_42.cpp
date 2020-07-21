/*
选择题
1.
常见的http错误描述原因错误的是(D)
A 404-Not found（没有找到）
B 302-临时重定向
C 500-内部服务器错误
D 403- IP address rejected

注：
302 Found请求的资源现在临时从不同的URI响应请求。由于这样的重定向是临时的，客户端应当继续向原有地址发送以后的请求。只有在Cache-Control或
Expires中进行了指定的情况下，这个响应才是可缓存的。新的临时性的URI应当在响应的Location域中返回。除非这是一个HEAD请求，否则响应的实体中应当
包含指向新的URI的超链接及简短说明。如果这不是一个GET或者HEAD请求，那么浏览器禁止自动进行重定向，除非得到用户的确认，因为请求的条件可能因此
发生变化。注意：虽然RFC 1945和RFC 2068规范不允许客户端在重定向时改变请求的方法，但是很多现存的浏览器将302响应视作为303响应，并且使用GET方
式访问在Location中规定的URI，而无视原先请求的方法。状态码303和307被添加了进来，用以明确服务器期待客户端进行何种反应。
307 Temporary Redirect
请求的资源现在临时从不同的URI响应请求。由于这样的重定向是临时的，客户端应当继续向原有地址发送以后的请求。只有在Cache-Control或Expires中进行了
指定的情况下，这个响应才是可缓存的。新的临时性的URI应当在响应的Location域中返回。除非这是一个HEAD请求，否则响应的实体中应当包含指向新的URI
的超链接及简短说明。因为部分浏览器不能识别307响应，因此需要添加上述必要信息以便用户能够理解并向新的URI发出访问请求。如果这不是一个GET或者
HEAD请求，那么浏览器禁止自动进行重定向，除非得到用户的确认，因为请求的条件可能因此发生变化。

2.
Linux中，一个端口能够接受tcp链接数量的理论上限是(D)
A 1024
B 65535
C 65535 * 65535
D 无上限

注：
不考虑ip地址分类等因素，最大tcp连接数约为2的32次方（ip数）×2的16次方（port数），也就是server端单机最大tcp连接数约为2的48次方。

3.
TCP报文首部信息中与关闭连接有关的是(D)
A URG
B ACK
C SYN
D FIN

注：
URG:URG=1时，表明紧急指针字段有效，告诉系统有紧急字段需要立即传送。
ACK:ACK=1时确认好才有效，ACK=0时，确认号无效。TCP规定在连接建立之后所有传送的报文都必须吧ACK置1.
RST：RST=1时表示TCP连接出现严重差错，必须释放连接再重新建立连接。
FIN：FIN=1表示要求释放连接。
*/


/*
编程题

1.
链接：https://www.nowcoder.com/questionTerminal/16fa68271ee5448cafd504bb4a64b482

nowcoder要和朋友交流一些敏感的信息，例如他的电话号码等。因此他要对这些敏感信息进行混淆，
比如在数字中间掺入一些额外的符号，让它看起来像一堆乱码。
现在请你帮忙开发一款程序，解析从nowcoder那儿接收到的信息，读取出中间有用的信息。

示例：
输入
$Ts!47&*s456  a23* +B9k
输出
47456239
*/

/*
思路
1. 题目明确说明有多行：采用getline进行循环输入
2. 对输入的字符串进行遍历，如果是数字字符，将其输出即可
*/

#include<iostream>
#include<string>

using namespace std;
int main(){
	string s;
	while (getline(cin, s))
	{
		int len = s.length();
		for (int i = 0; i<len; i++){
			if (s[i] >= '0'&&s[i] <= '9')
				cout << s[i];
		} 
		cout << endl;
	} 
	return 0;
}

/*
2.
链接：https://www.nowcoder.com/questionTerminal/6276dbbda7094978b0e9ebb183ba37b9

NowCoder最喜欢游乐场的迷宫游戏，他和小伙伴们比赛谁先走出迷宫。
现在把迷宫的地图给你，你能帮他算出最快走出迷宫需要多少步吗？

示例:
输入
#.########
#........#
#........#
#........#
#........#
#........#
#........#
#........#
#........#
########.#
#.########
#........#
########.#
#........#
#.########
#........#
########.#
#........#
#.######.#
########.#

输出
16
30
*/


/*
解题思路:
1. 采用一个二维数组，不断的接受迷宫地图(因为有多个地图)，获取到迷宫地图后，采用广度优先方式走
迷宫，找到的第一条路径一定是最短的路径，但是深度优先则不一定。
2. 结构设定：
pos：x，y表示当前所在位置，level所经过步数
dir: 表示当前位置的上、下、左、右四个方向
queue: 广度优先遍历，需要用到队列，保存所经路径
visit：对走过的路径进行标记
start和end表示入口和出口
3. 采用广度优先方式走迷宫：将start入队列，对该位置进行标记，只要队列不为空，继续以下步骤，直到
到达出口：
从队列中取出当前位置cur，计算该位置的上、下、坐、右四个方向，计算要走的下一步
如果next在出口的位置，已经找到返回所走步数level
否则：如果该位置有效(坐标在地图中)不是墙(该位置字符为'.')，并且没有走过(visit标记为false)
时，将该位置入队列，再继续其他几个方向
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
struct pos { int x, y, level; };
int bfs(vector<vector<char> > & map)
{
	const int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
	queue<pos> que;
	int m = map.size(), n = map[0].size();
	vector<vector<bool> > visit(m, vector<bool>(n, false));
	pos start{ 0, 1, 0 }, end{ 9, 8, 0 };
	que.push(start);
	visit[start.x][start.y] = true;
	while (!que.empty())
	{
		pos cur = que.front(), next; //定义cur和next
		que.pop();
		for (int i = 0; i < 4; ++i) //BFS,优先四个方向进行搜索
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x && next.y == end.y)
				return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n && \
				!visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				que.push(next);
				visit[next.x][next.y] = true;
			}
		}
	} 
	return 0;
} 

int main()
{
	vector<vector<char> > map(10, vector<char>(10));
	while (cin >> map[0][0]) //由多个测试用例，需要全部读取
	{
		for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
		{
			if (i == 0 && j == 0) continue;
			cin >> map[i][j];
		}
		cout << bfs(map) << endl;
	} 
	return 0;
}
//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
/*
  Some Search Algorithm
*/
/*First question
  ��1-n��ȫ����
  ���磺 n=3   
  �õ��� 123,132,213,231,312,321
  ˼·�� n=3ʱ�����������ӣ���������1��2��3�ֱ�����3�������У��������ѵķ�������������
  1. 1 2 3
  2. ��ʱ���� 1 3 2
*/
//using dfs
#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v(10,0);
vector<bool> book(10, false);       //��Ǿ���
void dfs(int step) {
	if (n+1== step) {
		//���һ��ȫ����
		for (int i = 1; i <= n; i++)
			cout << v[i];
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!book[i]) {            //δ�����
			v[step] = i;
			book[i] = true;
			dfs(step + 1);
			book[i] = false;       //����
		}
	}
}
int main() {
	cin >> n;
	dfs(1);
	return 0;
}
/*
  Seconde question
  ��������,�����0������Ϊ0,����һ��λ�ã������λ�õ�½�����
  1 2 1 0 0 
  3 0 2 0 1 
  1 2 0 2 1
  2 0 1 6 1
  4 1 0 2 0
  ������λ��Ϊ��4�У�4��(6),�����Ϊ7
  �����Դ�����bfs�Ƚϼ򵥣������������ҷ��������ļ�������У����ι������
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int m,n;                //m��,n��
	int startx, starty;     //��Ҫ�����Ŀ�ʼ��
	cin >> m >> n;
	cin >> startx >> starty;
	vector<vector<int>> map(m+1,vector<int>(n+1,0));     //�洢��ͼ
	vector<vector<int>> book(m + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	int next[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };      //�ֱ����ϣ��£����ҽ�������
	queue<pair<int,int>> que;      //�����м�¼����x��y������
	//��ʼ��
	que.push(pair<int, int>(startx, starty));
	book[startx][starty] = 1;             
	int sum = 1;
	while (!que.empty()) {
		for (int k = 0; k < 4; k++) {
			int tx = que.front().first + next[k][0];
			int ty = que.front().second + next[k][1];
			if (tx<1 || tx>m || ty<1 || ty>n) continue;
			if (book[tx][ty] == 0 && map[tx][ty] > 0) {      //Ϊ��ǣ�����Ϊ½��
				sum++;
				book[tx][ty] = 1;
				que.push(pair<int, int>(tx, ty));
			}
		}
		que.pop();
	}
	cout << sum << endl;
}


/*
  Third question
  ը������Ϸ
  #############
  #GG.GG##GGG.#
  ###.#G#G#G#G#
  #.......#..G#
  #G#.###.GGG.#
  ##G...G.....#
  #G#.#G##GG#G#
  #...G#GGG.GG#
  #G#.#G##G#G.#
  #GG.GGG#G.GG#
  #############
*/
#include<iostream>
#include <vector>
using namespace std;
int max = INT_MIN, mx, my,m,n;
//�������ķ���Ϊ20*20
vector<vector<char>> map(21, vector<char>(21,'.'));     
vector<vector<int>> book(21, vector<int>(21, 0));
//ͳ�Ʒ���x,y�������ĵ�����
int getsum(int x, int y) {
	int sum = 0;
	int i = x, j = y;
	while (i>=0&&map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		i--;
	}
	i = x; j = y;
	while (i <m && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		i++;
	}
	i = x; j = y;
	while (j >= 0 && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		j--;
	}
	i = x; j = y;
	while (j <n && map[i][j] != '#') {
		if (map[i][j] == 'G')
			sum++;
		j++;
	}
	return sum;
}
void dfs(int x, int y) {
	int next[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	int sum = getsum(x, y);
	if (sum>max) {       //������������
		max = sum;
		mx = x;
		my = y;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + next[i][0];
		int ty = y + next[i][1];
		if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
		if (book[tx][ty] == 0 && map[tx][ty] == '.') {
			book[tx][ty] = 1;      //���
			dfs(tx, ty);
		}
	}
	return;
}
int main() {
	int startx, starty;
	cin >> m >> n>>startx>>starty;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	dfs(startx, starty);
	cout << max << endl;
	cout << mx << " " << my << endl;
}
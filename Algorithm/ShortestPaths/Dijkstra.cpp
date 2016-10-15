//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  Dijkstra Algorithm
  ��Դ���·������.
  //��һ����Ϊ���㣬�ڶ�����Ϊ����
  //�����Ϊ �Ӷ���i,������j ��Ȩֵ w ,����1��2��ȨֵΪ2
  6 9
  1 2 1
  1 3 12
  2 3 9
  2 4 3
  3 5 5
  4 3 4
  4 5 13
  4 6 15
  5 6 4
*/
#include<iostream>
#include<vector>
using namespace std;
int m, n,u;
const int inf = 100;
//map��ʾ�ڽӾ���i��ʾ���i���㵽����ÿ����ľ���
vector<int> Dijkstra(vector<vector<int>> &map, int beg) {
	vector<int> book(m + 1, 0);    //��Ǿ���Ϊ0��ʾδȷ���Ƿ�����Сֵ
	vector<int> dis(m + 1, 0);     //���ؾ���
	book[beg] = 1;                   //����ǰ�ĵ��Ѿ�ȷ��Ϊ�����
	for (int i = 1; i <= m; i++)
		dis[i] = map[beg][i];
	//Dijkstra �����㷨
	for (int i = 1; i <= m - 1; i++) {   //m-1�αߵ��ɳ�
		int min = inf;
		for (int j = 1; j <= m; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;         //��¼λ�õ�
			}
		}
		book[u] = 1;           //�Ѿ�ȷ�ϵĴ�beg��u�����
		for (int v = 1; v <= m; v++) {       //ÿ����u����ĵ�v
			if (map[u][v] < inf) {
				if (dis[v] > dis[u] + map[u][v])    //�����Կ��ܷ񾭹�u��ת�õ���С�ľ���
					dis[v] = dis[u] + map[u][v];
			}
		}
	}
	return dis;
}
int main() {
	cin >> m >> n;
	//�ռ临�Ӷ�O(M^2),���Խ�һ���Ż�
	vector<vector<int>> map(m + 1, vector<int>(m + 1, 0));    //�ڽӾ���												  //��ʼ������
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if (i != j)
				map[i][j] = inf;
	//��������
	int t1, t2, t3;
	for (int i = 1; i <= n; i++) {
		cin >> t1 >> t2 >> t3;
		map[t1][t2] = t3;
	}
	vector<int>dis = Dijkstra(map, 1);      //��һ����
	for (int i = 1; i <= m; i++)
		cout << dis[i] << " ";
	cout << endl;
}

/*
  һ��ʵ����http://hihocoder.com/problemset/problem/1081
*/
#include<iostream>
#include<vector>
using namespace std;
const int n_max = 10010;
const int inf = 1 << 30;
int n, m, s, t, u;
//��������ȫ�ֱ����ᳬ���ڴ����ƣ�Ҫע��
//vector<vector<int>> map(n_max, vector<int>(n_max, inf));
vector<int> Dijkstra(vector<vector<int>>&map, int s) {          //sΪ���
	vector<int> dis(n + 1, inf);
	vector<int> book(n + 1, 0);
	for (int i = 1; i <= n; i++)        //��ʼ��dis����
		dis[i] = map[s][i];
	dis[s] = 0;
	book[s] = 1;
	for (int i = 1; i <= n - 1; i++) {   //n-1�αߵ��ɳ�
		int min = inf;
		//��һ�������
		for (int j = 1; j <= n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;         //��¼λ�õ�
			}
		}
		if (min == inf) break;
		book[u] = 1;           //�Ѿ�ȷ�ϵĴ�s��u�����
		for (int v = 1; v <= n; v++) {       //ÿ����u����ĵ�v
			if (map[u][v] < inf) {
				if (dis[v] > dis[u] + map[u][v] && book[v] == 0)    //�����Կ��ܷ񾭹�u��ת�õ���С�ľ���
					dis[v] = dis[u] + map[u][v];
			}
		}
	}
	return dis;
}
int main() {
	cin >> n >> m >> s >> t;
	vector<vector<int>> map(n + 1, vector<int>(n + 1, inf));
	for (int i = 1; i <= m; i++) {    //ע��m�Ǳ�,n�Ƕ���
		int a, b, c;
		cin >> a >> b >> c;
		if (c < map[a][b])          //�ر�ע��ѡ����С��·��
			map[a][b] = map[b][a] = c;
	}
	vector<int>dis = Dijkstra(map, s);
	cout << dis[t] << endl;
	return 0;
}

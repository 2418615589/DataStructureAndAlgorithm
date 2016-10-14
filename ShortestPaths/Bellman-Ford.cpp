//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  Bellman-Ford Algorithm
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
const int inf = 100;
int main() {
	int m, n;     //mΪ��������nΪ�ߵ���Ŀ
	cin >> m >> n;
	//ע��������������u,v,wȡ�����ڽӾ���u,v��ʾ����wΪȨ��
	vector<int> dis(m + 1,inf), u(n + 1), v(n + 1), w(n + 1);
	//���������
	for (int i = 1; i <= n; i++)      //i��ʾΪ�ڼ�����
		cin >> u[i] >> v[i] >> w[i];
	//��ʼ��dis����
	dis[1] = 0;          //�����ʾҪ�ҳ�1��������ľ���

	int check=0, flag = 0;    //check������ǰ�˳���flag���ڼ���Ƿ���
	//Bellman-Ford Algorithm�㷨���Ĵ���
	for (int k = 1; k <= m- 1; k++) {       //����m-1�αߵ��ɳ�
		check = 0;
		for (int i = 1; i <= n; i++) {
			if (dis[v[i]] > dis[u[i]] + w[i]) {
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		}
		if (check == 0) break;
	}

	//����Ƿ��и�Ȩֵ
	for (int i = 1; i <= n; i++)
		if (dis[v[i] > dis[u[i]] + w[i]])
			flag = 1;
	if (flag == 1) cout << "�и�Ȩֵ" << endl;
	else {
		for (int i = 1; i <= m; i++)
			cout << dis[i] << "  " << endl;
	}
	cout << endl;
}
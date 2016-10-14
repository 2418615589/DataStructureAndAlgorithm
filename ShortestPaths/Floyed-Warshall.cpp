//Author	: yqtao
//date		: 2016.09.19
//Email		: yqtao@whu.edu.cn
/*
  Floyed-Warshall Algorithm
  ��Դ���·������
  �����ʽ��
  4 8             //��һ����Ϊ���㣬�ڶ�����Ϊ����
  1 2 2           //�����Ϊ �Ӷ���i,������j ��Ȩֵ w ,����1��2��ȨֵΪ2
  1 3 6
  1 4 4
  2 3 3
  3 1 7
  3 4 1
  4 1 5
  4 3 12
*/

#include <iostream>
#include<vector>
const int inf = 100;
using namespace std;
int main() {
	int m, n;           //m�Ƕ���ĸ�����n�ߵĸ���
	cin >> m >> n;
	vector<vector<int>> map(m + 1, vector<int>(m + 1, 0));    //�ڽӾ����ʾͼ
	//��ʼ������
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
	//Floyed-Warshall Algorithm���Ĵ��룬����forѭ��
	for (int k= 1; k<= m; k++) {        //�ֱ��Զ���1...mΪ��ת��
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {                
				if (map[i][j] > map[i][k] + map[k][j])	// k = 2ʱ������1->3�ľ����������1->2->3�����
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}
	//������
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cout << map[i][j] << "  ";
		}
		cout << endl;
	}
}


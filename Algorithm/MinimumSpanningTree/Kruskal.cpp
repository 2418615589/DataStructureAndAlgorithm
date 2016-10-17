//Author	: yqtao
//date		: 2016.10.17
//Email		: yqtao@whu.edu.cn
/*
  ��С��������Kruskal�㷨
  ��Ȩֵ�����
  �������ݣ�
  6 9
  2 4 11
  3 5 13
  4 6 3
  5 6 4
  2 3 6
  4 5 7
  1 2 1
  3 4 9
  1 3 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//�����ṹ�壬����Ա߽�������
struct edge {
	int u;
	int v;
	int w;
};
edge e[10];       //����ֻ��9����
int n, m;
int f[10];        //���鼯
//
int getf(int v) {
	if (v == f[v])
		return f[v];
	else {
		f[v] = getf(f[v]);
		return f[v];
	}
}
int merge(int u, int v) {
	int t1 = getf(u);
	int t2 = getf(v);
	if (t1 != t2) {   //����һ��������
		f[t2] = t1;
		return 1;
	}
	return 0;
}
//��������
void quick_sort(int low, int high) {
	int i, j;
	edge pivot;
	if (low < high) {
		pivot = e[low]; i = low; j = high;
		while (i < j) {
			while (i<j&&e[j].w>pivot.w)
				j--;
			e[i] = e[j];
			while (i < j&&e[i].w < pivot.w)
				i++;
			e[j] = e[i];
		}
		e[i] = pivot;
		quick_sort(low, i - 1);
		quick_sort(i + 1, high);
	}
}
int main() {
	//����n,m������nΪ���������mΪ�ߵĸ���
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	//�Ա߽�������
	quick_sort(1, m);
	/*for (int i = 1; i <= m; i++) {
		cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
	}*/
	for (int i = 1; i <= n; i++)
		f[i] = i;
	
	//Kruskal�����㷨
	int count = 0, sum = 0;
	for (int i = 1; i <= m; i++) {
		if (merge(e[i].u, e[i].v)) {        //����������㲻��һ��������
			count++;
			sum += e[i].w;
		}
		if (count == n - 1) break;
	}
	cout << sum << endl;
	return 0;
}
//Author	: yqtao
//date		: 2016.10.14
//Email		: yqtao@whu.edu.cn
/*
  Ѱ�ҷ����Ż�
  ��һ��Ϊm=С͵������n=�����ռ�������Ϣ
  �ڶ��е����Ϊn���Ż���Ϣ
  ���ж��ٸ��Ż�
  10 9         
  1 2
  3 4
  5 2
  4 6
  2 6
  8 7
  9 7
  1 6
  2 4
*/
#include<iostream>
#include<vector>
using namespace std;
int m,n;
vector<int> f(101, 0);   //�������100��С͵
//��ʼ���Ĺ��̣��տ�ʼ���ǵ��Ż�����Լ�
void init() {
	for (int i = 1; i <= m; i++)
		f[i] = i;
}
//�������ȵĹ��̣�ֱ���ҵ�����λ��
int getf(int v) {
	if (v == f[v])     //�����������Լ�
		return v;
	else {
		//·��ѹ���Ĺ��̣�ÿ�κ�������ʱ��˳���޸��伯��
		f[v] = getf(f[v]);
		return f[v];
	}
}
//�ϲ������Ӽ��Ĺ���
void merge(int v,int u) {
	int t1, t2;
	t1 = getf(v);   //�������ȵĹ���
	t2 = getf(u);
	if (t1 != t2) {     //�������Ȳ�һ������������ͬһ�Ż��ϲ�
		f[t2] = t1;
	}
}
//
int main() {
	cin >> m >> n;
	init();
	int x, y;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		merge(x, y);
	}
	//����ж��ٸ������Ż�
	int sum = 0;
	for (int i = 1; i <= m; i++)
		if (i == f[i])
			sum++;
	cout << sum << endl;
}

/*
  һ��ʵ����
  http://hihocoder.com/problemset/problem/1066?sid=943717
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
 using namespace std;
 map< string, int > s;
 int father[100001];
 int find_set(int x) {
	 if (x == father[x])
		 return x;
	 else {
		 father[x] = find_set(father[x]);
		 return father[x];
	 }

 }
 void Union(int a, int b) {
		 int x = find_set(a);
	     int y = find_set(b);
	     if (x != y) father[x] = y;
}
int main() {
	     int n, c = 1;
	     bool ok;
	     cin >> n;
	     for (int i = 0; i <= n; ++i)     //��ʼ���Ĺ���
		         father[i] = i;
	     while (n--) {
		       string a, b;
		       cin >> ok >> a >> b;
		       if (s[a] == 0)  s[a] = c++;
		       if (s[b] == 0)  s[b] = c++;
			   if (ok) {
			       if (find_set(s[a]) == find_set(s[b]))
		              cout << "yes" << endl;
    	           else cout << "no" << endl;
			   }
		      else {
			       Union(s[a], s[b]);
		       }
	    }
	     return 0;
 }
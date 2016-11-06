//Author	: yqtao
//date		: 2016.09.07
//Email		: yqtao@whu.edu.cn
/*
�����������ʽ��ӵ�����
����˳��洢���ݽṹ
*/
#ifndef POLYADD_H
#define POLYADD_H
#include<vector>
#include<iostream>
using namespace std;
const int maxSize = 10;
struct polyElem
{
	double coef;    //����ʽϵ��
	int exp;        //ָ��
};
class polyClass
{
private:
	polyElem* data;
	int length;
public:
	polyClass() { data = new polyElem[maxSize]; length = 0; }
	~polyClass() { delete[] data; }
	void creatList(vector<double>& coef, vector<int>& exp);
	polyClass& operator=(polyClass& s);                   //���ز��������ڼ���p3=p1+p2
	friend polyClass& operator+(polyClass&, polyClass&);
	void sort();    //��һ������ʽ��ָ���Ӹߵ�������
	void display();
};


void polyClass::creatList(vector<double>& coef, vector<int>& exp) {
	for (int i = 0; i < coef.size(); i++) {
		data[i].coef = coef[i];
		data[i].exp = exp[i];
	}
	length = coef.size();
}
polyClass& polyClass::operator=(polyClass& s) {
	delete[] data;  //�ͷ�ԭ�еĿռ�
	data = new polyElem[maxSize];
	for (int i = 0; i < s.length; i++) {
		data[i].coef = s.data[i].coef;
		data[i].exp = s.data[i].exp;
	}
	length = s.length;
	return *this;
}
polyClass& operator+(polyClass& poly1, polyClass& poly2) {
	int i = 0, j = 0, k = 0;
	static polyClass poly3;        //��ΪҪ���ظö����������Ϊ��̬��
	while (i < poly1.length&&j < poly2.length) {
		if (poly1.data[i].exp > poly2.data[j].exp) {
			poly3.data[k].exp = poly1.data[i].exp;
			poly3.data[k].coef = poly1.data[i].coef;
			i++; k++;
		}
		else if (poly1.data[i].exp < poly2.data[j].exp) {
			poly3.data[k].exp = poly2.data[j].exp;
			poly3.data[k].coef = poly2.data[j].coef;
			j++; k++;
		}
		else {
			double c = poly1.data[i].coef + poly2.data[j].coef;
			if (c) {
				poly3.data[k].coef = c;
				poly3.data[k].exp = poly1.data[i].exp;
				k++;
			}
			i++; j++;
		}
	}
	while (i < poly1.length) {
		poly3.data[k].coef = poly1.data[i].coef;
		poly3.data[k].exp = poly1.data[i].exp;
		++i; ++k;
	}
	while (j < poly2.length) {
		poly3.data[k].coef = poly2.data[j].coef;
		poly3.data[k].exp = poly2.data[j].exp;
		++j; ++k;
	}
	poly3.length = k;
	return poly3;
}
//
void polyClass::sort() {
	int j;   //ֱ�Ӳ�������
	for (int i = 1; i < length; i++) {
		polyElem temp = data[i];
		for ( j = i - 1; j >= 0 && temp.exp > data[j].exp;j--)
			data[j + 1] = data[j];
		data[j + 1] =temp;
	}
}
//
void polyClass::display() {
	int i = 0;
	bool first = true;
	while (i < length) {
		if (first) first = false;    //��һ�β�����Ӻ�
		else if (data[i].coef > 0) cout << "+";
		//else cout << "-";   ����������ţ���Ϊ���Ϊ�����Ļ�������
		if (data[i].exp == 0)
			cout << data[i].coef;
		else if (data[i].exp == 1)
			cout << data[i].coef << "x";
		else
			cout << data[i].coef << "x^" << data[i].exp;
		i++;
	}
}
#endif // !POLYADD_H

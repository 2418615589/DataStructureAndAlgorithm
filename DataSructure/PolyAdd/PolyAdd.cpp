#include "PolyAdd.h"
int main()
{
	//������ʽ2*x^3+3.2*x^5-6*x+10,�Ͷ���ʽ6*x+1.8*x^5-2*x^3+x^2-2.5*x^4-5
	polyClass poly1, poly2, poly3;
	vector<double>coef1 = { 2,3.2,-6,10 };
	vector<int>exp1 = { 3,5,1,0 };
	vector<double>coef2 = { 6,1.8,-2,1,-2.5,-5 };
	vector<int>exp2 = { 1,5,3,2,4,0};
	poly1.creatList(coef1, exp1);
	poly1.display(); cout << endl;
	poly1.sort();
	poly1.display();   //����
	cout << endl;

	poly2.creatList(coef2, exp2);
	poly2.display();
	poly2.sort();
	cout << endl;
	
	poly3 = poly1 + poly2;
	poly3.display();
}

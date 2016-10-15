#include "myVector.h"
#include <string>
#include <vector>
using namespace std;
int main()
{
	myVector<float>v;
	cout << "����Ĭ�Ϲ��캯��" << endl;
	cout << v.size() << " " << v.capacity() << endl;
	cout << "���Թ��캯��������10��1Ԫ��" << endl;
	myVector<int> v1(10, 1);				
	for (int i = 0; i < v1.size(); i++)	
		cout << v1[i] <<"  ";			 //����������[]�ɹ�   
	cout << endl;
	cout << "�õ�ͷ��β��ֵ" << endl;
	cout <<v1.front()<<"  "<<v1.back() << endl;  //���Ժ���
	cout << endl;
	cout << "���Ը��ƹ��캯��" << endl;
	myVector<int> vcopy(v1);
	for (int i = 0; i < vcopy.size(); i++)
		cout << vcopy[i] <<"  ";
	cout << endl;


	cout << "���Ը�ֵ������" << endl;
	myVector<int>vv;
	vv = v1;
	for (int i = 0; i < vv.size(); i++)
		cout << vv[i] << "  ";
	cout << endl;
	

	cout << "���Թ��캯��,����n��0Ԫ��" << endl;
	myVector<float>v2(10);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";	
	cout << "�����Ƿ�Ϊ��" << endl;
	cout <<boolalpha<< v2.empty() << endl;
	cout << "����push_back()" << endl;
	v2.push_back(3);
	cout << v2.size() << "  " << v2.capacity() << "  " << v2[1] << endl;
	cout << "����pop_back()" << endl;
	v2.pop_back();
	cout << v2.size() << "  " << v2.capacity() << "  " << v2[10] << endl;
	cout << "����erase(fisrt,last)" << endl;
	for (int i = 0; i < v2.size(); i++) {
		v2[i] += i; cout << v2[i] << "  ";
	}
	cout << endl;
	v2.erase(v2.begin(), v2.begin() + 2);    //�ӿ�ʼ��ɾ������Ԫ��
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";
	cout << endl;
	cout << "����erase(positon)" << endl;
	v2.erase(v2.begin() + 2);
	for (int i = 0; i < v2.size(); i++)
		cout << v2[i] << "  ";
	cout << endl;
	
	//������Ҫ�ĺ���insert()
	cout << "����insert(iterator positon, size_type n, const T& x)" << endl;
	myVector<string>vec(5, "test");
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "  " ;
	cout << endl;
	vec.insert(vec.begin() + 2, 7, "program");   //����7����ͬ�ַ�
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << "  ";
	cout << endl;
	cout << vec.size() << "  " << vec.capacity() << endl;

	cout << "���Ե�����" << endl;
	myVector<string> str(10, "test");
	auto it = str.begin();          //autoλc++11�ؼ��֣��ж�����
	for (; it != str.end(); ++it)
		cout << *it << " ";
	cout << endl;

	cout << "ʹ�������������ֵ" << endl;
	int a[] = { 1,2,3,4,5,6,7,8,9 };
	myVector<int> v4(a, a + sizeof(a)/sizeof(a[0]));
	for (int i = 0; i < v4.size(); i++)
		cout << v4[i] << "  ";
	cout << endl;
	

}
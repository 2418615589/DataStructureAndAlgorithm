#include "LinkList.h"
int main() {
	vector<int> arr = { 1,2,3,4,5 };
	LinkList<int> list;

	list.creatList(arr);   //���Դ�������
	list.printList();

	cout << list.getLen() << endl;   //��ó���

	list.insElem(5, 6);    //�ڵ����λ�ò���6
	list.printList();

	list.delElem(5);    //ɾ��λ��Ϊ5��Ԫ��
	list.printList();

	cout <<boolalpha<< list.empty() << endl;   //�ж��Ƿ�Ϊ��
}
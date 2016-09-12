//Author	: yqtao
//date		: 2016.09.09
//Email		: yqtao@whu.edu.cn
/*
Implement binary search tree
*/
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include<iostream>
#include<stack>
#include<deque>
using namespace std;
template<typename T> struct BSTNode{
	T val;
	BSTNode<T> *left, *right;
	BSTNode<T>(int x) : val(x),left(nullptr),right(nullptr){}
};
template<typename T> class BST {
private:
	BSTNode<T>* root;
public:
	BST() { root = nullptr; }
	bool empty() { return root = nullptr; }
	void insert(const T& x);    
	BSTNode<T>* search(const T& x);
	void inorder();            //�����������
	void morris_inorder();     //mirror�������
	void breadFirst();         //������ȱ���
	void findAndDelete(const T& x);
	void deleteNode(BSTNode<T>*& node);
};
template<typename T>
 void BST<T>::insert(const T& x){
	 BSTNode<T> *p = root, *prev = 0;
	 while (p) {
		 prev = p;
		 if (x < p->val) p = p->left;
		 else p = p->right;
	 }
	 if (root == nullptr) root = new BSTNode<T>(x);
	 else if (x < prev->val) prev->left = new BSTNode<T>(x);
	 else prev->right = new BSTNode<T>(x);
}
 //
 template<typename T>
 BSTNode<T>* BST<T>::search(const T& x) {
	 BSTNode<T>* p = root;
	 while (p) {
		 if (p->val == x)
			 return p;
		 else if (x < p->val)
			 p = p->left;
		 else
			 p = p->right;		 
	 }
	 return nullptr;
 }
 //
template<typename T>
void BST<T>::inorder() {
	stack<BSTNode<T>*> st;
	BSTNode<T> *p = root;
	while (!st.empty() || p) {
		if (p) {
			st.push(p);
			p = p->left;
		}
		else {
			p = st.top();
			st.pop();
			cout << p->val << " ";
			p = p->right;
		}
	}
	cout << endl;
}
//
template<typename T>
void BST<T>::morris_inorder() {
	BSTNode<T> *cur = root, *pre = nullptr;
	while (cur) {
		if (cur->left==nullptr) {              //1.��ǰ��ڵ�Ϊ�գ������
			cout << cur->val << " ";               //����ǰ���Ϊ�����Һ���
			cur = cur->right;
		}
		else {
			pre = cur->left;                 //2.��ǰ��㲻Ϊ�գ���Ѱ���������������ǰ�����
			while (pre->right&&pre->right!=cur) {
				pre = pre->right;
			}
			if (pre->right == nullptr) {     //2.1 �����ǰ�Ľ���ǰ�������Һ���Ϊ��
				pre->right = cur;                  //����ָ��ǰ���
				cur = cur->left;
			}
			else {                //2.2 �����ǰ�����Һ��Ӳ��գ���ԭԭ���Ľṹ
				pre->right = nullptr;
				cout << cur->val << " ";
				cur = cur->right;
			}
		}
	}
	cout << endl;
}
//
template<typename T>
void BST<T>::breadFirst() {
	deque<BSTNode<T>*> deq;
	BSTNode<T> *p = root;
	deq.push_back(p);
	while (!deq.empty()) {
		p = deq.front();
		deq.pop_front();
		cout<< p->val << " ";
		if (p->left) deq.push_back(p->left);
		if (p->right) deq.push_back(p->right);
	}
	cout << endl;
}
//
template<typename T>
void BST<T>::findAndDelete(const T& x) {
	BSTNode<T>* node = root, *prev = 0;
	while (node) {
		if (node->val == x)
			break;
		prev = node;
		if (node->val < x)
			node = node->right;
		else
			node = node->left;
	}
	if (node&&node->val == x) {                
		if (node == root)
			deleteNode(root);
		else if (prev->left == node)         
			deleteNode(prev->left);    
		else
			deleteNode(prev->right);
	}
	else if (root)
		cout << x << " is not in the tree" << endl;
	else cout << "the tree is empty" << endl;
	
}
//
template<typename T>
void BST<T>::deleteNode(BSTNode<T>*& node) {
	BSTNode<T> *prev, *tmp = node;
	if (node->left == nullptr)     //node has no left child
		node = node->right; 
	else if (node->right == nullptr)    //node has no right child
		node = node->left;
	else {							   //have both child
		tmp = node->left;
		prev = node;
		while (tmp->right) {
			prev = tmp;
			tmp = tmp->right;
		}
		node->val = tmp->val;
		if (prev == node)
			prev->left = tmp->left;
		else
			prev->right = tmp->left;
	}
	delete tmp;
}
#endif // !BINARY_SEARCH_TREE




// Date   : 2016.07.22
// Author : yqtao
// https://github.com/yqtaowhu
/********************************
* ʵ���Լ���vector
* ע��vector�еĵ�����ֻ����ͨ��ָ�룬��˲��ؽ������ز���
* ����Random Access Iterator
********************************/
#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <memory>
#include <iostream>
#include <algorithm>
template <class T, class Alloc=std::allocator<T>> class myVector
{
public:
	//vector��Ƕ������
	typedef T						value_type;
	typedef value_type*				iterator;
	typedef const value_type*		const_iterator;
	typedef value_type&				reference;
	typedef value_type*				pointer;
	typedef	size_t					size_type;    
	typedef ptrdiff_t				difference_type; //��ʾ����������֮��ľ��� ,c++���ö��� typedef int ptrdiff_t;
protected:
	std::allocator<value_type> _alloc;  //�ռ������,����ʹ��stl��׼д����������sgi��׼д��
	iterator _start;					//�������Ԫ��
	iterator _end;					//Ŀǰʹ�ÿռ��β
	iterator _end_of_storage;			//Ŀǰ���ÿռ��β
public:
	myVector() :_start(0), _end(0), _end_of_storage(0){}//Ĭ�Ϲ��캯��
	myVector(size_type n, const T& value);
	myVector(size_type n);  
	myVector(iterator first, iterator last);
	myVector(const myVector& v);			//���ƹ��캯��
	myVector& operator=(const myVector& rhs);  //��ֵ����������
	~myVector() { _destroy(); }

	
	iterator begin() { return _start; }
	iterator end()	 { return _end; }
	const_iterator cbegin() const { return _start; }    //����������
	const_iterator cend() const { return _end; }

	size_type size()  { return size_type(end() - begin()); }  //ע��ת����size_t����
	size_type capacity() { return size_type(_end_of_storage - begin()); }
	bool empty() { return begin() == end(); }
	void swap(myVector &other);
	

	reference front() { return *begin(); }
	reference back() { return *(end() - 1); }
	reference operator[] (size_type n) { return *(begin() + n); }           //����[],����������a[n]���з���Ԫ��

																			//ɾ�������е�Ԫ�أ������ͷ��ڴ�
	 
	void insert_aux(iterator positon, const T& x);  //һ�����븨���ĺ�����������Ϊ����ʱ���õ�
	void push_back(const T& value);
	void pop_back();
	void insert(iterator position, size_type n, const T& x);  

	iterator erase(iterator position);
	iterator erase(iterator first, iterator last);  //ɾ��[first,last)��Ԫ��
	void clear() { erase(begin(), end()); }
private:
	
	void _destroy();   //ɾ�������е�Ԫ�أ������ͷ��ڴ�
	
};



template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(size_type n, const T& value) {
	_start = _alloc.allocate(n);						 //�������������������ڴ�
	std::uninitialized_fill(_start, _start + n, value);  //����c++���ú������г�ʼ��
	_end = _end_of_storage = _start + n;                 //�޸ĵ�������ָ��
}
//���캯��n ��0
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(size_type n) {
	_start = _alloc.allocate(n);
	std::uninitialized_fill(_start, _start + n, 0);
	_end = _end_of_storage = _start + n;              
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(iterator first, iterator last) {
	_start=_alloc.allocate(last - first);  //����ռ�
	_end=_end_of_storage=std::uninitialized_copy(first, last, _start);
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc>::myVector(const myVector& v) {
	size_type n= v.cend() - v.cbegin();
	_start=_alloc.allocate(n);    //����ռ�
	_end = _end_of_storage = std::uninitialized_copy(v.cbegin(), v.cend(), _start);
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::swap(myVector &other) {
		std::swap(_start, other._start);
		std::swap(_end, other._end);
		std::swap(_end_of_storage, other._end_of_storage);
}
//
template <class T, class Alloc = std::allocator<T>>
myVector<T, Alloc> &myVector<T, Alloc>::operator=(const myVector &rhs) {
	if (this == &rhs)
		return *this;
	size_type n = rhs.cend() - rhs.cbegin();
	_start=_alloc.allocate(n);
	_end = _end_of_storage = std::uninitialized_copy(rhs.cbegin(), rhs.cend(), _start);
}
//

template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::insert(iterator position, size_type n, const T& x) {
	if (n >= 0) {
		if (_end_of_storage - _end >= n) {   //ʣ��ռ乻��,���������
			T x_copy = x;
			const size_type elem_after = _end - position;   //��������֮���Ԫ�ظ���
			iterator old_end = _end;       
			if (elem_after >n) {
				uninitialized_copy(_end - n, _end, _end);
				_end = _end + n;        //��β�˺���
				copy_backward(position, old_end - n, old_end);
				fill(position, position + n, x_copy);
			}
			else {                      //Ҫ�����Ԫ�ش��ڵ��ڲ����֮��Ԫ��
				uninitialized_fill_n(_end, n - elem_after, x_copy);
				_end += n - elem_after;
				uninitialized_copy(position, old_end, _end);
				_end += elem_after;
				fill(position, old_end, x_copy);
			}
		}
		else {            //���ʣ��ռ䲻��
			const size_type old_size = size();
			const size_type len = old_size + max(old_size, n);
			iterator new_start = _alloc.allocate(len);
			iterator new_end = new_start;
			new_end =uninitialized_copy(_start, position , new_start);   //��position֮ǰ��Ԫ�ظ��Ƶ�������
			new_end=uninitialized_fill_n(new_end, n, x);    //����Ԫ��
			new_end=uninitialized_copy(position, _end, new_end);
			_destroy();   //���ó�Ա���������ͷſռ�
			//���µ�����������ʹ��ָ���µ�λ��
			_start = new_start;
			_end = new_end;
			_end_of_storage = new_start + len;
		}
	}
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::insert_aux(iterator positon, const T& x) {
	if (_end != _end_of_storage) {

	}
	else {
		const size_type old_size = size();                    //��Ҫע�⣬�����ʼ����Ϊ0
		const size_type len = old_size ? 2 * old_size : 1;    //�����ó���1�����򣬼ӱ�
		iterator new_start = _alloc.allocate(len);            //���·���ռ�
		iterator new_end = new_start;
	    
		new_end = uninitialized_copy(_start, positon, new_start);   //����push_back��˵position=_end,���俽������
	    _alloc.construct(new_end, x);                     //����Ԫ��
		++new_end;
		new_end = uninitialized_copy(positon, _end, new_end);     //���������Ԫ��Ҳ��������

		_destroy();                    //ִ���Զ��庯��
		//������������ָ���µ�ָ��

		//���µ�����������ʹ��ָ���µ�λ��
		_start = new_start;
		_end = new_end;
		_end_of_storage = new_start + len;

	
	}
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::push_back(const T& value) {
	if (_end != _end_of_storage) {        //�������ʣ��Ŀռ�
		_alloc.construct(_end, value);        //��_end����������������value
		++_end;                               //����������
	}
	else
		insert_aux(end(), value);                //����ռ�����		
}
//
template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::pop_back() {
	--_end;               //����Ҫע����ǣ�ɾ��β����Ҫ��_end���ƶ������һ��Ԫ��
	_alloc.destroy(_end);
}
//
template <class T, class Alloc = std::allocator<T>>
typename myVector<T, Alloc>::iterator myVector<T, Alloc>::erase(iterator position) {
	if (position + 1 != end())   //Ҳ����˵Ҫɾ�������Ԫ�ز������һ��Ԫ��
		copy(position + 1, end(), position);
	--_end;
	_alloc.destroy(_end);
	return position;
}
//
template <class T, class Alloc = std::allocator<T>>
typename myVector<T, Alloc>::iterator myVector<T, Alloc>::erase(iterator first, iterator last) {
	difference_type left = _end - last;   
	std::copy(last, _end, first);         //first last avail ��ǰǨ��Ԫ��
	iterator it(first + left);
	while (_end != it)                   //��Ҫ�������п��ܲ���Ҫ��������Ҫ����last��Ԫ����ɾ��Ԫ�صıȽ�
		_alloc.destroy(--_end);
	return first;
}


template <class T, class Alloc = std::allocator<T>>
void myVector<T, Alloc>::_destroy() {
	//��ִ����������
	if (_start)
	{
		iterator it(_end); //��ʼ
		while (it != _start)
			_alloc.destroy(--it);
	}

	//�ͷ��ڴ�
	_alloc.deallocate(_start, _end_of_storage - _start);
	_start= _end_of_storage = _end = NULL;
}
#endif

//Author	: yqtao
//date		: 2016.08.28
//Email		: yqtao@whu.edu.cn
#ifndef MY_SORT_H
#define MY_SORT_H
#include<vector>
using namespace std;
template <typename T> 
class mySort {
public:
	/*
	Insert Sort
	@param arr is the arry to be sort
	*/
	static void insert_sort(vector<T>& arr) {			//�����ɾ�̬����������ֱ������������
		if (arr.empty()) return;
		int n = arr.size(),j;
		for (int i = 1; i < n; i++) {
			int temp = arr[i];
			for (j = i - 1; j >= 0 && arr[j] > temp; j--)
				arr[j + 1] = arr[j];
			arr[j + 1] = temp;
		}
	}
	/*
	Shell Sort
	*/
	static void shell_sort(vector<T> & arr) {
		int i, j,n=arr.size();
		for (int d = n / 2; d >= 1; d = d / 2){ //���岽��{
			for (i = d; i < n; i++)	{			//һ�˲������򣬵�d=1ʱ�����������ȫ��ͬ
				int temp = arr[i];				//�ڱ�
				for (j =i - d; j >= 0 && temp < arr[j]; j -= d)
					arr[j + d] = arr[j];
				arr[j + d] = temp;
			}
		}
	}
	/*
	Bubble sort 
	*/
	static void bubble_sort(vector<T>& arr) {
		int i, j, exchange = 0;   //exchage is to be use of check if exchage two numbers
		int n = arr.size();
		for (i = 0; i < n-1; i++) {      //most n-1 times
			exchange = 0;
			for (j = n- 1; j >i; j--) {  //every time find a smallest number
				if (arr[j] < arr[j - 1]) {
					int temp = arr[j - 1];
					arr[j - 1] =arr[j];
					arr[j] = temp;
					exchange = 1;                //if change ,let exchange=1
				}
			}
			if (!exchange) return;       //the array is sorted
		}
	}
	/*
	Select sort
	every time select a smaller number of array
	*/
	static void select_sort(vector<T>& arr) {
		int n = arr.size(),index=0;
		for (int i = 0; i < n - 1; i++) {   //total n-1 time
			int minElem = arr[i];
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < minElem) {
					minElem = arr[j];
					index = j;
				}
			}
			arr[index] = arr[i];
			arr[i] = minElem;      // select a min number in the array
		}
	}
	/*
	Heap sort
	Note : ����汾�Ķ������Ƕ�ARR��1...length����������ģ����Ҫ�ڣ�����ǰ����һ��Ԫ��
	*/
	static void heap_sort(vector<T>& arr) {
		int n = arr.size()-1;
		for (int i = n / 2; i >= 1; i--)
			sift(arr, i, n);
		for (int i = n; i >= 2; i--) {
			T temp = arr[1];
			arr[1] = arr[i];
			arr[i] = temp;
			sift(arr, 1, i - 1);    //ɸѡ��arr[1]��㣬�õ�i-1���ڵ�Ķ�
		}
	}
private:
	/*
	sift is to be using of change the array,���������ѣ�ʹ���Ϊ�����
	*/
	static void sift(vector<T>& arr, int low, int high) {
		int i = low, j = 2*i;
		T temp = arr[i];
		while (j <= high) {
			if (j < high&&arr[j] < arr[j + 1]) j++;    //����Һ��ӽϴ���jָ���к���
			if (temp < arr[j]) {    //�����С�����ĺ���
				arr[i] = arr[j];
				i = j; j = 2 * i;
			}
			else break;   //����������
		}
		arr[i] = temp;      //��ɾѡ�Ľڵ������λ��
	}
	/*
	Quick Sort
	@param l is left index of array
	@param r is right index of array
	*/
	public:
	static void quick_sort(vector<T>& arr, int l, int r) {
		if (l < r) {
			int k = partion(arr, l, r);
			quick_sort(arr, l, k - 1);
			quick_sort(arr, k + 1, r);
		}
	}
	
	/*
	Merge sort
	@param l is left element of array
	@param r is right element of array
	@arr is the array to be sort
	*/
	static void merge_sort(vector<T>& arr, int l, int r) {
		if (l < r) {
			int m = (l + r) >> 1;
			merge_sort(arr, l, m);
			merge_sort(arr, m + 1, r);
			merge(arr, l, m, r);
		}
	}
private:
	/*
	merge function ,is to be use of merge_sort
	*/
	static void merge(vector<T>& arr, int l, int m, int r) {
		int i = l, j = m + 1,k=0;
		vector<T>temp(r - l + 1);
		while (i <= m&&j <= r) {
			if (arr[i] <= arr[j]) temp[k++] = arr[i++];
			else temp[k++] = arr[j++];
		}
		while (i <= m) temp[k++] = arr[i++];
		while (j <= r) temp[k++] = arr[j++];
		for (int i = 0; i < k; i++) arr[l + i] = temp[i];
	}
	/*
	partion : is to be use of quick sort
	*/
	static int partion(vector<T> & arr, int l, int r) {
		int i = l, j = r, pivot = arr[l];
		while (i < j) {
			while (i < j&&arr[j] >= pivot) j--;
			arr[i] = arr[j];
			while (i < j&&arr[i] <= pivot) i++;
			arr[j] = arr[i];
		}
		arr[i] = pivot;
		return i;
	}
public:
	static void print(vector<T>& arr) {
		for (auto c : arr)
			cout << c << " ";
		cout << endl;
	}
};
#endif // !MY_SORT_H

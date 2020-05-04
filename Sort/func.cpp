#include "sort.h"

//比较
bool myless(int i, int j){
	if (i < j) return true;
	else return false;
}
//互换数值
void swap(vector<int> &a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
//归并函数
void merge(vector<int> &a, int lo, int mid, int high){
	vector<int> b = a;
	int h = lo,j = mid + 1;
	for (int i = lo; i <=high; i++){
		if (h>mid) a[i] = b[j++];
		else if (j >high) a[i] = b[h++];
		else if (myless(b[h], b[j])) a[i] = b[h++];
		else a[i] = b[j++];
	}
}
//切分
int partition(vector<int>&a, int lo, int hi){
	int i = lo, j = hi + 1;
	while (true){
		while (myless(a[++i], a[lo])) if (i == hi) break;
		while (myless(a[lo], a[--j]));
		if (i>=j) break;
		swap(a, i, j);
	}
	swap(a, lo, j);
	return j;
}
//上浮动
void swim(vector<int>&a, int k){
	while (k>1&&myless(a[k / 2], a[k])){
		swap(a, k / 2, k);
		k /= 2;
	}
}
//下沉(堆的界限下标为N)
void sink(vector<int>&a, int k,int N){
	int j ;
	while (2 * k <= N){
		j = 2 * k;
		if (2 * k + 1 <= N&&myless(a[j], a[j + 1])) j++;
		if (myless(a[k], a[j])) swap(a, j, k);
		else return;
		k = j;
	}
}
//建立有序堆(数组下标为1-N的范围为堆，0号位置没有用)
void build_heap(vector<int>&a,int N){
	for (int k = N / 2; k >= 1; k--)
		sink(a, k,N);
}


//选择排序
void Selection(vector<int>& a){
	int min;
	for (int i = 0; i != a.size(); i++){
		min = i;
		for (int j = i + 1; j != a.size(); j++){
			if(!myless(a[min], a[j])) min = j;
		}
		swap(a, i, min);
	}
}

//插入排序
void Insertion(vector<int>& a){
	for (int i = 1; i != a.size();i++)
	for (int j = i;j!=0&& myless(a[j], a[j - 1]); j--)
		swap(a, j, j - 1);

}
//希尔排序
void Shell(vector<int> &a){
	int h = 1;
	while (h < a.size() / 3) h = 3 * h + 1;
	cout << h << endl;
	while (h>=1){
		for (int i = h; i != a.size();i++)
		for (int j = i; j >= h&&myless(a[j], a[j - h]); j -= h)
			swap(a, j, j - h);
		h =h/ 3;
	}
}
//归并排序（递归）
void mergesort_i(vector<int>& a, int lo, int hi){
	if (lo >= hi) return;
	int mid = lo + (hi - lo) / 2;
	mergesort_i(a, lo, mid);
	mergesort_i(a, mid + 1, hi);
	merge(a, lo, mid,hi);
}
//归并排序（非递归）
void mergesort_ii(vector<int>& a){
	for (int sz = 1; sz < a.size() ; sz = sz +sz){
		for (int j = 0; j <= a.size()-sz; j = j + sz + sz)
			merge(a, j, j + sz -1, min(j + sz + sz - 1, (int)a.size()-1));
	}
}
//快速排序
void quick_sort(vector<int>& a,int lo, int hi){	
	if (lo >= hi) return;
	int j = partition(a, lo, hi);
	quick_sort(a, lo, j - 1);
	quick_sort(a, j + 1, hi);
}
//三向切分快速排序
void quick_3way(vector<int>&a,int lo,int hi){
	if (lo >= hi) return;
	int lt = lo, i = lo + 1, gt = hi,v=a[lo];
	while (i <= gt){
		if (a[i] < v) swap(a, lt++, i++);
		else if (a[i]>v) swap(a, gt--, i);
		else i++;
	}
	quick_3way(a, lo, lt - 1);
	quick_3way(a, gt + 1, hi);
}
//堆排序
void heap_sort(vector<int> &a){
	int sz = a.size() - 1;
	build_heap(a, sz);
	
	while (sz > 1){
		swap(a, 1, sz);
		sz = sz - 1;
		sink(a, 1, sz);
	}

}

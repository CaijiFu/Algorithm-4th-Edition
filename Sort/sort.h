#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool myless(int a, int b);
void swap(vector<int> &a, int i, int j);
void merge(vector<int> &a, int lo, int mid, int high);
int partition(vector<int>&a, int lo, int hi);
void swim(vector<int>&a, int k);
void sink(vector<int>&a, int k, int N);
void build_heap(vector<int>&a, int N);


void Selection(vector<int>& a);
void Insertion(vector<int>& a);
void Shell(vector<int> &a);
void mergesort_i(vector<int> &a, int lo, int hi);
void mergesort_ii(vector<int>& a);
void quick_sort(vector<int>& a, int lo, int hi);
void quick_3way(vector<int>&a, int lo, int hi);
void heap_sort(vector<int> &a);
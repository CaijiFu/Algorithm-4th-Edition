#include "sort.h"
int main(){
	vector<int> a = { 0,5, 2, 0, 0, 2,5,5,2,0 };
	heap_sort(a);
	for (auto i : a)
		cout << i << endl;


}
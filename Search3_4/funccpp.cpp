#include "search3_4.h"

/*计算哈希值*/
int linear_hash::hash_val(const string & s){
	int res = 0;
	for (auto i : s)
		res = (12 * res + i) % C;
	return res;
}

//插入一个键值对
void linear_hash::insert(const string & s,  int i){
	if (size > C / 2) resize(C * 2);
	int index = hash_val(s);
	for (; key[index] != No && key[index] != s; index = (index + 1) % C);
	key[index] = s;
	val[index] = i;
	size++;
}

//删除key键
void linear_hash::del(const string & s){
	int index = hash_val(s);
	//查找元素
	while (key[index] != No && key[index] != s)
		index = (index + 1) % C;
	//删除一个不存在的元素
	if (key[index] == No) return;
	//删除相应的元素
	key[index] = No;
	//和此元素连片的元素均需要向前挪动一个位置
	index=(index+1) % C;
	while (key[index] != No){
		string s_tem = key[index];
		int i_tem = val[index];
		key[index] = No;
		insert(s_tem, i_tem);
		index = (index+1)%C;
	}
	size--;
	if (size > 0 && size <= C / 8) resize(C / 2);


}

//扩充或者缩小表
void linear_hash::resize(int new_size){
	//创建新的临时表
	linear_hash t(new_size);
	//原表内容拷贝到新表
	for (int i = 0; i != C; i++){
		if (key[i] != No) t.insert(key[i], val[i]);
	//释放原表
	//int* temi = val;
	//string* tems = key;
	//key = NULL;
	//val = NULL;
	//delete[] temi;
	//delete[] tems;
	key = t.key;
	val = t.val;
	C = new_size;
	}

}

//查找key,返回值
void linear_hash::serach(const string &s){
	int index = hash_val(s);
	while (key[index] != No && key[index] != s)
		index = (index + 1) % C;
	if (key[index] == No) {
		cout << "没找到" << endl;
	}
	else
		cout << "值为:" << val[index];

}


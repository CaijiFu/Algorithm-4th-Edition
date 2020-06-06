#ifndef SERCH3_4
#define SERCH3_4
#include <iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

#define SIZE 31
#define No ""
struct node{
	string key;
	int val;
	node* next;
};


/*哈希表 取余数 拉链法*/
class my_hash{
public:
	/*构造函数*/
	my_hash(){
		for (int i = 0; i != SIZE; i++)
			hash_table[i] = NULL;
	}

	my_hash(ifstream& in){
		for (int i = 0; i != SIZE; i++)
			hash_table[i] = NULL;
		string s;
		while (getline(in, s)){
			istringstream ele(s);
			string key, val;
			ele >> key >> val;
			put(key, stoi(val));
		}
	}

	/*计算哈希值*/
	int hash_val(const string & s){
		int res = 0;
		for (auto i : s)
			res += (12 * res + i) % SIZE;
		return res;
	}

	/*插入一个键值对*/
	void put(const string & s, int val){
		short index = hash_val(s);
		node* head = serch(s);
		if (head == NULL){
			/*因为插入第一个元素导致search为空*/
			if (hash_table[index] == NULL){
				node* n = new node;
				n->key = s;
				n->val = val;
				n->next = NULL;
				hash_table[index] = n;
			}
			/*index处已经有元素但相应链表中没有该元素*/
			else{
				node* find = hash_table[index];
				while (find->next)
					find = find->next;
				node* n = new node;
				n->key = s;
				n->val = val;
				n->next = NULL;
				find->next = n;
			}
		}
		else
			head->val = val;

	}

	void del(const string & s){
		node* head = serch(s);
		if (head == NULL) return;
		node* former = hash_table[hash_val(s)];
		/*找到要删除节点的前一个节点*/
		while (former->next != head)
			former = former->next;
		former->next = head->next;
	}

	/*链表中查找指定key的元素*/
	node* serch(const string & s){
		short index = hash_val(s);
		node* head = hash_table[index];
		while (head){
			if (head->key == s) return head;
			head = head->next;
		}
		return NULL;
	}


private:
	node* hash_table[SIZE];

};



/*哈希表 线性探索法*/
class linear_hash{
public:
	//构造函数
	linear_hash() {
		val = new int[SIZE];
		key = new string[SIZE];
		C = SIZE;
	}
	linear_hash(int i){
		val = new int[i];
		key = new string[i];
		C = i;
	}
	linear_hash(ifstream & in){
		val = new int[SIZE];
		key = new string[SIZE];
		C = SIZE;
		string line;
		while (getline(in, line)){
			stringstream ele(line);
			string s,i;
			ele >> s >> i;
			insert(s, stoi(i));
		}
		
	}
	/*计算哈希值*/
	int hash_val(const string & s);
	//插入一个键值对
	void insert(const string & s, int i);
	//删除key键
	void del(const string & s);
	//扩充或者缩小表
	void resize(int m);
	//查找key,返回值
	void serach(const string &s);
private:
	int C; //符号表容量
	int size; //符号表中已经存在元素个数
	int * val ;
	string* key;
};

#endif
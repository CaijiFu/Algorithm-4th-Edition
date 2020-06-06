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


/*��ϣ�� ȡ���� ������*/
class my_hash{
public:
	/*���캯��*/
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

	/*�����ϣֵ*/
	int hash_val(const string & s){
		int res = 0;
		for (auto i : s)
			res += (12 * res + i) % SIZE;
		return res;
	}

	/*����һ����ֵ��*/
	void put(const string & s, int val){
		short index = hash_val(s);
		node* head = serch(s);
		if (head == NULL){
			/*��Ϊ�����һ��Ԫ�ص���searchΪ��*/
			if (hash_table[index] == NULL){
				node* n = new node;
				n->key = s;
				n->val = val;
				n->next = NULL;
				hash_table[index] = n;
			}
			/*index���Ѿ���Ԫ�ص���Ӧ������û�и�Ԫ��*/
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
		/*�ҵ�Ҫɾ���ڵ��ǰһ���ڵ�*/
		while (former->next != head)
			former = former->next;
		former->next = head->next;
	}

	/*�����в���ָ��key��Ԫ��*/
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



/*��ϣ�� ����̽����*/
class linear_hash{
public:
	//���캯��
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
	/*�����ϣֵ*/
	int hash_val(const string & s);
	//����һ����ֵ��
	void insert(const string & s, int i);
	//ɾ��key��
	void del(const string & s);
	//���������С��
	void resize(int m);
	//����key,����ֵ
	void serach(const string &s);
private:
	int C; //���ű�����
	int size; //���ű����Ѿ�����Ԫ�ظ���
	int * val ;
	string* key;
};

#endif
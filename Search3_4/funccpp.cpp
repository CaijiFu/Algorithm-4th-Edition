#include "search3_4.h"

/*�����ϣֵ*/
int linear_hash::hash_val(const string & s){
	int res = 0;
	for (auto i : s)
		res = (12 * res + i) % C;
	return res;
}

//����һ����ֵ��
void linear_hash::insert(const string & s,  int i){
	if (size > C / 2) resize(C * 2);
	int index = hash_val(s);
	for (; key[index] != No && key[index] != s; index = (index + 1) % C);
	key[index] = s;
	val[index] = i;
	size++;
}

//ɾ��key��
void linear_hash::del(const string & s){
	int index = hash_val(s);
	//����Ԫ��
	while (key[index] != No && key[index] != s)
		index = (index + 1) % C;
	//ɾ��һ�������ڵ�Ԫ��
	if (key[index] == No) return;
	//ɾ����Ӧ��Ԫ��
	key[index] = No;
	//�ʹ�Ԫ����Ƭ��Ԫ�ؾ���Ҫ��ǰŲ��һ��λ��
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

//���������С��
void linear_hash::resize(int new_size){
	//�����µ���ʱ��
	linear_hash t(new_size);
	//ԭ�����ݿ������±�
	for (int i = 0; i != C; i++){
		if (key[i] != No) t.insert(key[i], val[i]);
	//�ͷ�ԭ��
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

//����key,����ֵ
void linear_hash::serach(const string &s){
	int index = hash_val(s);
	while (key[index] != No && key[index] != s)
		index = (index + 1) % C;
	if (key[index] == No) {
		cout << "û�ҵ�" << endl;
	}
	else
		cout << "ֵΪ:" << val[index];

}


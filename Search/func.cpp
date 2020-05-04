#include "search.h"
//˳�����
bool Sequential_Search(vector<int>&a, int b,int& pos){
	for (int i = 0; i != a.size();i++)
	if (a[i] == b){
		pos = i;
		return true;
	}
	return false;
}

//���ֲ��ң��ҵ�һ��������С�ڸ���ֵ��Ԫ�ظ������ǵݹ�汾
int binary_search_ii(vector<int>&a ,int val){
	sort(a.begin(),a.end());
	int lo = 0, hi = a.size() - 1,mid;
	while (lo <= hi){
		mid = lo + (hi - lo) / 2;
		if (a[mid] > val) hi = mid - 1;
		else if (a[mid] < val) lo = mid + 1;
		else return mid;
	}
	return lo;
}

//�ݹ�汾
int binary_search_i(vector<int>&a, int val,int lo,int hi){
	if (lo > hi) return lo;
	int mid = lo + (hi - lo) / 2;
	if (a[mid]>val) return binary_search_i(a, val, lo, mid - 1);
	else if (a[mid] < val) binary_search_i(a, val, mid + 1, hi);
	else return mid;
}

//��������
bool visit(char e,int i){
	cout << e << i<<endl;
	return 1;
}

//��ʼ��������
bool InitTree(BiTree &T){
	if (T == NULL) return 0;
	T = NULL;
	return 1;
}
//���������
bool CreatTree(BiTree &T,ifstream &file){
	char ch;
	file >> ch;
	if (ch == '0') T = NULL;
	else{
		if (!(T = (BiTree)malloc(sizeof(BiTNode)))) exit(0);
		T->data = ch;
		CreatTree(T->lchild,file);
		CreatTree(T->rchild,file);
	}
	return 1;
}
//�������������
bool Creat_Binary_Search_Tree(BiTree& T,ifstream& file){
	char c;
	while (file >> c) T=myput(T, c);
	return 1;

}

//�������������(�ݹ飩
bool PreOrderTraverse_i(BiTree &T, bool(*visit)(char e,int i)){
	if (T == NULL) return 1;
	else{
		if (visit(T->data,T->size))
		if (PreOrderTraverse_i(T->lchild, visit))
		if (PreOrderTraverse_i(T->rchild, visit))
			return 1;
		return 0;
	}
}
//����������ݹ飩
bool InOrderTraverse_ii(BiTree & T, bool(*visit)(char e)){
	vector<BiTree> S; 
	S.push_back(T);
	BiTree n;
	while (!S.empty()){
		while (n = S.back()) S.push_back(n->lchild);
		S.pop_back();
		if (!S.empty()){
			n = S.back();
			S.pop_back();
			if (!visit(n->data)) return 0;
			S.push_back(n->rchild);
		}
		
	}
	return 1;
}

//��NODEΪ�ڵ�Ķ������Ĵ�С
int mysize(BiTree & T){
	if (T == NULL) return 0;
	return T->size;
}

//û���ҵ����ؿ�ָ�룬�ҵ��ͷ��ؽڵ��ָ��
BiTree myget(BiTree& T, char key){
	if (T == NULL) return NULL;
	if (T->data > key) return myget(T->lchild, key);
	else if (T->data < key) return myget(T->rchild, key);
	else return T;
}

//���key�Ѿ�������T�У����ԣ���������ڣ���ô����ڵ㣬������ָ��ýڵ��ָ��
BiTree myput(BiTree &T, char key){
	if (T == NULL) {
		BiTree h = (BiTree)malloc(sizeof(BiTNode));
		h->size = 1;
		h->data = key;
		h->lchild = NULL;
		h->rchild = NULL;
		return h;
	}
	if (key > T->data) T->rchild = myput(T->rchild, key);
	else if (key < T->data) T->lchild = myput(T->lchild, key);
	else ;
	T->size = mysize(T->lchild) + mysize(T->rchild)+1;
	return T;
}

//������T��ָ�����ļ�ֵ������
BiTree mymax(BiTree &T){
	if (T->rchild == NULL) return T;
	return mymax(T->rchild);
}

//������T��ָ����С�ļ�ֵ������
BiTree mymin(BiTree &T){
	if (T->lchild == NULL) return T;
	return mymin(T->lchild);
}
//������TС�ڵ��ڼ������������û�У�����0
char myfloor(BiTree &T, char key){
	if (T == NULL) return 0;
	if (key < T->data) return myfloor(T->lchild,key);
	if (key == T->data) return T->data;
	char N = myfloor(T->rchild,key);
	if (N == 0) return T->data;
	return N;
}
//���ظ�����key����������(������0��ʼ)
int myrank(BiTree &T, char key){
	if (T == NULL) return 0;
	if (key < T->data) return myrank(T->lchild, key);
	else if (key == T->data) return mysize(T->lchild);
	else return myrank(T->rchild,key)+ mysize(T->lchild) + 1;
}
//������������ΪK�ļ���������0��ʼ��,k������Χ����0
char myselect(BiTree &T, int k){
	if (T == 0) return 0;
	if (mysize(T->lchild) == k) return T->data;
	else if (mysize(T->lchild) >k) return myselect(T->lchild, k);
	else return myselect(T->rchild, k - 1 - mysize(T->lchild));
}
//ɾ����T����С�ڵ�
BiTree mydeletemin(BiTree& T){
	if (T->lchild == NULL) return T->rchild;
	T->lchild=mydeletemin(T->lchild);
	T->size = mysize(T->lchild) + mysize(T->rchild) + 1;
	return T;
}
//ɾ����T�����ڵ�
BiTree mydeletemax(BiTree& T){
	if (T->rchild == NULL) return T->lchild;
	T->rchild = mydeletemin(T->rchild);
	T->size = mysize(T->lchild) + mysize(T->rchild) + 1;
	return T;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
ɾ��һ��һ��ڵ�,���ĵ�˼�������������������С�ڵ��滻��ɾ���Ľڵ㣬
��Ϊ����������С�ڵ�������ڱ�ɾ���ڵ���������С�ڱ�ɾ���ڵ����������
��˲��ı��������������,������������У���ô�����䣬���������κ�Ӱ��
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */ 
BiTree mydelete(BiTree& T, char key){
	if (T == NULL) return NULL;
	if (key > T->data) T->rchild = mydelete(T->rchild, key);
	else if (key <T->data) T->lchild = mydelete(T->lchild, key);
	else
	{
		if (T->lchild == NULL) return T->rchild;
		if (T->rchild == NULL) return T->lchild;
		BiTree x = T;
		T = mymin(x->rchild);
		T->rchild = mydeletemin(x->rchild);
		T->lchild = x->lchild;
	}
	T->size = mysize(T->lchild) + mysize(T->rchild) + 1;
	return T;
}



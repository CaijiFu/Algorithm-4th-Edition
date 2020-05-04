#include "search.h"
//顺序查找
bool Sequential_Search(vector<int>&a, int b,int& pos){
	for (int i = 0; i != a.size();i++)
	if (a[i] == b){
		pos = i;
		return true;
	}
	return false;
}

//二分查找（找到一个数组中小于给定值的元素个数）非递归版本
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

//递归版本
int binary_search_i(vector<int>&a, int val,int lo,int hi){
	if (lo > hi) return lo;
	int mid = lo + (hi - lo) / 2;
	if (a[mid]>val) return binary_search_i(a, val, lo, mid - 1);
	else if (a[mid] < val) binary_search_i(a, val, mid + 1, hi);
	else return mid;
}

//遍历函数
bool visit(char e,int i){
	cout << e << i<<endl;
	return 1;
}

//初始化二叉树
bool InitTree(BiTree &T){
	if (T == NULL) return 0;
	T = NULL;
	return 1;
}
//构造二叉树
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
//构造二叉搜索树
bool Creat_Binary_Search_Tree(BiTree& T,ifstream& file){
	char c;
	while (file >> c) T=myput(T, c);
	return 1;

}

//二叉树先序遍历(递归）
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
//中序遍历（递归）
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

//以NODE为节点的二叉树的大小
int mysize(BiTree & T){
	if (T == NULL) return 0;
	return T->size;
}

//没有找到返回空指针，找到就返回节点的指针
BiTree myget(BiTree& T, char key){
	if (T == NULL) return NULL;
	if (T->data > key) return myget(T->lchild, key);
	else if (T->data < key) return myget(T->rchild, key);
	else return T;
}

//如果key已经存在树T中，忽略，如果不存在，那么插入节点，并返回指向该节点的指针
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

//返回树T中指向最大的键值的链接
BiTree mymax(BiTree &T){
	if (T->rchild == NULL) return T;
	return mymax(T->rchild);
}

//返回树T中指向最小的键值的链接
BiTree mymin(BiTree &T){
	if (T->lchild == NULL) return T;
	return mymin(T->lchild);
}
//返回树T小于等于键的最大键，如果没有，返回0
char myfloor(BiTree &T, char key){
	if (T == NULL) return 0;
	if (key < T->data) return myfloor(T->lchild,key);
	if (key == T->data) return T->data;
	char N = myfloor(T->rchild,key);
	if (N == 0) return T->data;
	return N;
}
//返回给定键key在树中排名(排名从0开始)
int myrank(BiTree &T, char key){
	if (T == NULL) return 0;
	if (key < T->data) return myrank(T->lchild, key);
	else if (key == T->data) return mysize(T->lchild);
	else return myrank(T->rchild,key)+ mysize(T->lchild) + 1;
}
//返回树中排名为K的键（排名从0开始）,k超出范围返回0
char myselect(BiTree &T, int k){
	if (T == 0) return 0;
	if (mysize(T->lchild) == k) return T->data;
	else if (mysize(T->lchild) >k) return myselect(T->lchild, k);
	else return myselect(T->rchild, k - 1 - mysize(T->lchild));
}
//删除树T的最小节点
BiTree mydeletemin(BiTree& T){
	if (T->lchild == NULL) return T->rchild;
	T->lchild=mydeletemin(T->lchild);
	T->size = mysize(T->lchild) + mysize(T->rchild) + 1;
	return T;
}
//删除树T的最大节点
BiTree mydeletemax(BiTree& T){
	if (T->rchild == NULL) return T->lchild;
	T->rchild = mydeletemin(T->rchild);
	T->size = mysize(T->lchild) + mysize(T->rchild) + 1;
	return T;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
删除一个一般节点,核心的思想就是用其右子树的最小节点替换被删除的节点，
因为右子树的最小节点满足大于被删除节点左子树，小于被删除节点的右子树，
因此不改变二叉树的有序性,如果键不在树中，那么树不变，即不产生任何影响
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



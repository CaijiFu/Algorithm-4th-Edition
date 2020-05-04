#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//二叉链表数据结构
struct BiTNode{
	char data;
	int size;
    BiTNode * lchild,*rchild;
};
typedef BiTNode* BiTree;
//初始化二叉树
bool InitTree(BiTree &T);
//构造普通二叉树
bool CreatTree(BiTree &T,ifstream &file);
//先序遍历(递归)
bool PreOrderTraverse_i(BiTree &T, bool(*visit)(char e,int i));
//中序遍历（非递归）
bool InOrderTraverse_ii(BiTree & T, bool(*visit)(char e,int i));
//构造二叉搜索树
bool Creat_Binary_Search_Tree(BiTree& T, ifstream& file);
//以NODE为节点的二叉树的大小
int mysize(BiTree & T);
//没有找到返回空指针，找到就返回节点的指针
BiTree myget(BiTree& T, char key);
//如果key已经存在树T中，忽略，如果不存在，那么插入节点，并返回指向该节点的指针
BiTree myput(BiTree &T, char key);
//返回树T中指向最大的键值的链接
BiTree mymax(BiTree &T);
//返回树T中指向最小的键值的链接
BiTree mymin(BiTree &T);
//返回树T小于等于键的最大键，如果没有，返回0
char myfloor(BiTree &T, char key);
//返回给定键key在树中排名(排名从0开始)
int myrank(BiTree &T, char key);
//返回树中排名为K的键（排名从0开始）,k超出范围返回0
char myselect(BiTree &T, int k);
//删除树T的最小节点
BiTree mydeletemin(BiTree& T);
//删除树T的最大节点
BiTree mydeletemax(BiTree& T);
//删除任意节点
BiTree mydelete(BiTree& T, char key);

bool Sequential_Search(vector<int>&a, int b, int& pos);
int binary_search_ii(vector<int>&a, int val);
int binary_search_i(vector<int>&a, int val, int lo, int hi);
bool visit(char e,int i);
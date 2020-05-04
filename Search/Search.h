#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//�����������ݽṹ
struct BiTNode{
	char data;
	int size;
    BiTNode * lchild,*rchild;
};
typedef BiTNode* BiTree;
//��ʼ��������
bool InitTree(BiTree &T);
//������ͨ������
bool CreatTree(BiTree &T,ifstream &file);
//�������(�ݹ�)
bool PreOrderTraverse_i(BiTree &T, bool(*visit)(char e,int i));
//����������ǵݹ飩
bool InOrderTraverse_ii(BiTree & T, bool(*visit)(char e,int i));
//�������������
bool Creat_Binary_Search_Tree(BiTree& T, ifstream& file);
//��NODEΪ�ڵ�Ķ������Ĵ�С
int mysize(BiTree & T);
//û���ҵ����ؿ�ָ�룬�ҵ��ͷ��ؽڵ��ָ��
BiTree myget(BiTree& T, char key);
//���key�Ѿ�������T�У����ԣ���������ڣ���ô����ڵ㣬������ָ��ýڵ��ָ��
BiTree myput(BiTree &T, char key);
//������T��ָ�����ļ�ֵ������
BiTree mymax(BiTree &T);
//������T��ָ����С�ļ�ֵ������
BiTree mymin(BiTree &T);
//������TС�ڵ��ڼ������������û�У�����0
char myfloor(BiTree &T, char key);
//���ظ�����key����������(������0��ʼ)
int myrank(BiTree &T, char key);
//������������ΪK�ļ���������0��ʼ��,k������Χ����0
char myselect(BiTree &T, int k);
//ɾ����T����С�ڵ�
BiTree mydeletemin(BiTree& T);
//ɾ����T�����ڵ�
BiTree mydeletemax(BiTree& T);
//ɾ������ڵ�
BiTree mydelete(BiTree& T, char key);

bool Sequential_Search(vector<int>&a, int b, int& pos);
int binary_search_ii(vector<int>&a, int val);
int binary_search_i(vector<int>&a, int val, int lo, int hi);
bool visit(char e,int i);
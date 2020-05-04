#include "Search.h"
void main(){
	BiTree H,K;
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	测试一般二叉树
	ifstream file("binarytree.txt");
	if (InitTree(H)) cout << "初始化成功" << endl;
	if (CreatTree(H,file)) cout << "创建成功" << endl;
	if (InOrderTraverse_ii(H, visit)) cout << "遍历成功" << endl;
	*  * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	/* * * * * * * * * * * * *
	有序二叉树的形状为：
	        H
		C       S
	A      E   R   X
	他们排名为：A C E H R S X
	* * * * * * * * * * * * */
	ifstream file("binarysearchtree.txt");
	char c;
	if (InitTree(H)) cout << "初始化成功" << endl;
	if (Creat_Binary_Search_Tree(H, file))  cout << "构建成功" << endl;
	cout << "先序遍历" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "遍历成功" << endl;

	cout << "排名为3的键（从0开始）" << endl;
	if(c=myselect(H,3)) cout<<c<<endl;
	else cout << "范围超出限制" << endl;

	cout << "找键E（从0开始）" << endl;
	if (K = myget(H, 'E')) cout << "找到"<< endl;
	else cout << "不存在" << endl;

	cout << "最大键:" << mymax(H)->data<< endl;
	 
	cout << "最小键:" << mymin(H)->data << endl;

	cout << "小于等于M的最大值" << endl;
	if (c = myfloor(H, 'M')) cout << c << endl;
	else cout << "不存在" << endl;

	cout << "M的排名：" << myrank(H,'M')<< endl;

	cout << "删除最小值" << endl;
	mydeletemin(H);
	cout << "先序遍历" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "遍历成功" << endl;

	cout << "删除最大值" << endl;
	mydeletemax(H);
	cout << "先序遍历" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "遍历成功" << endl;

	cout << "删除键H" <<  endl;
	mydelete(H, 'H');
	cout << "先序遍历" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "遍历成功" << endl;


}
#include "Search.h"
void main(){
	BiTree H,K;
	/* * * * * * * * * * * * * * * * * * * * * * * * * * * *
	����һ�������
	ifstream file("binarytree.txt");
	if (InitTree(H)) cout << "��ʼ���ɹ�" << endl;
	if (CreatTree(H,file)) cout << "�����ɹ�" << endl;
	if (InOrderTraverse_ii(H, visit)) cout << "�����ɹ�" << endl;
	*  * * * * * * * * * * * * * * * * * * * * * * * * * * * */
	/* * * * * * * * * * * * *
	�������������״Ϊ��
	        H
		C       S
	A      E   R   X
	��������Ϊ��A C E H R S X
	* * * * * * * * * * * * */
	ifstream file("binarysearchtree.txt");
	char c;
	if (InitTree(H)) cout << "��ʼ���ɹ�" << endl;
	if (Creat_Binary_Search_Tree(H, file))  cout << "�����ɹ�" << endl;
	cout << "�������" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "�����ɹ�" << endl;

	cout << "����Ϊ3�ļ�����0��ʼ��" << endl;
	if(c=myselect(H,3)) cout<<c<<endl;
	else cout << "��Χ��������" << endl;

	cout << "�Ҽ�E����0��ʼ��" << endl;
	if (K = myget(H, 'E')) cout << "�ҵ�"<< endl;
	else cout << "������" << endl;

	cout << "����:" << mymax(H)->data<< endl;
	 
	cout << "��С��:" << mymin(H)->data << endl;

	cout << "С�ڵ���M�����ֵ" << endl;
	if (c = myfloor(H, 'M')) cout << c << endl;
	else cout << "������" << endl;

	cout << "M��������" << myrank(H,'M')<< endl;

	cout << "ɾ����Сֵ" << endl;
	mydeletemin(H);
	cout << "�������" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "�����ɹ�" << endl;

	cout << "ɾ�����ֵ" << endl;
	mydeletemax(H);
	cout << "�������" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "�����ɹ�" << endl;

	cout << "ɾ����H" <<  endl;
	mydelete(H, 'H');
	cout << "�������" << endl;
	if (PreOrderTraverse_i(H, visit)) cout << "�����ɹ�" << endl;


}
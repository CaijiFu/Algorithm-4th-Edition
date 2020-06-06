#include "search33.h"

/* * * * * * * * * * * * * * * * * * * *
Լ���սڵ�Ϊ������,��������˼Ϊ������  *
* * * * * * * * * * * * * * * * * * * */



//�������Ϊ�����ӻ��Ǻ�����
bool is_red(Node* n){
	if (n == NULL) return BLACK;
	return n->color;
}

//��ɫ��������ת����������
Node* rotate_left(Node * n){
	Node* x = n->right;
	n ->right = x->left;
	x->left = n;
	x->color = n->color;
	n->color = RED;
	x->size = n->size;
	n->size = n->left->size + n->left->size + 1;
	return x;
}

//��ɫ��������ת����������
Node* rotate_right(Node * n){
	Node* x = n->left;
	n->left = x->right;
	x->right = n;
	x->color = n->color;
	n->color = RED;
	x->size = n->size;
	n->size = n->right->size + n->right->size + 1;
	return x;
}

//��һ��3�ڵ������Ԫ��ʱ������4�ڵ��м��С�ڵ��ϸ������������ֳ�����2�ڵ�
void flip_color(Node * n){
	n->color = RED;
	n->left->color = BLACK;
	n->right->color = BLACK;
}



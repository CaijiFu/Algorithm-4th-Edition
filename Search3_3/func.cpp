#include "search33.h"

/* * * * * * * * * * * * * * * * * * * *
约定空节点为黑链接,红链接意思为左链接  *
* * * * * * * * * * * * * * * * * * * */



//检查连接为红链接还是黑链接
bool is_red(Node* n){
	if (n == NULL) return BLACK;
	return n->color;
}

//红色的右链接转化成左链接
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

//红色的左链接转化成右链接
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

//向一个3节点插入新元素时，最终4节点中间大小节点上浮，其余两个分成两个2节点
void flip_color(Node * n){
	n->color = RED;
	n->left->color = BLACK;
	n->right->color = BLACK;
}



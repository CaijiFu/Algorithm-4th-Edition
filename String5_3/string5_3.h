#ifndef string5_3_h
#define string5_3_h
#include <string>
#include <iostream>
using namespace std;

#define	Q 10000
#define	R 10


/* * * * * * * * rabin-karpָ��ƥ���㷨* * * * * * * * * * * * * * */
long Pat_hash(const string& pat);////����ģʽ�ַ�����ɢ��ֵ
int rk_search(const string& txt, const string& pat, int m, long pat_val); //���Һ���
bool valid(const string& txt, const string& pat, int index, int m);//��֤����
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */








#endif

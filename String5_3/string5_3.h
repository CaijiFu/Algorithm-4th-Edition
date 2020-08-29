#ifndef string5_3_h
#define string5_3_h
#include <string>
#include <iostream>
using namespace std;

#define	Q 10000
#define	R 10


/* * * * * * * * rabin-karp指纹匹配算法* * * * * * * * * * * * * * */
long Pat_hash(const string& pat);////计算模式字符串的散列值
int rk_search(const string& txt, const string& pat, int m, long pat_val); //查找函数
bool valid(const string& txt, const string& pat, int index, int m);//验证函数
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */








#endif

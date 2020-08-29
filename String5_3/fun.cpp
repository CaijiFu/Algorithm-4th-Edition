#include "string5_3.h"


/* * * * *Rabin-Karp算法* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//计算模式字符串的散列值
long Pat_hash(const string& pat) {
	long res = 0;
	for (auto i : pat) res = (R * res + i - 'A') % Q;
	return res;
}

//查找函数
int rk_search(const string& txt, const string& pat, int m, long pat_val) {
	long RM = 1; //减去最前面一位用
	for (int i = 1; i <= m - 1; i++) RM = (R * RM) % Q;
	//首次匹配
	long txt_val = 0;
	for (int i = 0; i <= m - 1; i++) txt_val = (txt_val * R + txt[i]-'A') % Q;
	if (txt_val == pat_val && valid(txt, pat, 0, m)) return 0;
	//查找
	for (int i = m; i < txt.size(); i++) {
		txt_val = ((txt_val - (txt[i-m]-'A')*RM %Q + Q) * R + txt[i]-'A') % Q;
		if(txt_val == pat_val && valid(txt, pat, i-m+1, m)) return i - m + 1;
	}
	return - 1;//没有匹配
}

//验证函数
bool valid(const string& txt, const string& pat, int index, int m) {
	for (int i = 0; i <= m - 1; i++) if (txt[index + i] != pat[i]) return false;
	return true;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*KMP算法*/



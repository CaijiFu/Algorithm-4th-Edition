#include "string5_3.h"


/* * * * *Rabin-Karp�㷨* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
//����ģʽ�ַ�����ɢ��ֵ
long Pat_hash(const string& pat) {
	long res = 0;
	for (auto i : pat) res = (R * res + i - 'A') % Q;
	return res;
}

//���Һ���
int rk_search(const string& txt, const string& pat, int m, long pat_val) {
	long RM = 1; //��ȥ��ǰ��һλ��
	for (int i = 1; i <= m - 1; i++) RM = (R * RM) % Q;
	//�״�ƥ��
	long txt_val = 0;
	for (int i = 0; i <= m - 1; i++) txt_val = (txt_val * R + txt[i]-'A') % Q;
	if (txt_val == pat_val && valid(txt, pat, 0, m)) return 0;
	//����
	for (int i = m; i < txt.size(); i++) {
		txt_val = ((txt_val - (txt[i-m]-'A')*RM %Q + Q) * R + txt[i]-'A') % Q;
		if(txt_val == pat_val && valid(txt, pat, i-m+1, m)) return i - m + 1;
	}
	return - 1;//û��ƥ��
}

//��֤����
bool valid(const string& txt, const string& pat, int index, int m) {
	for (int i = 0; i <= m - 1; i++) if (txt[index + i] != pat[i]) return false;
	return true;
}
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*KMP�㷨*/



#include "search3_4.h"

int main(){
	cout << "启动" << endl;
	ifstream in("info.txt");
	vector<string> m;
	string s;
	/*while (in >> s)
	   cout << s << endl;;
	while(getline(in, s))
	cout << s << endl;*/
	/*测试拉链哈希表
	my_hash k(in);
	node* h = k.serch("fuyin");
	cout << h->val << endl;
	k.del("fuyin");
	h = k.serch("fuyin");
	if (h == NULL) cout << "没找到" << endl;*/
	linear_hash l(in);
	l.insert("fuyin", 100);
	l.serach("fuyin");
	l.del("fuyin");
	l.serach("fuyin");
	l.serach("liguai");
	return 0;


}
#include "graph41.h"

int main(){
	/*int v = 5;
	vector<vector<int>> g;
	vector<int> a;
	for (int i = 0; i != v; i++)
		g.push_back(a);
	cout << g.size() << endl;*/
	/* * * * * * * * * * * * * * */
	cout << "ͼģ��Ϊ��" << endl;
	ifstream in("graph.txt");
	graph g(in);
	cout << g << endl;
	/* * * * * * * * * * * * * * * */

	/* * * * * * * * * * * * * * * */
	cout << "�붥��0��ͨ�Ľڵ�Ϊ��" << endl;
	vector<bool> vec(13, false);
	depth_first_search(g, vec, 0);
	for (int i = 0; i!= vec.size(); i++){
		if (vec[i] == true) cout << i<<" ";

	}
	cout << endl;

	/* * * * * * * * * * * * * * * * */
	cout << "0��6��ô��" << endl;
	path_to(g, 0, 6);
	/* * * * * * * * * * * * * * * * */

	/* * * * * * * * * * * * * * * * */
	cout << "0��6�����ô��" << endl;
	bpath(g,0 ,6);
	/* * * * * * * * * * * * * * * * */
	cc(g);



}
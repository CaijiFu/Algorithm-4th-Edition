#include "graph41.h"

int main(){
	/*int v = 5;
	vector<vector<int>> g;
	vector<int> a;
	for (int i = 0; i != v; i++)
		g.push_back(a);
	cout << g.size() << endl;*/
	/* * * * * * * * * * * * * * */
	cout << "图模型为：" << endl;
	ifstream in("graph.txt");
	graph g(in);
	cout << g << endl;
	/* * * * * * * * * * * * * * * */

	/* * * * * * * * * * * * * * * */
	cout << "与顶点0连通的节点为：" << endl;
	vector<bool> vec(13, false);
	depth_first_search(g, vec, 0);
	for (int i = 0; i!= vec.size(); i++){
		if (vec[i] == true) cout << i<<" ";

	}
	cout << endl;

	/* * * * * * * * * * * * * * * * */
	cout << "0到6怎么走" << endl;
	path_to(g, 0, 6);
	/* * * * * * * * * * * * * * * * */

	/* * * * * * * * * * * * * * * * */
	cout << "0到6最近怎么走" << endl;
	bpath(g,0 ,6);
	/* * * * * * * * * * * * * * * * */
	cc(g);



}
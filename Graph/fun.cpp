#include"graph41.h"

//添加一条边
void graph::add_e(int a, int b){
	g[a].push_back(b);
	g[b].push_back(a);
	e_size++;
}
//添加一个顶点
void graph::add_v(){
	vector<int> a;
	g.push_back(a);
	v_size++;
}
//为graph类编写输出运算符函数
ostream& operator<<(ostream& os, const graph& g){
	for (int i = 0; i != g.v_size; i++){
		os << i << ":";
		for (int j = 0; j != g.g[i].size(); j++){
			os << g.g[i][j] << " ";
		}
		os << endl;
	}
	return os;
}
//深度优先搜索(所有与顶点v连通的点)
void depth_first_search(graph & g, vector<bool> & vec, int v){
	vec[v] = true;
	for (auto i : g.adj(v)){
		if (vec[i] == false) depth_first_search(g, vec, i);
	}
	
}

//是否存在从原点s到顶点v的路径
bool has_path_to(graph & g,int s, int v){
	vector<bool> marked(13, false);
	depth_first_search(g, marked, s);
	return marked[v];
}

//生成与与原点s到相连通的点的地图(即深度优先搜索路径图)
void path(graph&g, int s, vector<bool>& marked, vector<int> &edgeto){
	marked[s] = true;
	for (auto i : g.adj(s)){
		if (!marked[i]){
			edgeto[i] = s;
			path(g, i, marked, edgeto);
		}
	}	
}

//找出一条从原点s到v的路径
void path_to(graph&g, int s, int v){
	if (!has_path_to(g, s, v)) { 
		cout << "没有路径" << endl; 
		return;
	}
	vector<int> edge_to(13);
	vector<bool> marked(13, false);
	path(g, s, marked, edge_to);
	stack<int> map;
	for (int i = v; i != s; i = edge_to[i])
		map.push(i);
	cout << s<<":";
	while (!map.empty()) {
		cout << map.top()<<" "; 
		map.pop();
	}
	cout << endl;
	
	
}


//广度优先搜索,edgeto为搜索的路线图,与顶点s连通的图
void breadth_first(graph& g, vector<bool>& marked, vector<int>&edgeto, int s){
	queue<int> ve;
	ve.emplace(s);
	int v;
	while (!ve.empty()){
		v = ve.front();
		marked[v] = true;
		ve.pop();
		for (auto i : g.adj(v)){
			if (!marked[i]){
				edgeto[i] = v;
				ve.emplace(i);
			}
		}
	}
}

//找从s到v的最短路径
void bpath(graph&g, int s, int v){
	vector<bool> marked(13, false);
	vector<int> edgeto(13);
	breadth_first(g, marked, edgeto, s);
	if (!marked[v]) { 
		cout << "没有路" << endl;
		return; 
	}
	stack<int> sta;
	for (int i = v; i != s; i = edgeto[i])
		sta.push(i);
	cout << s << ":";
	while (!sta.empty()){
		cout << sta.top() << " ";
		sta.pop();
	}
	cout << endl;
}

//找到顶点s连通分量并标记为index
void cc_element(graph&g, vector<bool>&marked, int s,int index, vector<int>& ele){
	marked[s] = true;
	ele[s] = index;
	for (auto i : g.adj(s))
		if (!marked[i]) cc_element(g, marked, i, index, ele);
}

//返回图g的连通图分量
vector<vector<int>>& cc(graph& g){
	vector<bool> marked(g.V(), false);
	vector<int> ele(g.V());
	int count = 0;
	for (int i = 0; i != g.V(); i++){
		if (!marked[i]){
			cc_element(g, marked, i, count, ele);
			count++;
		}
	}
	vector<vector<int>> com(count+1);
	for (int i = 0; i != g.V(); i++)
		com[ele[i]].push_back(i);
	for (int i = 0; i != count; i++){
		cout << "第" << i << "类：";
		for (auto j : com[i])
			cout << j<<" ";
		cout << endl;
	}
	return com;
		
	

}
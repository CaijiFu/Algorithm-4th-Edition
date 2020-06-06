#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
using namespace std;

class graph{
friend ostream& operator<<(ostream& os, const graph&);
public:
	graph() = default;
	graph(int v){
		v_size = v;
		e_size = 0;
		vector<int> a;
		//压入表示和顶点i相邻矩阵的空表
		for (int i = 0; i != v; i++)
			g.push_back(a);
	}
	graph(ifstream& in){
		string line,v1,v2;
		while (getline(in, line)){
			istringstream ele(line);
			ele>> v1 >> v2;
			if (v1 == "E") e_size = stoi(v2);
			else if (v1 == "V") { 
				vector<int> a;
				v_size = stoi(v2);
				for (int i = 0; i != v_size; i++)
					g.push_back(a);
			}
			else{
				int index1 = stoi(v1), index2 = stoi(v2);
				g[index1].push_back(index2);
				g[index2].push_back(index1);
			}
		}
	}
	//返回顶点与顶点v相连的顶点
	vector<int>& adj(int v){
		return g[v];
	}
	//添加一条边
	void add_e(int a, int b);
	//添加一个顶点
	void add_v();
	//返回顶点数
	int V(){
		return v_size;
	}
	//返回边数
	int E(){
		return e_size;
	}

private:
	int v_size;//顶点数
	int e_size;//边数
	vector<vector<int>> g;//邻接表数组
};

// 为graph类编写输出运算符函数
ostream& operator<<(ostream& os, const graph&);


//深度优先搜索
void depth_first_search(graph & g, vector<bool> & vec, int v);

//是否存在从原点s到顶点v的路径
bool has_path_to(graph & g, int s, int v);

//生成与与原点s到相连通的点的地图(即深度优先搜索路径图)
void path(graph&g, int s, vector<bool>& marked, vector<int> &edgeto);

//找出一条从原点s到v的路径
void path_to(graph&g, int s, int v);

//找从s到v的最短路径
void bpath(graph&g, int s, int v);

//返回图g的连通图分量
vector<vector<int>>& cc(graph& g);




#endif
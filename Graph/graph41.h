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
		//ѹ���ʾ�Ͷ���i���ھ���Ŀձ�
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
	//���ض����붥��v�����Ķ���
	vector<int>& adj(int v){
		return g[v];
	}
	//���һ����
	void add_e(int a, int b);
	//���һ������
	void add_v();
	//���ض�����
	int V(){
		return v_size;
	}
	//���ر���
	int E(){
		return e_size;
	}

private:
	int v_size;//������
	int e_size;//����
	vector<vector<int>> g;//�ڽӱ�����
};

// Ϊgraph���д������������
ostream& operator<<(ostream& os, const graph&);


//�����������
void depth_first_search(graph & g, vector<bool> & vec, int v);

//�Ƿ���ڴ�ԭ��s������v��·��
bool has_path_to(graph & g, int s, int v);

//��������ԭ��s������ͨ�ĵ�ĵ�ͼ(�������������·��ͼ)
void path(graph&g, int s, vector<bool>& marked, vector<int> &edgeto);

//�ҳ�һ����ԭ��s��v��·��
void path_to(graph&g, int s, int v);

//�Ҵ�s��v�����·��
void bpath(graph&g, int s, int v);

//����ͼg����ͨͼ����
vector<vector<int>>& cc(graph& g);




#endif
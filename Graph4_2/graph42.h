#ifndef GRAPU_42
#define GRAPU_42

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<stack>
#include<queue>
using namespace std;

class Dgraph{
friend ostream& operator<<(ostream& out, const Dgraph& g);
public:
	Dgraph() = default;
	//����v�����������ͼ
	Dgraph(int v) :E_SIZE(0), V_SIZE(v){
		vector<int> a;
		while (v != 0)
			dg.push_back(a);
		v--;
	}
	//��TXT�ĵ��д���һ��ͼ
	Dgraph(ifstream& in){
		string line,ele1,ele2;
		vector<int> a;
		while (getline(in, line)){
			stringstream s(line);
			s >> ele1 >> ele2;
			if (ele1 == "V") { 
				V_SIZE = stoi(ele2);
				for (int i = 0; i != V_SIZE; i++)
					dg.push_back(a);
			}
			else if (ele1 == "E") E_SIZE = stoi(ele2);
			else {
				dg[stoi(ele1)].push_back(stoi(ele2));
			}
		}
	}

	//���һ����v��w
	void add(int v,int w){
		dg[v].push_back(w);
		E_SIZE++;
	}
	//���ض����붥��vֱ�������Ķ���
	vector<int>& adj(int v){
		return dg[v];
	}
	//���ض�����
	int V(){
		return V_SIZE;
	}
	//���ر���
	int E(){
		return E_SIZE;
	}
	//��תͼ
	Dgraph reverse(){
		vector<vector<int>> xg(V_SIZE);
		for (int i = 0; i != xg.size(); i++)
		for (auto j : dg[i])
			xg[j].push_back(i);
		dg = xg;
		return *this;
	}
private:
	vector<vector<int>> dg;
	int E_SIZE;
	int V_SIZE;
};

//���������
ostream& operator<<(ostream& out, const Dgraph& g);






#endif
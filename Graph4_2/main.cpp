#include"graph42.h"

int main(){
	ifstream in("dgraph.txt");
	Dgraph g(in);
	cout << g << endl;
	cout << g.reverse();



	return 0;
}
#include"graph42.h"

ostream& operator<<(ostream& out, const Dgraph& g){
	for (int i = 0; i != g.V_SIZE; i++){
		out << i << ":";
		for (int j = 0; j != g.dg[i].size(); j++){
			out << g.dg[i][j] << " ";
		}
		out << endl;
	}
	return out;
}
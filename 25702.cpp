#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	int m, n, x, b, p = 0;
	char c;
	cin >> n >> m >> x;
	unordered_map<int, int> L;
	unordered_map<int, int> C;
	unordered_map<int, unordered_map<int, int>> Closs;
	unordered_map<int, unordered_map<int, int>> Lloss;

	int P[5] = {};
	for(int i = 0; i < x; i++){
		p = (p)%4+1;
		cin >> c >> b;
		if(c == 'L'){
			L[b] = p;
			Lloss[b].clear();
			for(auto i : Closs)
				Closs[i.first][b] = p;
		}
		
		if(c == 'C'){
			C[b] = p;
			Closs[b].clear();
			for(auto i : Lloss)
				Lloss[i.first][b] = p;
		}
	}

	for(auto c : C)
		P[c.second] += n - Closs[c.first].size();

	for(auto l : L)
		P[l.second] += m - Lloss[l.first].size();
	
	cout <<"R" << P[1] <<" H" << P[2] <<" C" << P[3] <<" P" << P[4]<< "\n";

	return 0;
}

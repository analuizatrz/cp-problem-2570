#include <bits/stdc++.h> 

using namespace std;
bool cmp(pair<pair<int, int>, pair<int, int>>& a, pair<pair<int, int>, pair<int, int>>& b){ 
    return a.second.second < b.second.second; 
} 

int main(){
	int m, n, x, b, p = 0;
	char c;
	cin >> n >> m >> x;
	// pair L3 , input
	// pair P X, player and iteration
	map<pair<int, int>, pair<int, int>> inputs;
	unordered_map<int, pair<int, int>> L;
	unordered_map<int, pair<int, int>> C;

	int P[5] = {};
	for(int i = 0; i < x; i++){
		p = ((p)%4)+1;
		cin >> c >> b;
		inputs[{c=='C', b}] = {p, i};
	}
	
	vector<pair<pair<int, int>, pair<int, int>>> A; 

    for (auto& it : inputs)
        A.push_back(it); 

    sort(A.begin(), A.end(), cmp); 
  
    for (auto& it : A){
		if(it.first.first){
			C[it.first.second] = {it.second.first, n};
			for(auto& l : L)
				l.second.second--;
		}else{
			L[it.first.second] = {it.second.first, m};
			for(auto& c : C)
				c.second.second--;
		}
	}

	for(auto& it : C)
		P[it.second.first] += it.second.second;

	for(auto& it : L)
		P[it.second.first] += it.second.second;
	
	cout <<"R" << P[1] <<" H" << P[2] <<" C" << P[3] <<" P" << P[4]<< "\n";

	return 0;
}

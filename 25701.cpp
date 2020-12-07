#include<bits/stdc++.h>

using namespace std;

int main(){
	int m, n, x, b, p = 0;
	char c;

	cin >> n >> m >> x;
	int A[n][m] ={};
	int P[5] = {};

	for(int i = 0; i < x; i++){
		p = (p)%4+1;
		cin >> c >> b;

		if(c == 'L')
			for(int j = 0; j < m; j++){
				A[b-1][j] = p;
			}
			
		else
			for(int j = 0; j < n; j++){
				A[j][b-1] = p;
			}
	}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			P[A[i][j]]++;

	cout <<"R" << P[1] <<" H" << P[2] <<" C" << P[3] <<" P" << P[4]<< "\n";

	return 0;
}

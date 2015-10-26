#include<iostream>

using namespace std;

typedef long long int lli;

lli C(int n, int r){
	
	if (n == r || r == 0)
		return 1;

	if (r < n / 2)
		r = n - r;	// nCr  = nC(n-r)
	
	lli ans=1;

	for (int i = 1; i <= n-r; i++){
		ans *= (n-i+1);
		ans /= i;
	}
	return ans;
}


int main(){
	int T;
	cin >> T;

	int n, k;	
	
	while (T--){
		cin >> n >> k;		 
		cout << C(n - 1, k - 1) << endl;		
	}
	return 0;
}
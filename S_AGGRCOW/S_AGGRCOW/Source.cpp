#include<iostream>
#include<vector>
#include<set>
#include "math.h"
#include<algorithm>

#define for(i,N,val) for(int i=val;i<N;i++)
#define sz(A) int(A.size())

using namespace std;

//typedef long long int lli;
typedef vector<int> vi;

vi input;
int minNumberOfCows=0;

bool predicate(int minDist){
	int countOfCows = 1;
	if (sz(input) > 0){		
		int prev = input[0];
		for (i, sz(input), 1){
			if (input[i] - prev >= minDist){
				countOfCows++;
				prev = input[i];
			}
		}
	}
	return countOfCows >= minNumberOfCows;
}

int BinarySearch(){
	double hi = 0, lo = 0;

	if (sz(input) > 0){
		hi = input[sz(input) - 1] - input[0];
		lo = hi;
		for (i, sz(input), 1){
			if (input[i] - input[i - 1] < lo)
				lo = input[i] - input[i - 1];
		}

		while (lo < hi){			
			double mid = lo + ceil((hi - lo) / 2);
			if (predicate(mid)){
				lo = mid;
			}
			else{
				hi = mid - 1;
			}
		}
	}
	return lo;
}

int main(){
	int T;
	cin >> T;
	int N;
	
	while (T--){
		cin >> N >> minNumberOfCows;
		input = vi(N);
		for(i,N,0){
			cin >> input[i];
		}
		set<int> s_input(input.begin(), input.end());
		input = vi(s_input.begin(), s_input.end());

		if (sz(input) >= minNumberOfCows){	
			cout << BinarySearch() << endl;
		}
		else{
			cout << 0 << endl;
		}
	}
	return 0;
}
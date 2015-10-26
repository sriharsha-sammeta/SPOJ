#include<iostream>
#include<vector>
#include"math.h"

using namespace std;

void sieves(vector<bool>&primesFrom2){
	
	primesFrom2[0] = false;
	primesFrom2[1] = false;

	for (int i = 2; i < primesFrom2.size(); i++){
		if (primesFrom2[i]){
			for (int j = i*i; j < primesFrom2.size(); j+=i){
				primesFrom2[j] = false;
			}
		}
	}	
}

void caliclulatePrimesForSegment(vector<bool>&primes,int m,int n){

	vector<bool>primesFrom2(sqrt(n) + 1, true);
	sieves(primesFrom2);
	if (m == 1)
		primes[0] = false;

	for (int i = 2; i <= sqrt(n); i++){
		if (primesFrom2[i]){
			int m2 = m / i;
			m2 = m2*i;
			for (int j = m2; j <= n; j += i){
				if (j >= m && i!=j){
					primes[j - m] = false;
				}
			}
		}
	}

}

int main(){

	int T;
	scanf("%d", &T);
	int n, m;
	while (T--){
		scanf("%d %d", &m, &n);
		vector<bool>primes(n - m + 1,true); //ex: 10 to 13 -> 10,11,12,13 -> 13-10+1 4 
		caliclulatePrimesForSegment(primes, m, n);
		for (int i = 0; i < primes.size(); i++){
			if (primes[i]){
				cout << i+m << endl;
			}
		}
	}
	return 0;
}
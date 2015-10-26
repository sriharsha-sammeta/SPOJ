#include<iostream>
#include<vector>
#include "math.h"
#define sz(A) int(A.size())
using namespace std;
typedef vector<int> vi;

void getPrimesFrom0(vector<int> &SOE){
	
	bool end = false;
	SOE[0] = 1;
	SOE[1] = 1;
	for (int i = 2; i < sz(SOE); i++){
		if (SOE[i] == 1)
			continue;

		end = true;
		for (int j = i + i; j < sz(SOE); j += i){
			SOE[j] = 1;
			end = false;
		}

		if (end)
			break;
	}
}

void primeNumberList(vi &SOE,int x, int y){

	vector<int>primes(sqrt(y)+1, 0);
	getPrimesFrom0(primes);
	if (x == 1)
		SOE[0] = 1;
	for (int i = 2; i < sz(primes); i++){
		if (primes[i] == 1)
			continue;
		int temp = x / i;
		temp = temp*i;
		while (temp <= y){
			if (temp >= x && temp!=i)
				SOE[temp - x] = 1;
			temp += i;
		}
	}	
}


int main2(){
	int T;	
	scanf("%d",&T);

	int x, y;
	while (T-- != 0){	
		scanf("%d %d", &x, &y);
		vi SOE(y-x+1, 0);
		primeNumberList(SOE,x,y);
		for (int i = x; i <= y; i++){
			if (SOE[i - x] == 0)
				printf("%d\n", i);
		}
		//if (T > 0)
		//	cout << endl;
	}
	return 0;
}
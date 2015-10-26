#include<iostream>
#include<bitset>
#include<vector>

using namespace std;
const int SIZE = 10000000;

//vector<int>primes(5000001);

int main(){
	bitset<SIZE> primes;

	primes.flip();

	for (int i = 2; i <= sqrt(SIZE); i++){
		if (primes[i]){
			for (int j = i; j < SIZE; j += i){
				primes[j] = false;
			}
		}
	}

	
	int count = 0;
	for (int i = 2; i < SIZE; i++){
		if (primes[i])
			count++;			
	}
	cout << count << endl;
	
	return 0;
}
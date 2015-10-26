#include<iostream>

using namespace std;

long long int rev(int num){
	long long int total = 0;
	while (num != 0){
		total = (total * 10) + (num % 10);
		num /= 10;
	}
	return total;
}

int main(){
	int x, y;
	int N;
	cin >> N;
	while (N-- != 0){
		cin >> x >> y;
		cout << rev(rev(x) + rev(y)) << endl;
	}
	return 0;
}
#include<iostream>
#include<algorithm>

using namespace std;



int main(){
	int T,N;
	cin >> T;
	while (T-- != 0){
		cin >> N;
		int count2 = N / 2;
		int num = 5;
		int count5 = 0;
		while (num <= N){
			count5 += (N / num);
			num *= 5;
		}
		cout<<min(count2, count5)<<endl;
	}

	return 0;
}
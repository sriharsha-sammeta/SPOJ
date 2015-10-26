#include<iostream>

using namespace std;

int getForXequalsY(int x){	
	int count = x / 2;
	count *= 3;
	count += (x - (x / 2));
	return count;
}

int main(){
	int T;
	int x, y;
	int count = 0;
	cin >> T;
	while (T--){
		cin >> x >> y;
		if (x == y){
			cout << getForXequalsY(x) << endl;
		}
		else if(x-2==y){
			int Xchecker = getForXequalsY(x);
			int X1Checker = getForXequalsY(x - 1);
			if (X1Checker == Xchecker - 1)
				cout << X1Checker - 1 << endl;
			else if (X1Checker == Xchecker - 3)
				cout << X1Checker + 1 << endl;
			else
				cout << "No Number\n";
		}
		else{
			cout << "No Number\n";
		}
	}

	return 0;
}
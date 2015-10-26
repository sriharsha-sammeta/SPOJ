#include<iostream>
#include<vector>
#define sz(A) int(A.size())

using namespace std;

vector<int> fact;


void findFact(int n){
	
	fact = vector<int>(1000, 0);
	fact[0] = 1;
	vector<int> res(1000, 0);	
	int ul = 0;

	for (int j = 2; j <= n; j++){
		vector<int>m2(3, 0);
		res=vector<int>(1000, 0);
		int kul = -1;

		for (int p = j; p != 0 && kul<sz(m2);p/=10){
			kul++;
			m2[kul] = p % 10;						
		}

		int carry = 0;
				
		for (int i = 0; i <=ul; i++){

			for (int k = 0; k <=kul; k++){
				if (i == 0 && k == 0)
					res[i] = fact[i] * m2[k];
				else{
					res[i + k] += fact[i] * m2[k];
					if (res[i + k] > 0 && i+k > ul)
						ul = i + k;					
				}
				
				//res[i + k] += carry;
				
				res[i + k + 1] += res[i + k] / 10;
				if (res[i + k + 1] > 0 && i + k + 1 > ul)
					ul = i + k + 1;
				res[i + k] %= 10;				
			}			
		}			
		for (int i = 0; i <= ul; i++){
			fact[i] = res[i];
		}
	}

}


int main(){
	int T;
	long long int N;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &N);
		findFact(N);
		bool zeroflag = true;
		for (int i = sz(fact)-1; i >= 0; i--){
			if (fact[i] && zeroflag){
				zeroflag = false;				
			}
			if (!zeroflag)
				printf("%d", fact[i]);
		}
		if (T != 0)
			printf("\n");
	}
	return 0;
}
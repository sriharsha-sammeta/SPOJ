#include<cstdio>
#include<math.h>

int T(int n){
	int result = n;
	for (int i = 2; i*i <= n; i++) {
		if (n % i == 0) result -= result / i;
		while (n % i == 0) n /= i;
	}
	if (n > 1) result -= result / n;
	return result;
}

int main(){

	int N;
	scanf("%d", &N);	
	while (N--){
		int num;
		scanf("%d", &num);		
		printf("%d\n", T(num));
	}
	return 0;
}
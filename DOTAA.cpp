#include<cstdio>

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	int input[500];
	int t, n, m, d;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d %d", &n, &m, &d);
		int count = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", input + i);
			count += input[i] / d;
			if (input[i] % d == 0){
				count--;
			}			
		}
		if (count >= m){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
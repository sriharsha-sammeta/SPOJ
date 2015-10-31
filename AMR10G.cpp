#include<cstdio>
#include<algorithm>
#include<climits>
int input[20000];

using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int N, K;
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++){
			scanf("%d", input + i);
		}
		sort(input, input + N);
		int minValue = INT_MAX;
		for (int i = 0; i < N && i + K - 1 < N; i++){
			minValue = min(minValue, input[i + K - 1] - input[i]);
		}
		printf("%d\n", minValue);
	}
	return 0;
}
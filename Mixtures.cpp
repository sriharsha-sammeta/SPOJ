#include<cstdio>
#include<climits>
#include<algorithm>

int arr[100];
int N;

struct ChemRes{
	int chemical;
	long long int smoke;
};

struct ChemRes dp[100][100];

struct ChemRes TopDown(int i,int j){
	struct ChemRes res;
	res.chemical = -1;
	res.smoke = LLONG_MAX;
	if (dp[i][j].chemical != -1){
		return dp[i][j];
	}
	if (i == j){
		res.chemical = arr[i];
		res.smoke = 0;
	}
	else{
		for (int k = i; k < j; k++){
			auto a = TopDown(i, k);
			auto b = TopDown(k + 1, j);
			auto minSmoke = a.smoke + b.smoke + (a.chemical*b.chemical);
			if (minSmoke < res.smoke){
				res.smoke = minSmoke;
				res.chemical = (a.chemical + b.chemical) % 100;
			}
		}		
	}
	dp[i][j] = res;
	return dp[i][j];
}


void bottomUpDp(){	
	for (int i = N - 1; i >= 0; i--){
		for (int j = i; j < N; j++){
			dp[i][j].smoke = LLONG_MAX;
			if (i == j){
				dp[i][j].chemical = arr[i];
				dp[i][j].smoke = 0;
			}
			else{
				for (int k = i; k < j; k++){
					auto a = dp[i][k];
					auto b = dp[k + 1][j];
					auto minSmoke = a.smoke + b.smoke + (a.chemical*b.chemical);
					if (minSmoke < dp[i][j].smoke){
						dp[i][j].smoke = minSmoke;
						dp[i][j].chemical = (a.chemical + b.chemical) % 100;
					}
				}
			}
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	while (scanf("%d", &N) != EOF){		
		for (int i = 0; i < N; i++){
			scanf("%d", arr + i);
		}			
		bottomUpDp();
		printf("%lld\n", dp[0][N - 1].smoke);
	}
	return 0;
}
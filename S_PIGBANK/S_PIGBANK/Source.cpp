#include<cstdio>
#include<vector>
#include<algorithm>

#define INT_MAX 2147483647

using namespace std;

#define sz(A) int(A.size())

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

vector<pair<int,int> >input;

int dp[10000];

int minValue(int maxWeight){
	dp[0] = 0;
	for (int i = 1; i <= maxWeight; i++){
		dp[i] = INT_MAX;
	}
	for (int i = 0; i < sz(input); i++){
		for (int j = 1; j <= maxWeight; j++){
			if (input[i].second <= j && dp[j-input[i].second] != INT_MAX){
				dp[j] = min(dp[j], dp[j - input[i].second] + input[i].first);				
			}			
		}
	}
	return dp[maxWeight];
}


int main(){
	int N;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--){
		int onlyPigWeight;
		int pigWeight;
		scanf("%d %d", &onlyPigWeight, &pigWeight);
		int noOfCoins;
		scanf("%d", &noOfCoins);
		input.clear();
		while (noOfCoins--){
			int value, weight;
			scanf("%d %d", &value, &weight);
			input.push_back(make_pair(value, weight));
		}
		int res= minValue(pigWeight - onlyPigWeight);
		if (res != INT_MAX){
			printf("The minimum amount of money in the piggy-bank is %d.\n", res);
		}
		else{
			printf("This is impossible.\n");
		}
	}

	return 0;
}
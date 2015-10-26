#include<cstdio>
#include<vector>
#include<algorithm>


#define isBetween(val,x,y) (x<=val && val<=y)
#define sz(input) int(input.size())

using namespace std;

vector<int> input;
int dp[2000][2000];
int profit(int start, int end){

	if (start <= end){
		if (dp[start][end] == 0){
			int age = sz(input) - (end - start + 1) + 1;
			dp[start][end] =max(profit(start + 1, end) + input[start] * age, profit(start, end - 1) + input[end] * age);
		}
		return dp[start][end];
	}
	else {
		return 0;
	}
}


int main(){
	int N;
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	input = vector<int>(N);
	for(int i=0;i<N;i++){
		scanf("%d", &input[i]);
	}
	printf("%d\n", profit(0, sz(input) - 1));

	return 0;
}
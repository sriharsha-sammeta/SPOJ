#include<cstdio>
#include<vector>
#include<algorithm>

#define cost first
#define fun second
#define sz(A) int(A.size())

using namespace std;
typedef pair<int, int> pii;

vector<pii> input;
vector<vector<int>> dp(101, vector<int>(501));

int maxVal(int i, int budget){
	if (i >= sz(input) || budget <= 0)
		return 0;
	if (input[i].first > budget)
		return maxVal(i + 1, budget);
	else 		
		return max(input[i].second + maxVal(i + 1, budget - input[i].first), maxVal(i + 1, budget));	
}

pair<int,int> getMinBudgetAndMaxFun(int budget,int noOfParties){
	for (int i = 0; i <= budget; i++){
		dp[0][i] = 0;
	}
	for (int i = 0; i <= noOfParties; i++){
		dp[i][0] = 0;
	}		
	for (int i = 1; i <= noOfParties; i++){
		for (int j = 1; j <= budget; j++){			
			if (input[i].cost <= j){				
				dp[i][j] = max(input[i].fun + dp[i - 1][j - input[i].cost], dp[i - 1][j]);
			}
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	
	for (int j = 1; j <= budget; j++){
		if (dp[noOfParties][j] == dp[noOfParties][budget])
			return make_pair(j,dp[noOfParties][budget]);
	}
}


int main(){
	int budget, noOfParties;
	freopen("input.txt", "r", stdin);
	

	while (scanf("%d %d", &budget, &noOfParties), (budget || noOfParties)){
		input = vector<pii>();
		input.push_back(make_pair(0, 0));
		int ip1, ip2;
		for (int i = 0; i < noOfParties; i++){
			scanf("%d %d", &ip1, &ip2);
			input.push_back(make_pair(ip1, ip2));
		}
		pair<int,int>res=getMinBudgetAndMaxFun(budget, noOfParties);
		printf("%d %d\n", res.cost,res.fun);
	}

	return 0;
}
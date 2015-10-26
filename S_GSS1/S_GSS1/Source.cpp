#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;
typedef vector<int> vi;

vi input;
vi tree;

int buildSegTree(int i,int L,int R){
	if (L == R){
		tree[i] = input[L];
		return tree[i];
	}else if (L < R){
		int mid = (L + R) / 2;
		int leftV = buildSegTree((2 * i) + 1, L, mid);
		int rightV = buildSegTree((2 * i) + 2, mid + 1, R);
		tree[i] = max(max(leftV, rightV), leftV + rightV);
		return tree[i];
	}
	else{
		return INT_MIN;
	}
}

int query(int i, int L, int R,int qL,int qR){
	if (L == qL && R == qR){
		return tree[i];
	} 
	int mid = (L + R) / 2;
	if (L <= qL && qR <= mid){
		return query((2 * i) + 1, L, mid, qL, qR);
	}
	else if (mid < qL && qR <= R){
		return query((2 * i) + 2, mid + 1, R, qL, qR);
	}
	else if (L <= qL && qL <= mid && mid < qR && qR <= R){
		int lValue = query((2 * i) + 1, L, mid, qL, mid);
		int rValue = query((2 * i) + 2, mid + 1, R, mid + 1, qR);
		return max(max(lValue, rValue), lValue + rValue);
	}
	return 0;
}

int main2(){
	int N, M;
	scanf("%d", &N);
	input = vi(N+1);
	tree = vi(4 * N);
	for(int i=1;i<=N;i++){
		scanf("%d", &input[i]);
	}
	buildSegTree(0, 1, N);

	scanf("%d", &M);
	int x, y;
	while (M--){
		scanf("%d %d", &x, &y);
		printf("%d",query(0,1,N,x, y));
	}
	return 0;
}
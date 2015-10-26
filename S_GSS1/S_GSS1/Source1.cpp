#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

class SegmentTree{
private:
	struct node{
		int maxLeftSum;
		int maxRightSum;
		int maxSum;
		int Total;
	public: 
		node(int maxLeftSum,int maxRightSum,int maxSum,int Total){
			this->maxLeftSum = maxLeftSum;
			this->maxRightSum = maxRightSum;
			this->maxSum = maxSum;
			this->Total = Total;
		}
		node(){
			maxLeftSum = 0;
			maxRightSum = 0;
			maxSum = 0;
			Total = 0;
		}
	};

	vector<node>segmentArr;

	int *input;
	int sizeOfInput;

public:
	SegmentTree(int input[],int n){
		this->input = input;
		this->sizeOfInput = n;
		segmentArr = vector<node>(getSegmentArrSize(n));
	}

	void buildSegmentTree(int index,int lo,int hi){
		if (lo == hi){
			segmentArr[index] = makeNode(input[lo]);			
		}
		else if (lo < hi){
			int mid = (lo + hi) / 2;
			int left = (2 * index) + 1; int right = left + 1;
			buildSegmentTree(left, lo, mid);
			buildSegmentTree(right, mid + 1, hi);
			segmentArr[index] = merge(segmentArr[left], segmentArr[right]);		
		}		
	}

	int query(int lo,int hi){
		node res = query(0, 1, sizeOfInput, lo, hi);
		return res.maxSum;
	}

private:
	int getSegmentArrSize(int n){
		int size = 1;
		while (size < n){
			size <<= 1;
		}
		return size << 1;
	}

	node makeNode(int value){
		return node(value, value, value, value);
	}
	node merge(node&leftNode, node&rightNode){
		node res;		
		res.maxLeftSum = max(leftNode.maxLeftSum, leftNode.Total + rightNode.maxLeftSum);
		res.maxRightSum = max(rightNode.maxRightSum, leftNode.maxRightSum + rightNode.Total);
		res.Total = leftNode.Total + rightNode.Total;
		res.maxSum = max(res.maxLeftSum, max(res.maxRightSum,max(leftNode.maxSum,max(rightNode.maxSum,leftNode.maxRightSum+rightNode.maxLeftSum))));

		return res;
	}

	node query(int index,int lo, int hi, int qlo,int qhi){
		if (lo == qlo && hi == qhi){
			return segmentArr[index];
		}
		int left = (2 * index) + 1; int right = left + 1;
		int mid = (lo + hi) / 2;

		if (qhi <= mid){
			return query(left, lo, mid, qlo, qhi);
		}
		else if (mid < qlo){
			return query(right, mid + 1, hi, qlo, qhi);
		}
		else{
			node leftNode = query(left, lo, mid, qlo, mid);
			node rightNode = query(right, mid + 1, hi, mid + 1, qhi);
			return merge(leftNode, rightNode);
		}		
	}

};

int main(){
	int N, M;
	scanf("%d", &N);
	int * input = new int[N+1];

	for (int i = 1; i <= N; i++){
		scanf("%d", &input[i]);
	}
	SegmentTree tree(input, N);
	tree.buildSegmentTree(0,1, N);		

	scanf("%d", &M);
	int x, y;
	while (M--){
		scanf("%d %d", &x, &y);
		printf("%d\n", tree.query(x,y));
	}
	return 0;
}

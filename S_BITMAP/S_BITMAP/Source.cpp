#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<set>

using namespace std;

#define mp(i,j) make_pair(i,j)
#define MAX_V 183
#define isbetween(i,row,col) (1<=i.first && i.first<=row && 1<=i.second && i.second<=col)
#define fr(i,lo,hi) for(int i=lo;i<hi;i++)
#define frV(V,it) for(auto it=V.begin();it!=V.end();it++)

typedef pair<int, int>pii;
typedef vector<int> vi;

vector<vi> input;
int n, m;


void setChildren(vector<pii>&children, pii &root){

	children.push_back(mp(root.first, root.second + 1));
	children.push_back(mp(root.first + 1, root.second));
	children.push_back(mp(root.first, root.second - 1));
	children.push_back(mp(root.first - 1, root.second));
}


void caliculate(pii root){
	queue<pii> q;

	q.push(root);
	
	while (!q.empty()){
		root = q.front();
		q.pop();

		vector<pii>children;

		setChildren(children, root);
		int rootDist = input[root.first][root.second];

		frV(children, child){			
			if (isbetween((*child), n, m) && rootDist + 1 < input[child->first][child->second]){
				q.push(*child);
				input[child->first][child->second] = rootDist + 1;
			}
		}
	}
}


int main(){
	
	int T;
	queue<pii>ones;

	cin >> T;

	char ch;
	
	while (T--){		
	
		cin >> n >> m;		
		
		input = vector<vi>(n+1, vi(m+1));				

		fr(i, 1, n + 1){
			fr(j, 1, m + 1){
				cin >> ch;
				if (ch - 48 != 1){
					input[i][j] = 2 * MAX_V;
				}
				else{
					input[i][j] = 0;
					ones.push(mp(i, j));
				}
			}
		}		
		
		while (!ones.empty()){
			caliculate(ones.front());
			ones.pop();
		}

		fr(i, 1, n + 1){
			fr(j, 1, m + 1){
				cout << input[i][j];
				if (j < m)
					cout << " ";
			}
			cout << endl;
		}

	}
	
	return 0;
}
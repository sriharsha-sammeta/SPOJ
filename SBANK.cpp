#include<map>
#include<iostream>
#include<string>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	map<string, int> res;
	string ip;	
	while (T--){
		int fileCount;
		scanf("%d\n", &fileCount);		
		while (fileCount--){
			getline(cin, ip);			
			res[ip]++;
		}
		getline(cin, ip);
		for (auto it = res.begin(); it != res.end(); it++){
			cout << it->first << " " << it->second << endl;
		}
		cout << endl;
		res.clear();
	}
	return 0;
}
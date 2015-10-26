#include<iostream>
#include<string>
#include<vector>

#define sz(A) int(A.size())
using namespace std;

int main2(){
	int count=0;
	string str;
	
	while (true){
		cin >> count;
		vector<string>res(count,"");
		
		if (count == 0)
			break;
		cin >> str;
		int length = 0;
		bool flag = false;
		while (length < sz(str)){
			if (length%count == 0)
				flag = !flag;
			if (flag){
				res[length%count] += str[length];				
			}
			else{
				res[count-length%count - 1] += str[length];
			}
			length++;
		}
		for (int i = 0; i < count; i++){
			cout << res[i];
		}
		cout << endl;
	}


	return 0;
}
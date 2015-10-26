#include<iostream>
#include<string>
#include<ctype.h>

#define sz(A) int(A.size())

using namespace std;

enum lang{
	c,
	java,
	error,
	init
};

int main(){
	string input;
	string output;
	
	//freopen("input.txt", "r", stdin);	

	while(cin>>input){
		output = "";
		lang oplang = init;
		bool underscoreVisitedJustBefore = false;		
	
		int i = 0;
		if (i< sz(input) && isalpha(input[i]) && islower(input[i])){			
			output += input[i];
			for (i++; i < sz(input); i++){
				if (!isalpha(input[i]) && input[i] != '_'){
					oplang = error;
					break;
				}
				if (isupper(input[i])){
					if ((oplang == init || oplang == c)){
						oplang = c;
						output += '_';
						output += tolower(input[i]);
					}
					else{
						oplang = error;
						break;
					}
				}
				else if (input[i] == '_'){
					if (((oplang == init || oplang == java) && !underscoreVisitedJustBefore)){
						oplang = java;																		
						underscoreVisitedJustBefore = true;
					}
					else{
						oplang = error;
						break;
					}					
				}
				else{
					if (underscoreVisitedJustBefore){
						output += toupper(input[i]);
						underscoreVisitedJustBefore = false;
					}
					else{
						output += input[i];
					}					
				}
			}
		}
		else{
			oplang = error;
		}
	
		if (oplang == error || underscoreVisitedJustBefore){
			cout << "Error!" << endl;
		}
		else{
			cout << output << endl;
		}

	}
	return 0;
}
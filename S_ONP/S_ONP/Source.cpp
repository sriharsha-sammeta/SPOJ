#include<iostream>
#include<string>
#include<stack>
#include<map>

#define tr(V,it) for(auto it=V.begin();it!=V.end();it++)

using namespace std;

map<char, int>value;

void convertToPolish(string &input){
	string ans="";
	stack<char>mystack;
	
	tr(input, it){
		if (isalpha(*it)){
			ans += *it;
		}
		else {
			switch (*it)
			{
			case '(':
				mystack.push(*it);
				break;
			case')':
				
				while (!mystack.empty() && mystack.top() != '('){
					ans += mystack.top();
					mystack.pop();
				}
				if (!mystack.empty() && mystack.top()=='('){
					mystack.pop();
				}

				break;
			case '+':
			case'-':
			case'*':
			case '/':
			case '^':
			{
				if (!mystack.empty()){
					char topValue = mystack.top();
					if (value[topValue] >= *it){						
						ans += topValue;
						mystack.pop();
					}
				}				
					mystack.push(*it);				
			}
				break;
			default:

				break;
			}
		}
	}
	while (!mystack.empty()){
		ans += mystack.top();
		mystack.pop();
	}

	cout << ans << endl;
}

int main(){
	int T;
	scanf("%d", &T);
	string input;
	value['+'] = 1;
	value['-'] = 2;
	value['*'] = 3;
	value['/'] = 4;
	value['^'] = 5;
	while (T--){
		cin >> input;
		convertToPolish(input);
	}


	return 0;
}
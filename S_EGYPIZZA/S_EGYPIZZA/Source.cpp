#include<cstdio>
#include<vector>

using namespace std;
typedef vector<int> vi;

vi arr(3,0);

int totalNoOfPizzas = 1;

void nullify(){
	
	if (arr[1] >= arr[2]){
		totalNoOfPizzas += arr[2];
		arr[1] -= arr[2];
		arr[2] = 0;
	}
	else{
		totalNoOfPizzas += arr[1];
		arr[2] -= arr[1];
		arr[1] = 0;
	}


	totalNoOfPizzas += arr[2];
	arr[2] = 0;

	totalNoOfPizzas += (arr[0] / 2);
	arr[0] = arr[0] % 2;

	totalNoOfPizzas += (arr[1] / 4);
	arr[1] = arr[1] % 4;

	
	switch (arr[1]){
	case 0:
		if (arr[0]){
			totalNoOfPizzas++;
			arr[0] = 0;
		}
		break;
	case 1:
	case 2:				
		totalNoOfPizzas++;
		arr[1] = 0;
		break;
	case 3:
		if (arr[0] == 1){
			totalNoOfPizzas++;
			arr[0] = 0;
		}
		totalNoOfPizzas++;
		arr[1] = 0;
	default:		
		break;
	}
}

int  main(){
	int N;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int tempa, tempb;
	char useless;
	totalNoOfPizzas = 1;
	while (N--){		
		scanf("%d%c%d", &tempa,&useless,&tempb);
		if (tempa == 1 && tempb == 2){
			arr[0]++;
		}
		else if (tempa == 1 && tempb == 4){
			arr[1]++; 
		}
		else{
			arr[2]++;
		}		

	}
	nullify();
	printf("%d\n", totalNoOfPizzas);
	return 0;
}
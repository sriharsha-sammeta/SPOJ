#include<cstdio>
#include<climits>
typedef long long int lli;


void calcLps(char *pat, lli *lps, lli& m){
	lli j = 0;
	lli i = 1;
	lps[0] = 0; 

	while (i < m){
		while (pat[j] != pat[i]){
			if (j == 0)
				break;
			j = lps[j - 1];
		}
		lps[i] = j + 1;
		j++; i++;
	}
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
	
	lli m;
	char * pat;
	lli *lps;
	char Text;

	while (scanf("%lld", &m) != EOF){		
		pat = new char[m];		
		scanf("%s\n", pat);

		lps = new lli[m];
		
		calcLps(pat, lps, m);		
		
		lli i = 0;
		lli textCount = 0;
		lli res = -1;
		
		while (scanf("%c", &Text)!=EOF){
			if (Text == '\n'){
				printf("\n");
				break;
			}			
			if (i < m){
				while (i != 0 && Text != pat[i]){
					i = lps[i - 1];
				}				
				if (Text==pat[i])
					i++;				
			}
			textCount++;
			if (i == m){
				i = lps[i - 1];
				res = textCount - m;
				printf("%d\n", res);
			}			
		
		}				
		if (res == -1)
			printf("\n");
	}

	return 0;
}
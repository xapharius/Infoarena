#include <cstdio>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define PMAX 25000

int P, sume[PMAX];

int main(){
	freopen("sume.in", "r", stdin);
	freopen("sume.out", "w", stdout);
	
	//read
	scanf("%d", &P);
	for(int i = 0; i < P; ++i){
		scanf("%d", &sume[i]);		
	}

	//are solutii
	double n = (1 + sqrt(1+8*P))/2;	
	//printf("%f\n", n);
	if (n - (int)n != 0){
		printf("-1");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}	
	int sumant[(int)n];
	sumant[0] = (sume[0] + sume[1] - sume[(int)n-1])/2;
	for(int i = 0; i < n-1; ++i){
		sumant[i+1] = sume[i] - sumant[0];	
	}

	//test
	bool merge = true;
	int k = 0;
	for (int i = 0; i < n-1; ++i)
		for(int j = i +1; j < n; ++j)
			if (sumant[i] + sumant[j] != sume[k++]){
				printf("-1");
				fclose(stdin);
				fclose(stdout);
				return 0;
			}


	printf("%d\n", (int)n);
	for(int i = 0; i < n; ++i)
		printf("%d ", sumant[i]);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

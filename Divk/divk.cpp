#include <cstdio>
using namespace std;

#define NMAX 500001
#define KMAX 100000

int N, K, A, B;
int sumRest[NMAX], num[NMAX], freq[KMAX];

int main(){
	freopen("divk.in", "r", stdin);
	freopen("divk.out", "w", stdout);

	scanf("%d%d%d%d", &N, &K, &A, &B);
	
	for(int i = 1; i <= N; ++i)
		scanf("%d", &num[i]);

	//array of partial sums modulo K
	for(int i = 1; i <= N; ++i)
		sumRest[i] = (sumRest[i-1] + num[i]) % K; 	

	long long nrSubSeq = 0;
	//freq array contains the frequences of rests from subsequences(sums) of length [A,B]
	//if sum[i-A] % K == sum[i] % K then sum of subseq i-A+1 to i divisible by K
	for(int i = A; i <= N; ++i){
		//add subseq of len A
		++freq[sumRest[i-A]];
		if(i > B) 
			//remove subseq longer than B
			--freq[sumRest[i-B-1]];
		//add subseqs divisible by K (freq of sumRest[i])
		nrSubSeq += freq[sumRest[i]];
	}	

	printf("%lld", nrSubSeq);

	fclose(stdin);
	fclose(stdout);
}	

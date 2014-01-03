#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXLEN 1024

int M, N;
int a[MAXLEN+1], b[MAXLEN+1];
int m[MAXLEN+1][MAXLEN+1];
int t[MAXLEN+1];

void dp(){
	for(int i = 1; i <= M; ++i)
		for(int j = 1; j <= N; ++j)
			if(a[i] == b[j])
				m[i][j] = m[i-1][j-1] + 1;
			else
				m[i][j] = max(m[i-1][j], m[i][j-1]);
}

void traceback(int i, int j, int len){
	if(i == 0 || j == 0) return;
	else if(a[i] == b[j]){
		t[len] = a[i];
		traceback(i-1, j-1, len-1);
	}
	else if(m[i][j-1] > m[i-1][j])
		traceback(i, j-1, len);
	else
		traceback(i-1, j, len);
}

int main(){
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	scanf("%d%d", &M, &N);
	for(int i = 1; i <= M; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &b[i]);
	
	dp();
	int cmlsc = m[M][N];
	printf("%d\n", cmlsc);
	traceback(M, N, cmlsc);
	for(int i = 1; i <= cmlsc; ++i)
		printf("%d ", t[i]);
	
	fclose(stdin);
	fclose(stdout);
}

#include <cstdio>
using namespace std;

int T;

int euclid(int numerator, int denominator){
	if (denominator == 0)
		return numerator;
	else
		return euclid(denominator, numerator % denominator);
}


int main(){
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	for(int i = 0, a, b, cmmdc; i < T; ++i){
		scanf("%d%d", &a, &b);
		cmmdc = euclid(a,b);
		printf("%d\n", cmmdc);
	}

	fclose(stdin);
	fclose(stdout);
}

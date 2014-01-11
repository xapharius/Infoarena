#include <cstdio>
#include <assert.h>
using namespace std;

#define NMAX 100000

int N, M;
int v[NMAX];


int cautbin(int lo, int hi, int x){
	if (lo > hi) 
		return -1;
	
	int mid = lo + (hi - lo)/2;
	printf("%d\n", mid);
	if (v[mid] == x) 
		return mid;
	if (v[mid] < x)
		return cautbin(mid + 1, hi, x);
	else if (v[mid] > x)
		return cautbin(lo, mid - 1 , x);
	else
		assert(!"missed a case in cautbin");
}

//cea mai mare pozitie pe care se afla un element cu valoarea x
int cautbin0(int lo, int hi, int x){
	if (lo > hi) 
		return -2;
	
	int mid = lo + (hi - lo)/2;
	//printf("%d\n", mid);
	if (v[mid] == x && (mid == N-1 || v[mid+1] != x)) 
		return mid;
	if (v[mid] <= x)
		return cautbin0(mid + 1, hi, x);
	else if (v[mid] > x)
		return cautbin0(lo, mid - 1 , x);
	else
		assert(!"missed a case in cautbin0");
}

//cea mai mare pozitie pe care se afla un element cu valoarea mai mica sau egala cu x
int cautbin1(int lo, int hi, int x){
	int mid = lo + (hi - lo)/2;
	//printf("%d\n", mid);
	if (v[mid] <= x && (mid  == N-1 || v[mid+1] > x)) 
		return mid;
	if (v[mid] <= x)
		return cautbin1(mid + 1, hi, x);
	else if (v[mid] > x)
		return cautbin1(lo, mid - 1 , x);
	else
		assert(!"missed a case in cautbin1");
}

//cea mai mica pozitie pe care se afla un element cu valoarea mai mare sau egala cu x
int cautbin2(int lo, int hi, int x){
	int mid = lo + (hi - lo)/2;
	//printf("%d\n", mid);
	if (v[mid] >= x && (mid == 0 || v[mid-1] < x)) 
		return mid;
	if (v[mid] < x)
		return cautbin2(mid + 1, hi, x);
	else if (v[mid] >= x)
		return cautbin2(lo, mid - 1 , x);
	else
		assert(!"missed a case in cautbin2");
}


int main(){
	freopen("cautbin.in", "r", stdin);
	freopen("cautbin.out", "w", stdout);

	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &v[i]);

	scanf("%d", &M);
	for(int i = 0, opt, x, pos; i < M; ++i){
		scanf("%d %d", &opt, &x);
		switch(opt){
			case 0: 
				pos = cautbin0(0, N-1, x);
				break;
			case 1: 
				pos = cautbin1(0, N-1, x);
				break;
			case 2: 
				pos = cautbin2(0, N-1, x);
				break;
		}
		printf("%d\n", pos+1);
	}
	fclose(stdin);
	fclose(stdout);
}

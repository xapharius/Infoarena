#include <cstdio>
#include <algorithm>
using namespace std;

#define NMAX 800

int N;
int arr[NMAX];

//return index of rightmost nr smaller than x
int binSearch(int st, int dr, int x){
	if (st > dr) return -1;

	int mid = st + (dr - st)/2;
	
	if (arr[mid] <= x && (mid == dr || arr[mid+1] > x))
		return mid;
	if (arr[mid] <= x)
		return binSearch(mid+1, dr, x);
	else
		return binSearch(st, mid-1, x); 
}


int main(){
	freopen("nrtri.in", "r", stdin);
	freopen("nrtri.out", "w", stdout);
	
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &arr[i]);
	
	sort(arr, arr + N);
	
	int nrTri = 0;
	int indexTriCondOk;
	//triangle condition = every sum of 2 sides must be larger than 3rd one.
	//foreach pair look at which index the element is larger than their sum (at which point it doesnt satisfy the condition anymore)
	for(int i = 0; i < N - 2; ++i)
		for(int j = i + 1; j < N - 1; ++j){ 
			indexTriCondOk = binSearch(j+1, N-1, arr[i] + arr[j]);
			if (indexTriCondOk == -1) continue;
				//all elements ultil IndexTriCondOk satisfy Condition
				nrTri += indexTriCondOk - j;
		}
				 
	printf("%d", nrTri); 

	fclose(stdin);
	fclose(stdout);
}

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define NMAX 16000

int N, K;
int saltea[NMAX];
int salteaMax = 0;

//How many trips are needed for given cargo volume
int greedyNrDrumuri(int volum){
	if(volum < salteaMax)
		return INT_MAX;

	int nrDrumuri = 1;
	int cargo = 0;
	for(int i = 0; i < N; ++i){
		if(cargo + saltea[i] > volum){
			++nrDrumuri;
			cargo = 0;
		}
		cargo += saltea[i];
	}
	return nrDrumuri;
}

//binary search for min cargo volume. k is the nr of trips
int binSearch(int st, int dr, int k){
	if(st>dr) return salteaMax;

	int volum = st + (dr - st)/2;
	int nrDrumuri = greedyNrDrumuri(volum);

	//found min volume
	if(nrDrumuri <= k && greedyNrDrumuri(volum - 1) > k)
		return volum;

	if(nrDrumuri <= k)
		return binSearch(st, volum - 1, k);
	else
		return binSearch(volum + 1, dr, k);
}

int main(){

	freopen("transport.in", "r", stdin);
	freopen("transport.out", "w", stdout);
	
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%d", &saltea[i]);
		salteaMax = max(saltea[i], salteaMax);
	}

	int minVol = binSearch(salteaMax, NMAX * NMAX, K);
	printf("%d\n", minVol);
	

	fclose(stdin);
	fclose(stdout);
}

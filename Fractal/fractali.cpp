#include <cstdio>
#include <stdlib.h>
#include <math.h>
using namespace std;

int k, x, y;


int computeNrSteps(int _k, int _x, int _y){
	//printf("%d %d %d\n", _k, _x, _y);
//	anchor _k == 0
	if(_k == 0)
		return 0;

//	recursion
	int half = 1 << (_k - 1);
	if(_x <= half && _y <= half)
		//quadrant I - no additional steps
		//point needs to be rotated right and y-inverted for k-1 fractal
		return computeNrSteps(_k - 1, _y, _x) + 0;

	else if(_x <= half && _y >= half + 1)
		//quadrant II - one additional k-1 fractal steps + 1 
		//point doesn't have to be rotated, just scaled for k-1 fractal
		return computeNrSteps(_k - 1, _x, _y - half) + half*half;

	else if(_x >= half + 1 && _y >= half + 1)
		//quadrant III - two additional k-1 fractal steps + 2
		//both x and y scaled for k-1 fractal
		return computeNrSteps(_k - 1, _x - half, _y - half) + half*half*2;

	else if(_x >= half + 1 && _y <= half)
		//quadrant IV - three addtitiona k-1 fractal steps + 3
		//point rotated left and y-inverted for k-1 fractal
		return computeNrSteps(_k -1 , half - _y + 1, (1<<_k) - _x + 1) + half*half*3;
	else 
		throw("recursion error");

}

int main(){
	freopen("fractal.in", "r", stdin);
	freopen("fractal.out", "w", stdout);

	//read
	scanf("%d %d %d", &k, &x, &y);

	int nrSteps = computeNrSteps(k, x, y);

	printf("%d", nrSteps);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

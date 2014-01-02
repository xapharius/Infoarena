#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

#define GMax 1001
#define WMax 5001
#define inf INT_MAX/2

int G, W;
int cost[GMax][WMax];
int eg[GMax], ec[GMax];

void dp(){
    for(int w = 0; w <= W; ++w)
        cost[0][w] = inf;
       
    for(int i = 1; i <= G; ++i)
        for(int w = 0; w <= W; ++w){          
            if(w >= eg[i])
                cost[i][w] = min(cost[i-1][w], cost[i-1][w-eg[i]] + ec[i]);
            else
                //energie > necesara. alege costul minimal
                cost[i][w] = min(cost[i-1][w], ec[i]);
        }
}

int main(){
    freopen("energii.in", "r", stdin);
	freopen("energii.out", "w", stdout);
    scanf("%d %d", &G, &W);

    for(int i = 1; i <= G; ++i){
        scanf("%d %d", &eg[i], &ec[i]);
    }

    dp();

    if(cost[G][W] == inf)
        printf("-1");
    else
        printf("%d", cost[G][W]);


    fclose(stdin);
	fclose(stdout);
    return 0;
}

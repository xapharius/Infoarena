#include <cstdio>
#include <vector>  
#include <algorithm>
using namespace std;

struct generator{
    int EG, CG;
    
    generator(int eg, int cg){
        EG = eg;
        CG = cg;
    }
};

bool genComp(generator a, generator b){
    float propA = (float) a.EG/a.CG;
    float propB = (float) b.EG/b.CG;
    return(propA > propB);
}

int G, W;
vector<generator> gens;

int main(){
	freopen("energii.in", "r", stdin);
	freopen("energii.out", "w", stdout);
    scanf("%d %d", &G, &W);

    for(int i = 0, eg, cg; i < G; ++i){
        scanf("%d %d", &eg, &cg);
        gens.push_back(generator(eg, cg));
    }        

    sort(gens.begin(), gens.end(), genComp);

    int i = 0;
    int sumW = 0;
    int sumC = 0;
    while (i < G && sumW < W){
        sumW += gens[i].EG;
        sumC += gens[i].CG;
        ++i;
    }

    if(i >= G)
        printf("-1");
    else 
        printf("%d", sumC);

    fclose(stdin);
	fclose(stdout);
    return 0;
}

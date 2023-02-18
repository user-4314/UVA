#include <iostream>
#include <cstdio>
using namespace std;

long long SG(long long x){
    return x%2 == 0 ? x/2 :SG(x/2);
}

int main()
{   int cas;
    scanf("%d",&cas);
    while(cas--){
        int n;
        long long stone,ans=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&stone);
            ans = ans^SG(stone);
        }
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");

    }
    return 0;
}

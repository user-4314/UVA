#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 65;
int len,stick[N],n;
bool used[N];

int cmp(int &a,int &b){
    return a>b;
}

bool solve(int i,int l,int remain){
    if(l == 0){
        remain -= len;
        if(remain == 0)
            return true;

        for(i=0;used[i];i++);
        used[i] = true;

        if(solve(i+1,len-stick[i],remain))
            return true;
        used[i] = false;
        remain += len;
    }
    else{
        for(int j=i;j<n;j++){
            if(j>0 && (stick[j]==stick[j-1] && !used[j-1]) )
                continue;
            if(!used[j] && l>=stick[j]){
                used[j] = true;

                if(solve(j,l-stick[j],remain))
                    return true;

                used[j] = false;
                if(stick[j] == l)
                    break;
            }
        }
    }
    return false;
}

int main()
{
    while(scanf("%d",&n)  && n){
        int sum = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&stick[i]);
            sum+=stick[i];
            used[i] = false;
        }
        sort(stick,stick+n,cmp);
        bool flag = false;
        for(len = stick[0];len<=sum/2;len++){
            if(sum%len == 0){
                if(solve(0,len,sum)){
                    flag = true;
                    printf("%d\n",len);
                    break;
                }
            }
        }
        if(!flag)
            printf("%d\n",sum);
    }
    return 0;
}

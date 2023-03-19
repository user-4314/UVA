#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 35;
double dp[N];

int main()
{   int n;
    double t;
    while(scanf("%d%lf",&n,&t) && n){
        dp[n] = 1<<n;
        for(int i=n-1;i>=0;i--){
            double p = (double)(1<<i)/dp[i+1];

            if(t>=p)
                dp[i] = dp[i+1] * (1+t)/2;
            else
                dp[i] = (1<<i)*(p-t)/(1-t) + dp[i+1] * ( (1-p)/(1-t) ) * (1+p)/ 2 ;
        }
        printf("%.3f\n",dp[0]);
    }
    return 0;
}

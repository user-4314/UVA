#include <iostream>

using namespace std;

int main()
{   int a[100000],n,cas,ma,ans;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        ma=a[0];
        ans=a[0]-a[1];

        for(int i=1;i<n;i++){
            ans=max(ans,ma-a[i]);
            ma=max(ma,a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}

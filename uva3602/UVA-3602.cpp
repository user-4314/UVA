#include <iostream>
#include <cstdio>
using namespace std;
const int N = 1005;
int main()
{   int cas;
    scanf("%d",&cas);
    while(cas--){
        int m,n,error=0,ma;
        string dna[N],ans="",buf;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            cin>>dna[i];

        for(int i=0;i<n;i++){
            int ca=0,cc=0,cg=0,ct=0;
            for(int j=0;j<m;j++){
                if(dna[j][i]=='A')   ca++;
                else if(dna[j][i]=='C')   cc++;
                else if(dna[j][i]=='G')   cg++;
                else if(dna[j][i]=='T')   ct++;
            }
            ma=ca; buf="A";
            if(cc>ma){ma=cc;buf="C";}
            if(cg>ma){ma=cg;buf="G";}
            if(ct>ma){ma=ct;buf="T";}
            ans+=buf;
            error+=m-ma;
        }
        cout<<ans<<endl;
        cout<<error<<endl;
    }

    return 0;
}

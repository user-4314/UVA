#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{   string s1,s2;
    while(cin>>s1>>s2){
        int a1[26]={0},a2[26]={0};
        bool flag = true;
        for(int i=0;i<s1.size();i++){
            a1[s1[i]-'A']++;
            a2[s2[i]-'A']++;
        }
        sort(a1,a1+26);
        sort(a2,a2+26);
        for(int i=0;i<26;i++){
            if(a1[i]!=a2[i]){
                flag = false;
                break;
            }
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

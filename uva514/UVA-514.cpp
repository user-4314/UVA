#include <iostream>
#include <stack>
using namespace std;

int main()
{   int n ,b[1010],first=0;
    while(cin>>n && n!=0){
        if(first==0)
            first=1;
        else
            puts("");
        while(cin>>b[1] && b[1]!=0){
            for(int i=2;i<=n;i++)
                cin>>b[i];
            stack <int> s;
            int j=1;
            for(int i=1;i<=n;i++){
                s.push(i);
                while(!s.empty() && s.top()==b[j]){
                    s.pop();
                    j++;
                }
            }
            printf("%s\n",s.empty() &&j==n+1 ?"Yes" :"No");

        }
    }
    return 0;
}

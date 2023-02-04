#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a ,b,ca,cb,n;
    while(scanf("%d %d %d", &ca, &cb, &n) != EOF) {
        a = 0; b = 0;
        while(1) {
            if(b == n) {
                printf("success\n");
                break;
            }
            else if(b == cb) {
                    printf("empty B\n");
                    b = 0;
            }
            else if(a ==  0) {
                    printf("fill A\n");
                    a = ca;
            }
            else if(a != 0)  {
                    printf("pour A B\n");
                    if(a + b <= cb) {
                            b += a; a = 0;
                    }
                    else {
                            a = a + b - cb;
                            b = cb;
                    }
            }
        }
    }
    return 0;
}


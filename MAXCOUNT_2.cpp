#include<iostream>
#include<cstring>
#include<cassert>
#include<cstdio>

using namespace std;

#define s(n)                        scanf("%d",&n)
#define forall(i,a,b)               for(int i=a;i<b;i++)
using namespace std;

int freq[10005];
int A[101];

void solve()
{
    int N; s(N);
    assert(1 <= N <= 100);    
    int best = 0, besti = 0;
    forall(i, 0, N)
    {
        s(A[i]);
        assert(1 <= A[i] && A[i] <= 10000);
        int its = 0;
        forall(j, 0, i+1)
            if(A[i] == A[j])
                its ++;
        if(its > best || (its == best && A[i] < besti))
        {
            best = its; besti = A[i];
        }
    }
    printf("%d %d\n", besti, best);
}

int main()
{
    int T; s(T);
    assert(1 <= T && T <= 100);
    for(int testnum=1;testnum<=T;testnum++)
      solve();
}

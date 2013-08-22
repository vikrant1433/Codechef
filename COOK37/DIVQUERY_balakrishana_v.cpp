#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAXN 101000
#define MAXA 101000
using namespace std;

int N,Q;
int A[MAXN+2];
vector<int> positions[MAXA+1];

int countit(int L, int R, int K)
{
    if(positions[K].size()==0)
        return 0;
    int max_id = positions[K].size()-1;
    if(positions[K][0]>R || positions[K][max_id]<L)
        return 0;

    int low_low = 0;
    int high_low = max_id;
    while(low_low < high_low)
    {
        int mid = (low_low + high_low)/2;
        if(positions[K][mid]>=L)
        {
            high_low = mid;
        }
        else
        {
            low_low = mid + 1;
        }
    }


    int low_high = 0;
    int high_high = max_id;
    while(low_high < high_high)
    {
        int mid = (low_high + high_high + 1) / 2;
        if (positions[K][mid]<=R)
        {
            low_high = mid;
        }
        else
        {
            high_high = mid - 1;
        }
    }

    return (low_high - low_low + 1);
}

int main()
{
    cin>>N>>Q;
    for(int i=1; i<=N; i++)
    {
        cin>>A[i];
        for(int j=1; j<=A[i]/j; j++)
        {
            if(A[i]%j==0)
            {
                positions[j].push_back(i);
                if (j != A[i]/j)
                {
                    positions[A[i]/j].push_back(i);
                }
            }
        }
    }

    for(int q=1; q<=Q; q++)
    {
        int L,R,K;
        cin>>L>>R>>K;
        cout << countit(L, R, K) << endl;
    }





}

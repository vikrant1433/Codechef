#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<cstring>
#include<string.h>
#include<inttypes.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<functional>
#include<cmath>
#include<cstdlib>
#include<cassert>
 
#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define lli long long int
#define ld long double
#define llu unsigned long long int
 
using namespace std;
 
struct Demon
{
    vector<lli> Con;
    lli amount,val;
};
 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        // freopen ("out.txt", "w", stdout);
    #endif
    lli T;
    scanf("%lld",&T);
    while(T--)
    {
        lli moves=0;
        lli N;
        scanf("%lld",&N);
        lli x[N],y[N];
        for(lli i=0;i<N;i++)
        {
            scanf("%lld %lld",&x[i],&y[i]);
        }
 
        vector<Demon> Dx,Dy;
        lli flag=0;
        for(lli i=0;i<N;i++)
        {
            for(lli j=0;j<Dx.size();j++)
            {
                if(x[i]==Dx.at(j).val)
                {
                    Dx.at(j).Con.push_back(y[i]);
                    Dx.at(j).amount++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                Dx.resize(Dx.size()+1);
                Dx.at(Dx.size()-1).Con.push_back(y[i]);
                Dx.at(Dx.size()-1).val=x[i];
                Dx.at(Dx.size()-1).amount=Dx.at(Dx.size()-1).Con.size();
            }
            flag=0;
            for(lli j=0;j<Dy.size();j++)
            {
                if(y[i]==Dy.at(j).val)
                {
                    Dy.at(j).Con.push_back(x[i]);
                    Dy.at(j).amount++;
                    flag=1;
                }
            }
            if(flag==0)
            {
                Dy.resize(Dy.size()+1);
                Dy.at(Dy.size()-1).Con.push_back(x[i]);
                Dy.at(Dy.size()-1).amount=Dy.at(Dy.size()-1).Con.size();
                Dy.at(Dy.size()-1).val=y[i];
            }
            flag=0;
        }
 
        while(N!=0)
        {
            lli counter1=0,counter2=0,mark1,mark2;
            for(lli i=0;i<Dx.size();i++)
            {
                if(Dx.at(i).amount>counter1)
                {
                    counter1=Dx.at(i).amount;
                    mark1=i;
                }
            }
            for(lli i=0;i<Dy.size();i++)
            {
                if(Dy.at(i).amount>counter2)
                {
                    counter2=Dy.at(i).amount;
                    mark2=i;
                }
            }
            if(counter1>counter2)
            {
                N-=counter1;
                Dx.at(mark1).amount=-1;
                for(lli j=0;j<Dy.size();j++)
                {
                    for(lli k=0;k<Dy.at(j).Con.size();k++)
                    {
                        if(Dy.at(j).Con.at(k)==Dx.at(mark1).val)
                        {
                            Dy.at(j).Con.erase(Dy.at(j).Con.begin()+k);
                            Dy.at(j).amount--;
                        }
                    }
                }
            }
            else if(counter2>=counter1)
            {
                N-=counter2;
                Dy.at(mark2).amount=-1;
                for(lli j=0;j<Dx.size();j++)
                {
                    for(lli k=0;k<Dx.at(j).Con.size();k++)
                    {
                        if(Dx.at(j).Con.at(k)==Dy.at(mark2).val)
                        {
                            Dx.at(j).Con.erase(Dx.at(j).Con.begin()+k);
                            Dx.at(j).amount--;
                        }
                    }
                }
            }
            moves++;
        }
        printf("%lld\n",moves);
    }
	return 0;
}
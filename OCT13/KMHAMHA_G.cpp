#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}
int Test, r, c, demons;
vector<pair<int, int> > COR;
map<int, int> Rs, Cs;

int rSol();

int main()
{
    #ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        // freopen ("out.txt", "w", stdout);
    #endif
    scanf("%d",&Test);
    while(Test--)
    {
        COR.clear();
        Rs.clear();
        Cs.clear();
        scanf("%d",&demons);
        for(int i=0; i<demons; i++)
        {
            scanf("%d %d",&r, &c);
            COR.push_back(make_pair(r,c));
            if(Rs.find(r)==Rs.end()) Rs[r] = 1;
            else Rs[r] +=1;
            if(Cs.find(c)==Cs.end()) Cs[c] = 1;
            else Cs[c] +=1;
        }
        r = Rs.size();
        c = Cs.size();
        int res = rSol();
        printf("%d\n",min(res,min(r,c)));
    }
    return 0;
}

int rSol()
{
    int mr, mrx;
    int cnt=0;
    map<int, int>:: iterator it;
    vector<pair<int, int> >::iterator vt;
    vector<pair<int, int> > row, col;

    for(it=Rs.begin(); it!=Rs.end(); it++)
    {
        row.push_back(make_pair(it->first,it->second));
    }

    for(it=Cs.begin(); it!=Cs.end(); it++)
    {
        col.push_back(make_pair(it->first,it->second));
    }
    sort(row.begin(),row.end(),comp);
    sort(col.begin(),col.end(),comp);
    while(!COR.empty())
    {
        int d = row.size();
        int n = col.size();
        if(row[d-1].second>=col[n-1].second)
        {
            mr = row[d-1].first;
            row.pop_back();
            //cout<<"ROW: "<<mr<<" value: "<<row[d-1].second<<endl;
            int flag=0;
            for(vt=COR.begin(); vt!=COR.end();)
            {
                if(vt->first==mr) {COR.erase(vt); flag=1;}
                else vt++;
            }
            if(flag) cnt++;
        }
        else
        {
            mr = col[n-1].first;
            //cout<<"COL: "<<mr<<" value: "<<col[n-1].second<<endl;
            col.pop_back();
            int flag =0;
            for(vt=COR.begin(); vt!=COR.end();)
            {
                if(vt->second==mr) {COR.erase(vt); flag=1;}
                else vt++;
            }
            if(flag)cnt++;
        }
    }

    return cnt;

}
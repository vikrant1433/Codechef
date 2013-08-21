#include <iostream>
#include <iomanip>
using namespace std;
#define charges 0.50
int main()
{
    int wdraw;
    float bal;
    cout<<fixed;
    cin>>wdraw>>bal;
    if ((wdraw+charges) > bal)
        cout<<setprecision(2)<<bal;
    else
    {
        if ((wdraw%5) == 0)
        {
            bal = bal - wdraw - charges;
            cout<<setprecision(2)<<bal;
        }
        else
            cout<<setprecision(2)<<bal;
    }



    return 0;
}


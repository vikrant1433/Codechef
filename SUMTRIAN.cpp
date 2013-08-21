#include <iostream>
#include <stdio.h>

bool rawr=false;

using namespace std;

int main()
{
    int numCase, numLines, currVal=0, total=0;
    int tre[101][101];
    for(int i=0; i<101; i++)
        tre[0][i]=0;
    scanf("%d", &numCase);
    for(int i=0; i<numCase; i++)
    {
        scanf("%d", &numLines);
        for(int j=1; j<=numLines; j++)
        {
            for(int k=1; k<=j; k++)
            {
                scanf("%d", &tre[j][k]);
                if(tre[j-1][k-1]>tre[j-1][k])
                    currVal=tre[j-1][k-1];
                else
                    currVal=tre[j-1][k];
                if(rawr)
                    cout<<currVal<<endl;
                tre[j][k]+=currVal;
            }
        }
        for(int p=1; p<=numLines; p++)
        {
            if(tre[numLines][p]>total)
                total=tre[numLines][p];
        }
        printf("%d\n", total);
        total=0;
    }
    return 0;
}

using namespace std;
#include <cstdio>


// // Input macros
#define s(n)                        scanf("%d",&n)

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define forall(i,a,b)               for(int i=a;i<b;i++)

#define p(n)                          printf("%d\n",n)
#define freopen_in                    freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
#define numTest(t)						  int t; s(t); while(t--)



int makeNumber(int n, int times)
{
	int temp=0;
	for(int i = 0; i < times+1; i++)
	{
		temp = 10*temp + n;
	}
	return temp;
}
int makeNumber_with_zero(int times)
{
	int n = 1;
	forall(i,0,times+1)
		n *= 10;
	return n;
}


int main(int argc, char const *argv[])
{
	//freopen_in;
	numTest(t)
	{
		int numCount , num = 1;
		int zeroCount;
		s(zeroCount);   // reading 0's count
		s(numCount);    // reading 1's count
		int temp;
		forall(i,2,10)
		{
			s(temp);
			if (temp < numCount)    // comparing
			{
				numCount = temp;
				num = i;
			}
		}

		if (zeroCount == numCount || zeroCount > numCount)
		{
			p(makeNumber(num, numCount));
		}
		else
		{
			p(makeNumber_with_zero(zeroCount));
		}


	}


	return 0;
}

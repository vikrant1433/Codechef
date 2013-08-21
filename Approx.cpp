using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>

#define s(i) scanf("%d",&i)
int main()
{
//	FILE* in = freopen("in.txt","r");
//	FILE* out = freopen("out.txt","w");

	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int k;
		int num = 103993, denom = 33102;
		s(k);
		printf("3");
		if (k != 0)
			printf(".");
		for (int i = 0; i < k; ++i)
		{
			int rem = num%denom ;
			printf("%d",rem*10/denom);
			num = rem*10;
		}
		printf("\n");


	}
	return 0;
}

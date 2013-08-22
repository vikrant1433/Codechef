using namespace std;
#include <cstdio>
#define maX(a,b)  ((a)>(b)?(a):(b))

int arr[1000001]={0};
int main()
{
	int t;
	scanf("%d",&t);
	int cnt,max=0;
	for(int i=0;i<t;i++)
	{
		scanf("%d",&cnt);
		arr[cnt]++;
		max = maX(max,cnt);
	}
	for(int i=0;i<=max;i++)
	{
		while(arr[i]--){
			printf("%d\n",i);
		}
	}

}

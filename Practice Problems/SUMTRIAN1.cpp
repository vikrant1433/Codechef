using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int N;
		scanf("%d",&N);
		int arr[N][N];
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		for (int i = N-2; i >= 0; --i)
		{
			for (int j = 0; j <= i ; ++j)
			{
				arr[i][j] += max (arr[i+1][j], arr[i+1][j+1]);
			}
		}

		printf("%d\n",arr[0][0]);
	}


	return 0;
}

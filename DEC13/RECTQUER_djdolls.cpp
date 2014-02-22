#include <iostream>
#include <stdio.h>
#include <vector>
 
using namespace::std;
 
int P[300][300];
int S[10][300][300];
 
int get_sum(int i1, int j1, int i2, int j2, int k)
{
	int ans = S[k][i2][j2];
	if (i1)
		ans -= S[k][i1 - 1][j2];
	if (j1)
		ans -= S[k][i2][j1 - 1];
	if (i1 && j1)
		ans += S[k][i1 - 1][j1 - 1];
 
	return ans;
}
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen ("in.txt", "r", stdin);
		// freopen ("out.txt", "w", stdout);
	#endif
	int N;
	scanf("%d", &N);
 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int x;
			scanf("%d", &x);
 
			x--;
			P[i][j] = x;
		}
	}
 
	for (int k = 0; k < 10; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int c = (P[i][j] == k) ? 1 : 0;
				if (i == 0 && j == 0)
					S[k][i][j] = c;
				else if (i == 0)
					S[k][i][j] = c + S[k][i][j - 1];
				else if (j == 0)
					S[k][i][j] = c + S[k][i - 1][j];
				else
					S[k][i][j] = c + S[k][i - 1][j] + S[k][i][j - 1] - S[k][i - 1][j - 1];
			}
		}
	}
 	for (int k = 0; k < 10; ++k)
 	{
 		cout<<"\n"<<k+1<<":"<<"\n\n";
 		for (int i = 0; i < N; ++i)
 		{
 			for (int j = 0; j < N; ++j)
 			{
 				cout<<S[k][i][j]<<" ";
 			}
 			cout<<"\n";
 		}
 	}
	int Q;
	scanf("%d", &Q);
	for (int q = 0; q < Q; q++)
	{
		int a, b, c, d;
		
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);
		scanf("%d", &d);
 
		a--;
		b--;
		c--;
		d--;
 
		int ans = 0;
		for (int i = 0; i < 10; i++)
			if (get_sum(a, b, c, d, i))
				ans++;
 
		printf("%d\n", ans);
	}
 
	return 0;
}
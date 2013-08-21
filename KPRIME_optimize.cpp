#include <iostream>
#include <stdio.h>
#include <vector>

using namespace::std;

main()
{
	int N = 100000;
	vector<bool> mark(1 + N, false);
	vector<int> num(1 + N, 0);

	for (int i = 2; i <= N; i++)
	{
		if (mark[i])
			continue;

		num[i]++;
		for (int j = 2 * i; j <= N; j += i)
		{
			mark[j] = true;
			num[j]++;
		}
	}

	vector<vector<int> > P(1 + N, vector<int>(6, 0));
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 6; j++)
			P[i][j] = P[i - 1][j];

		if (num[i] > 5)
			continue;

		P[i][num[i]]++;
	}

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++)
	{
		int A, B, K;
		scanf("%d", &A);
		scanf("%d", &B);
		scanf("%d", &K);

		int ans = P[B][K] - P[A - 1][K];
		printf("%d\n", ans);
	}
}

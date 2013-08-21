#include <stdio.h>
 
#define MOD 1000000007
 
long long base, mult, answer;
 
long long RaiseToPow(long long x, long long y) {
	if (y == 0)
		return 1;
	if (y == 1)
		return x % MOD;
	long long res = RaiseToPow(x, y >> 1);
	res = (res * res) % MOD;
	if (y & 1)
		res = (res * x) % MOD;
	return res;
}
 
int main() {
	int T, N, K;
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		if (K == 1)
			printf("0\n");
		else {
			base = ((long long) K * (long long) (K - 1)) % MOD;
			mult = (long long) (K - 2);
			mult = (mult * mult) % MOD;
			mult = (mult + K - 1) % MOD;
			answer = (base * RaiseToPow(mult, N - 1)) % MOD;
			printf("%lld\n", answer);
		}
	}
 
	return 0;
}
using namespace std;
#include <cstdio>
#include <cmath>
#include <cstdlib>

#define s(n)                         scanf("%d",&n)

#define p(n)                          printf("%d\n",n)

#define freopen_in                    freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
#define numTest(t)                    int t; s(t); while(t--)

#define N 100001

bool isPrime(int n)
{
	int sqrt_n = (int)sqrt(n)+1;
	if (n%2==0)
		return false;
	for(int i=3; i<sqrt_n; i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}
int numPrimeFactor(int n, int primes[], int contPrimes[], int pLimit)
{
	if (n<=pLimit && primes[n] != 0)
		return 1;
	int sqrt_n = (int)ceil(sqrt(n));
	int k=0;
	for(int i=0; contPrimes[i] < sqrt_n && n>=sqrt_n; i++)
	{
		if(n%contPrimes[i]==0)
		{
			k++;
			while(n%contPrimes[i]==0)
				n /= contPrimes[i];
		}


	}
	if(n>1)
		k++;
	return k;
}
void genPrime(int primes[], int pLimit)
{
	primes[2] =2;
	for (int i = 3; i <= pLimit; ++i)
	{
		if (isPrime(i))
		{
			primes[i] = i;
		}
	}
}
void copyBack(int primes[], int contPrimes[], int n)
{
	for(int i=0,j=0; i < n; i++)
		if(primes[i]!=0)
			contPrimes[j++] = primes[i];
}
int search(int a[][N], int key, int hi, int k)
{
	int lo = 0;
	int mid;
	while(lo<=hi)
	{
		mid = lo + (hi-lo)/2;
		if(a[k][mid] == key)
			return mid;
		else if(a[k][mid] > key)
			hi = mid-1;
		else
			lo = mid+1;
	}
	return mid;
}
int main()
{
//	freopen_in;
	int pLimit = (int)ceil(sqrt(N));
	int primes[320] = {0};
	genPrime(primes, pLimit);
	int contPrimes[70] = {0};
	copyBack(primes, contPrimes, sizeof(primes)/sizeof(primes[0]));
	int A,B,k;
	int a[5][N]={0};
	int index[5] = {0};
	for (int i=2; i < N; ++i)
	{
		int p = numPrimeFactor(i, primes, contPrimes, pLimit);
		if (p > 5)
			continue;
		else
			a[p-1][index[p-1]++] = i;
	}
	int pA, pB, ans;
	numTest(t)
	{
		s(A);s(B);s(k);
		pA = search(a,A,index[k-1]-1, k-1);
		pB = search(a,B,index[k-1]-1, k-1);
		ans = pB-pA;
		if (A <= a[k-1][pA] && a[k-1][pB]<=B)
			ans++;
		if(a[k-1][pA]<A  && B<a[k-1][pB])
			ans--;
		p(ans);

	}



	return 0;
}

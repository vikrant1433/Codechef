using namespace std;
#include <iostream>
#include <cstdio>


// // Input macros
#define s(n)                        scanf("%d",&n)


// // Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)

#define freopen_in                    freopen("in.txt","r",stdin);
#define freopen_out                   freopen("out.txt","w",stdout);
#define numTest(t)						  int t; s(t); while(t--)


int findMin(int* arr, int L, int R)
{
	int minNum = arr[L];
	for(int i = L; i<=R; i++)
	{
		if(arr[i] < minNum)
			minNum = arr[i];
	}
	return minNum;
}

float cal(int* arr, int minNum, int L, int R, int N)
{
	float maxNum = 0.0;
	float temp;
	for(int i=0; i<N; i++)
	{
		if (i<L || i>R)
			temp = minNum + arr[i];
		else
			temp = minNum + (arr[i] - minNum)/2.0;
		if (temp > maxNum)
			maxNum = temp;
	}
	return maxNum;
}
int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen_in;
	#endif
	int N;
	int L,R, minNum;
	int arr[100001];
	while (s(N)==1)
	{
		forall(i,0,N)
			s(arr[i]);
		numTest(Q)
		{
			s(L);
			s(R);
			minNum = findMin(arr,L,R);

			printf("%.1f\n",cal(arr,minNum,L,R,N));
		}
	}

	return 0;
}

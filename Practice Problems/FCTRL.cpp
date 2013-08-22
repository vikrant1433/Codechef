#include <iostream>
using namespace std;

int main(void)
{
	int T;
	cin>>T;
	while(T--)
	{
	    int n;
		int z = 0;
		cin>>n;
		while(n)
		{
			z = z +  n/5;
			n = n/5;
		}
		cout<<z<<endl;
	}

	return 0;
}


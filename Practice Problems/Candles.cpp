#include <stdio.h>

int a[10];

void inc(int val)
{
    for (int i = 0; i < 10; i++)
        a[i] += val;
}

int solve()
{
    /*	int b[10];
    	for (int answer=1; answer <= 1111111111; answer++) {
    		for (int i=0; i < 10; i++)
    			b[i] = a[i];
    		bool ok = true;
    		int i = answer;
    		while (ok && (i > 0)) {
    			b[i % 10]--;
    			if (b[i % 10] < 0)
    				ok = false;
    			i /= 10;
    		}
    		if (!ok) {
    			printf("answer = %d\n", answer);
    			break;
    		}
    	}*/
    // 1 3 6 2 3 4 2 3 2 5
    int pow = 1;
    for (int len = 1; len <= 10; len++)
    {
        for (int digit = 1; digit <= 9; digit++)
            if (a[digit] <= 0)
            {
//				printf("break len=%d digit=%d\n", len, digit);
                int res = digit;
                inc(1);
                a[digit]--;
                for (int d = 2; d <= len; d++)
                {
                    for (int i = 0; i <= 9; i++)
                        if (a[i] <= 0)
                        {
                            res = res * 10 + i;
                            inc(1);
                            a[i]--;
                            break;
                        }
                }
                return res;
            }
        inc(-1);
        pow *= 10;
        if (a[0] < 0)
            return pow;
    }
    return -1/0;
}

int main()
{
    freopen("in.txt","r",stdin);
    int cnt;
    scanf("%d", &cnt);
    for (int tst=1; tst <= cnt; tst++)
    {
        for (int i=0; i < 10; i++)
            scanf("%d", &a[i]);
        printf("%d\n", solve());
    }
    return 0;
}

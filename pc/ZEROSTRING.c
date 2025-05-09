#include <stdio.h>

int main()
{
    long long t;
    scanf("%lld", &t);

    while (t--)
    {
        long long int n;
        scanf("%lld", &n);
        long long int a = 0, b = 0;
        char s[n];
        scanf("%s", s);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                a++;
            }
            else if (s[i] == '0')
            {
                b++;
            }
        }
        if (a == n)
            printf("%lld\n", 1);
        else if (b == n)
            printf("%lld\n", 0);
        else if (a == b)
            printf("%ld\n", a);
        else
            printf("%lld\n", b + 1);
    }

    return 0;
}
#include <stdio.h>

long long bruteForce(long long n)
{
    long long a = 1, b = 1, c;
    long long sum = 0;

    while (b <= n)
    {
        if (b % 2 == 0)
            sum += b;

        c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

long long optimized(long long n)
{
    if (n < 2)
        return 0;

    long long e1 = 2;
    long long e2 = 8;
    long long sum = 0;

    while (e1 <= n)
    {
        sum += e1;

        long long next = 4 * e2 + e1;
        e1 = e2;
        e2 = next;
    }

    return sum;
}

int main()
{
    long long n;

    printf("Enter n: ");
    scanf("%lld", &n);

    printf("Brute Force Sum = %lld\n", bruteForce(n));
    printf("Optimized Sum = %lld\n", optimized(n));

    return 0;
}

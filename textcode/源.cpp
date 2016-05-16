#include <stdio.h> 
#include <time.h> 
#include <string.h> 
#include <stdlib.h> 
#define PRIME_LIM 10000000 
#define N 100000000 
int primes[PRIME_LIM] = {0}; 
int flags[N/96 + 1] = {0}; 
int get_prime() 
{ 
    int nu = 5, to = 0; 
    primes[0] = 2; 
    primes[1] = 2, primes[2] = 3; 
    for(int i = 0; nu <= N; i++) 
    { 
        if(!(flags[i>>5]&(1<<(i&31)))) 
            primes[++primes[0]] = nu; 
        for(int j = 3; j <= primes[0] && primes[j] * nu <= N; j++) 
        { 
            to = (nu * primes[j] - 5) >> 1; 
            to -= to/3; 
            flags[to>>5] |= 1<<(to&31); 
            if(!(nu % primes[j])) 
                break; 
        } 
        nu += 2 + ((i&1) << 1); 
    } 
    return primes[0]; 
} 
int main() 
{ 
    clock_t t = clock(); 
    printf("%d\n", get_prime()); 
    printf("Time:%f\n", 1.0 * (clock() - t) / CLOCKS_PER_SEC); 
    for(int i = 1; primes[i] < 100; i++) 
    { 
        printf("%d\n", primes[i]); 
    }
    system("pause");
    return 0; 
}
//Sieve of eratosthenes
#include<bits/stdc++.h>
using namespace std;

void Sieve(int n){
    int count = 0;
    bool *isPrime = new bool[n + 1];
    memset(isPrime, true, n + 1);
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= n; i++){
        for (int j = 2 * i; j <= n; j+=i){
            isPrime[j] = false;
        }
    }
    for (int i = 0; i < n + 1; i++){
        if(isPrime[i]==1)
            count++;
    }
    cout << count << endl;

    delete[] isPrime;
}

int main()
{
    Sieve(10);
    return 0;
}
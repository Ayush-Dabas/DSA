//Find only non repeating element in array where k is the frequency
#include<bits/stdc++.h>
using namespace std;

void answer (int *a, int n, int k){
    int Size = 8 * sizeof(unsigned int);
    int *count = new int[Size];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < Size; i++){
        for (int j = 0; j < n; j++){
            if((a[j]&(1<<i))!=0)
                count[i] += 1;
        }
    }
    unsigned res = 0;
    for (int i = 0; i < n; i++)
        res += (count[i] % k) * (1 << i);
    cout << res << endl;
    delete[] count;
}

int main()
{
    int a[] = {1, 1, 1, 2, 2, 2, 5};
    int n = 7;
    answer(a, n , 3);
    return 0;
}
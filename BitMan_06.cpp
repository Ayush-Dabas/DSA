// number of bits to convert a to b
#include<bits/stdc++.h>
using namespace std;

void Answer(int a, int b){
    a = (a ^ b);
    int count = 0;
    do{
        count++;
        a = (a & a - 1);
    } while (a > 0);
    cout << count << endl;
}

int main()
{
    Answer(22, 27);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class power{
    public:
        double bruteForce(double x, int n);
        double optimized(double x, int n);
};

double power::bruteForce(double x, int n){
    double ans = x;
    int temp = 1;
    while(temp<abs(n)){
        ans *= x;
        temp++;
    }
    if(n<0){
        ans = (double)1.0 / ans;
    }
    return ans;
}

double power::optimized(double x, int n){
    double ans = 1.0;
    int temp = n;
    if(temp<0){
        temp = temp * -1;
    }
    while (temp>0){
        if(temp%2 == 0){
            x *= x;
            temp /= 2;
        }
        else{
            ans *= x;
            temp--;
        }
    }
    if(n<0){
        ans = (double)1.0 / ans;
    }
    return ans;
}

int main(){
    double x = 2.00000;
    int n = 10;
    class power p;
    cout<<p.bruteForce(x, n)<<endl;
    cout << p.optimized(x, n) << endl;
    return 0;
}
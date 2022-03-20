// recursion ki maa ki jai
#include <bits/stdc++.h>
using namespace std;

int Sum_By_Recursion(int n)
{
    if (n == 1)
        return 1;
    return n + Sum_By_Recursion(n - 1);
}

int Pow_ab(int a, int b)
{
    if (b == 0)
        return 1;
    return a * Pow_ab(a, b - 1);
}

int main()
{
    int t;
    cout << "Enter 1 for Sum of n numbers.\nEnter 2 for Power of a raised to b\n";
    cin >> t;
    switch (t)
    {
    case 1:
        int n;
        cout << "Enter n for sum of digits :\n";
        cin >> n;
        cout << "Sum of the numbers till n is : " << Sum_By_Recursion(n) << endl;
        break;

    case 2:
        int a, b;
        cout << "Enter the value of a : ";
        cin >> a;
        cout << "Enter the value of b : ";
        cin >> b;
        cout << "A raise to power b is : " << Pow_ab(a, b) << endl;

    default:
        break;
    }

    return 0;
}
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int main()
{
   
    // factorial
    int n;
    cout << "enter n:" << endl;
    cin >> n;
    int ans=fact(n);
    cout<<ans;
}
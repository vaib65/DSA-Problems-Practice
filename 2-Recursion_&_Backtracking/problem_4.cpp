#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
void addition(int i, int sum)
{
    if (i < 1)
    {
        cout << "sum=" << sum << endl;
        return;
    }
    addition(i - 1, sum + i);
}

int sum_1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum_1(n - 1);
}
int main()
{
    // sum of n numbers using parameterised recur
    //  int n;
    //  cout<<"enter n:"<<endl;
    //  cin>>n;
    //  addition(n,0);

    // sum of n numbers using functional recur
    int n;
    cout << "enter n:" << endl;
    cin >> n;
    int ans=sum_1(n);
    cout<<ans;
}
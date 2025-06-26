#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter value of n" << endl;
    cin >> n;

    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout <<n-j+1;;//n-j+1; or j
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }

    return 0;
}
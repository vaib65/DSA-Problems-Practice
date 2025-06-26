#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter n";
    cin >> n;

    int row = 1;
    while (row <= n)
    {

        int star = n-row+1;
        while (star)
        {

            cout << "*";
            star = star - 1;
        }
        int space = n - row + 1;
        while (space)
        {
            cout << " ";
            space--;
        }

        cout << endl;
        row = row + 1;
    }
    return 0;
}
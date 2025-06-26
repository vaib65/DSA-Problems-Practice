#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter value of n=";
    cin >> n;

    int row = 1;
    char val='A';

    while (row <= n)
    {
        int col = 1;
        while (col <= n)
        {
            //char ch='A' + row-1;
            cout << val ;//cout<<ch;
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
        val++;
    }

    return 0;
}
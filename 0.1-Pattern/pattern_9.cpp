#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter value of n";
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        int col = 1;
        // char ch='A';
        while (col <= n)
        {
            char ch = 'A'+row+col-2;
            cout << ch << " ";
            // ch=ch+row+col-2;
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
        
    }
    return 0;
}
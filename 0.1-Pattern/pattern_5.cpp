#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "value of n=";
    cin >> n;

    int row = 1;
  
    while (row <= n)
    {
        int col = 1;
        int val = row;
        while (col <=row)
        {
            cout << val;
            // val =  row + 1; //find logic other than this
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enetr n=";
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        int space_left = n - row;
        while (space_left)
        {
            cout << " ";
            space_left--;
        }

        int num_left = 1;
        while (num_left <= row)
        {
            cout << num_left;
            num_left++;
        }
        
        int num_right = row - 1;
        while (num_right)
        {
            cout << num_right;
            num_right--;
        }

        // int space_right = n - row + 1;
        // while (space_right)
        // {
        //     cout << " ";
        //     space_right--;
        // }

        cout << endl;
        row = row + 1;
    }
    return 0;
}
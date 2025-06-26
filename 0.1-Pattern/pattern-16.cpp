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
         int num_left = n - row+1;
         int num=1;
        while (num_left)
        {
            cout << num;
            num++;
            num_left--;
        }

        int star_left = 1;
        while (star_left <= row-1)
        {
            cout << "*";
            star_left++;
        }
        
        int star_right = row - 1;
        while (star_right)
        {
            cout << "*";
            star_right--;
        }

        int num_right = n - row + 1;
        while (num_right)
        {
            cout << num_right;
            num_right--;
        }




        cout << endl;
        row = row + 1;
    }
    return 0;
}
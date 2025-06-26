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
        char ch='A';
        while (col <= n)
        {
        
            cout<<ch;
            col=col+1;
            ch++;
           
        }
        cout<<endl;
        row=row+1;
    }
    return 0;
}
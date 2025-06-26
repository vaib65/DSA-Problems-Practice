#include<iostream>
using namespace std;

int main(){
     int n;
    cout << "enter value of n";
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        int col = 1;
        char ch='A'+n-row;
        while (col <= row)
        {
            cout << ch << " ";
            ch++;
            col = col + 1;
        }
        cout << endl;
        row = row + 1;
        
    }
    return 0;
}
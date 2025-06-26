#include<iostream>
using namespace std;

int main(){
     int n;
    cout<<"enter n";
    cin>>n;

    int row=1;
    while(row<=n)
    {
        int space=row-1;
        while (space)
        {
           cout<<" ";
           space--;
        }
        int star=n-row+1;;
        while(star){
            cout<<"*";
            star--;
        }
        
        cout<<endl;
        row=row+1;
    }
    return 0;
}
#include<iostream>//print all digit of no
#include<vector>
#include<limits.h>
using namespace std;
void printDigits(int num){
    //bc
    if(num==0){
        return;
    }
   //
    printDigits(num/10);

    //
    int digit=num%10;
    cout<<digit<<endl;
 
}
int main(){
    int num=647;
    printDigits(num);
}
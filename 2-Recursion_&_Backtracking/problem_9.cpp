#include<iostream>//print subsequence
#include<vector>
#include<limits.h>
using namespace std;
void  PrintSubSequence(string str,string output,int i){
    //bc
    if(i>=str.length()){
        cout<<output<<endl;
        return;
    }

    //exclude
    PrintSubSequence(str,output,i+1);

    //include
    output.push_back(str[i]);
    PrintSubSequence(str,output,i+1);

}
int main(){
    string str="abc";
    string output="";
    int i=0;
    PrintSubSequence(str,output,i);
}
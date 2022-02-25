#include<iostream>
using namespace std;

int main(void){
    
    for(int i=3;i<=100;i++){
        bool isPrime=true;
        for(int j=2;j<=(i+1)/2;j++){
            if(i%j==0){
                isPrime=false;
                break;
            }       
        }
        if(isPrime) cout<<i<<" ";
    }
    cout<<endl;

}
#include<iostream>
#include<iomanip>
using namespace std;

int main(void){
    double input;
    cout<<"input: ";
    cin>>input;
    double guess=input/2;
    for(int i=0;i<5;i++){
        double r=input/guess;
        guess=(guess+r)/2;
    }

    cout<<"output: "<<setprecision(2)<<fixed<<guess<<endl;
}
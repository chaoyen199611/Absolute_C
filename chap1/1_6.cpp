#include <iostream>
using namespace std;

int main(void){
    double distance;
    int minutes;
    double fee=2;
    cout<<"distance:";
    cin>>distance;
    cout<<"minutes:";
    cin>>minutes;
    distance-=2;
    if(distance<=6){
        fee+=distance*0.5;
    }
    else{
        fee+=3;
        distance-=6;
        fee+=distance;
    }
    fee+=minutes*0.2;
    cout<<"total fee:"<<fee<<endl;
}
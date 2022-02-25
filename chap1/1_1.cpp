//one gallon 3785.41 ml
#include<iostream>
using namespace std;

int main(){
    double amount;
    cout<<"how many ml per packets:";
    cin>>amount;
    double gallon;
    gallon=amount/3785.41;
    cout<<"total "<<gallon<<" gallon"<<endl;
    int packet=1/gallon;
    cout<<packet+1<<" packets"<<endl;

}
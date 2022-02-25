#include<iostream>
using namespace std;

int main(void){
    double amount,interest,withdraw,start;
    cout<<"start deposit: ";
    cin>>amount;
    cout<<"bank interest: ";
    cin>>interest;
    cout<<"fixed amount withdrawn: ";
    cin>>withdraw;    
    int month=0;
    start=amount;
    while(true){
        if(withdraw>=amount)    break;
        else{
            amount-=withdraw;
            amount=amount*(1+interest);
            if(amount>=start){
                cout<<"the interest earned is greater than fixed withdrawal"<<endl;
                return 0;
            }
            month++;
        }
    }
    cout<<"total month:"<<month<<endl;
}
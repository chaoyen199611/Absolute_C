#include<iostream>
#include<cstdlib>
using namespace std;

class Payment{
public:
    Payment();
    Payment(float amount);
    void setPayment(float amount);
    float getPayment();
    void paymentDetails();
private:
    float amt;
};

Payment::Payment():amt(0){}

Payment::Payment(float amount):amt(amount){}

void Payment::setPayment(float amount){
    amt=amount;
}

float Payment::getPayment(){
    return amt;
}

void Payment::paymentDetails(){
    cout<<"The payment amount is "<<amt<<endl;
}

class CashPayment:public Payment{
public:
    CashPayment();
    CashPayment(float amount);
    void paymentDetails();
};

CashPayment::CashPayment():Payment(){}

CashPayment::CashPayment(float amount):Payment(amount){}

void CashPayment::paymentDetails(){
    cout<<"The cash payment amount is "<<getPayment()<<endl;
}

class CreditcardPayment:public Payment{
public:
    CreditcardPayment();
    CreditcardPayment(float amount,string n,string exp,string cred);
    void paymentDetails();
private:
    string name;
    string expiration;
    string creditcard;
};

CreditcardPayment::CreditcardPayment():Payment(){
    name="";
    expiration="";
    creditcard="";
}

CreditcardPayment::CreditcardPayment(float amount,string n,string exp,string cred):Payment(amount){
    this->name=n;
    this->expiration=exp;
    this->creditcard=cred;
}

void CreditcardPayment::paymentDetails(){
    cout<<"The credit card payment amount is "<<getPayment()<<endl;
    cout<<"The name on the card is: "<<name<<endl;
    cout<<"The expiration date is: "<<expiration<<endl;
    cout<<"The credit card number is: "<<creditcard<<endl;
}

int main(void){
    CashPayment cash1(50.5),cash2(20.45);
    CreditcardPayment credit1(10.5,"Fred","10/5/2010","123456789"),credit2(100,"Barney","11/15/2009","987654321");
    cout<<"Cash 1 details:"<<endl;
    cash1.paymentDetails();
    cout<<"Cash 2 details:"<<endl;
    cash2.paymentDetails();
    cout<<"Credit 1 details:"<<endl;
    credit1.paymentDetails();
    cout<<"Credit 2 details:"<<endl;
    credit2.paymentDetails();
}
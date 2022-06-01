#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

class Money {
public:
    Money();
    Money(double amount);
    Money(int theDollars,int theCents);
    Money(int theDollars);
    double getAmount() const;
    int getDollars() const;
    int getCents() const;
    friend istream& operator >>(istream& inputStream , Money& amount);
    friend ostream& operator <<(ostream& outputStream, const Money& amount);

    friend bool operator >(const Money& amount1, const Money& amount2);
    friend bool operator >=(const Money& amount1, const Money& amount2);
    friend bool operator <(const Money& amount1, const Money& amount2);
    friend bool operator <=(const Money& amount1, const Money& amount2);
    friend bool operator ==(const Money& amount1, const Money& amount2);

    friend const Money operator +(const Money& amount1, const Money& amount2);
    friend const Money operator -(const Money& amount1, const Money& amount2);
    const Money percent(int percentFigure) const;

private:
    int dollarPart(double amount) const;
    int centPart(double amount) const;
    int round(double number) const;
    int dollars;
    int cents;

};

int main(void){
    
    Money myamount(10,9),youramount;
    int percentfigure;
    cout<<"Enter an amount of money: ";
    cin>>youramount;
    cout<<"Enter a percent you wish to take of your amount: ";
    cin>>percentfigure;
    cout<<"Your amount is "<<youramount<<endl;
    cout<<"My amount is "<<myamount<<endl;
    cout<<percentfigure<<"% of your amount is " 
        << youramount.percent(percentfigure)
        <<endl;
    cout<<"15% of my amount is "<<myamount.percent(15)<<endl;

    if(youramount==myamount){
        cout<<"We have the same amounts"<<endl;
    }
    else    
        cout<<"One of us is richer."<<endl;

    Money ouramount=youramount+myamount;
    Money diffamount=youramount-myamount;

    //+
    cout<<youramount<<" + "<<myamount<<" equals "<<ouramount<<endl;
    //-
    cout<<youramount<<" - "<<myamount<<" equals "<<diffamount<<endl;

    cout<<"Your amount is "<<youramount<<endl;
    cout<<"My amount is "<<myamount<<endl;

    if(youramount>=myamount)
        cout<<"Your amount is greater than or equal to my amount."<<endl;
    else    
        cout<<"Your amount is less than mine."<<endl;

    if(ouramount>diffamount)
        cout<<"The sum of our amounts is greater than the difference."<<endl;
    else    
        cout<<"error."<<endl;
    
    if(youramount>myamount)
        cout<<"Your amount is greater than my amount."<<endl;
    else    
        cout<<"Your amount is less than or equal to mine."<<endl;
    
    if(ouramount>=diffamount)
        cout<<"The sum of our amounts is greater than or equal to the difference."<<endl;
    else    
        cout<<"error."<<endl;
}

Money::Money(double amount):dollars(dollarPart(amount)),cents(centPart(amount)){}

Money::Money(int theDollars, int theCents):dollars(theDollars),cents(theCents){}

Money::Money():dollars(0),cents(0){}

istream& operator >>(istream& inputStream, Money& amount){
    char dollarSign;
    inputStream>>dollarSign;
    
    if(dollarSign!='$'){
        cout<<"No dollar sign in Money input."<<endl;
        exit(1);
    }

    double amountAsDouble;
    inputStream>>amountAsDouble;
    amount.dollars=amount.dollarPart(amountAsDouble);
    amount.cents=amount.centPart(amountAsDouble);
}

ostream& operator <<(ostream& outputStream, const Money& amount){
    int absDollars=abs(amount.dollars);
    int absCents=abs(amount.cents);
    if(amount.dollars<0||amount.cents<0){
        outputStream<<"$-";
    }
    else outputStream<<'$';
    outputStream<<absDollars;
    if(absCents>=10){
        outputStream<<'.'<<absCents;
    }
    else    
        outputStream<<".0"<<absCents;
    return outputStream;
}

const Money operator +(const Money& amount1, const Money& amount2){
    int amount1Total=amount1.dollars*100+amount1.cents;
    int amount2Total=amount2.dollars*100+amount2.cents;
    int total = amount1Total+amount2Total;
    int d=total/100;
    int c=total%100;
    return Money(d,c);
}

const Money operator -(const Money& amount1, const Money& amount2){
    int amount1Total=amount1.dollars*100+amount1.cents;
    int amount2Total=amount2.dollars*100+amount2.cents;
    int total = amount1Total-amount2Total;
    int d=total/100;
    int c=total%100;
    return Money(d,c);
}

bool operator ==(const Money& amount1, const Money& amount2){
    if(amount1.dollars==amount2.dollars&&amount1.cents==amount2.cents){
        return true;
    }
    else    
        return false;
}

bool operator >=(const Money& amount1, const Money& amount2){
    if(amount1.dollars*100+amount1.cents<amount2.dollars*100+amount2.cents)
        return false;
    else    
        return true;
}

bool operator <=(const Money& amount1, const Money& amount2){
    if(amount1.dollars*100+amount1.cents>amount2.dollars*100+amount2.cents)
        return false;
    else    
        return true;
}

bool operator <(const Money& amount1, const Money& amount2){
    if(amount1.dollars*100+amount1.cents<amount2.dollars*100+amount2.cents)
        return true;
    else    
        return false;
}

bool operator >(const Money& amount1, const Money& amount2){
    if(amount1.dollars*100+amount1.cents>amount2.dollars*100+amount2.cents)
        return true;
    else    
        return false;
}

int Money::dollarPart(double amount) const{
    return static_cast<int>(amount);
}

int Money::centPart(double amount) const{
    double full=amount*100;
    int intCents=(round(fabs(full)))%100;

    if (amount<0){
        intCents*=-1;
    }
    return intCents;

}
const Money Money::percent(int percentFigure) const{
    int d = dollars*percentFigure/100;
    int c = dollars*percentFigure%100+cents*percentFigure/100;
    return Money(d,c);
}

int Money::round(double number) const{
    return static_cast<int> (number);
}
#include<iostream>
#include<cstdlib>
using namespace std;

class Temperature{
public:
    Temperature(){};
    friend ostream& operator <<(ostream& outputStream,Temperature& temp);
    friend istream& operator >>(istream& inputStream,Temperature& temp);
    friend bool operator ==(Temperature& temp1,Temperature& temp2);
    void setTemp(double n);
    double getFahr();
    void out();
private:
    double kelvin;
    double celsius;
    double fahrenheit;
};

int main(void){

    Temperature temp1,temp2;

    cout<<"Input a temperature1 in Fahrenheit."<<endl;
    cin>>temp1;
    temp1.out();
    cout<<temp1<<endl;

    cout<<"Input a temperature2 in Fahrenheit."<<endl;
    cin>>temp2;
    temp2.out();
    cout<<temp2<<endl;

    cout<<"temperature1 == temperature2 : ";
    if(temp1==temp2){
        cout<<"true"<<endl;
    }
    else    
        cout<<"false"<<endl;

}

istream& operator >>(istream& inputStream,Temperature& temp){
    double input;
    inputStream>>input;
    temp.setTemp(input);
}

ostream& operator <<(ostream& outputStream,Temperature& temp){
    outputStream<<"In Fahrenheit: "<<temp.getFahr()<<endl;
}

bool operator ==(Temperature& temp1,Temperature& temp2){
    if(temp1.getFahr()==temp2.getFahr()){
        return true;
    }
    else    
        return false;
}

void Temperature::out(){
    cout<<"In Kelvin: "<<kelvin<<endl;
    cout<<"In Celsius: "<<celsius<<endl;
}

void Temperature::setTemp(double n){
    fahrenheit=n;
    celsius=(n-32)*5.0/9.0;
    kelvin=(n+459.67)*5.0/9.0;
}

double Temperature::getFahr(){
    return fahrenheit;
}
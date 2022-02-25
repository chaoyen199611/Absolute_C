#include <iostream>
using namespace std;

int main(void){
    double c=100,f=0;
    while(true){
        f=1.8*c+32;
        if(f==c)    break;
        c--;
    }
    cout<<"same at "<<c<<" celsius and "<<f<<" fahrenheit."<<endl;


}
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

int main(void){
    fstream file;
    string name;
    double sum,value;
    int count=0;
    cout<<"Enter a file name : ";
    cin>>name;
    file.open(name);

    file>>value;
    while(file){
        count++;
        sum+=value;
        file>>value;
    }
    sum/=count;
    cout<<"Average of "<<count<<" numbers is "<<sum<<endl;

}
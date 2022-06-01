#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(void){

    string n;
    cout<<"When enter a single \"-1\" in one line this program will end."<<endl;
    while(getline(cin,n)&&n!="-1"){
        for(int i=0;i<n.size();i++){
            if((int(n[i])>=65&&int(n[i])<=90)||(int(n[i])>=97&&int(n[i])<=122)){    
                n[i]=char(int(n[i])+3);
                
                if((int(n[i])>90&&int(n[i])<97)||int(n[i])>122){
                    if(int(n[i])>122)
                        n[i]=char(96+int(n[i])-122);
                    else
                        n[i]=char(89+int(n[i])-90);
                }
                
            }
            else if(int(n[i])>=48&&int(n[i])<=57){ 
                n[i]=char((int(n[i])-48+5)%10+48);
            }
            else if(n[i]=='\n'||n[i]==' '){
                continue;
            }
            else{
                n[i]=' ';
            }
            cout<<n[i];
        }
        cout<<endl;
    }




}
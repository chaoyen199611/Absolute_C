#include<iostream>
#include<cstdlib>
using namespace std;

class CharPair{
public:
    CharPair();
    CharPair(int sz);
    CharPair(int sz,char ch);
    int getSize();
    char& operator[](int index);

    friend ostream& operator <<(ostream& outputStream, CharPair& array);

private:
    int size;
    char slot[100];

};

int main(void){
    CharPair a;
    cout<<"Default output(10):"<<a;
    cout<<"Size: "<<a.getSize()<<endl<<"-----clear array-----"<<endl;
    cout<<"First sz member of the char array to #:";
    int sz;
    cin>>sz;
    CharPair b(sz);
    cout<<b
        <<"Size: "<<b.getSize()<<endl<<"-----clear array-----"<<endl;
    char n;
    cout<<"First sz member of the char array to ?:";
    cin>>sz>>n;
    CharPair c(sz,n);
    cout<<c
        <<"Size: "<<c.getSize()<<endl<<"-----clear array-----"<<endl;
}

ostream& operator <<(ostream& outputStream, CharPair& array){
    for(int i=0;i<array.size;i++){
        outputStream<<array[i]<<" ";
    }
    outputStream<<endl;
}

CharPair::CharPair(){
    size=10;
    for(int i=0;i<size;i++){
        slot[i]='#';
    }
}

CharPair::CharPair(int sz){
    size=sz;
    for(int i=0;i<size;i++){
        slot[i]='#';
    }
}

CharPair::CharPair(int sz,char ch){
    size=sz;
    for(int i=0;i<size;i++){
        slot[i]=ch;
    }
}

int CharPair::getSize(){
    return size;
}

char& CharPair::operator[](int index){
    if(index<=size){
        return slot[index];
    }
    else{
        cout<<"error"<<endl;
        exit(1);
    }
}
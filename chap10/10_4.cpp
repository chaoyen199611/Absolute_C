#include<iostream>
#include<string>
using namespace std;

class Subscriber{
public:
    Subscriber();
    Subscriber(string name,int num);
    void input(string n,int num);
    void output();
    void reset();
    const Subscriber& operator=(const Subscriber& sub);
    ~Subscriber();
private:
    string name;
    int numChannels;
    string * channelList;

};

int main(void){
    string name;
    int num;

    cout<<"Enter person name."<<endl;
    cin>>name;
    cout<<"Enter number of channels."<<endl;
    cin>>num;
    Subscriber one(name,num),two;
    for(int i=0;i<num;i++){
        cout<<"Enter name of channel "<<i+1<<endl;
        cin>>name;
        one.input(name,i);
    }
    cout<<endl<<"Person 1's data:"<<endl;
    one.output();
    two=one;
    cout<<"Person 2's data after assignment from student 1:"<<endl;
    two.output();
    cout<<"Person 1's data after reset:"<<endl;
    one.reset();
    one.output();
    cout<<"Person 2's data, should still have original classes:"<<endl;
    two.output();
}

Subscriber::Subscriber(){}

Subscriber::Subscriber(string n,int num){
    name=n;
    numChannels=num;
    channelList=new string[numChannels];
}

Subscriber::~Subscriber(){
    delete[] channelList;
}

void Subscriber::input(string n,int num){
    channelList[num]=n;
}

void Subscriber::output(){
    cout<<"Name : "<<name<<endl;
    cout<<"Number of channels:"<<numChannels<<endl;
    for(int i=1;i<numChannels+1;i++){
        cout<<"\tChannel "<<i<<":"<<channelList[i-1]<<endl;
    }
}

void Subscriber::reset(){
    delete[] channelList;
    numChannels=0;
}

const Subscriber& Subscriber::operator=(const Subscriber& sub){
    name=sub.name;
    numChannels=sub.numChannels;
    delete[] channelList;
    channelList=new string[numChannels];
    for(int i=0;i<numChannels;i++){
        channelList[i]=sub.channelList[i];
    }
}
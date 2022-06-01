#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

class Viewer{
    public:
        Viewer();
        void getCommand();
    protected:
        void displayMenu();
        void displayMessage();
        static vector<string> messages;
};

vector<string> Viewer::messages;

Viewer::Viewer(){}

void Viewer::getCommand(){
    int cmd;
    do{
        cout<<endl;
        displayMenu();
        cout<<"Enter command."<<endl;
        cin>>cmd;
        cin.ignore(2,'\n');
        if(cmd==1)
            displayMessage();
    }while(cmd!=0);
}

void Viewer::displayMenu(){
    cout<<"Menu options:"<<endl;
    cout<<"0> EXIT\n1> Display all messages"<<endl;
}

void Viewer::displayMessage(){
    cout<<"Message Posted:"<<endl;
    for(int i=0;i<messages.size();i++){
        cout<<i+1<<". "<<messages[i]<<endl;
    }
}

class Owner:public Viewer{
    public:
        Owner():Viewer(){}
        void getCommand();
    protected:
        void displayMenu();
        void postMessage(string post);
        void deleteMessage(int num);
};

void Owner::getCommand(){
    int cmd;
    cout<<"Enter command."<<endl;
    do{
        Viewer::displayMenu();
        displayMenu();
        cin>>cmd;
        cin.ignore(4,'\n');
        if(cmd==1){
            Viewer::displayMessage();
        }
        else if(cmd==2){
            string mes;
            cout<<"Enter new message"<<endl;
            getline(cin,mes);
            postMessage(mes);
        }
        else if(cmd==3){
            int sel;
            cout<<"Which message do you want ot delete?"<<endl;
            cin>>sel;
            deleteMessage(sel);
        }
        else{
            continue;
        }
    }while(cmd!=0);
}

void Owner::displayMenu(){
    cout<<"2> Post new message\n3> Delete message"<<endl;
}

void Owner::postMessage(string post){
    messages.push_back(post);
    cout<<"Message Posted"<<endl;
}

void Owner::deleteMessage(int num){
    messages.erase(messages.begin()+(num-1));
}

int main(void){
    cout<<"First, enter data as the owner"<<endl;
    Owner own;
    own.getCommand();
    cout<<"Access data as viewer"<<endl;
    Viewer view;
    view.getCommand();
}
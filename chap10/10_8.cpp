#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
using namespace std;

class Television{
public:
    Television();
    Television(string name,double dim,string list[],int n);
    const Television& operator=(const Television& tv);
    void setType(string t);
    void setDim(double t);
    void setMode(int t);
    void setList(string list[]);
    void output(int t);
private:
    string displayType;
    double dimension;
    string * connectivitySupport;
    int mode;
};

int main(void){

    
    vector<Television> tel;

    string typeT;
    double dimension;
    int modes,TVnum;
    cout<<"Enter default TV display type :"<<endl;
    cin>>typeT;
    cout<<"Enter default TV Dimension : "<<endl;
    cin>>dimension;
    cout<<"Enter the number of connectivity modes"<<endl;
    cin>>modes;
    cout<<"Enter default TV connectivity support types :"<<endl;
    string * modeList = new string[modes];
    for(int i=0;i<modes;i++){
        cin>>modeList[i];
    }
    Television root(typeT,dimension,modeList,modes),copy;
    root.output(modes);
    cout<<"Enter TV numbers :";
    cin>>TVnum;
    for(int i=0;i<TVnum;i++){
        copy=root;
        tel.push_back(copy);
    }
    int sel;
    delete[] modeList;
    do{
        cout<<"Enter index of TVs required fo custimization(input -1 to end)";
        cin>>sel;
        cout<<"Enter TV#"<<sel<<" display type :"<<endl;
        cin>>typeT;
        tel[sel].setType(typeT);
        cout<<"Enter TV#"<<sel<<" Dimension :"<<endl;
        cin>>dimension;
        tel[sel].setDim(dimension);
        cout<<"Enter the number of connectivity modes"<<endl;
        cin>>modes;
        cout<<"Enter TV#"<<sel<<" connectivity support types :"<<endl;
        string * modeList = new string[modes];
        for(int i=0;i<modes;i++){
            cin>>modeList[i];
        }
        
    }while(sel!=-1);
    for(int i=0;i<tel.size();i++){
        tel[i].output(i);
    }

}

Television::Television(){}

Television::Television(string name,double dim,string list[],int n){
    displayType=name;
    dimension=dim;
    connectivitySupport=new string[n];
    mode=n;
    for(int i=0;i<n;i++){
        connectivitySupport[i]=list[i];
    }
}

void Television::setType(string t){
    displayType=t;
}

void Television::setDim(double t){
    dimension=t;
}

void Television::setMode(int t){
    mode=t;
}

void Television::setList(string list[]){
    delete[] connectivitySupport;
    connectivitySupport=new string[mode];
    for(int i=0;i<mode;i++){
        connectivitySupport[i]=list[i];
    }
}

void Television::output(int t){
    cout<<"TV#"<<t<<endl;
    cout<<"Display type : "<<displayType<<endl;
    cout<<"Dimension(inches): "<<dimension<<endl;
    cout<<"connectivity support types:"<<endl;
    for(int i=0;i<mode;i++){
        cout<<connectivitySupport[i]<<endl;
    }
}

const Television& Television::operator=(const Television& tv){
    displayType=tv.displayType;
    dimension=tv.dimension;
    delete[] connectivitySupport;
    connectivitySupport=new string[mode];
    for(int i=0;i<mode;i++){
        connectivitySupport[i]=tv.connectivitySupport[i];
    }
}
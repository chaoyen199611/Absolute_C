#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

class BoxOfProduce{
public:
    BoxOfProduce();
    void addBundle(string n);
private:  
    vector<string> bundle;
};

int main(void){
    BoxOfProduce a;
    cout<<"The box contains: ";
    while(true){
        cin>>a;
    }

}

BoxOfProduce::BoxOfProduce(){
    bundle.clear();
}

void BoxOfProduce::addBundle(string n){
    bundle.push_back(n);
}
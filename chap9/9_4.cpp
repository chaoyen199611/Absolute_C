#include<iostream>
#include<string>
#include<cstdlib>
#include<vector>
#include<utility>
using namespace std;

int main(void){
    cout<<"enter 'quit' when want to terminate"<<endl;
    string n;
    int wordcount=0;
    vector<pair<int,int> > range;
    while(getline(cin,n)&&n!="quit"){
        for(int i=0;i<n.size();i++){
            if((int(n[i])>=65&&int(n[i])<=90)||(int(n[i])>=97&&int(n[i])<=122)){
                wordcount++;
            }
            else{
                if(wordcount!=0){
                    range.push_back(make_pair(i-wordcount,i-1));
                }
                wordcount=0;
            }
        }
        for(int j=0;j<range.size();j++){
            if((range[j].second-range[j].first+1)==4){
                if(n[range[j].first]<=90){
                    n[range[j].first]='L';
                }
                else{
                    n[range[j].first]='l';
                }
                n[range[j].first+1]='o';
                n[range[j].first+2]='v';
                n[range[j].first+3]='e';
            }
        }
        cout<<n<<endl;
    }



}
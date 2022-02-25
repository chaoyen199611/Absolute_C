#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

int main(void){
    int subjectNum=0;
    double total;
    char grade;

    map <char,int > point;
    point.insert(pair<char,int>('S',10));
    point.insert(pair<char,int>('A',9));
    point.insert(pair<char,int>('B',8));
    point.insert(pair<char,int>('C',7));
    point.insert(pair<char,int>('D',6));
    point.insert(pair<char,int>('E',5));
    point.insert(pair<char,int>('F',0));
    cout<<"how many subject : ";
    cin>>subjectNum;
    for(int i=0;i<subjectNum;i++){
        cout<<"subject"<<i+1<<": ";
        cin>>grade;
        total+=point[grade];
    }
    cout<<"avg. score : "<<setprecision(2)<<fixed<<total/subjectNum<<endl;

}
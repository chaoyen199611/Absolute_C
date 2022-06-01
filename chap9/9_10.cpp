#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<typeinfo>
using namespace std;

class Trivia{
public:
    Trivia();
    Trivia(string n,string ans,int a);
    friend ostream& operator <<(ostream& outputStream, const Trivia& t);
    friend istream& operator >>(istream& inputStream, Trivia& t);
    int getPrize();
    bool check();
    string getAnswer();
private:
    string ques;
    string answer;
    int prize;
    string res;
};

int main(void){

    vector<Trivia> quiz;
    int totalprize=0; 
    Trivia a("Year that Amelia Earhart disappeared?","1938",5),
            b("Which season that the children will growth faster?","spring",5),
            c("Can human keep the eyes open when sneezeing?","no",5),
            d("Which muscle of human's body is most strongth?","tongue",10),
            e("What is the 49th state admitted to the USA?","alaska",2);

    quiz.insert(quiz.end(),{a,b,c,d,e});
    cout<<"Trivia Game!"<<endl;
    for(int i=0;i<quiz.size();i++){
        cout<<"You have $"<<totalprize<<endl;
        cout<<quiz[i];
        string tmp;
        cin>>tmp;
        if(quiz[i].check()){
            cout<<"That's right! You win $"<<quiz[i].getPrize()<<endl;
            totalprize+=quiz[i].getPrize();
        }
        else{
            cout<<"Sorry, the correct answer is: "<<quiz[i].getAnswer()<<endl;
        }
    }
    cout<<"Game over. Your total winnings are: $"<<totalprize<<endl;
    
    
}

Trivia::Trivia(string n,string ans,int a){
    ques=n;
    answer=ans;
    prize=a;
    res="";
}

ostream& operator <<(ostream& outputStream, const Trivia& t){
    outputStream<<t.ques<<endl;
}

istream& operator >>(istream& inputStream, Trivia& t){
    string tmp;
    inputStream>>tmp;
    t.res=tmp;
}

bool Trivia::check(){
    
    if(res==answer){
        cout<<answer<<endl;
        return true;
    }
    else
        return false;
}
int Trivia::getPrize(){
    return prize;
}
string Trivia::getAnswer(){
    return answer;
}
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main(void){
    char n[80];
    char *head=NULL,*tail=NULL;
    char temp;
    cout<<"Enter a string less than 80 characters long."<<endl;
    cin.getline(n,80);
    head=n;
    tail=&n[strlen(n)-1];
    cout<<head<<" "<<tail<<endl;
    while(head<tail){
        temp=*head;
        *head=*tail;
        *tail=temp;
        head++;
        tail--;
        cout<<tail<<endl;
    }
    cout<<"Your string reversed is : "<<n<<endl;

    return 0;
}
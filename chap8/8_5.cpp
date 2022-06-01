#include<iostream>
#include<cstdlib>
using namespace std;


class Vector2D{
public:
    Vector2D(int newx,int newy);
    void setX(int newx);
    void setY(int newy);
    int getX();
    int getY();
    friend ostream& operator <<(ostream& outputStream, Vector2D vect);
    friend int operator *(Vector2D& vect1, Vector2D& vect2);
    
private:
    int x,y;
};

int main(void){
    Vector2D a(9,10),b(17,0),c(10,12),d(0,8),e(19,13),f(7,20);
    cout<<a<<" * "<<b<<" = "<<a*b<<endl;
    cout<<c<<" * "<<d<<" = "<<c*d<<endl;
    cout<<e<<" * "<<f<<" = "<<e*f<<endl;
}

Vector2D::Vector2D(int newx,int newy){
    x=newx;
    y=newy;
}

int operator *(Vector2D& vect1,Vector2D& vect2){
    int a = vect1.getX()*vect2.getX();
    int b = vect1.getY()*vect2.getY();
    return a+b;
}

ostream& operator <<(ostream& outputStream, Vector2D vect){
    outputStream<<'('<<vect.x<<','<<vect.y<<')';
}

int Vector2D::getX(){
    return x;
}

int Vector2D::getY(){
    return y;
}
#include<iostream>
#include<cstdlib>
using namespace std;

class Student{
    public:
        Student();
        Student(string uni,int num,const UniversityStaff staff);
        Student(const Student& stu);
        Student operator=(const Student& stu);
    private:
        string university;
        int registerNum;
        UniversityStaff proctor;
};

class UniversityStaff{
    public:
        UniversityStaff();
        UniversityStaff();
        UniversityStaff();
        string getName()const;
        UniversityStaff& operator=(const UniversityStaff& rtSide);
        friend istream& operator>>(istream& inputStream, UniversityStaff& staff);
        friend ostream& operator<<(ostream& outputStream,const UniversityStaff& staff);
    private:
        string name;
};

int main(void){




}
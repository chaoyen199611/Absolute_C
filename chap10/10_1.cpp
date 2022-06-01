#include<iostream>
#include<cstdlib>
using namespace std;

typedef double* DoubleArrayPtr;

class TwoD{
public:
    TwoD();
    TwoD(int maxR, int maxC);
    double& operator ()(int r,int c);
    const TwoD& operator=(const TwoD& rhs);
    friend int matrixRow(const TwoD& rhs);
    friend int matrixCol(const TwoD& rhs);
    friend TwoD operator+(const TwoD& rhs1,const TwoD& rhs2);
private:
    int MaxRows,MaxCols;
    DoubleArrayPtr * matrix;
};

int main(void){

    int d1,d2,i,j;
    cout<<"Enter the row and column dimensions of the array\n";
    cin>>d1>>d2;

    TwoD matrix1(d1,d2);

    cout<<"Enter "<<d1<<" rows of "<<d2<<" doubles each"<<endl;
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cin>>matrix1(i,j);
        }
    }
    cout<<"Echoing the 2 dim. array, matrix1"<<endl;
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<matrix1(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the row and column dimensions of the array\n";
    cin>>d1>>d2;

    TwoD matrix2(d1,d2),matrix3;

    cout<<"Enter "<<d1<<" rows of "<<d2<<" doubles each"<<endl;
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cin>>matrix2(i,j);
        }
    }
    cout<<"Echoing the 2 dim. array, matrix2"<<endl;
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<matrix2(i,j)<<" ";
        }
        cout<<endl;
    }
    matrix3=matrix2;
    cout<<"Assigning matrix2 to matrix3"
        <<endl<<"Displaying the 2 dim array, matrix3 resulting from assingment"<<endl
        <<"Rows "<<matrixRow(matrix3)<<" Cols "<<matrixCol(matrix3)<<endl;
    
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<matrix3(i,j)<<" ";
        }
        cout<<endl;
    }
    cout<<"Displaying the 2 dim array, sum of matrix 1 and 2"<<endl;
    matrix3=matrix1+matrix2;
    cout<<"Rows "<<matrixRow(matrix3)<<" Cols "<<matrixCol(matrix3)<<endl;
    for(int i=0;i<d1;i++){
        for(int j=0;j<d2;j++){
            cout<<matrix3(i,j)<<" ";
        }
        cout<<endl;
    }

}

int matrixRow(const TwoD& rhs){
    return rhs.MaxRows;
}

int matrixCol(const TwoD& rhs){
    return rhs.MaxCols;
}

double& TwoD::operator()(int r,int c){
    return matrix[r][c];
}

TwoD operator+(const TwoD& rhs1,const TwoD& rhs2){
    if(rhs1.MaxCols!=rhs2.MaxCols||rhs1.MaxRows!=rhs2.MaxRows){
        exit(1);
    }
    TwoD sum(rhs1.MaxRows,rhs1.MaxCols);

    for(int i=0;i<rhs1.MaxRows;i++){
        for(int j=0;j<rhs1.MaxCols;j++){
            sum.matrix[i][j]=rhs1.matrix[i][j]+rhs2.matrix[i][j];
        }
    }
    return sum;
    
}

TwoD::TwoD():MaxCols(10),MaxRows(10){}

TwoD::TwoD(int maxR, int maxC){
    MaxRows=maxR;
    MaxCols=maxC;
    matrix = new DoubleArrayPtr[MaxRows];
    for(int i=0;i<MaxRows;i++){
        matrix[i] = new double[MaxCols];
    }
    for(int i=0;i<MaxRows;i++){
        for(int j=0;j<MaxCols;j++){
            matrix[i][j]=0;
        }
    }

}

const TwoD& TwoD::operator=(const TwoD& rhs){
    if(matrix==rhs.matrix){
        return rhs;
    }
    for(int i=0;i<MaxRows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    MaxRows=rhs.MaxRows;
    MaxCols=rhs.MaxCols;

    matrix=new DoubleArrayPtr[MaxRows];
    for(int i=0;i<MaxRows;i++){
        matrix[i]=new double[MaxCols];
    }
    for(int i=0;i<MaxRows;i++){
        for(int j=0;j<MaxCols;j++){
            matrix[i][j]=rhs.matrix[i][j];
        }
    }
    return rhs;
}
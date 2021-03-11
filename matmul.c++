#include <iostream>

using namespace std;
#include "Matrix.h"




int main(){

    //float data[3][3] = {1,1,1,1,1,1,1,1,1};
    float* pd = new float(9);

    pd[1] = 1;
    pd[0] = 0;

    for (size_t i = 0; i < 9; i++)
    {
        pd[i] = 1;
    }
    
    matrix A(3,3,pd);

    A.Print_shape();

    matrix B;


    B = A;

    B.Print_shape();
    A.Print_shape();
    cout<< "hello-oh"<<endl;

    A.Print_elem();

    B.Print_elem();

    matrix C = A*B;
    cout<<"-------matmul"<<endl;
    C.Print_elem();

}
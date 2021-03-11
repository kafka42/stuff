#ifndef Matrix_hpp
#define Matrix_hpp
#endif 

#ifndef debug
#define debug
#endif 

#include <iostream>
#include <math.h>
using namespace std;

class matrix
{
private:
    int ncol,nrow;
    float* elem = new float[ncol*nrow];

public:
    


    matrix(){ ncol = 0; nrow = 0; }

    matrix(int row, int col){   ncol = col; nrow = row; }

    matrix(int row, int col, float* elements){
        ncol = col;
        nrow = row;
        elem = elements;
                }          

    matrix operator = (matrix &obj){
        nrow = obj.nrow;
        ncol = obj.ncol;
        elem = obj.elem;
    }             

    friend matrix operator * (matrix &,matrix &);

    void Print_shape(){cout<< "[" << nrow << "," << ncol << "]" << endl;}
    
    void Print_elem(){
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < nrow; j++)
            {
                cout<< elem[i*ncol +j] <<",";
            }
            cout << endl;
        }     
    }


    
};

/*
    Function that performs matrix-matrix multliplication ( row * col )
    C = A * B
    Input:

    ->matrix A: left matrix, must have ncol = B.nrow

    ->matrix B: right matrix, must have nrow = A.ncol

    Output:

    matrix C = A*B
*/
    matrix operator *( matrix &A, matrix &B){
        matrix C(B.nrow,A.ncol);

        float serv = 0.0;

        for (size_t c = 0; c < C.ncol; c++)
        {
            for (size_t r = 0; r < C.nrow; r++)
            {   
                float serv = 0.0;
                for (size_t i = 0; i < A.ncol; i++)
                {
                    serv += A.elem[r*A.ncol+i]*B.elem[i*B.ncol+c];
                }                
                C.elem[r*C.ncol+c] =  serv; 
            }
        }
        return C;
    }
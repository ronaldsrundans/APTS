#include <iostream>

using namespace std;
void mult(double *A,double *B,double *C,int n)
{
    int i=0;
    int j=0;
    int k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {


        }

    }



}
int main()
{

    double *A;
    double *B;
    double *C;
    int n=3;
    int l=0;
    l=n*n;
    A=new double [l];
    B=new double [l];
    C=new double [l];
    mult(A,B,C,n);
    delete [] A;
    delete [] B;
    delete [] C;
    cout << "Hello world!" << endl;
    return 0;
}

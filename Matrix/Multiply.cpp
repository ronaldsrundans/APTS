#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("in.txt",ios::in);
    int n,t;
    f>>n;
    f>>t;
    int i,j,k,l;
    l=n*n;
    double **A=new double *[n];
    double **B=new double* [n];
    double **C=new double *[n];


    for(i=0;i<n;i++)
    {
        A[i]=new double[n];
        B[i]=new double[n];
        C[i]=new double[n];
    }
    /*while(f)
    {
            cout<<t<<endl;
            f>>t;
    }
*/
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j]=t;
            f>>t;
        }
    }
        for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            B[i][j]=t;
            f>>t;
        }
    }


    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             for(k=0;k<n;k++)
             {
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
             }
        }
    }
//    mult(A,B,C,n);
 for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<C[i][j];
        }
        cout<<endl;
    }
 for(i=0;i<n;i++)
    {
        delete [] A[i];
        delete [] B[i];
        delete [] C[i];
    }
    delete [] A;
    delete [] B;
    delete [] C;

    f.close();
   // cout << "Hello world!" << endl;
    return 0;
}

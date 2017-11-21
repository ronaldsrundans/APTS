
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("in3.txt",ios::in);
    int r1,r2,c1,c2;
    double n,t,sum;
    int i,j,k,l;
    f>>r1;
    f>>c1;
    double **A=new double *[r1];
    for(i=0;i<r1;i++)
    {
        A[i]=new double[c1];
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            f>>t;
            A[i][j]=t;
        }
    }
    f>>r2;
    f>>c2;
    double **B=new double *[r2];
    for(i=0;i<r2;i++)
    {
        B[i]=new double[c2];
    }
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            f>>t;
            B[i][j]=t;
        }
    }
     f.close();
    double **C=new double *[r1];
    for(i=0;i<r1;i++)
    {
        C[i]=new double[c2];
    }
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            C[i][j]=0;
        }
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
             for(k=0;k<r2;k++)
             {
                C[i][j]=C[i][j]+A[i][k]*B[k][j];
             }
        }
    }
 for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
 for(i=0;i<r1;i++)
    {
       delete [] A[i];
       delete [] C[i];
    }
    for(i=0;i<r2;i++)
    {
        delete [] B[i];
    }
    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}

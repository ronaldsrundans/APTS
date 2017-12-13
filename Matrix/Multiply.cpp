#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int r1,r2,c1,c2,i,j,k;
    float t;
    f>>r1;
    f>>c1;
    float **A=new float *[r1];
    for(i=0;i<r1;i++)
    {
        A[i]=new float[c1];
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
    float **B=new float *[r2];
    for(i=0;i<r2;i++)
    {
        B[i]=new float[c2];
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
    float **C=new float *[r1];
    for(i=0;i<r1;i++)
    {
        C[i]=new float[c2];
    }

    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            t=0;
             for(k=0;k<r2;k++)
             {
                t=t+A[i][k]*B[k][j];
             }
            C[i][j]=t;
        }
    }
 for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
           // cout<<C[i][j]<<" ";
             fout<<C[i][j]<<" ";
        }
       // cout<<endl;
        fout<<endl;
    }
     fout.close();
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

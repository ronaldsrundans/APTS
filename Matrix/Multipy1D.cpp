#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("in.txt",ios::in);
    fstream fout("out.txt",ios::out);
    int r1,r2,c1,c2,l1,l2,l3,i,j,k;
    float t;
    f>>r1;
    f>>c1;
    l1=c1*r1;
    float *A=new float [l1];
    for(i=0;i<l1;i++)
    {
            f>>t;
            A[i]=t;
    }
    f>>r2;
    f>>c2;
    l2=r2*c2;
    float *B=new float [l2];
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            f>>t;
            B[i+j*r2]=t;
        }
    }
     f.close();
     l3=r1*c2;
    float *C=new float [l3];
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c2;j++)
        {
            t=0;
             for(k=0;k<r2;k++)
             {
                t=t+A[i*r1+k]*B[j*c2+k];
             }
             C[i*r1+j]=t;
        }
    }
 for(i=0;i<c2;i++)
    {
        for(j=0;j<r1;j++)
        {
           // cout<<C[i*c2+j]<<" ";
            fout<<C[i*c2+j]<<" ";
        }
       // cout<<endl;
        fout<<endl;
    }
    fout.close();
    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}

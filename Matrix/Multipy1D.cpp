
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream f("in.txt",ios::in);
    int r1,r2,c1,c2,l1,l2,l3;
    double n,t,sum, tmp;
    int i,j,k,l;
    f>>r1;
    f>>c1;
    l1=c1*r1;
    double *A=new double [l1];
    /*for(i=0;i<r1;i++)
    {
        A[i]=new double[c1];
    }*/
    for(i=0;i<l1;i++)
    {
        //for(j=0;j<c1;j++)
      //  {
            f>>t;
            A[i]=t;
       // }
    }
    f>>r2;
    f>>c2;
    l2=r2*c2;
    //cout<<"c2"<<c2<<endl;
    double *B=new double [l2];
    /*for(i=0;i<r2;i++)
    {
        B[i]=new double[c2];
    }*/
    for(i=0;i<r2;i++)
    {
        for(j=0;j<c2;j++)
        {
            f>>t;
            B[i+j*r2]=t;
            //cout<< i+j*r2<<" "<<i<<" "<<j<<endl;
          // cout<<endl;
            //coutendl;
        }
    }
     f.close();
     l3=r1*c2;
    double *C=new double [l3];
    /*for(i=0;i<r1;i++)
    {
        C[i]=new double[c2];
    }*/
    for(i=0;i<l3;i++)
    {
       // for(j=0;j<c2;j++)
      //  {
            C[i]=0;
       // }
    }





tmp=0;

    for(i=0;i<r1;i++)
    {

        for(j=0;j<c2;j++)
        {

             for(k=0;k<r2;k++)
             {
                tmp=tmp+A[i*r1+k]*B[j*c2+k];
cout<<"A*B="<<A[i*r1+k]<<"*"<<B[j*c2+k]<<"="<<tmp<<endl;
             }
             cout<<"tmp="<<tmp<<endl;
             C[i*r1+j]=tmp;
             tmp=0;
        }
    }
 for(i=0;i<c2;i++)
    {
        for(j=0;j<r1;j++)
        {
            cout<<C[i*c2+j]<<" ";
        }
        cout<<endl;
    }
 /*for(i=0;i<r1;i++)
    {
       delete [] A[i];
       delete [] C[i];
    }
    for(i=0;i<r2;i++)
    {
        delete [] B[i];
    }*/
    delete [] A;
    delete [] B;
    delete [] C;
    return 0;
}


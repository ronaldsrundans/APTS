#include <iostream>
#include <fstream>
using namespace std;


int main ()
{
    char c=0;
    int i;
    int r=0;
    fstream fin("in1.txt", ios::in);
    int p=0;
    int n=0;
    int pm=0;
    int nm=0;
    int px=0;
    int py=0;
    int nx=0;
    int ny=0;
    int p_f=0;
    int n_f=0;
    int n_min=0;
    int p_min=0;
    int *arr_p;
    int *arr_n;
    int *p_id;
    int *n_id;
    int *p_out;
    int *n_out;
    fin>>i;
    p=i;
    p_f=i;
    arr_p=new int[p];
    p_id=new int[p];
    p_out=new int[p];
    for(int t=0;t<p;t++)
    {
        p_out[t]=0;
    }
    fin>>i;
    n=i;
    n_f=i;
    arr_n=new int[n];
    n_id=new int[n];
    n_out=new int[n];
    for(int t=0;t<n;t++)
    {
        n_out[t]=0;
    }
    fin>>i;
    pm=i;
    for(int t=0;t<p;t++)
    {
        arr_p[t]=pm;
    }
    for(int t=0;t<p;t++)
    {
        p_id[t]=0;
    }
    fin>>i;
    nm=i;
    for(int t=0;t<n;t++)
    {
        arr_n[t]=nm;
    }
    for(int t=0;t<n;t++)
    {
        n_id[t]=0;
    }

    //cout<<"p="<<p<<endl;///pilsonu muitnieku masiva garums
    //cout<<"n="<<n<<endl;///neilsonu muitnieku masiva garums
   // cout<<"p="<<pm<<endl;///pilsonu muitnieku laiks
    //cout<<"n="<<nm<<endl;///nepilsonu muitnieku laiks
    fin>>i;
    fin.clear();
    fin.get(c);
     //cout<<c;
    while(c!='X')
    {
        if(c=='T')///nomaina attiecigo tipu
        {
            fin.get(c);
            fin.get(c);
            if(c=='P')
            {
                fin.get(c);
                fin>>i;
                cout<<i<<endl;
                px=i-1;
                fin>>i;
                cout<<i<<endl;
                py=i;
                arr_p[px]=py;
            }
            else
            {
                fin.get(c);
                fin>>i;
                cout<<i<<endl;
                nx=i-1;
                fin>>i;
                cout<<i<<endl;
                ny=i;
                arr_n[nx]=ny;

            }
        }
       else
       {
           if(c=='P')///ja atnak pilsonis
           {
               fin.get(c);
                fin>>i;///panem ID
               cout<<i<<endl;
               if(p_f>0)
               {
                    int p_r=0;
                  if(p_min==0)
                  {
                      cout<<"p_f>0"<<endl;
                  }
                  //while(p_r<p)
                 // {

                  //}
               }
           }
           else if(c=='N')
           {
               fin.get(c);
                fin>>i;
               cout<<i<<endl;
               if(n_f>0)
               {
                  cout<<"n_f>0"<<endl;
               }
           }
       }
       fin.get(c);
    }
    cout<<"masivu izdrukas"<<endl;
    ///izdrukas
    cout<<"muitnieki"<<endl;
    for(int t=0;t<p;t++)
    {
        cout<<arr_p[t]<<endl;
    }
    cout<<endl;
    for(int t=0;t<n;t++)
    {
        cout<<arr_n[t]<<endl;
    }
    cout<<"ID"<<endl;
    for(int t=0;t<p;t++)
    {
        cout<<p_id[t]<<endl;
    }
    cout<<endl;
    for(int t=0;t<n;t++)
    {
        cout<<n_id[t]<<endl;
    }
    cout<<"out"<<endl;
    for(int t=0;t<p;t++)
    {
        cout<<p_out[t]<<endl;
    }
    cout<<endl;
    for(int t=0;t<n;t++)
    {
        cout<<n_out[t]<<endl;
    }
    delete [] arr_p;
    delete [] arr_p;
    delete [] p_out;
    delete [] n_out;
    delete [] p_id;
    delete [] n_id;
    fin.get(c);
    fin.close();
    return 0;
}

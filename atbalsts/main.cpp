#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int find_min(int& min_v,int *arr )
{
    int i=0;
    while(arr[i]>(-2))
    {
        if(arr[i]>(-1))
        {
            if(arr[i]<min_v)
            {
                min_v=arr[i];
            };
        }
        i++;

    }
    return 1;
}
void add(int *arr, int n, int pos)
{
    arr[pos+1]=-2;
    arr[pos]=n;
}
void delete_elem(int *arr, int pos)
{
   // arr[pos+1]=-2;
    arr[pos]=-1;
}

int main ()
{
        char carr[7];
        carr[0]=0;
        int i=0;
        int lucky=0;
        int line=0;
        int l_count=0;
        int money=0;
        int romey=0;
        int in_line=0;
        int reg_sk=0;
        int min_v=2000;
        int position=0;
        int r_sk;
        char c;
        fstream fin("in3.txt", ios::in);
        fstream fout("out.txt", ios::out);
        fin.get(c);
        while(c>='0'and c<='9')//laimigie
        {
           lucky=(lucky*10+(int)c-'0');
            fin.get(c);
        }
        int *arr=new int[lucky+1];
        arr[0]=-2;
        fin.get(c);
        i=0;
      while(c>='0'and c<='9')///rinda
        {
            line=(line*10+(int)c-'0');
            fin.get(c);
        }
        fin.get(c);
        cout<<" lucky="<<lucky<<endl;
        cout<<" line="<<line<<endl;
        while(!fin.eof())
        {
            if(c=='M')
            {    fin.get(c);///izlaizatstarpi
                 fin.get(c);
                    position=0;

                 while(c>='0'and c<='9')///rinda
                {
                    money=(money*10+(int)c-'0');
                    fin.get(c);
                }
                 //cout<<"money="<<money<<endl;
                if(in_line>0)in_line--;
               // cout<<in_line<<endl;
                int j=0;
                while(arr[j]!=-2)///kamer nav beigas
                {
                    if(arr[j]==min_v)///ja atrod mazako
                    {
                        position=j+1;
                        delete_elem(arr, j);
                        break;
                    }
                    j++;
                }
                //min_v=2000;
                find_min(min_v, arr);

               // cout<<"minv=="<<min_v<<endl;
                cout<<"M="<<position<<" "<<money<<endl;
               // cout<<"minv=="<<min_v<<endl;
            }
            money=0;
            if(c=='R')///registresana
            {


                 fin.get(c);///izlaiz atstarpi
                 fin.get(c);
                while(c!='\n')///rinda
                {
                    romey=(romey*10+c-'0');
                    fin.get(c);
                }
            if(reg_sk<lucky && romey<2000)
                {
                    add(arr, romey, reg_sk);
                        min_v=romey;
                    find_min(min_v, arr);

               // cout<<"min="<<min_v<<endl;
                if(in_line<line)
                {
                    reg_sk++;///pieregisto skaits
                    in_line++;///cik tagad ir rinda
                    //cout<<"In line="<<in_line<<" reg_sk="<<reg_sk<<endl;
                    cout<<"R="<<reg_sk<<" "<<romey<<endl;
                    find_min(min_v,arr);

                }
                else cout<<"R="<<0<<" "<<romey<<endl;///neregistre

               // else{}
               // cout<<"reg="<<reg_sk<<endl;

            }
            else
            {
                cout<<"R="<<0<<" "<<romey<<endl;}///neregistre
            romey=0;
            }


            fin.get(c);
        }
        cout<<"arr saturs"<<endl;
        for(int t=0;t<reg_sk; t++)
        {
            cout<<"arr["<<t+1<<"]="<<arr[t]<<endl;
        }
        delete[] arr;
        fin.close();
        fout.close();

    return 0;
}

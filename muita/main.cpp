
#include <iostream>
#include <fstream>


using namespace std;
int sum(char &c, int &summa)
{
        int n=0;
        n=((int)c-(int)'0');
        summa=(summa*10+n);
        return 0;
}
void fill_arr(int *arr, int n, int Size)
{
    for(int i=0;i<Size;i++)
        {
            arr[i]=n;
        }
};
void print_arr(int *arr, int n)
{
      for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<endl;
        }
};
void free_spot(int *arr, int n, int &num)
{

  for(int i=0; i<n;i++)
  {
      if(arr[i]==0)
    {
      num=i;
      break;
    }
  }


};
void change_arr(int *arr, int n, int pos)
{
     arr[pos]=n;
};

int main ()
{
        int i=0;
        int p_muitnieki=0;
        int n_muitnieki=0;
        int n_laiks=0;
        int p_laiks=0;
        int p_m=0;
        int n_m=0;
       // int pos_n=0;
       // int pos_p=0;
        int p_sum=0;
        int n_sum=0;
        int p_r=0;
        int n_r=0;
      //  int r_sk;
        char c=0;

        fstream fin("in1.txt", ios::in);
        fstream fout("out.txt", ios::out);
        fin.get(c);
        while(c>='0'and c<='9')///p_muitnieki
        {
           sum(c, p_muitnieki);
            fin.get(c);
        }

        fin.get(c);
        while(c>='0'and c<='9')///n_muitnieki
        {
            sum(c, n_muitnieki);
            fin.get(c);
        }
        int *arr_p=new int[p_muitnieki];///muitnieku darba laiki
        int *arr_n=new int[n_muitnieki];
        int *p_time=new int[p_muitnieki];///iecelotaju laiki pie muitniekiem
        int *n_time=new int[n_muitnieki];
        fin.get(c);
        while(c>='0'and c<='9')///n_laiks
        {
            sum(c, p_laiks);
            fin.get(c);
        }
        cout<<"p_laiks="<<p_laiks<<endl;
        fin.get(c);
        while(c>='0'and c<='9')///p_laiks
        {
            sum(c, n_laiks);
            fin.get(c);
            if(c=='\n')break;
        }
        cout<<"n_laiks="<<n_laiks<<endl;
        fill_arr(arr_p,p_laiks, p_muitnieki);
        fill_arr(arr_n,n_laiks, n_muitnieki);
      //   print_arr(arr_p, p_muitnieki);
        fill_arr(n_time,0, n_muitnieki);
        fill_arr(p_time,0, p_muitnieki);
        p_laiks=0;
        n_laiks=0;
        fin.get(c);
        print_arr(arr_p, p_muitnieki);
        print_arr(arr_n, n_muitnieki);
        while(fin)
        {
           if(c=='T')
            {
            fin.get(c);
            fin.get(c);
            if(c=='P')
            {
                fin.get(c);
                fin.get(c);
                while(c>='0'and c<='9')///p_m(atsevisks)muitnieks
                {
                    sum(c, p_m);
                        fin.get(c);
                }
                cout<<"P nr="<<p_m<<endl;
                fin.get(c);
                while(c>='0'and c<='9')///p_laiks konkretam muitniekam
                {
                    sum(c, p_laiks);
                        fin.get(c);
                }
                cout<<"P laiks="<<p_laiks<<endl;
                change_arr(arr_p,p_laiks, p_m-1);
               // p_m=0;
                p_laiks=0;
            }
            else  if(c=='N')
            {
                fin.get(c);
                fin.get(c);
                while(c>='0'and c<='9')///p_laiks kadam muitniekam
                {
                    sum(c, n_m);
                        fin.get(c);
                }
                fin.get(c);
               // cout<<"N nr="<<n_m<<endl;
                while(c>='0'and c<='9')///p_laiks kadam muitniekam
                {
                    sum(c, n_laiks);
                        fin.get(c);
                }
              //  cout<<"N laiks="<<n_laiks<<endl;
                change_arr(arr_n,n_laiks, n_m-1);
                n_m=0;
                n_laiks=0;
                }
            }///seit beidzas T (type)
               // cout<<"arr_p"<<endl;
           //     print_arr(arr_p, p_muitnieki);
           if(c!='T')
            {
                if(c=='P')
                {
                fin.get(c);
                fin.get(c);
                while(c>='0'and c<='9')///p_laiks konkretam iecelotajam
                {
                    sum(c, p_laiks);
                        fin.get(c);
                }
              //  cout<<"P ="<<p_laiks<<endl;
                    int pos_p=-1;
                //int pos_p=-1;
 //cout<<"pos ="<<pos_p<<endl;
                free_spot(p_time, p_muitnieki, pos_p);

               // cout<<"pos ="<<pos_p<<endl;
                if(pos_p!=-1)///ja brivs muitnieks
                {
                    p_laiks=p_laiks+arr_p[pos_p];
                  //   cout<<"P new ="<<p_laiks<<endl;
                    change_arr(p_time,p_laiks, pos_p);
                }


                   // p_r++;

                   // p_m=-1;
                    p_laiks=0;
                }///pilsonis N
                else if(c=='N')
                {
                fin.get(c);
                fin.get(c);
                while(c>='0'and c<='9')///p_laiks konkretam iecelotajam
                {
                    sum(c, n_laiks);
                        fin.get(c);
                }
             //   cout<<"N ="<<n_laiks<<endl;


                    //n_m=0;
                    n_laiks=0;
                }

            }

            else if(c=='X')
            {
                    cout<<"nothing"<<endl;
            }




            fin.get(c);
        }
        print_arr(arr_p, p_muitnieki);
  print_arr(arr_n, n_muitnieki);
        delete[] arr_p;
        delete[] arr_n;
        fin.close();
        fout.close();

    return 0;
}

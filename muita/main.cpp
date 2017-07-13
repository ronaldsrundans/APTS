#include <iostream>
#include <fstream>

using namespace std;

struct elem
{
    int n;
    elem *next;
};
void add_element (elem*&first, elem*&last, int i)///jauna elementa pievienosana saraksta gala
{
    elem *p = new elem;
    p->n = i;
    p->next = NULL;
    if (first == NULL) first = p;///ja saraksts ir tukss, tad nomaina pirmo elementu
    else last->next = p;///ja saraksts nav tukss, tad pieliek gala
    last = p;
};

void print_list (elem *first)///saraksta izdrukasana
{
    for (elem *p = first; p!=NULL; p=p->next)
    {
        cout << p->n << endl;
    };
};

void delete_list (elem*&first)///saraksta dzesana
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
};
void delete_first (elem*&first)///saraksta dzesana
{
    elem *p = first;
    first = first->next;
    delete p;
};
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
int find_min(int *arr, int n, int num)
{
    int m=0;
    for(int i=0; i<n;i++)
    {
      if(arr[i]>0&&num==m)
        {
          //  cout<<"ieraksta"<<endl;
            m=arr[i];
         //   cout<<"m="<<m<<endl;
        }
     if(arr[i]<m && arr[i]!=0)
        {
            m=arr[i];
            return m;
        }
  }
  return m;
}
void change_arr(int *arr, int n, int pos)
{
     arr[pos]=n;
};
void get_out(int *arr_id, int *arr_time, int pos)
{
    cout<<arr_id[pos]<<" "<<arr_time[pos]<<endl;
    change_arr(arr_id, 0, pos);
    change_arr(arr_time, 0, pos);
}


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
        int p_tmp=0;
        int n_tmp=0;
        int p_free=0;
        int n_free=0;
        int n_space=0;
         int p_space=0;

      //  int r_sk;
        char c=0;
        elem *first_p=NULL, *last_p=NULL, *first_n=NULL, *last_n=NULL;
        fstream fin("in3.txt", ios::in);
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
        n_free=n_muitnieki;
        p_free=p_muitnieki;
        int *arr_p=new int[p_muitnieki];///muitnieku darba laiki
        int *arr_n=new int[n_muitnieki];
        int *id_p=new int[p_muitnieki];
        int *id_n=new int[n_muitnieki];
        int *p_time=new int[p_muitnieki];///iecelotaju laiki pie muitniekiem
        int *n_time=new int[n_muitnieki];
        fin.get(c);
        while(c>='0'and c<='9')///n_laiks
        {
            sum(c, p_laiks);
            fin.get(c);
        }
        //cout<<"p_laiks="<<p_laiks<<endl;
        fin.get(c);
        while(c>='0'and c<='9')///p_laiks
        {
            sum(c, n_laiks);
            fin.get(c);
            if(c=='\n')break;
        }
      //  cout<<"n_laiks="<<n_laiks<<endl;
        fill_arr(arr_p,p_laiks, p_muitnieki);///darba laiki
        fill_arr(arr_n,n_laiks, n_muitnieki);
        fill_arr(id_n,0, n_muitnieki);///id nr
        fill_arr(id_p,0, p_muitnieki);
      //   print_arr(arr_p, p_muitnieki);
        fill_arr(n_time,0, n_muitnieki);///kopejais laiks
        fill_arr(p_time,0, p_muitnieki);
        p_laiks=0;
        n_laiks=0;
        fin.get(c);
      //  print_arr(arr_p, p_muitnieki);
      //  print_arr(arr_n, n_muitnieki);
        while(fin)///turpina ar type un sarakstiem
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
                //cout<<"P nr="<<p_m<<endl;
                fin.get(c);
                while(c>='0'and c<='9')///p_laiks konkretam muitniekam
                {
                    sum(c, p_laiks);
                        fin.get(c);
                }
                //cout<<"P laiks="<<p_laiks<<endl;
                change_arr(arr_p,p_laiks, p_m-1);
                p_m=0;
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
              //  cout<<"P old ="<<p_laiks<<endl;
                add_element (first_p, last_p,p_laiks);///vertibas pievienosana saistitajam sarakstam

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

               // cout<<"N ="<<n_laiks<<endl;

                add_element (first_n, last_n,n_laiks);
                    //n_m=0;
                    n_laiks=0;
                }

            }///izveidoti saraksti

            if(c=='X')
            {
                if(first_n==NULL && first_p==NULL)
                {
                    cout<<"nothing"<<endl;
                }
                else///parstaigasim sarakstus
                {
                    elem *zp = first_p;
                    int last_p=0;

                    while (zp!=NULL)///kamer ir iebrauceji
                    {
                        if(zp!=NULL)
                        {
                            int min_p=0;
                            min_p=find_min(p_time,p_muitnieki, min_p);
                            int delay_p=0;///kavejas
                            p_tmp=zp->n;
                            if(last_p>p_tmp)
                                {
                                    delay_p=last_p-p_tmp;
                                }

                          //  cout <<"min_p="<<min_p<< endl;
                            if(p_free!=0)
                            {
                                free_spot(id_p, p_muitnieki,p_space);///atrod vinu
                                change_arr(id_p,p_tmp,p_space);///ienem vietu

                                p_tmp=delay_p+p_tmp+arr_p[p_space];///apr laiku
                                //cout <<"p_tmp="<<p_tmp<< endl;
                                change_arr(p_time,p_tmp,p_space);///saglaba laiku
                                p_free--;///mazak brivo vietu
                                zp=zp->next;
                                delete_first(first_p);
                            }
                            else
                            {
                                for(int j=0;j<p_muitnieki;j++)
                                {
                                    if(min_p==p_time[j])
                                    {
                                        last_p=p_time[j];
                                        get_out(id_p, p_time,j);
                                        p_free++;
                                    }
                                }
                            }
                        }
                    }

                    while(zp==NULL&&p_free!=p_muitnieki)//&&min_p!=0)
                    {
                    int min_p=0;
                    min_p=find_min(p_time,p_muitnieki, min_p);

                   // cout <<"min_p="<<min_p<< endl;
                            for(int j=0;j<p_muitnieki;j++)
                                {
                                    if(min_p==p_time[j])
                                    {
                                        get_out(id_p, p_time,j);
                                        p_free++;
                                    }
                                }
                                min_p=find_min(p_time,p_muitnieki, min_p);

                    }


                }

            }

            fin.get(c);
        }
     //   print_arr(arr_p, p_muitnieki);
 // print_arr(arr_n, n_muitnieki);
  /*cout << "id p=" << endl;
 print_arr(id_p, p_muitnieki);
   cout << "id n=" << endl;
 print_arr(id_n, n_muitnieki);
  cout << "n time=" << endl;
 print_arr(n_time, n_muitnieki);
   cout << "p time=" << endl;
 print_arr(p_time, p_muitnieki);*/
 cout << "list p" << endl;
     print_list (first_p);
      cout << "list n" << endl;
      print_list (first_n);
     delete_list(first_p);
      delete_list(first_n);
        delete[] arr_p;
        delete[] arr_n;
        delete[] p_time;
        delete[] n_time;
        delete[] id_p;
        delete[] id_n;
        fin.close();
        fout.close();

    return 0;
}

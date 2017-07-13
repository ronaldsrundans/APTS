#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct elem
{
    char num[255];
    elem *next;
};
void add_element (elem*&first, elem*&last, char* c)
{
    elem *p = new elem;
    elem *r = new elem;
    r->next = NULL;
    int i;
    for(i=0;c[i]!=0;i++)
    {
         p->num[i] = c[i];
    }
    p->num[i] = 0;
    p->next = NULL;
    if (first == NULL)
    {
        first = p;
        last = p;
    }
    else
    {
        for(elem *q = first; q!=NULL; q=q->next)
        {
            if(p->num[0]>q->num[0])
            {

                if(r->next!=NULL)
                {
                     if(q==first)
                    {
                        p->next=q->next;
                        q->next=p;
                    }
                    else if(q==last)
                    {
                        q->next=p;
                        last=p;
                    }
                }
                if(q->next==NULL)
                {
                    p->next=q->next;
                    q->next=p;
                     last=p;
                }


            }
            else if(p->num[0]==q->num[0]&& p!=q)
            {
                p->next=q;
                r->next=p;
                if(q==first)
                {
                    first=p;
                }
                break;
            }
            else if(p->num[0]<q->num[0])
            {
                //cout<<"check="<<p->num<<" q="<<q->num;


                if(q==first)
                  {
                       first=p;
                      p->next=q;
                        break;
                  }
                  else
                  {
                      r->next=p;
                       p->next=q;
                       break;
                  }
            }
                r=q;
    }}
};

void print_list (elem *first, char &c)
{
    if(first==NULL)
    {
        cout<<"nothing";
    }
    for (elem *p = first; p!=NULL; p=p->next)
    {
        for(int i=0;p->num[i]!=0;i++)
        {
            c=p->num[i];
        }
       // c=" ";
    };

};

void delete_list (elem*&first)
{
    elem *p = first;
    while (p!=NULL)
    {
        first = first->next;
        delete p;
        p = first;
    };
};
int main ()
{
        char carr[255];
        carr[0]=0;
        elem *first1=NULL, *last1=NULL, *p,*q;
        int i=0;
        char c;
        char c2;
        char n_carr[]="nothing";
        fstream fin("in3.txt", ios::in);
        fstream fout("out.txt", ios::out);
        fin.get(c);
        while(!fin.eof())
        {
            if(c==' 'or c=='\n')
            {
                i=0;
                if(carr[0]!=0)
                {
                    add_element (first1, last1, carr);
                    carr[0]=0;
                }
            }
            else
            {
                carr[i]=c;
                i++;
                carr[i]=0;
            }
            fin.get(c);
        }
        if(first1==NULL)
        {
          for(int z=0;n_carr[z]!=0;z++)
          {
              cout<<n_carr[z];
          }
        }
        else
        {
           for (elem *z = first1; z!=NULL; z=z->next)
            {
            for(int k=0;z->num[k]!=0;k++)
            {
                c2=z->num[k];
                fout.put(c2);
                cout<<c2;
            }
            c2=' ';
            cout<<c2;
            fout.put(c2);
            }
        }


       //print_list (first1,c2);
 //

    fin.close();
      fout.close();
       // cout<<





        delete_list (first1);

    return 0;
}

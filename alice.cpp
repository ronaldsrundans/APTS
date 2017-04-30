#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int i=0;
    int size1=10000;
    int n=0;
    int n2=0;
    int num=0;
    int *arr=new int[size1];///children array
    int *arr2=new int[size1];///parent array
    int *arr3=new int[size1];///parent array
    int *arr4=new int[size1];///parent array
    char c;
    fstream fin("alise.i8", ios::in);
   fin.get(c);

   while(fin)
   {
//cout<<c<<endl;
   while(c!=' '&&c!='\n')///pirmais rindas skaitlis
   {
       i=i*10+(int)c-'0';
       fin.get(c);
   }

   if(i==0)///ja rinda sakas ar 0
   {
       break;
   }
 /*  if(i==3)
   {
       cout<<"Parent i="<<i<<endl;
   }*/

   /////parent
   arr2[n2]=i;
   n2++;
 // cout<<n2<<endl;

    i=0;
    num=0;
    //fin.get(c);
   while(c!='\n')///kamer nav rindas beigas
   {
       fin.get(c);
      /* if(c==' ')
        {
         fin.get(c);
       }*/
       //  cout<<"c="<<c<<endl;
        while(c!=' '&&c!='\n')///ielasa parejos masiva
        {
            i=i*10+(int)c-'0';
            fin.get(c);
        }

   if(i==0)///ja rinda sakas ar 0
   {
       break;
   }
    //   cout<<"*i="<<i<<endl;
      //  if(n<size1)///kamer vieta masiva
       // {
           // cout<<"n="<<n<<" i="<<i<<endl;
            arr[n]=i;
            n++;
       // }

        i=0;
        num++;
   }


    arr3[n2-1]=num;///children count for parent

  //  cout<<"arr3="<<num<<endl;
    arr4[n2-1]=n-1;///right children pos
//cout<<"arr4="<<n-1<<endl;

  //  cout<<"n2="<<n2<<endl;
    fin.get(c);
   }
    fin.close();

     //while
    //int size3=n2/3-1;

  //  cout<<"n2="<<n2<<endl;

    int *arr5=new int[n2];///
     for(int t=0;t<n2;t++)///vecaki
    {
        bool bol=0;
            //cout<<arr2[t];
            for(int t2=0;t2<n;t2++)
            {
                if(arr2[t]==arr[t2])
                {
                    bol=1;
                    break;
                }
            }
            if(bol==0)
            {
             //   cout<<"sakne= "<<arr2[t]<<endl;
              //  cout<<"t="<<t<<endl;
                arr5[0]=t;
                break;
            }
    }
  //  cout<<"arr5="<<arr5[0]<<endl;

      //cout<<"arr2="<<arr2[pos]<<endl;
      int p=0;
      int rinda=1;
while(p<n2)
{
        rinda--;
        int next=0;
        //cout<<"p="<<p<<endl;
       // cout<<arr5[p]<<endl;///vajadzes p
        int pos=arr5[p];
        int wait;
       // cout<<"parent="
        cout<<arr2[pos];
       // cout<<"child=";
           for(int t=arr4[pos];t>arr4[pos]-arr3[pos];t--)
            {
                 cout<<" "<<arr[t];///child izdruka
                 for(int z=0;z<n2;z++)
                 {
                     wait=0;
                     if(arr2[z]==arr[t])
                     {
                     //    cout<<"yes="<<arr[t]<<endl;
                      //   cout<<"rinda="<<rinda<<endl;


                         wait=rinda+next;
                       //  cout<<"wait="<<wait<<endl;
                       //  cout<<"arr wait"<<arr5[wait]<<endl;
                         while(wait>0)
                         {
                             arr5[wait+1+p]=arr5[wait+p];
                             wait--;
                         }
                         next++;
                        //  cout<<"next="<<next<<endl;
                         arr5[p+next]=z;
                      //   cout<<"z pos="<<p+next<<" "<<z<<endl;
                        /* if(arr2[z]==8)
                         {
                             cout<<"Jabut 3="<<arr5[p+next+1]<<endl;
                         }*/


                         //

                     }

                 }
            }
            cout<<endl;

            rinda=rinda+next;

          p++;
}
cout<<"0"<<endl;

///masivu izdruka
/*cout<<"mas izdruka:"<<endl;
    for(int z=0;z<n2;z++)
    {
         cout<<"Parents0:"<<endl;

        cout<<arr2[z]<<endl;

        cout<<"Children:"<<endl;
        for(int t=arr4[z];t>arr4[z]-arr3[z];t--)
        {
             cout<<arr[t]<<endl;
        }

    }*/


    delete[] arr;
    delete[]arr2;
    delete[] arr3;
    delete[] arr4;
    delete []arr5;
    return 0;
}

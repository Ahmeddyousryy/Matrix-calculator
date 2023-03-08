#include<iostream>
#include<cmath>
using namespace std;
void value_matrix_A(int m1[10][10],int r_m1,int c_m1);
void value_matrix_B(int m1[10][10],int r_m2,int c_m2);
long long determinant (int mat[10][10],int r_m,int c_m);
int main()
{
    cout<<"Please enter dimensions of Matrix A:"<<endl;
    int r_m1,c_m1,r_m2,c_m2,op;
    cin>>r_m1>>c_m1;
    cout<<"Please enter dimensions of Matrix B:"<<endl;
    cin>>r_m2>>c_m2;
    int m1[10][10], m2[10][10];
    value_matrix_A(m1,r_m1,c_m1);
    value_matrix_B(m2,r_m2,c_m2);


    do
    {
       cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
      cin>>op;

     if(op==1)
     {
         for(int r1=0;r1<r_m1;r1++)
         {
             for (int c1=0;c1<c_m1;c1++)
             {
                 cout<<m1[r1][c1]+m2[r1][c1]<<" ";
             }
             cout<<endl;
         }
     }
     else if(op==2)
     {
          for(int r2=0;r2<r_m1;r2++)
         {
             for (int c2=0;c2<c_m1;c2++)
             {
                 cout<<m1[r2][c2]-m2[r2][c2]<<" ";
             }
             cout<<endl;
         }
     }

         else if(op==3)
        {

            if(c_m1==r_m2)
            {

           int sum;
            for(int r=0;r<r_m1;r++)
            {

                for(int c=0;c<c_m2;c++)
                {
                    for(int i=0;i<c_m1;i++)
                    {
                        sum=sum+m1[r][i]*m2[i][c];
                    }
                      cout<<sum<<" "; sum=0;
                }
               cout<<endl;

            }
        }
        else
        {
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
        }
        }
        else if(op==4)
        {

        }


        else if(op==5)
        {
         if(r_m1==c_m1)
         {
          cout<<determinant(m1,r_m1,c_m1)<<endl;
         }
         else
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
        }
        else if(op==6)
        {
        if(r_m2==c_m2)
         {
          cout<<determinant(m2,r_m2,c_m2)<<endl;
         }
         else
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
        }


     else if(op==7)
     {
         cout<<"Thank you!"<<endl;
         break;

     }
    }while(op!=7);


}
void value_matrix_A(int m1[10][10],int r_m1,int c_m1)
{
    cout<<"Please enter values of Matrix A:"<<endl;
    for(int r=0;r<r_m1;r++)
    {
        for(int c=0;c<c_m1;c++)
        {

            cin>>m1[r][c];

        }

    }
}
    void value_matrix_B(int m1[10][10],int r_m2,int c_m2)
{
    cout<<"Please enter values of Matrix B:"<<endl;
    for(int r=0;r<r_m2;r++)
    {
        for(int c=0;c<c_m2;c++)
        {

            cin>>m1[r][c];

        }

    }

}
long long  determinant (int mat[10][10],int r_m,int c_m)
{
    int det=0;int mat_2[10][10];
    if(r_m ==2)
        return ((mat[0][0]*mat[1][1])-(mat[1][0]*mat[0][1]));
    else
    {

        for(int n=0;n<r_m;n++)
    {
        int m1=0;
        for(int r=1;r<r_m;r++)
        {  int m2=0;
            for(int c=0;c<c_m;c++)
            {
                if(n==c)
                    continue;

                mat_2[m1][m2]=mat[r][c];   m2++;
            }
            m1++;
        }
       det= det+(pow(-1,n)*mat[0][n]*determinant(mat_2,r_m-1,c_m-1));
    }

    } return det;

}


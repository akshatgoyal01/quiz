#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>

using namespace std;
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void starline();
int main()
{
    int no=0;
    bool har=0;
    int b=0;
    int ans[10];
    float score=0;
    int anshard[]={1,2,2,3,1};
    int anseasy[]={1,3,4,3,4};
    int ansmedium[]={};
    int ansin;
    int k=0,h=0,i=0,j=0,l=0,ea=0,q=0;
    float correct=0;
    char ch;
    string x[5];
    string y[5];
    string z[5];
    char s[100];
    ifstream medium;
    ifstream hard;
    ifstream easy;
    int e=0,m=0,n=0,main=0;
    starline();
    starline();
    gotoxy(50,2);
    cout<<"welcome to quiz \n";
    starline();
    starline();
    cout<<"THe rules are given \n Time given 30 seconds \n Total no of questions given 5 \n";
    cout<<"\n press 1 to continue\n";
    cin>>ch;

    while(main<5)
    {
        medium.open("medium.txt");
        for(int i=0;i<5;i++)
        {
            getline(medium,x[i],'\n');
            if(i==main)
                {
                    no++;
                    system("cls");
                    cout<<"Q="<<endl;
                    cout<<"("<<no<<")"<<x[i]<<endl;
                    cout<<"please select right option 1,2,3,4 :"<<endl;
                    cout<<ansin;
                }

        }
        if(ansin==ansmedium[main])
        {
            correct++;
            score=score+4;
            q=main-ea;
            h++;
            hard.open("hard.txt");
            for(int j=0;j<5;j++)
            {
                getline(hard,y[j],'\n');
            if(j==q)
                {
                    no++;
                    system("cls");
                    cout<<"Q="<<endl;
                    cout<<"("<<no<<")"<<x[i]<<endl;
                    cout<<"please select right option 1,2,3,4 :"<<endl;
                    cout<<ansin;
                    if(ansin==anshard[j])
                    {
                        correct++;
                        score=score+5;
                    }
                }
            }
        }
        else
        {
            ea++;
            l=main-h;
            easy.open("easy.txt");
             for(int k=0;k<5;k++)
            {
                getline(easy,z[k],'\n');
            if(k==l)
                {
                    no++;
                    system("cls");
                    cout<<"Q="<<endl;
                    cout<<"("<<no<<")"<<x[i]<<endl;
                    cout<<"please select right option 1,2,3,4 :"<<endl;
                    cout<<ansin;
                    if(ansin==anseasy[k])
                    {
                        correct++;
                        score=score+3;
                    }
                }
            }
        }
         main++;

         if(main==5)
         {
             if(ea<5 || h<5)
             {
                 while(ea<5)
                 {
                     easy.open("easy.txt");
                     for(int t=0;t<=5;t++)
                     {
                         getline(easy,z[t],'\n');
                         if(t==ea)
                         {
                             no++;
                             system("cls");
                             cout<<"Q="<<endl;
                             cout<<"("<<no<<")"<<x[i]<<endl;
                             cout<<"please select right option 1,2,3,4 :"<<endl;
                             cout<<ansin;
                             if(ansin==anseasy[t])
                             {
                                 correct++;
                                 score=score+3;
                             }
                         }
                     }
                     ea++;
                 }
                 if(ea==5)
                 {
                     while(h<=5)
                     {

                         hard.open("hard.txt");
                         for(int w=0;w<=5;w++)
                         {
                            getline(hard,y[w],'\n');
                            if(h==w)
                            {
                                no++;
                                system("cls");
                                cout<<"Q="<<endl;
                                cout<<"("<<no<<")"<<x[i]<<endl;
                                cout<<"please select right option 1,2,3,4 :"<<endl;
                                cout<<ansin;
                                if(ansin==anshard[w])
                                {
                                    correct++;
                                    score=score+5;
                                }
                            }
                         }
                         h++;
                         if(h==5)
                         {
                             break;
                         }
                     }
                 }

             }
         }
    }
    system("cls");
    cout<<"your scorein the quiz is = "<<score<<"out of 60";
    cout<<endl<<"you answered "<<correct<<" right";
    cout<<endl<<"you answered "<<(15-correct)<<" wrong";
    return 0;
}
void starline()
{
    for(int j=0;j<59;j++)
    {
        cout<<"*";

    }
    cout<<endl;
}

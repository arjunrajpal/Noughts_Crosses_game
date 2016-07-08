
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<curses.h>

using namespace std;

void ins(char a[][3],int r,int c)
{int i,j;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
a[i][j]='#';
}


void display(char a[][3],int r,int c)
{int i,j;
cout<<"\n";
for(i=0;i<r;i++)
{cout<<"\n";
for(j=0;j<c;j++)
cout<<a[i][j];
}}

void input(char a[][3],int r,int c)
{int i,j,n,m,p;
p=0;
do
{
cout<<"\n"<<"enter r :";
cin>>n;
cout<<"enter c :";
cin>>m;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
if((i==n-1)&&(j==m-1)&&(a[n-1][m-1]=='#'))
{a[i][j]='X';
p++;
break;}
if(p==0)
cout<<"wrong";
}
while(p==0);
display(a,r,c);}

void inp(char a[][3],int r,int c)
{int i,j,x,y,p;
p=0;
do
{
srand(time(NULL));
x=(rand()%(3));
y=(rand()%(3));
for(i=0;i<r;i++)
for(j=0;j<c;j++)
if((x==i)&&(y==j)&&(a[i][j]=='#'))
{a[x][y]='O';
p++;
break;}
}
while(p==0);
display(a,r,c);}

void comp(char a[][3],int r,int c,int k)
{int i,j,win;
win=0;
if(k==2)
{if((a[0][0]=='X')&&(a[0][1]=='X')&&(a[0][2]=='X'))
win=1;
else
if((a[1][0]=='X')&&(a[1][1]=='X')&&(a[1][2]=='X'))
win=1;
else
if((a[2][0]=='X')&&(a[2][1]=='X')&&(a[2][2]=='X'))
win=1;
else
if((a[0][0]=='X')&&(a[1][0]=='X')&&(a[2][0]=='X'))
win=1;
else
if((a[0][1]=='X')&&(a[1][1]=='X')&&(a[2][1]=='X'))
win=1;
else
if((a[0][2]=='X')&&(a[1][2]=='X')&&(a[2][2]=='X'))
win=1;
else
if((a[0][0]=='X')&&(a[1][1]=='X')&&(a[2][2]=='X'))
win=1;
else
if((a[0][2]=='X')&&(a[1][1]=='X')&&(a[2][0]=='X'))
win=1;}
else
if(k==-2)
{if((a[0][0]=='O')&&(a[0][1]=='O')&&(a[0][2]=='O'))
win=2;
else
if((a[1][0]=='O')&&(a[1][1]=='O')&&(a[1][2]=='O'))
win=2;
else
if((a[2][0]=='O')&&(a[2][1]=='O')&&(a[2][2]=='O'))
win=2;
else
if((a[0][0]=='O')&&(a[1][0]=='O')&&(a[2][0]=='O'))
win=2;
else
if((a[0][1]=='O')&&(a[1][1]=='O')&&(a[2][1]=='O'))
win=2;
else
if((a[0][2]=='O')&&(a[1][2]=='O')&&(a[2][2]=='O'))
win=2;
else
if((a[0][0]=='O')&&(a[1][1]=='O')&&(a[2][2]=='O'))
win=2;
else
if((a[0][2]=='O')&&(a[1][1]=='O')&&(a[2][0]=='O'))
win=2;}

if(win==1)
{cout<<"\nplayer 1\n";
    exit(0);}
else
if(win==2)
{cout<<"\nplayer 2\n";
    exit(0);}
}

void creat(char a[][3], int r, int c,int s)
{int i,j,k;
for(i=0;i<r;i++)
for(j=0;j<c;j++)
{if(s==1)
{input(a,r,c);
k=2;}
else
{inp(a,r,c);
k=-2;}
s=s*(-1);
comp(a,r,c,k);}
cout<<"\nDraw\n";
}

int main()
{int r,c,s,opt;
char a[3][3];
cout<<"enter rows :";
cin>>r;
cout<<"enter columns :";
cin>>c;
cout<<"Player first\n";
cout<<"Computer first\n";
cout<<"Enter choice(1/2) :";
cin>>opt;
if(opt==1)
s=1;
else
s=-1;
ins(a,r,c);
display(a,r,c);
creat(a,r,c,s);
    cin.get();
    return 1;
}

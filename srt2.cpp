# include<stdio.h>
# include<conio.h>
#include<iostream>

# define max1 10      //MAX PROCESSES
# define r 6          //MAX RESOURCES

using namespace std;

void sort(int st,int a[],int b[],int pr[],int np)
{       int i,j,t,p,z;
for(i=0;i<np-1;i++)
{
for(j=st;j<np-i-1;j++)
{
if(a[j]>a[j+1])
{
    t=a[j];      z=b[j];        p=pr[j];
    a[j]=a[j+1]; b[j]=b[j+1]; pr[j]=pr[j+1];
    a[j+1]=t;  b[j+1]=z; pr[j+1]=p;
}
}
}
}
/* SHEDULING ALGO-SHORTEST REMAINING TIME FIRST-PREEMTIVE */

void srtf()
{
int p1[max1],t1[max1],i,ch,np;
int arr[max1];
int tat[max1];
int wt[max1];
int resp[max1];
float rdelay[max1];
float atat;
float awt;
float aresp;
float ardelay;
int pgant[max1];
int tgant[max1];
int tex=0;
int j,k,count,c,a;
int trem[max1];

cout<<"\nEnter no. of processes  : ";
cin>>np;
for(i=0;i<np;i++)
{
cout<<"\nEnter the Process  :- ",i;
p1[i]=i;
cout<<"\nExecution time : ";
cin>>t1[i];
cout<<"\nArrival time   : ";
cin>>arr[i];
}
cout<<"\nPROCESSES\t\tEXECUTION TIME\t\tARRIVAL TIME";
for(i=0;i<np;i++)
{
cout<<"\n p "<<p1[i]<<"  \t\t\t"<<t1[i]<<"  \t\t\t"<<arr[i];
}
for(i=0;i<np;i++)
{ tex=tex+t1[i];
trem[i]=t1[i];
}
sort(0,arr,p1,t1,np);
tgant[0]=0;
j=0,k=0,count=0,c=0;
while(count!=tex)
{
if(j!=np)
{       j=k;
for(i=k;i<np;i++)
{
if(arr[i]<=count)
j++;
else
break;
}
if((j-k)>1)
sort(k,trem,p1,arr,j);
}
while(trem[k]==0)
k++;
c++;
pgant[c-1]=p1[k];
if(j==np)
a=trem[k];
else
{ if(trem[k] < (arr[j]-tgant[c-1]) )
a=trem[k];
else
a=arr[j]-tgant[c-1];
}
tgant[c]=tgant[c-1]+a;
count=tgant[c];
trem[k]=trem[k]-(tgant[c]-tgant[c-1]);
if(c>1)
{
if(pgant[c-1]==pgant[c-2])
{ tgant[c-1]=tgant[c];
c--;
}
}
}
sort(0,arr,p1,trem,np);


cout<<"\nGANTT CHART:- "<<endl;


for(i=0;i<c;i++){
	cout<<endl<<"process\t\tstart\tend"<<endl;
	for(j=0;j<c;j++){
		if(i>=j){
			cout<<"   P"<<pgant[j]<<"\t\t"<<tgant[j]<<"\t"<<tgant[j+1]<<endl;
		}
		else{
			cout<<"   P --"<<"\t\t"<<"--"<<"\t"<<"--"<<endl;
		}
	}
	

}


getch();
}

int main()
{
      srtf();
     getch();
}

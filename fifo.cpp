#include<iostream>
#include<conio.h> 
#include<stdio.h>
#include<math.h>
#include <cstdlib>

using namespace std;

char fr[12];

int main()
{
	int i,j;
	char page[12];
	int flag1[12],flag2[12],pf=0,frsize,top=0;
	
	cout<<"No. of memory blocks: ";
	cin>>frsize;
	
	printf("Enter Reference String [12 pages]: ");
	for(i=0;i<12;i++)
	{
		cin>>page[i];
	}
	
	for(i=0;i<12;i++)
	{
		fr[i]=-1;					//frame is empty
		flag1[i]=0;
		flag2[i]=0;
	}
	
	for(j=0;j<12;j++)
	{
		cout<<endl<<"Memory no.  Page no.\n";
		for(i=0;i<frsize;i++)
		{
			if(fr[i]==page[j])		//page exist in frame
			{	
				flag1[i]=1;
				flag2[i]=1;
				break;		
			}
		}
		if(flag1[i]==0)				//page doesn't exist frame
		{
			for(i=0;i<frsize;i++)	//traverse in each frame
			{
				if(fr[i]==-1)		//there is an empty frame
				{
					fr[i]=page[j];
					flag2[i]=1;
					pf++;
					break;
				}
			}
		}
		
		if(flag2[i]==0)			//no empty frame
		{
			fr[top]=page[j];	//replace top with page referred
			top++;				//ang sunod na number from the victim page is considered the oldest in the block
			pf++;				//increment page fault counter
			if(top>=frsize)		//if ang page naa sa last na mem block ang victim page balik na sa first na block ang order
			{
				top=0;
			}
		}
		
		for(i = 0; i < frsize; i++)
		{
			if(flag2[i]==0)
			{
				cout<<"   "<<i<<"\t\t"<<"empty"<<endl;
			}
			else
			{
	        	cout<<"   "<<i<<"\t\t"<<fr[i]<<endl;
	        }
   		}
	}
	
	cout<<endl<<endl<<"Number of page faults: "<<pf;
	getch();
}


#include<iostream>

#include "schedule.h"
using namespace std;
 
class priority : public schedule
{
    int tat[5],pr[5];
     float atat,awt;
public:
void computePri(int processes[],int bt[],int n,int pr[])
{
    int i,j,pos,temp;
     atat = 0.0;awt = 0.0;
     float total=0.0;
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
    }
 
    wt[0]=0;            //waiting time for first process is zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    awt=total/n;      //average waiting time
    total=0;
 
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
     }
      atat=total/n; 

      cout << "Process-ID\t\tPriority\t\tBT(s)\t\tWT(s)\t\tTAT(s)\n";

        for (int i = 0; i < n; i++)
        {
            cout << processes[i] << "\t\t\t" << pr[i] << "\t\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << endl;
        }

       cout << "awt=" << awt << " atat=" << atat; 
    }
    float sendAwt()
    {
        return awt;
    }
    float sendAtat()
    {
        return atat;
    }
};


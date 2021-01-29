// C++ program for implementation of FCFS
// *scheduling with different arrival time
#include <iostream>
#include<vector>
#include<algorithm>
#include<iterator>

#include "schedule.h"
#include "fcfs2.h"
#include "priority.h"
#include "sjf1.h"
using namespace std;
//base class to inherit the properties
class schedule
{
protected:
    int processess[5], bt[5], wt[5], at[5], pr[5], n = 5;
    float atat,awt;
public:
    void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]);
    void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
    void findavgTime(int processes[], int n, int bt[], int at[]);

    //sjf
    void computeSJF(int processes[], int at[], int n, int bt[]);

    //priority
    void computePri(int processes[],int bt[], int n, int pr[]);
    float sendAwt();
    float sendAtat();
};
class fcfs : public schedule
{
public:
    void findWaitingTime(int processes[], int n, int bt[],
                         int wt[], int at[])
    {
        int service_time[n];
        service_time[0] = 0;
        wt[0] = 0;

        // calculating waiting time
        for (int i = 1; i < n; i++) //*remember why its i = 1
        {
            // Add burst time of previous processes
            service_time[i] = service_time[i - 1] + bt[i - 1];

            // Find waiting time for current process =
            // sum - at[i]
            wt[i] = service_time[i] - at[i] + 1;

            // If waiting time for a process is in negative
            // that means it is already in the ready queue
            // before CPU becomes idle so its waiting time is 0
            if (wt[i] < 0)
                wt[i] = 0;
        }
    }

    // Function to calculate turn around time
    void findTurnAroundTime(int processes[], int n, int bt[],
                            int wt[], int tat[])
    {
        // Calculating turnaround time by adding bt[i] + wt[i]
        for (int i = 0; i < n; i++)
            tat[i] = bt[i] + wt[i];
    }

    // Function to calculate average waiting and turn-around
    // times.
    void findavgTime(int processes[], int n, int bt[], int at[])
    {
        int wt[n], tat[n];

        // Function to find waiting time of all processes
        findWaitingTime(processes, n, bt, wt, at);

        // Function to find turn around time for all processes
        findTurnAroundTime(processes, n, bt, wt, tat);

        // Display processes along with all details

cout << "Process-ID\tAT(s)\tBT(s)\tWT(s)\tTT(s)\tET(s)\n";
        int total_wt = 0, total_tat = 0;
        for (int i = 0; i < n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            int compl_time = tat[i] + at[i];
            cout << " " << i + 1 << "\t\t" << bt[i] << "\t\t"
                 << at[i] << "\t\t" << wt[i] << "\t\t "
                 << tat[i] << "\t\t " << compl_time << endl;

       
        
        }
        awt =  (float)total_wt / (float)n;
        atat = (float)total_tat / (float)n;
        cout << "Average waiting time = "
             << awt;
        cout << "\nAverage turn around time = "
             << atat;
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

class sjf : public schedule
{
    int e[5], tat[5];

public:
    void computeSJF(int processes[], int at[], int n, int bt[])
    {
        int temp, tt = 0, min, d, i, j;
        //average tat , avg wat , sum tat , sum wait time
        atat = 0;
        awt = 0;
        float stat = 0, swt = 0;
        //int at[n], bt[n], tat[n], wt[n];
        //bubble sort
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (bt[i] > bt[j])
                { //sort arrival time according to sorted burst time
                    temp = at[i];
                    at[i] = at[j];
                    at[j] = temp;

                    temp = bt[i];
                    bt[i] = bt[j];
                    bt[j] = temp;

                    temp = processes[i];
                    processes[i] = processes[j];
                    processes[j] = temp;
                }
            }
        }
        min = at[0]; //1
        for (i = 0; i < n; i++)
        {
            if (min > at[i])
            {
                min = at[i];
                d = i; //d = 0
            }
        }
        tt = min;          //tt = 1
        e[d] = tt + bt[d]; //1+5 = 6
        tt = e[d];         //tt = 6

        for (i = 0; i < n; i++)
        {
            if (at[i] != min) //false
            {
                e[i] = bt[i] + tt;
                tt = e[i];
            }
        }
        for (i = 0; i < n; i++)
        {

            tat[i] = e[i] - at[i];  //tat[0] = 6-1 = 5
            stat = stat + tat[i];   //
            wt[i] = tat[i] - bt[i]; //5-5 = 0
            if (wt[i] < 0)
            {
                wt[i] = 0;
            }
            swt = swt + wt[i];
        }
        //wt[1] = 1;
        atat = stat / n;
        awt = swt / n;

        cout << "Process-ID\t\tAT(s)\t\tBT(s)\t\tWT(s)\t\tTT(s)\t\tET(s)\n";

        for (int i = 0; i < n; i++)
        {
            cout << processes[i] << "\t\t" << at[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << e[i] << endl;
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


class priority : public schedule
{
    int tat[5],pr[5];
public:
void computePri(int processes[],int bt[],int n,int pr[])
{
    int i,j,pos,temp;
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

      cout << "Process-ID\t\tAT(s)\t\tBT(s)\t\tWT(s)\t\tTT(s)\t\tET(s)\n";

        for (int i = 0; i < n; i++)
        {
            cout << processes[i] << "\t\t" << pr[i] << "\t\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << endl;
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


// Function to find the waiting time for all
// processes

// Driver code
int main()
{
    std::vector<float>awt;
    std::vector<float>atat;
    int arrival_time[5], burst_time[5], pri[5];
    int processes[] = {1, 2, 3, 4, 5};
    int n = 5;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter burst time for process number " << i + 1 << ": ";
        cin >> burst_time[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter arrival time for process number " << i + 1 << ": ";
        cin >> arrival_time[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter priority for process number " << i + 1 << ": ";
        cin >> pri[i];
    }

    fcfs f;
    f.findavgTime(processes, n, burst_time, arrival_time);
    cout<<endl;
    sjf s;
    s.computeSJF(processes, arrival_time, n, burst_time);
    cout<<endl;
    priority p;
    p.computePri(processes,burst_time,n,pri);
    awt.push_back(f.sendAwt());
    awt.push_back(s.sendAwt());
    awt.push_back(p.sendAwt());
    atat.push_back(f.sendAwt());
    atat.push_back(s.sendAwt());
    atat.push_back(p.sendAwt());
	for (auto it = awt.begin(); it != awt.end(); it++) 
        cout << *it << " "; 
    float f =min_element(begin(awt),end(awt));
    return 0;
}

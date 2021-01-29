// C++ program for implementation of FCFS
// *scheduling with different arrival time
#include <iostream>
#include "schedule.h"

using namespace std;
//base class to inherit the properties

class fcfs : public schedule
{
     float atat,awt;
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
    cout << "Process-ID\tArrival Time(s)\tBurst Time(s)\tWaiting Time(s)\tTT(s)\tET(s)\n";
        int total_wt = 0, total_tat = 0;
        for (int i = 0; i < n; i++)
        {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];
            int compl_time = tat[i] + at[i];
            cout << " " << i + 1 << "\t\t" << at[i] << "\t\t"
                 <<  bt[i]<< "\t\t" << wt[i] << "\t\t "
                 << tat[i] << "\t\t " << compl_time << endl;
        }
    // cout << "Processes "
    //      << " Burst Time "
    //      << " Arrival Time "
    //      << " Waiting Time "
    //      << " Turn-Around Time "
    //      << " Completion Time \n";
    // int total_wt = 0, total_tat = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     total_wt = total_wt + wt[i];
    //     total_tat = total_tat + tat[i];
    //     int compl_time = tat[i] + at[i];
    //     cout << " " << i + 1 << "\t\t" << bt[i] << "\t\t"
    //          << at[i] << "\t\t" << wt[i] << "\t\t "
    //          << tat[i] << "\t\t " << compl_time << endl;
    // }
        awt = (float)total_wt / (float)n;
        atat = (float)total_tat / (float)n;
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
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

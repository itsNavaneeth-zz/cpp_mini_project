#include <iostream>
#pragma once
using namespace std;

class schedule
{
protected:
    int processess[5], bt[5], wt[5], at[5], pr[5], n = 5;
   
public:
    schedule()
    {
        for(int i=0;i<5;i++)
        {
            at[i] = 0;
        }
    }
    //fcfs
    void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]);
    void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
    void findavgTime(int processes[], int n, int bt[], int at[]);

    //sjf
    void computeSJF(int processes[], int at[], int n, int bt[]);

    //priority
    void computePri(int processes[],int bt[], int n, int pr[]);
    //fucn to return the ATAT and AWT 
    float sendAwt();
    float sendAtat();
  
};
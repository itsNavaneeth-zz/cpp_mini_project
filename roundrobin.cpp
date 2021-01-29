// C++ program to implement
// Round Robin Scheduling with
// different arrival time
#include<iostream>
#include<iomanip>
using namespace std;
 
void CalcWaitingTime(int process[], 
                     int wt_time[], int n, 
                     int burst_time[], 
                     int quantum, 
                     int completion_time[], 
                     int arrival_time[])
{
  // Copy the value of brust 
  // time array into waiting 
  // time array.
  int rem_time[n];
 
  for(int i = 0; i < n; i++)
    rem_time[i] = burst_time[i];
 
  int t = 0;
  int arrival = 0;
 
  // Processing until the value 
  // of element of rem_time array 
  // is 0
  while(true)
  {
    bool done = true;
    for(int i = 0; i < n; i++)
    {
      if(rem_time[i] > 0)
      {
        done = false;
        if(rem_time[i] > quantum && 
           arrival_time[i] <= arrival)
        {
          t += quantum;
          rem_time[i] -= quantum;
          arrival++;
        }
        else
        {
          if(arrival_time[i] <= arrival)
          {
            arrival++;
            t += rem_time[i];
            rem_time[i] = 0;
            completion_time[i] = t; 
          }
        }
      }
    }
 
    if(done==true) 
      break;
  } 
}
 
void CalcTurnAroundTime(int process[], 
                        int wt_time[], int n, 
                        int burst_time[], 
                        int tat_time[], 
                        int completion_time[], 
                        int arrival_time[])
{
  for(int i = 0; i < n; i++)
  {
    tat_time[i] = completion_time[i] - 
                  arrival_time[i];
    wt_time[i] = tat_time[i] - 
                 burst_time[i];
  }
}
 
void CalcAvgTime(int process[], int n, 
                 int burst_time[], 
                 int quantum, 
                 int arrival_time[])
{
  int wt_time[n];
  int tat_time[n];
  int completion_time[n];
  int total_wt = 0, total_tat = 0;
  CalcWaitingTime(process, wt_time, 
                  n, burst_time, 
                  quantum, 
                  completion_time, 
                  arrival_time); 
  CalcTurnAroundTime(process, wt_time, 
                     n, burst_time, 
                     tat_time, 
                     completion_time, 
                     arrival_time);
  cout << setw(9) << "PROCESS" << 
          setw(14) << "ARRIVAL TIME" << 
          setw(12) << "BURST TIME" << 
          setw(17) << "COMPLETION TIME" <<
          setw(18) << "TURN AROUND TIME" <<
          setw(16) << "WAITING TIME\n";
 
  for (int i = 0; i < n; i++) 
  { 
    total_wt = total_wt + wt_time[i]; 
    total_tat = total_tat + tat_time[i]; 
    cout << setw(6) << i + 1 << 
            setw(11) << arrival_time[i] << 
            setw(12) << burst_time[i] << 
            setw(17) << completion_time[i] <<
            setw(15) << tat_time[i] <<
            setw(16) << wt_time[i] << endl; 
  } 
 
  cout << "\nAVERAGE WAITING TIME : " <<
          (float)total_wt / (float)n; 
  cout << "\nAVERAGE TURN AROUND TIME : " <<
          (float)total_tat / (float)n; 
}
 
// Driver code
int main()
{
  int quantum = 2;
  int arrival_time[] = {0,1,2,3};
  int process[] = {1,2,3,4};
  int burst_time[] = {5,4,2,1};
  int n = sizeof process /
          sizeof process[0];
  CalcAvgTime(process, n, 
              burst_time, 
              quantum, 
              arrival_time);
  return 0;
}
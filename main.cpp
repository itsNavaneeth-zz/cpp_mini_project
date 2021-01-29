// C++ program for implementation of FCFS
// *scheduling with different arrival time
#include <iostream>

#include "schedule.h"
#include "fcfs2.h"
#include "priority.h"
#include "sjf1.h"
using namespace std;
//base class to inherit the properties


// Function to find the waiting time for all
// processes

// Driver code
int main()
{
    int arrival_time[5], burst_time[5], pri[5];
    int choice;
    do
    {   cout<<"\n Enter your choice\n";
        cout<<"\n1.Reading data\n2.Displaying scheduling parameters\n3.display least waiting time and TAT\n";
        cin>>choice;
    switch(choice)
    {
        case 1:
        {
            fcfs f;
            sjf s;
            priority p;
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
           
            break;
        }
        case 2:
        {
            int processes[] = {1, 2, 3, 4, 5};
            int n = 5;
        
            fcfs f;
            f.findavgTime(processes, n, burst_time, arrival_time);
            cout<<endl; 
            cout<<endl; 
            sjf s;
            s.computeSJF(processes, arrival_time, n, burst_time);
            cout<<endl;
            cout<<endl; 
            priority p;
            p.computePri(processes,burst_time,n,pri);
            cout<<endl; 
            break;
        }
      case 3:
      {
          fcfs f;
          sjf s;
          priority p;
           float awt[3],atat[3];
               awt[0] = f.sendAwt();
               awt[1] = s.sendAwt();
               awt[2] = p.sendAwt();
               atat[0] = f.sendAtat();
               atat[1] = s.sendAtat();
               atat[2] = p.sendAtat();
               cout<<endl;
               float minwt = awt[0],minAt = atat[0];
               for(int i=0;i<3;i++)
               {
                   if(minwt>awt[i])
                    {
                        minwt = awt[i];
                    }
                    if(minAt>atat[i])
                    {
                        minAt = atat[i];
                    }
               }
               cout<<"Least waiting time is "<<minwt<<endl;
               cout<<"Least Turn Around time is "<<minAt<<endl;
            break;
      }

    }
     } while (choice!=4);
   
    return 0;
}

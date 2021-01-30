#include <iostream>
//including various code files using modular programming technique
#include "schedule.h"
#include "fcfs.h"
#include "priority.h"
#include "sjf.h"
using namespace std;

// Driver code
int main()
{
    int arrival_time[5], burst_time[5], pri[5];
    int choice;
    do
    {
        cout << "\n-----MENU-----\n";
        cout << "\n1.Reading data\n2.Displaying scheduling parameters\n3.display least waiting time and TAT\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        { //reading scheduling parameters for the algos
            fcfs f;
            sjf s;
            priority p;
            //adding exceptions
            int a;
            for (int i = 0; i < 5; i++)
            {

                try
                {
                    cout << "Enter burst time for process number " << i + 1 << ": ";
                    cin>>a;
                    if(a<0)
                        throw a;
                    else
                        burst_time[i] = a;
                }
                catch(int k)
                {
                    cout<<"\nBurst Time can never be negative( )\n"<<k<<endl;
                    cout<<"\nEnter Burst Time Again\n"<<endl;
                    i = i-1;
                }

            }
<<<<<<< HEAD
                 for (int i = 0; i < 5; i++)
                {
                    try
                    {
                        cout << "Enter arrival time for process number " << i + 1 << ": ";
                        cin>>a;
                        if(a<0)
                            throw a;
                        else
                            arrival_time[i] = a;
                    }
                    catch(int k)
                    {
                        cout<<"\nArrival Time can never be negative( )\n"<<k<<endl;
                        cout<<"\nEnter Arrival time Again\n"<<endl;
                        i = i-1;
                    }
                }
=======
            for (int i = 0; i < 5; i++)
            {
                cout << "Enter arrival time for process number " << i + 1 << ": ";
                cin >> arrival_time[i];
            }
>>>>>>> 62ba130650f81618add9777576d0aa7773e9380a

            for (int i = 0; i < 5; i++)
            {
                cout << "Enter priority for process number " << i + 1 << ": ";
                cin >> pri[i];
            }

            break;
        }
        case 2:
<<<<<<< HEAD
        {//computing tat and wt
=======
        { //computing tat and wt
>>>>>>> 62ba130650f81618add9777576d0aa7773e9380a
            int processes[] = {1, 2, 3, 4, 5};
            int n = 5;

            fcfs f;
            f.findavgTime(processes, n, burst_time, arrival_time);
<<<<<<< HEAD
            cout<<endl;
            cout<<endl;
            sjf s;
            s.computeSJF(processes, arrival_time, n, burst_time);
            cout<<endl;
            cout<<endl;
            priority p;
            p.computePri(processes,burst_time,n,pri);
            cout<<endl;
=======
            cout << endl;
            cout << endl;
            sjf s;
            s.computeSJF(processes, arrival_time, n, burst_time);
            cout << endl;
            cout << endl;
            priority p;
            p.computePri(processes, burst_time, n, pri);
            cout << endl;
>>>>>>> 62ba130650f81618add9777576d0aa7773e9380a
            break;
        }
        case 3:
        { //storing the ATAT and AWT into an array and finding minimum from them
            fcfs f;
            sjf s;
            priority p;
            float awt[3], atat[3];
            awt[0] = f.sendAwt();
            awt[1] = s.sendAwt();
            awt[2] = p.sendAwt();
            atat[0] = f.sendAtat();
            atat[1] = s.sendAtat();
            atat[2] = p.sendAtat();
            cout << endl;
            float minwt = awt[0], minAt = atat[0];
            for (int i = 0; i < 3; i++)
            {
                if (minwt > awt[i])
                {
                    minwt = awt[i];
                }
                if (minAt > atat[i])
                {
                    minAt = atat[i];
                }
            }
            cout << "Least waiting time is= " << minwt << endl;
            cout << "Least Turn Around time is= " << minAt << endl;
            cout << "Thank you for using our program." << endl;
            break;
        }
        }
    } while (choice != 4);

<<<<<<< HEAD
    }
     } while (choice!=4);

=======
>>>>>>> 62ba130650f81618add9777576d0aa7773e9380a
    return 0;
}

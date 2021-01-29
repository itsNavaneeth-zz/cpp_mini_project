//C++ Program to implement Round Robin 
//Scheduling CPU Algorithm

#include <iostream>
#include<vector>
/*at = Arrival time,
bt = Burst time,
time_quantum= Quantum time
tat = Turn around time,
wt = Waiting time*/

using namespace std;

int main()
{
	int i,n,time,remain,temps=0,time_quantum;

	int wt=0,tat=0;

	cout<<"Enter the total number of process="<<endl;
	cin>>n;

	remain=n;
	// assigning the number of process to remain variable

	vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
	//dynamic array declaration using vector method of (STL)
	//STL standard template library of C++

	
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter burst time for process number " << i + 1 << ": ";
            cin >> bt[i];
            rt[i] = bt[i];
         }
             for(int i=0;i<5;i++)
             {
                 cout<<"Enter arrival time for process number "<<i+1<<": ";
                 cin>>at[i];
             }

	cout<<"Enter the value of time QUANTUM:"<<endl;
	cin>>time_quantum;

	cout<<"\n\nProcess\t:Turnaround Time:Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=time_quantum && rt[i]>0)
		{
			time += rt[i];
			//Addition using shorthand operators
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= time_quantum;
			//Subtraction using shorthand operators
			time += time_quantum;
			//Addition using shorthand operators
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			//Desplaying the result of wating, turn around time:
			printf("Process{%d}\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
			
			// cout << "Process-time(s) ";
			cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}
     cout<<"Process-time(s) Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s) Exit-time(s)\n";

            for(int i=0;i<n;i++)
            {
                cout<<processes[i]<<"                "<<at[i]<<"                "<<bt[i]<<"                "<<wt[i]<<"                "<<tat[i]<<"                          "<<e[i]<<endl;
            }
  }

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n<<endl;;

	return 0;
}
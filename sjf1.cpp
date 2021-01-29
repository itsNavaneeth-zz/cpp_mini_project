#include<iostream>

using namespace std;

class schedule
{
    protected:
    int processess[5],bt[5],wt[5],at[5],n = 5;
    public:
    void computeSJF(int processes[],int at[], int n, int bt[]);
};
class sjf : public schedule
{
    int e[5],tat[5];
    float atat,awt;
    public:
        void computeSJF(int processes[],int at[],int n,int bt[])
        {
             int temp,tt=0,min,d,i,j;
      //average tat , avg wat , sum tat , sum wait time
       atat=0;
       awt=0;
       float stat=0,swt=0;
    //int at[n], bt[n], tat[n], wt[n];
      //bubble sort
      for(i=0;i<n;i++)
      {
         for(j=i+1;j<n;j++)
          {
                if(bt[i]>bt[j])
                {  //sort arrival time according to sorted burst time
                      temp=at[i];
                      at[i]=at[j];
                      at[j]=temp;

                      temp=bt[i];
                      bt[i]=bt[j];
                      bt[j]=temp;

                      temp=processes[i];
                      processes[i]=processes[j];
                      processes[j]=temp;
                }
          }
      }
      min=at[0];//1
      for(i=0;i<n;i++)
      {
            if(min>at[i])
            {
                  min=at[i];
                  d=i;//d = 0
            }
      }
      tt=min;//tt = 1
      e[d]=tt+bt[d];//1+5 = 6
      tt=e[d];//tt = 6

      for(i=0;i<n;i++)
      {
            if(at[i]!=min)//false
            {
                  e[i]=bt[i]+tt;
                  tt=e[i];
            }
      }
      for(i=0;i<n;i++)
      {

            tat[i]=e[i]-at[i];//tat[0] = 6-1 = 5
            stat=stat+tat[i];//
            wt[i]=tat[i]-bt[i];//5-5 = 0
            if (wt[i] < 0)
                {
                    wt[i] = 0;
                }
            swt=swt+wt[i];
      }
      //wt[1] = 1;
      atat=stat/n;
      awt=swt/n;
      
        cout<<"Process-time(s) Arrival-time(s)  Burst-time(s)  Waiting-time(s)  Turnaround-time(s) Exit-time(s)\n";

            for(int i=0;i<n;i++)
            {
                cout<<processes[i]<<"                "<<at[i]<<"                "<<bt[i]<<"                "<<wt[i]<<"                "<<tat[i]<<"                          "<<e[i]<<endl;
            }

            cout<<"awt="<<awt<<" atat="<<atat;  
    }


  
};

int main()
{

     int arrival_time[5],burst_time[5],priority[5];
    int processes[] = {1, 2, 3, 4, 5};
    int n=5;
   
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter burst time for process number " << i + 1 << ": ";
            cin >> burst_time[i];
         }
             for(int i=0;i<5;i++)
             {
                 cout<<"Enter arrival time for process number "<<i+1<<": ";
                 cin>>arrival_time[i];
             }
            //  for(int i=0;i<5;i++)
            //  {
            //      cout<<"Enter priority for process number "<<i+1<<": ";
            //      cin>>priority[i];
            //  }
        sjf s;
        s.computeSJF(processes,arrival_time,n,burst_time);
       // s.display();
       // cout<<"awt="<<awt<<" atat="<<atat;  //average waiting time and turn around time
}
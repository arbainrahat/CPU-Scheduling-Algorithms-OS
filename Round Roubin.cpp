#include<iostream>
#include<iomanip>
using namespace std;
class rr_alg
{
    int exe[10];
    int n,q;
public:
    void getdata();
    void display();
    void cal_wt_tt();
};
void rr_alg::getdata()
{
    cout<<"How many process to be entered : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter execution time of process "<<i+1<<" : ";
        cin>>exe[i];
    }
    cout<<"Enter Quantum slice : ";
 cin>>q;
}
void rr_alg::display()
{
    cout<<endl<<"Process ID\tExecution time\tArrival Time "<<endl;
    for(int i=0;i<n;i++)
        cout<<setw(5)<<i+1<<setw(15)<<exe[i]<<setw(15)<<"0"<<endl;
}
void rr_alg::cal_wt_tt()
{
    int texe=0,exe2[10],flag=1;
 int wt=0,tnt=0;
 float avg=0,avtnt=0;
 for(int i=0;i<n;i++)
 {
     texe+=exe[i];
     exe2[i]=exe[i];
 }
 cout<<"\nProcess ID \tWaiting time \tTurn Around time "<<endl;
 for(int y=0;y<texe;y++)
    {
        for(int i=0;i<n;i++)
        {
            if(exe[i]<=0)
                continue;
      tnt+=q;
      exe[i]-=q;
         if(exe[i]<=0)
         {
             tnt+=exe[i];
             wt=tnt-exe2[i];
          cout<<setw(5)<<i+1<<setw(15)<<wt<<setw(15)<<tnt<<endl;
          avg+=wt;
          avtnt+=tnt;
         }
        }
    }
    avg=avg/(float)n;
    avtnt/=(float)n;
    cout<<"\nAverage Waiting time     : "<<avg;
    cout<<"\nAverage turn Around time : "<<avtnt<<endl;
}
int main()
{
 rr_alg rr;
 rr.getdata();
 rr.display();
 rr.cal_wt_tt();
    return 0;
}


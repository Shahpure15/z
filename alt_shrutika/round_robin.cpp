#include<iostream>
using namespace std;

int main(){
    int n=5, tq=2;
    int at[]={0,1,2,3,4};
    int bt[]={5,3,1,2,3};
    int rt[5];
    for(int i=0;i<n;i++) rt[i]=bt[i];

    int time=0, done=0;
    while(done<n){
        for(int i=0;i<n;i++){
            if(rt[i]>0 && at[i]<=time){
                if(rt[i]>tq){
                    time+=tq;
                    rt[i]-=tq;
                } else {
                    time+=rt[i];
                    rt[i]=0;
                    done++;
                    cout<<"Process P"<<i+1<<" completed at time "<<time<<endl;
                }
            }
        }
    }
}

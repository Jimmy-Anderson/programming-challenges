#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<iomanip>
using namespace std;


typedef struct Interval{
    int starthr;
    int startmin;
    int endhr;
    int endmin;
    char person;
}interval;

void getTime(string time,int &hour,int &mint){
    int div=time.find(':');
    int length=time.length();
    hour=stoi(time.substr(0,div));
    mint=stoi(time.substr(div+1,length-div-1));

}
int getTimeCompare(int hr1,int min1,int hr2,int min2){
    if(hr1<hr2)
        return -1;
    else if(hr1==hr2){
        if(min1<min2)
            return -1;
        else if(min1==min2)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}
double getTimeDifference(int hr1,int min1,int hr2,int min2){
    int hrdiff,mindiff;
    double res;
    hrdiff=abs(hr1-hr2)-1;
    if(hr1<hr2){
        mindiff=60-min1+min2;
        res=hrdiff+(double)mindiff/60;
        return -1*res;
    }
    else if(hr2<hr1){
        mindiff=60-min2+min1;
        res=hrdiff+(double)mindiff/60;
        return res;
    }
    else{
        mindiff=abs(min1-min2);
        res=hrdiff+(double)mindiff/60;
        return res;
    }
}
interval convertToSlot(string start,string end,char person){
    interval x;
    int hour,mint;
    getTime(start,hour,mint);
    x.starthr=hour;
    x.startmin=mint;
    getTime(end,hour,mint);
    x.endhr=hour;
    x.endmin=mint;
    x.person=person;
    return x;
}


bool compareList(interval a,interval b){
    double diff=getTimeDifference(a.starthr,a.startmin,b.starthr,b.startmin);
    return diff<0;
}
void getAvailableSlots(vector<interval>&slotList,vector<interval>&possibleList){
    stack<interval>st;
    st.push(slotList[0]);
    for(int i=1;i<slotList.size();i++){
        interval top=st.top();
        interval curInterval= slotList[i];
        int isLess=getTimeCompare(curInterval.starthr,curInterval.startmin,top.endhr,top.endmin);
        if(isLess==-1){
            st.pop();
            if(curInterval.person!=top.person){
                if(abs(getTimeDifference(curInterval.starthr,curInterval.startmin,top.endhr,top.endmin))>=1.0){
                    interval possint;
                    if(getTimeDifference(curInterval.starthr,curInterval.startmin,top.starthr,top.startmin)>=0){
                        possint.starthr=curInterval.starthr;
                        possint.startmin=curInterval.startmin;
                    }
                    else{
                        possint.starthr=top.starthr;
                        possint.startmin=top.startmin;
                    }
                    if(getTimeDifference(curInterval.endhr,curInterval.endmin,top.endhr,top.endmin)<0){
                        possint.endhr=curInterval.endhr;
                        possint.endmin=curInterval.endmin;
                    }
                    else{
                        possint.endhr=top.endhr;
                        possint.endmin=top.endmin;
                    }
                    possint.person='X';
                    possibleList.push_back(possint);
                }
            }
            else
            {
                top.endhr=max(curInterval.endhr,top.endhr);
                top.endmin=max(curInterval.endmin,top.endmin);
            }
            st.push(top);
        }
        else
        {
            st.push(curInterval);
        }
    }
}
void printSlotList(vector<interval>&slotlist){
    cout<<setw(6)<<"Start Time  "<<setw(6)<<"End Time\n";
    for(interval x:slotlist){
        cout<<setw(6)<<x.starthr<<":"<<x.startmin<<" ";
        cout<<setw(6)<<x.endhr<<":"<<x.endmin<<"\n";
    }
}
int main()
{
    vector<interval>slotList;
    stack<interval>st;
    int n,m;
    cout<<"\nEnter the number of slots for person A\n";
    cin>>n;
    cout<<"\nEnter "<<n<<" slots in form [starttime  endtime] i.e,[hour:min hour:min]\n";
    for(int i=1;i<=n;i++){
        string start,end;
        cin>>start>>end;
        interval x=convertToSlot(start,end,'A');
        slotList.push_back(x);
    }
    cout<<"\nEnter the number of slots for person B\n";
    cin>>m;
    cout<<"\nEnter "<<m<<" slots in form [starttime  endtime] i.e,[hour:min hour:min]\n";
    for(int i=1;i<=m;i++){
        string start,end;
        cin>>start>>end;
        interval x=convertToSlot(start,end,'B');
        slotList.push_back(x);
    }
    sort(slotList.begin(),slotList.end(),compareList);
    vector<interval>possibleList;
    getAvailableSlots(slotList,possibleList);
    cout<<"The possible Slots where both the people are free\n";
    printSlotList(possibleList);

}

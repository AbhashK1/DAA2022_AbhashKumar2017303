/*Given a list of activities with their starting time and finishing time. Your goal is to select
maximum number of activities that can be performed by a single person such that selected
activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of an
activity is greater than or equal to the finishing time of the other activity. Assume that a person
can only work on a single activity at a time.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Activity
{
    public:int start,end;
};
bool comp(Activity act1,Activity act2)
{
    return(act1.end<act2.end);
}
void maxActivity(Activity act[],int n)
{
    sort(act,act+n,comp);
    cout<<"Selected Activity: "<<endl;
    int count=1;
    int i=0;
    cout<<"Activity: "<<i+1<<endl; //, Start: "//<act[i].start<<"End: "<<act[i].end<<endl;
    for(int j=1;j<n;j++)
    {
        if(act[j].start>=act[i].end)
        {
            cout<<"Activity: "<<j+1<<endl; //, Start: "//<<act[j].start<<"End: "<<act[j].end<<endl;
            count++;
            i=j;
        }
    }
    cout<<"No. of Non Conflicting Activity: "<<count<<endl;
}
int main()
{
    int N;
    cin>>N;
    Activity act[N];
    for(int i=0;i<N;i++)
        cin>>act[i].start;
    for(int i=0;i<N;i++)
        cin>>act[i].end;
    maxActivity(act,N);
}

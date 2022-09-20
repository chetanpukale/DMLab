#include<bits/stdc++.h>
using namespace std;
float getmed(vector<int>marks,int n)
{
    if(n%2==0)
    {
        return((marks[(n-1)/2]+marks[n/2])/2.0);
    }
    else 
    {
        return marks[n/2];
    }
}
float getQ3(vector<int>marks,int start,int end)
{
    //cout<<start<<" "<<end<<" ";
    int tmp=(start+end)/2;
        if(((end-start)+1)%2==1)
        {
            //cout<<"1"<<endl;
            return marks[(end+start)/2];
        }
        else
        {
                return (marks[tmp]+marks[tmp+1])/2.0;
        }
}
int main()
{
    ifstream fin("assignment1.txt");
    vector<int>marks;
    int num;
    int count=0;
    while(fin>>num)
    {
            marks.push_back(num);
    }
    sort(marks.begin(),marks.end());
   
    int n=marks.size();
     cout<<"Sorted Marks of student:- ";
    for(int i=0;i<n;i++)
    {
        cout<<marks[i]<<" ";
    }
    cout<<endl;
    cout<<"Max Val:- "<<marks[n-1]<<endl;
    cout<<"Min Val:- "<<marks[0]<<endl;

    if(marks.size()%2==0)
    {
        cout<<"Median:-"<<(marks[(n-1)/2]+marks[n/2])/2.0<<endl;
    }
    else
    {
        cout<<"Median:-"<<marks[n/2]<<endl;
    }
    cout<<"Q1:- "<<getmed(marks,n/2)<<endl;
    cout<<"Q3:- "<<getQ3(marks,(n/2+(n%2)),n-1)<<endl;
    int sum=accumulate(marks.begin(),marks.end(),0);
    cout<<"Mean:- "<<sum/(float)n<<endl;

}
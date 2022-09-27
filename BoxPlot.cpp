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
vector<double> calZ(vector<int>p,float mean)
{
    cout<<" HII";
    double sum=0;
    for(int i=0;i<p.size();i++)
    {
        sum+=(p[i]-mean)*(p[i]-mean);
    }
    cout<<sum<<endl;
    float sd=sum/(float)(p.size()-1);
    cout<<sd<<" ";
    vector<double>zval;
    for(int i=0;i<p.size();i++)
    {
        
        zval.push_back((p[i]-mean)/(double)sd);
        
    }

    return zval;
}
vector<double> calminmax(vector<int>p,int min,int max)
{
    int new_min=0;
    int new_max=1;
    vector<double>minmax1;
    for(int i=0;i<p.size();i++)
    {
            double ans=((p[i]-min)*(new_max-new_min))/(double)(max-min);
            ans+=new_min;
            minmax1.push_back(ans);
    }
    return minmax1;
}
int main()
{
    fstream fin("Book1.csv",ios::in);
    string line;
    stringstream dat;
    vector<int>p;
    vector<int>p1;
    vector<int>a;
    int num;
    if(fin.is_open())
    {
        int c=0;
        while(getline(fin,line))
        {
            if(c!=0)
            {
                    stringstream str(line);
                    //cout<<line; 
                    int cnt=1;
                    string data;
                    while(getline(str,data,','))
                    {
                            int val=stoi(data);
                            if(cnt==2)
                            {
                            p.push_back(val);
                            p1.push_back(val);
                            }
                            else if(cnt==3)
                            {

                                a.push_back(val);
                            }
                            cnt++;
                    }
            }
          c++;
        }
    }
    else
    {
        cout<<"no";
    }
    for(int i=0;i<p.size();i++)
    {
        cout<<p[i]<<" "<<a[i]<<endl;
    }
     sort(p.begin(),p.end());
   
    int n=p.size();
     cout<<"Sorted Marks of student:- ";
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    cout<<"Max Val:- "<<p[n-1]<<endl;
    cout<<"Min Val:- "<<p[0]<<endl;

    if(p.size()%2==0)
    {
        cout<<"Median:-"<<(p[(n-1)/2]+p[n/2])/2.0<<endl;
    }
    else
    {
        cout<<"Median:-"<<p[n/2]<<endl;
    }
    cout<<"Q1:- "<<getmed(p,n/2)<<endl;
    cout<<"Q3:- "<<getQ3(p,(n/2+(n%2)),n-1)<<endl;
    int sum=accumulate(p.begin(),p.end(),0);
    
}

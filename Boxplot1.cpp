#include<bits/stdc++.h>
using namespace std;

vector<double> calZ(vector<int>p,float mean)
{

    double sum=0;
    for(int i=0;i<p.size();i++)
    {
        sum+=(p[i]-mean)*(p[i]-mean);
    }
    //cout<<sum<<endl;
    float sd=sum/(float)(p.size()-1);
    cout<<"Standard Deviation:--- "<<sd<<endl;
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
    
     sort(p.begin(),p.end());
   
    int n=p.size();
     cout<<"Sorted Presenties of student:- ";
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    cout<<endl;
    //cout<<"Max Val:- "<<p[n-1]<<endl;
    //cout<<"Min Val:- "<<p[0]<<endl;

    
    int sum=accumulate(p.begin(),p.end(),0);
    cout<<"Mean:- "<<sum/(float)n<<endl;
    vector<double>zval=calZ(p,sum/(float)n);
    cout<<"Z Value of all student:----  ";
    for(int i=0;i<zval.size();i++)
    {
        cout<<zval[i]<<endl;
    }
    cout<<endl;
 cout<<"Min Max Value of all student:----  ";
    vector<double>minmax1=calminmax(p,p[0],p[n-1]);
    for(int i=0;i<n;i++)
    {
        cout<<minmax1[i]<<endl;
    }

}

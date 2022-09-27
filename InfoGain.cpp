#include<bits/stdc++.h>
using namespace std;
double calcEntropy(int y,int n)
{
    if(y==0||n==0)
    return 0;
    double s_entropy=-(y/(float)(y+n))*(log2(y/(float)(y+n)));
    s_entropy=s_entropy+(-(n/(float)(y+n))*(log2(n/(float)(y+n))));
    return s_entropy;
}
double calcgain(map<string,pair<int,int>>tmp,double s_entropy,int total)
{
 for(auto itr=tmp.begin();itr!=tmp.end();++itr)
 {
    //cout<<itr->first<<"-"<<endl;
    //cout<<"Yes="<<itr->second.second<<" ";
    //cout<<"No="<<itr->second.first<<endl;
    double p_entropy=calcEntropy(itr->second.second,itr->second.first);
    double mul=(itr->second.second+itr->second.first);
    mul=mul/total;
    s_entropy-=((mul)*p_entropy);
    //cout<<"Entropy for "<<itr->first<<":- "<<p_entropy<<endl<<endl;
 } 
 return s_entropy;  
}
int main()
{
    fstream fin("InfogainFile.csv",ios::in);
    vector<vector<string>> content;
    vector<string> row;
    map<string,pair<int,int>>outlook;
    map<string,pair<int,int>>temp;
    map<string,pair<int,int>>humidity;
    map<string,pair<int,int>>wind;
    string line, word;
    int cnty=0;
    int cntn=0;
    if(fin.is_open())
    {
        while(getline(fin,line))
        {
           // cout<<line<<endl;
            row.clear();
            stringstream s(line);
            while(getline(s,word,','))
            {
                    row.push_back(word);
            }
            content.push_back(row);
        }
    }
    cout<<"Hii";
    for(int i=1;i<content.size();i++)
    {
        if(content[i][5]=="No")
        {
            outlook[content[i][1]].first+=1;
            temp[content[i][2]].first+=1;
            humidity[content[i][3]].first+=1;
            wind[content[i][4]].first+=1;
            cntn++;
        }
        else
        {
            cnty++;
             outlook[content[i][1]].second+=1;
            temp[content[i][2]].second+=1;
            humidity[content[i][3]].second+=1;
            wind[content[i][4]].second+=1;
        }
    }
  
double s_entropy=calcEntropy(cnty,cntn); 
cout<<s_entropy<<endl; 
double infogain=calcgain(outlook,s_entropy,content.size()-1);
 
cout<<"InfoGain for outlook:--- "<<infogain<<endl<<endl<<endl;
 infogain=calcgain(temp,s_entropy,content.size()-1);
 cout<<"InfoGain for temp:--- "<<infogain<<endl<<endl<<endl;
infogain=calcgain(humidity,s_entropy,content.size()-1);
 cout<<"InfoGain for humidity:---  "<<infogain<<endl<<endl<<endl;
infogain=calcgain(wind,s_entropy,content.size()-1);
 cout<<"InfoGain for wind:--- "<<infogain<<endl<<endl<<endl;
 
}
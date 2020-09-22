#include<bits/stdc++.h>
using namespace std;

struct Sample { 
    int f;
    string s;  
    Sample(int ff, string ss) : f(ff), s(ss) 
    { 
    } 
};   
struct CompareFreq { 
    bool operator()(Sample const& p1, Sample const& p2) 
    { 
        if(p1.f == p2.f)
        {
            return p1.s > p2.s; 
        }
        else
        {
            return p1.f < p2.f; 
        }
    } 
}; 
bool match(string s,string b)
{
    size_t found = s.find(b); 
    if (found != string::npos) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void isPresentInDict(string input,map<string,int> &mp,string * dict,int ndict)
{
    for(int i=0;i<ndict;i++)
    {
        if(match(input,dict[i]))
        {
            mp[dict[i]]++;
        }
    }
}
void topKthMostFrequentWord(string * dict, int ndict, string *f, int fn,int k)
{
    map<string,int> mp;
    for(int i=0;i<fn;i++)
    {
        isPresentInDict(f[i],mp,dict,ndict);
    }
    priority_queue<Sample, vector<Sample>, CompareFreq> Q; 
    for(auto mi =mp.begin();mi!=mp.end();mi++)
    {
        Q.push(Sample(mi->second, mi->first)); 
    }
    while (!Q.empty() && k--)
    { 
        Sample p = Q.top(); 
        Q.pop(); 
        cout << p.s << " && " << p.f << "\n"; 
    } 
}
int main()
{
    string dict[]={"waterproof","battle","house"};
    int sn = sizeof(dict)/sizeof(dict[0]);
    
    string f[]={"waterproof phone is new trend house.","battle of waterproof phone is rising","house of battle.","every phone is going to be house"};
    int fn = sizeof(f)/sizeof(f[0]);

    int k = 2;
    topKthMostFrequentWord(dict,sn,f,fn,k);
    return 0;
}


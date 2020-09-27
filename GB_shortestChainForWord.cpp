#include<bits/stdc++.h>
using namespace std;
//Using BFS
int shortestChain(string s,string d,set<string>& dict)
{
    if(s==d)return 0;
    list<string> Q;
    Q.push_back(s);
    int l=0;
    while(!Q.empty())
    {
        l++;
        int s = Q.size();
        for(int i=0;i<s;i++)
        {
            string s = Q.front();
            Q.pop_front();
            //cout<<s<<endl;
            for(int i =0;i<s.length();i++)
            {
                char temp = s[i];
                for(char c='a';c<'z';c++)
                {
                    s[i] = c;
                    if(s==d)
                        return l+1;
                    if(dict.find(s)==dict.end())//not in list
                    continue;
                    dict.erase(s);
                    Q.push_back(s);
                }
                s[i] = temp;
            }
        }
    }
    return l;
}
int main() 
{ 
    set<string> dictionary; 
    dictionary.insert("koon"); 
    dictionary.insert("poon"); 
    dictionary.insert("plee");
    dictionary.insert("plam");
    dictionary.insert("same"); 
    dictionary.insert("poie"); 
    dictionary.insert("plie"); 
    dictionary.insert("poin"); 
    dictionary.insert("plea"); 
    string source = "toon"; 
    string destination = "plea"; 
    cout << "Length of shortest chain is: "
         << shortestChain(source, destination, dictionary); 
    return 0; 
} 

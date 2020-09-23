#include<bits/stdc++.h>
using namespace std;
int getSize(string s)
{
    stringstream sample(s);
    int x = 0;
    sample >> x;
    return x;
}
string getType(string s)
{
    if(s.find("mp3")!=string::npos || s.find("flac")!=string::npos || s.find("wav")!=string::npos)
    {
        return "music";
    }
    else if(s.find("mp4")!=string::npos || s.find("flv")!=string::npos || s.find("avi")!=string::npos)
    {
        return "video";
    }
    else if(s.find("gif")!=string::npos || s.find("png")!=string::npos || s.find("jpeg")!=string::npos)
    {
        return "images";
    }
    else
    {
        return "others";
    }
}
string getSummary(string s)
{
    string result;
    int mCount = 0, iCount = 0, vCount = 0, oCount = 0;
    vector<int> szv;
    vector<string> ssv;
    istringstream ss(s);
    do
    {
        string w;
        ss >> w;
        int sz = getSize(w);
        if(sz)
        {
            szv.push_back(sz);
        }
        else
        {
            string sw = getType(w);
            ssv.push_back(sw);
        }
    }while(ss);

    for(int i=0;i<szv.size();i++)
    {
        if(ssv[i]=="music")
        {
            mCount += szv[i];
        }
        else if(ssv[i]=="images")
        {
            iCount +=szv[i];
        }
        else if(ssv[i]=="video")
        {
            vCount += szv[i];
        }
        else
        {
            oCount += szv[i];
        }
    }
    result = "Music "+to_string(mCount)+"b"+"\n"+"Image "+to_string(iCount)+"b"+"\n"+"Video "+to_string(vCount)+"b"+"\n"+"Other "+to_string(oCount)+"b";
    return result;
}
int main()
{
    string s="my.song.mp3 110b \nmysing.mp4 10b \nmy.song2.mp3 120b \nmysing2.mp4 20b \nmyfile.txt 40b";
    cout<<getSummary(s)<<endl;
    return 0;
}

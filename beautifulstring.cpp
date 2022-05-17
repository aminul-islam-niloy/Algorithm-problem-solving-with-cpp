#include<bits/stdc++.h>
using namespace std;

int main()

{
    int n,t,i,j,l,f=0,c=0;

    string s,s1;

    while(cin>>t)
    {
        while(t--)
        {
            f=0,c=0;
            cin>>s;
            l=s.size();
            for(i=0; i<l; i++)
            {
                if((s[i]==s[i+1])&&(s[i]=='a'||s[i]=='b'||s[i]=='c'))
                {
                    cout<<"-1"<<endl;
                    c=1;
                    break;
                }
            }
            if(c==0)
            {
                for(i=0; i<l; i++)
                {
                if(s[i]=='?')
                        for(j='a'; j<='c'; j++)
                        {
                            if(j!=s[i-1]&&j!=s[i+1])
                                s[i]=j;
                        }
                }
                for(i=0; i<l; i++)
                {
                cout<<s[i];
                }
                cout<<endl;
            }
        }
    }
}

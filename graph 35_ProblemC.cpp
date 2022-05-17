#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>pi;

void preFunc(string s)
{
    ll len=s.size();
    pi.resize(len+5);
    pi[0]=0;
    for(ll i=1;i<len;i++){
        ll j=pi[i-1];
        while(j>0&&s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
}

int main()
{
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll len=s.size();
        reverse(s.begin(),s.end());
        preFunc(s);
        ll idx;
        for(ll i=len-1;i>=0;i--){
            if(pi[i]*2==(i+1)){
                idx=pi[i]-1;
                break;
            }
        }
        string ans="";
        for(ll i=0;i<=idx;i++)ans+=s[i];
        len=ans.size();
        ll rep=0;
        if(len<8){
            rep=(8/len);
            if(8%len!=0)rep++;
        }
        for(ll i=0;i<rep;i++){
            ans+=ans;
        }
        reverse(ans.begin(),ans.end());
        for(ll i=0;i<8;i++)cout<<ans[i];
        cout<<"...\n";
    }
    return 0;
}

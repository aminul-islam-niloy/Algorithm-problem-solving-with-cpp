#include <bits/stdc++.h>
using namespace std;

//**************************************************************************************************************************************************************************
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
//**************************************************************************************************************************************************************************
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9
#define inf 1e18
#define sz(x) (int)((x).size())
#define gcd(a, b) __gcd(a, b)
#define LCM(x, y) (((x) / __gcd((x), (y))) * (y))
#define mem(x, n) memset(x, n, sizeof(x))
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define ps(x, y) fixed << setprecision(y) << x
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//**************************************************************************************************************************************************************************

void c_p_c()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif   
}

vector<int>lps_value(string pat, int ch)
{
    int i = 1, j;
    vector<int>lps(ch);

    int len = 0;
    while(i<ch)
    {
        if(pat[i] == pat[len])
        {
            len++; 
            lps[i] = len;
            i++;          
        }
        else 
        {
            if(len!=0)
            {
                len = lps[len-1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    } 
    return lps;
}

void KMP(string txt, string pat)
{
    int len = pat.size();
    int t = 0;
    bool ans = false;
    int i = 0, j = 0;
    vector<int>lps = lps_value(pat, len);
    while(i<txt.size())
    {
        if(txt[i] == pat[j])
        {
            i++;
            j++;
        }
        else 
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else 
                i++;
        }
        if(j == len)
        {
            j = 0;
            t = i-len;
            cout<<t<<endl;
            i = t+1;
            ans = true;
        }
    }
    if(ans == false)
    {
        cout<<endl;
    }
}

int main(int argc, char const *argv[])
{
    //c_p_c();    
    FastIO;
    string txt,pat,n;
    int d = 1;
    while(cin>>n>>pat>>txt)
    {
        if(pat.size()>txt.size())
        {
            cout<<endl;
            continue;            
        }

        KMP(txt, pat);
        
        if(d>1)
        {
            cout<<endl;
        }
        d++;
        
    }    
}


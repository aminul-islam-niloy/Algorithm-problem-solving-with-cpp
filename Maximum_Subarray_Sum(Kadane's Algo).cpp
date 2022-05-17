#include<bits/stdc++.h>
using namespace std;

//kadan's algo

vector<int>data;
int kadane()
{
    int max_so_far = INT_MIN, max_ending_here = 0;
    int start = 0, end = 0, now = 0;
    for (int i = 0; i < data.size(); i++)
    {
        max_ending_here = max_ending_here + data[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = now;
            end = i;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            now = i + 1;
        }
            
            
    }
    printf("%d %d\n", start, end);
    return max_so_far;
}

int main()
{
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        data.push_back(val);
    }
    cout<<kadane()<<endl;
    return 0;
}
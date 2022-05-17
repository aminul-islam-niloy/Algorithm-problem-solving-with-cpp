#include <iostream>
#include <vector>
#define MAX 1000

using namespace std;

int p[MAX];

vector<int>v;

string msting,pattern;
int lenS,lenP;
void kmp();

int main(){
    int t;
    cin>>t;

    while(t--){
        cin>>msting;
        cin>>pattern;

        lenS = msting.length();
        lenP = pattern.length();

        for(int i=0;i<lenP;i++){
            p[i]=0;
        }

        kmp();
        cout<<endl;
    }

    return 0;
}

void kmp(){

    v.clear();

    int i=0,j=0;

    int flag=0;

    while(i<lenS){
        if(msting[i]==pattern[j]){
            i++;
            j++;
            if(j==lenP){
                flag=1;
                j=0;
                i=i-lenP+1;
                v.push_back(i);
            }
        }
        else{
            if(j!=0){
                j=p[j-1];
            }
            else{
                i++;
            }
        }
    }

    if(flag){
        cout<<v.size()<<endl;

        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }

    if(!flag){
        cout<<"Not Found";
    }
    cout<<endl;
}

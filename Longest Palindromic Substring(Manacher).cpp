#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e5+50;
const int mod = 1e9+7;
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

void manacher(string s){
    string T;
    T += "$"; int sl = s.length();
    for(int i=0; i<sl; i++){
        T += "#"; T += s[i];
    }
    T += "#@";

    vector<int>P(T.length(),0);
    int center = 0, right = 0;
    int tl = T.length();

    for(int i=1; i<tl-1; i++){
        int mir = 2*center - i;
        if(i<right){
            P[i] = min(right-i, P[mir]);
        }
        while(T[i+(1+P[i])] == T[i-(1+P[i])]){
            P[i]++;
        }
        if((i+P[i])>right){
            center = i; right = i+P[i];
        }
    }

    int mxLen = 0; center = 0;
    for(int i=1; i<tl-1; i++){
        if(mxLen<P[i]){
            mxLen = P[i]; center = i;
        }
    }

    int left = (center-1-mxLen)/2;
    right = (center-1+mxLen)/2-1;
    //cout<<left<<" "<<right<<"\n";
    for(int i=left; i<=right; i++){
        cout<<s[i];
    }
}

int32_t main(){
    fast();
    string s; cin>>s;
    manacher(s);
    return 0;
}



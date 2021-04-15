#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define F first
#define S second
#define all(v) v.begin(),v.end()
#define Mid(b,e) b+(e-b)/2
#define inf 2147483647

//---------------------------------------------------------------------------//
//Timus: 314795JS

//knight moves
//ll X[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 	
//ll Y[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
//ll dx[]={1,-1,0,0};
//ll dy[]={0,0,1,-1};
void yesNo(bool ck){cout<<(ck? "YES\n":"NO\n");}
ll toInt(string s){stringstream ss;ss<<s;int n;ss>>n;return n;}
string toString(ll n){stringstream ss;ss<<n;string s;ss>>s;return s;}
string UPPER(string s){transform(all(s),s.begin(),::toupper);return s;}
string LOWER(string s){transform(all(s),s.begin(),::tolower);return s;}
bool isDigit(char ch){if(ch>=48 && ch<=57) return true; else return false;}
vector<ll>removeDup(vector<ll>v){sort(all(v)); v.resize(distance(v.begin(),unique(all(v))));return v;}
bool isVowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E'){return true;}return false;}
bool isCons(char ch){if(isalpha(ch) && !isVowel(ch)){return true;} return false;}

//------------------------------------------------------------------------------//

const ll p=29;
const ll N=2e6+50;
const ll mod=1e9+7;

vector<ll>lps(N);
void prefix_function(string str){
	ll len=str.size(),j;
	for(ll i=1; i<len; i++){
		j=lps[i-1];
		while(j>0 and str[i]!=str[j]){
			j=lps[j-1];
		}
		if(str[i]==str[j]){
			j++;
		}
		lps[i]=j;
		//cout<<i<<" "<<j<<"\n";
	}
}


int main(){

	//freopen("C:/Users/Aman/Documents/output.txt", "w", stdout);
	//freopen("C:/Users/Aman/Documents/input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll t=1;
	for(ll T=1; T<=t; T++){
		ll n; cin>>n;
		string text,pat;
		cin>>text>>pat;
		text=pat+" "+text+text;
		prefix_function(text);
		ll ok=0,idx,len=text.size();
		for(ll i=n+1; i<len; i++){
			//cout<<lps[i]<<"\n";
			if(lps[i]==n){
				ok=1;
				idx=i+1;
				break;
			}
		}
		if(ok==0){
			cout<<"-1\n";
		}
		else{
			idx=idx-(n+1)-n;
			if(idx==0){
				cout<<"0\n";
			}
			else{
				ll res=n-idx;
				cout<<res<<"\n";
			}
		}
	}
	return 0;
}


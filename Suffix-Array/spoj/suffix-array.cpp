#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

string str;
ll SA[N], tempSA[N], RA[N], tempRA[N], count_sort[N], n;

void counting_sort(ll k) {
  memset(count_sort, 0, sizeof(count_sort));
  ll Max = max(300LL, n);
  for(ll i = 0; i < n; i++) {
    ll a = ((i + k) < n) ? RA[i + k] : 0;
    count_sort[a]++;
  }
  for(ll i = 0, sum = 0; i < Max; i++) {
    ll x = count_sort[i];
    count_sort[i] = sum;
    sum += x;
  }
  for(ll i=0; i<n; i++) {
    ll a = ((SA[i] + k) < n) ? RA[SA[i] + k] : 0;
    ll b = count_sort[a];
    count_sort[a]++;
    tempSA[b] = SA[i];
  }
  for(ll i = 0; i < n; i++) {
    SA[i] = tempSA[i];
  }
}

void build_Suffix_Array() {
  for(ll i = 0; i < n; i++) {
    RA[i] = str[i];
    SA[i] = i;
  }
  for(ll k = 1; k < n; k *= 2) {
    counting_sort(k);
    counting_sort(0);
    ll r;
    tempRA[SA[0]] = r = 0;
    for(ll i = 1; i < n; i++) {
      if(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) tempRA[SA[i]] = r;
      else tempRA[SA[i]] = ++r;
    }
    for (ll i = 0; i < n; i++) {
       RA[i] = tempRA[i];
    }
    if (RA[SA[n - 1]] == n-1) break;
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  for (ll T = 1; T <= t; T++) {
    cin >> str;
    str += "$";
    n = str.size();
    build_Suffix_Array();
    for (ll i = 1; i < n; i++) {
      cout << SA[i] << "\n";
    }
  }
  return 0;
}


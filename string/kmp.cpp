//pi[i] = the length of the longest proper suffix of the substring  s[0…i] which is also a proper prefix of this substring.
//Tested: https://cses.fi/problemset/result/1501795/

//KMP::O(|s|)
vector<int> cal_pi(string s){
  int n = s.size();
  vector<int> pi(n);
  for (int k = 0, i = 1; i < n; ++i){
    if(s[i]==s[k])  pi[i] = ++k;
    else if(k==0) pi[i]=0;
    else  k = pi[k-1], --i;
  }
  return pi;
}

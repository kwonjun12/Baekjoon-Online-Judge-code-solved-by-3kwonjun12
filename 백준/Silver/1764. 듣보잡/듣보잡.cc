#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string>s;
vector<string>ans;

int main(void) {
  int n,m;
  cin >> n >> m;
  string t;
  for(int i = 0; i < n; i++) {
    cin >> t;
    s.insert(t);
  }
  for(int i = 0; i < m; i++) {
    cin >> t;
    if(s.find(t) != s.end()) {
      ans.push_back(t);
    }
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for(int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
}
     
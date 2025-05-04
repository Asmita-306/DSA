#include <iostream>
#include <vector>
using namespace std;
void solve() {
    int n;
cin >> n;

vector<int> a(n);
for(int i=0;i<n;i++){
    cin >> a[i];
}
const int MAX_VAL = 1000001; vector<int> freq(MAX_VAL, 0);
int minRemove = 0;
int uniqueEnd = n - 1;
while (uniqueEnd >= 0 && freq[a[uniqueEnd]] == 0) { 
    freq[a[uniqueEnd]]++;
    uniqueEnd--;
}
minRemove = uniqueEnd + 1;
cout << minRemove << "\n";
}
int main() {
    int t;
cin >> t;
while (t--) {
solve();
}
return 0;
}
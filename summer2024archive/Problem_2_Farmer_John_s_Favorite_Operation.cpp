// #define _GLIBCXX_DEBUG
// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// #define dbg(v) \
//     cerr << #v << " = " << (v) << "\n";

// #define mp make_pair

// int n; ll m;
// void solve() {
//     cin >> n >> m;
//     vector<int> A(n), addToVal(n+1), subToVal(n+1);
//     set<int> modMs;
//     for (int i = 0; i < n; i++) {
//         cin >> A[i];
//         A.emplace_back(A[i]%m);
//         modMs.insert(A[i]%m);
//         modMs.insert(-(m-(A[i]%m)));
//     }
//     sort(A.begin(), A.end());

//     for (int i = 1; i <= n; i++) {
//         addToVal[i] = addToVal[i-1]+(m-A[i-1]);
//         subToVal[i] = subToVal[i-1]+(A[i-1]);
//     }

//     int ans = INT32_MAX;
//     for (auto x : modMs) {
//         // assume the value of x as something in the set of modMs
//         int sub_right = (m+((((m-1)/2)+x)%m))%m;
//         int sub_left = (m+(x%m))%m;

//         int operations = 0;
//         if (sub_left < sub_right) {
//             // the subtraction interval is in the center while the addition intervals are on the edges
//             int l = lower_bound(A.begin(), A.end(), sub_left)-A.begin();
//             int r = upper_bound(A.begin(), A.end(), sub_right)-A.begin();

//             if (x < 0) {
//                 operations = x*(r-l+1) + subToVal[r+1] - subToVal[l];
//             }
//             else {
//                 operations =  
//             }

//         }
//     }
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
		
// 	int t = 1;
//     cin >> t;
// 	while (t--) {
// 		solve();
// 	}
// }
#include <bits/stdc++.h>
using namespace std;

/*
  We want to compute:
     cost(x) = sum_{k=0..N-1} min(|R[k]-x|, M - |R[k]-x|)
  where 0 <= R[k] < M and 0 <= x < M.

  We'll do it by splitting the R[k] into two groups:
   - Those <= x: distance = x - R[k]
   - Those >  x: distance = R[k] - x
  Then we do a naive sum of these distances, and correct for
  elements whose distance is > M/2 (because then the real cost
  is M - distance).
*/

// static const long long INF = (long long)1e18;

// // We'll precompute prefix sums: PS[i] = R[0]+R[1]+...+R[i-1], with PS[0]=0.
// // So sum of R[l..r-1] = PS[r] - PS[l].
// long long getCost(long long x, const vector<long long> &R, long long M,
//                   const vector<long long> &PS) {
//     // N is the length of R
//     int N = (int)R.size();

//     // 1) Split by <= x and > x:
//     //    idx = # of R[k] <= x
//     //         = upper_bound(R.begin(), R.end(), x) - R.begin()
//     int idx = int(upper_bound(R.begin(), R.end(), x) - R.begin());
//     // naiveLeft = sum of (x - R[k]) for k in [0..idx-1]
//     //           = idx*x - sum(R[0..idx-1])
//     long long sumLeft = 0;
//     sumLeft = (long long)idx * x - PS[idx];

//     // naiveRight = sum of (R[k] - x) for k in [idx..N-1]
//     //            = ( sum(R[idx..N-1]) ) - x*(N-idx)
//     long long sumRight = 0;
//     sumRight = (PS[N] - PS[idx]) - (long long)(N - idx)* x;

//     // cost = naiveLeft + naiveRight, then we add corrections
//     // for distances that exceed M/2.
//     long long costLeft = sumLeft;
//     long long costRight = sumRight;

//     // We'll define halfDist = M/2.0 as double for comparisons:
//     long double halfDist = (long double)M / 2.0;

//     // 2) Correction for "left side" (those <= x) if x - R[k] > M/2:
//     //    That means R[k] < x - M/2. Let Ld = x - halfDist.
//     //    We want R[k] < Ld => distance (x-R[k]) > M/2 => actual cost = M - (x-R[k]).
//     //    The difference from naive is: (M - (x-R[k])) - (x-R[k]) = M - 2*(x-R[k]).
//     //    Summation for all such R[k].
//     long double Ld = (long double)x - halfDist;
//     // Find how many are strictly < Ld, but only among those in [0..idx-1].
//     // We'll do cidx = (int)(lower_bound(R.begin(), R.begin()+idx, Ld) - R.begin()).
//     int cidx = 0;
//     if (idx > 0) {
//         // clamp Ld so we can do a valid search on integer R
//         // If Ld <= R[0], cidx=0. If Ld > R[idx-1], cidx=idx.
//         // We'll just use lower_bound safely:
//         cidx = int(lower_bound(R.begin(), R.begin() + idx, Ld) - R.begin());
//     }
//     if (cidx > 0) {
//         // For those cidx elements, we add:
//         //  sum_{k=0..cidx-1}[ M - 2*(x - R[k]) ] = cidx*M - 2* [ sum_{k=0..cidx-1}(x - R[k]) ]
//         // Let sumDist = sum_{k=0..cidx-1}(x - R[k]) = cidx*x - sumR(cidx).
//         long long sumRleft = PS[cidx]; // sum of R[0..cidx-1]
//         long long sumDist = (long long)cidx * x - sumRleft;
//         long long correction = (long long)cidx * M - 2LL * sumDist;
//         costLeft += correction;
//     }

//     // 3) Correction for "right side" (those > x) if R[k] - x > M/2:
//     //    That means R[k] > x + M/2. Let Ud = x + halfDist.
//     //    We want R[k] > Ud => distance (R[k]-x) > M/2 => actual cost = M - (R[k]-x).
//     //    difference from naive: (M - (R[k]-x)) - (R[k]-x) = M - 2*(R[k]-x).
//     long double Ud = (long double)x + halfDist;
//     // Among [idx..N-1], find first that is > Ud => c2idx
//     int c2idx = N; 
//     if (idx < N) {
//         // c2idx = the earliest index in [idx..N] s.t. R[c2idx] > Ud
//         // so c2idx = upper_bound(..., Ud).
//         c2idx = int(upper_bound(R.begin() + idx, R.end(), Ud) - R.begin());
//     }
//     // Then the elements [c2idx..N-1] all satisfy R[k] > Ud => need correction
//     long long c2 = (long long)N - c2idx;
//     if (c2 > 0) {
//         // sumDist = sum_{k=c2idx..N-1} (R[k] - x).
//         //         = (PS[N] - PS[c2idx]) - x*c2.
//         long long sumRright = (PS[N] - PS[c2idx]);
//         long long sumDist = sumRright - (long long)c2 * x;
//         // correction = sum_{k=c2idx..N-1} [M - 2*(R[k]-x)] 
//         //            = c2*M - 2*sumDist.
//         long long correction = c2 * M - 2LL * sumDist;
//         costRight += correction;
//     }

//     long long totalCost = costLeft + costRight;
//     return totalCost;
// }


// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while(T--){
//         long long N, M;
//         cin >> N >> M;

//         vector<long long> A(N), R(N);
//         for(int i=0; i<N; i++){
//             cin >> A[i];
//         }

//         // Edge case: if N=1, answer = 0 (we can always pick x = A[0] to have cost 0)
//         if(N == 1){
//             cout << 0 << "\n";
//             continue;
//         }

//         // 1) Take residues mod M
//         for(int i=0; i<N; i++){
//             R[i] = A[i] % M;
//         }

//         // 2) Sort R
//         sort(R.begin(), R.end());

//         // 3) Build prefix sums PS for R
//         //    PS[i] = R[0] + R[1] + ... + R[i-1], (PS[0]=0)
//         vector<long long> PS(N+1, 0LL);
//         for(int i=1; i<=N; i++){
//             PS[i] = PS[i-1] + R[i-1];
//         }

//         // 4) Build doubled array S of size 2N
//         //    S[i] = R[i], S[i+N] = R[i] + M
//         vector<long long> S(2*N);
//         for(int i=0; i<N; i++){
//             S[i]   = R[i];
//             S[i+N] = R[i] + M;
//         }

//         // We'll do a two-pointer sweep to find arcs of length <= M/2 (in a real sense).
//         // We'll keep j "walking" forward as i goes from 0..N-1.
//         // Let halfDist = M/2.0.
//         long double halfDist = (long double)M / 2.0;
//         int j = 0;
//         long long ans = LLONG_MAX;

//         for(int i=0; i<N; i++){
//             long double limit = (long double)S[i] + halfDist;

//             // advance j while S[j] <= limit and j < i+N
//             while(j < i+N && (long double)S[j] <= limit){
//                 j++;
//             }
//             // now j is the first index where S[j] > limit (or j == i+N)
//             // the valid window is [i.. j-1].
//             int c = j - i; // number of points in the arc

//             // Decide candidate X:
//             if(2*c > N){
//                 // pick X = S[i]
//                 long long X = S[i];
//                 if(X >= M) X -= M;  // reduce mod M
//                 long long costVal = getCost(X, R, M, PS);
//                 ans = min(ans, costVal);
//             }
//             else if(2*c < N){
//                 // pick X = S[j-1]
//                 // but we must ensure j>i to have j-1 >= i
//                 if(c>0){
//                     long long X = S[j-1];
//                     if(X >= M) X -= M;
//                     long long costVal = getCost(X, R, M, PS);
//                     ans = min(ans, costVal);
//                 }
//             }
//             else{
//                 // 2*c == N, choose either boundary
//                 // pick X = S[i]
//                 {
//                     long long X = S[i];
//                     if(X >= M) X -= M;
//                     long long costVal = getCost(X, R, M, PS);
//                     ans = min(ans, costVal);
//                 }
//                 // or pick X = S[j-1] (if c>0)
//                 if(c>0){
//                     long long X = S[j-1];
//                     if(X >= M) X -= M;
//                     long long costVal = getCost(X, R, M, PS);
//                     ans = min(ans, costVal);
//                 }
//             }
//         }

//         // Print the best found
//         cout << ans << "\n";
//     }

//     return 0;
// }

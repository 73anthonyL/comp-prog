#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
#include <cmath>
#include <numeric>
#include <set>
#include <unordered_set>
#include <cstdint>
#include <string>
#include <map>
#include <unordered_map>
#include <bitset>
#include <iomanip>

const int MAXN = 100001;

using namespace std;
using ll = long long;
array<int, MAXN> a;
int t[4*MAXN];

// the build function takes in the actual array, the segtree node number, and the values in the real array that it represents
void build(array<int, MAXN> &a, int v, int tl, int tr) {
    // if the contiguous array represented by the current node is of size 1 (pointers are on top of each other) then set the node's sum to the number
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        // build the left side of the tree
        build(a, v*2, tl, tm);
        // build the right side of the tree
        build(a, v*2+1, tm+1, tr);
        // the sum of the current node is the sum of its two children
        t[v] = t[v*2] + t[v*2+1];
    }
}

// the sum function takes in the representative node, the left and ride actual element indices of the current segtree node
// the function also takes in the actual indices (inclusive) of the elements you want to sum
int sum(int v, int tl, int tr, int l, int r) {
    // check whether the current range to sum is valid
    if (l > r) 
        return 0;
    // if the node is completely equivalent to the stuff that needs to be summed then return the sum of the node that encloses the stuff
    if (l == tl && r == tr) {
        return t[v];
    }
    // since the node is not equivalent to the stuff that must be summed, you have to sum the intersection between the segtree child 1 & the l r interval, 
    // as well as the intersection between the segtree child 2 & the l r interval
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

// helper functions

int sum(int l, int r) {
    return sum(1, 0, n-1, l, r);
}

void update(int pos, int new_val) {
    update(1, 0, n-1, pos, new_val);
}

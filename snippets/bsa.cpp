ll lo = 0, hi = 10000000000012;
    // first true
    while (lo < hi) {
        ll mid = lo + (hi-lo)/2;
        if (canMake(mid)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    // last true
    while (lo < hi) {
        ll mid = lo + (hi-lo+1)/2;
        if (canMake(mid)) {
            lo = mid;
        }
        else {
            hi = mid-1;
        }
    }
    cout << lo << "\n";
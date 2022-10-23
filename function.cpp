#include <iostream>
#include <cstdio>

using namespace std;

#define ll long long 

ll binary(ll *a, ll n, ll l, ll r, ll k) {
    while (r - l > 1) {
        ll mid = (r+l)/2;
        ll count = 0;
        ll count1 = 1;
        for (ll i = 0; i < n; i++) {
            if (count + a[i] > mid) {
                count1 += 1;
                count = a[i];
            }
            else count += a[i];
            //
        }
        if (count1 <= k) {   //слишком мало
            r = mid;
        }
        else {
            l = mid;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n;
    ll k;
    cin >> n >> k;
    ll a[n];
    ll l_m = 0;
    ll r = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        l_m = max(l_m, a[i]);
    }
    ll s = binary(a, n, l_m, r, k);
    ll count = 0;
    ll count1 = 1;
    bool c[n];
    for (ll i = 0; i < n; i++) {
        c[i] = false;
    }
    for (ll i = 0; i < n && count1 < k; i++) {
        if (count + a[i] > s) {
            count1 += 1;
            count = a[i];
            c[i] = true;
        }
        else {
            c[i] = false;
            count += a[i];
        }
    }
    for (ll i = 1; count1 < k; i++) {
        count1 += !c[i];
        c[i] = true;
    }
    for (ll i = 0; i < n; i++) {
        if(c[i])
            printf("%d ", i);
    }
    return 0;
}
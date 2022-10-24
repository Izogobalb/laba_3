#include "iostream"
#include "string"
#include "vector"
#include "math.h"

using std::cin;
using std::cout;
using std::string;
//using std::endl;
using std::vector;

void quick_sort(vector<long long> &arr, int l, int r) {
    long long i = l;
    long long j = r;
    long long x = arr[(l + r) / 2];
    while (i <= j) {
        while (arr[i] < x) {
            i++;
        }
        while (arr[j] > x) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (l < j) {
        quick_sort(arr, l, j);
    }
    if (i < r) {
        quick_sort(arr, i, r);
    }
}


void razbienie(int arr[], int n, long long l, long long r, int k, vector<long long> &ans) {
    while (true) {
        if (l == r) {
            long long subsum = 0;
            int cnt = 0;
            vector<long long> borders;
            for (int i = 0; i < n - 1; i++) {
                subsum += arr[i];
                if (subsum + arr[i + 1] > r) {
                    cnt += 1;
                    borders.push_back(i+1);
                    ans.push_back(i+1);
                    subsum = 0;
                }
            }
            if (cnt < k-1) {
                for (int i = 1; i<n; i++) {
                    if (cnt == k - 1) {
                        break;
                    }
                    int flag = 0;
                    for (int j = 0; j < borders.size(); j++) {
                        if (borders[j] == i) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) {
                        ans.push_back(i);
                        cnt += 1;
                    }
                }
            }
            return;
        }
        long long mid = (l + r) / 2;
        int cnt = 0;
        long long subsum = 0;
        for (int i = 0; i < n - 1; i++) {
            subsum += arr[i];
            if (subsum + arr[i + 1] > mid) {
                cnt += 1;
                subsum = 0;
            }
        }
        if (cnt <= k-1) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
}



int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long max = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    vector<long long> ans;
    razbienie(arr, n, max, sum, k, ans);
    quick_sort(ans, 0, ans.size()-1);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
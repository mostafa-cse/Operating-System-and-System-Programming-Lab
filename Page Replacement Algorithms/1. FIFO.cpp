#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    int _nPages, _nFrames;
    cin >> _nPages >> _nFrames;

    vector<int> pages(_nPages);
    for (int i = 0; i < _nPages; i++) {
        cin >> pages[i];
    }

    queue<int> Memory;
    set<int> isExist;
    int hits = 0, faults = 0;
    for (int i = 0; i < _nPages; i++) {
        dout(Memory, pages[i]);
        if (isExist.count(pages[i])) {
            dout(i, ":", "Hits");
            hits++;
        } else {
            faults++;
            if (Memory.size() == _nFrames) {
                // Remove longer stay page
                int longerStay = Memory.front();
                Memory.pop();
                isExist.erase(longerStay);

                // Push demanding page
                Memory.push(pages[i]);
                isExist.insert(pages[i]);
                dout("Pop : ", longerStay, "Push : ", pages[i]);
            } else {
                // Push demanding page
                Memory.push(pages[i]);
                isExist.insert(pages[i]);
                dout("Push : ", pages[i]);
            }
        }
        dout(Memory);
        dout("current : Hits", hits, "\tFaults : ", faults);
        cerr << endl;
    }

    cout << "Hits : " << hits << endl;
    cout << "Hits ratio : " << hits * 1.00 / _nPages * 100 << "%" << endl
         << endl;
    ;

    cout << "Faults : " << faults << endl;
    cout << "Faults Ratio : " << faults * 1.00 / _nPages * 100 << "%" << endl;

    return 0;
}
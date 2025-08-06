#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
using PQ = priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>;
void fixLocation(PQ &pq, const vector<int>& pages, int idx) {
    PQ temp;
    while (!pq.empty()) {
        auto [pi, mi] = pq.top();
        pq.pop();
        if (pi == idx || pages[pi] == pages[idx]) {
            pi = idx;
        }
        temp.emplace(pi, mi);
    }
    pq = move(temp);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _nPages, _nFrames;
    cin >> _nPages >> _nFrames;
    vector<int> pages(_nPages);
    for (int &x : pages) cin >> x;

    PQ memory_order;
    vector<int> Memory;
    unordered_set<int> isExist;
    int hits = 0, faults = 0;

    for (int i = 0; i < _nPages; i++) {
        int p = pages[i];
        dout("Access", p, "idx", i);
        if (isExist.count(p)) {
            hits++;
            dout("Hit", p);
            fixLocation(memory_order, pages, i);
        } else {
            faults++;
            dout("Fault", p);
            if ((int)Memory.size() == _nFrames) {
                auto [pi, mi] = memory_order.top();
                memory_order.pop();
                int oldPage = Memory[mi];
                isExist.erase(oldPage);
                Memory[mi] = p;
                isExist.insert(p);
                dout("Replace idx", mi, "oldPage", oldPage, "newPage", p);
                memory_order.emplace(i, mi);
            } else {
                Memory.push_back(p);
                isExist.insert(p);
                memory_order.emplace(i, Memory.size() - 1);
                dout("Allocate frame", Memory.size()-1, "page", p);
            }
        }
        dout("Memory", [&]{ string s; for(int v:Memory) s += to_string(v)+" "; return s; }());
    }
    cout << "Hits : " << hits << "\n";
    cout << "Faults : " << faults << "\n";
    return 0;
}

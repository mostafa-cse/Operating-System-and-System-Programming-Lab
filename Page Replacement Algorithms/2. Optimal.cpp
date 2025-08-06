#include <bits/stdc++.h>
using namespace std;

int get_index(const vector<int>& pgs, const vector<int>& memory, int n, int idx) {
    int farthest = idx, res = -1;
    for (int i = 0; i < memory.size(); i++) {
        int notDemaiding = true;
        for (int j = idx; j < n; j++) {
            if (memory[i] == pgs[j]) {
                notDemaiding = false;
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (notDemaiding) {
            return i;
        }
    }
    return (res == -1) ? 0 : res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _nPages, _nFrames;
    cin >> _nPages >> _nFrames;

    vector<int> pages(_nPages);
    for (int &x : pages)
        cin >> x;

    vector<int> memory;
    int faults = 0, hits = 0;

    for (int i = 0; i < _nPages; i++) {
        int page = pages[i];
        auto it = find(memory.begin(), memory.end(), page);
        if (it == memory.end()) {
            if ((int)memory.size() < _nFrames) {
                memory.push_back(page);
            } else {
                int idx = get_index(pages, memory, _nPages, i + 1);
                memory[idx] = page;
            }
            faults++;
        } else {
            hits++;
        }
    }

    cout << "Page Faults: " << faults << "\n";
    cout << "Hits: " << hits << "\n";
    return 0;
}

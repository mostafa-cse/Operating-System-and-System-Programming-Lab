#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;

struct Process {
    int id, arrival, burst, remain, wait, turn, complete;
};

signed main() {
    int n;
    cin >> n;
    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].arrival >> p[i].burst;
        p[i].remain = p[i].burst;
    }

    int time = 0, done = 0;
    int prev = -1;
    vector<bool> completed(n, false);

    while (done < n) {
        int idx = -1;
        int min_remain = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].arrival <= time && p[i].remain < min_remain) {
                min_remain = p[i].remain;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].remain--;
            time++;

            if (p[idx].remain == 0) {
                completed[idx] = true;
                done++;
                p[idx].complete = time;
                p[idx].turn = p[idx].complete - p[idx].arrival;
                p[idx].wait = p[idx].complete - p[idx].burst;
            }
        } else {
            time++;
        }
    }

    double total_wait = 0, total_turn = 0;
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : p) {
        total_wait += x.wait;
        total_turn += x.turn;
        cout << "P" << x.id << "\t" << x.arrival << "\t" << x.burst << "\t" << x.complete << "\t" << x.turn << "\t" << x.wait << '\n';
    }
    cout << "Avg WT: " << fixed << setprecision(2) << total_wait / n << " Avg TAT: " << total_turn / n << '\n';
    return 0;
}

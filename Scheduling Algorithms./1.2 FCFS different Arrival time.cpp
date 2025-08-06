#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrival;
    int brust;
    int waiting;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Process> P(n);
    for (int i = 0; i < n; i++) {
        P[i].id = i;
        cin >> P[i].arrival >> P[i].brust;
    }

    sort(P.begin(), P.end(), [](const Process &a, const Process &b)
         { return a.arrival < b.arrival || (a.arrival == b.arrival && a.id < b.id); });

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        // If CPU is idle, jump to arrival
        if (currentTime < P[i].arrival) {
            currentTime = P[i].arrival;
        }
        // Waiting = time from arrival until it actually starts
        P[i].waiting = currentTime - P[i].arrival;
        // Advance clock by its burst
        currentTime += P[i].brust;
    }

    cout << "ID\tArrival\tBrust\tWaiting\n";
    for (auto &pr : P) {
        cout << pr.id << "\t" << pr.arrival << "\t" << pr.brust << "\t" << pr.waiting << "\n";
    }
    cout << P.back().waiting * 1.00 / n << endl;
    return 0;
}
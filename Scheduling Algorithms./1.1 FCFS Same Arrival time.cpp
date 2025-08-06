#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> processes(n);
    for (int i = 0; i < n; i++) {
        cin >> processes[i];
    }

    vector<int> burst_time(n);
    for (int i = 0; i < n; i++) {
        cin >> burst_time[i];
    }
    
    vector<int> waiting(n, 0);
    for (int i = 1; i < n; i++) {
        waiting[i] = burst_time[i - 1] + waiting[i - 1];
    }

    int total_waiting = 0;
    for (int i = 0; i < n; i++) {
        total_waiting += waiting[i];
    }
    cout << "Process\t\tBrust time\t\t Waiting Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t\t" << burst_time[i] << "\t\t" << waiting[i] << endl;
    }
    cout << "Average Waiting Time : " << total_waiting * 1.00 / n << endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int pid;           // Process ID
    int burstTime;     // Burst Time
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

bool compareBurst(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

int main() {
    int n;
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cin >> processes[i].burstTime;
    }

    // Sort processes based on burst time
    sort(processes.begin(), processes.end(), compareBurst);

    int currentTime = 0;
    float totalTAT = 0, totalWT = 0;

    for (int i = 0; i < n; i++) {
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime; // AT = 0
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;
    }

    // Output
    cout << "\nPID\tBT\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        cout << "P" << p.pid << "\t" << p.burstTime << "\t" << p.completionTime
             << "\t" << p.turnaroundTime << "\t" << p.waitingTime << "\n";
    }

    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    cout << "\nAverage Waiting Time: " << totalWT / n << endl;

    return 0;
}

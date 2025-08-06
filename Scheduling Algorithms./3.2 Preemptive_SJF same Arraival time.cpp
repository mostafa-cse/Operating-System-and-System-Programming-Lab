#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n;
    cin >> n;

    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        cin >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
    }

    int completed = 0;
    int currentTime = 0;
    int prev = -1;
    int shortest = -1;
    int minRemaining = INT_MAX;

    while (completed != n) {
        shortest = -1;
        minRemaining = INT_MAX;

        // Find process with shortest remaining time
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0 && processes[i].remainingTime < minRemaining) {
                minRemaining = processes[i].remainingTime;
                shortest = i;
            }
        }

        if (shortest == -1) {
            // No process left to run (should not happen here)
            currentTime++;
            continue;
        }

        // Execute process for 1 unit time
        processes[shortest].remainingTime--;
        currentTime++;

        // If process finished
        if (processes[shortest].remainingTime == 0) {
            completed++;
            processes[shortest].completionTime = currentTime;
            processes[shortest].turnaroundTime = processes[shortest].completionTime;  // AT=0
            processes[shortest].waitingTime = processes[shortest].turnaroundTime - processes[shortest].burstTime;
        }
    }

    float totalTAT = 0, totalWT = 0;
    cout << "\nPID\tBT\tCT\tTAT\tWT\n";
    for (auto& p : processes) {
        cout << "P" << p.pid << "\t" << p.burstTime << "\t" << p.completionTime << "\t"
             << p.turnaroundTime << "\t" << p.waitingTime << "\n";

        totalTAT += p.turnaroundTime;
        totalWT += p.waitingTime;
    }

    cout << "\nAverage Turnaround Time: " << totalTAT / n;
    cout << "\nAverage Waiting Time: " << totalWT / n << endl;

    return 0;
}

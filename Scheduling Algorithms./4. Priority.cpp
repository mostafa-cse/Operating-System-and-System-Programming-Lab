#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string pid;
    int burst;
    int priority;
    int arrival = 0;
    int finish = 0;
    int waiting = 0;
    int turnaround = 0;
};
int main()
{
    int n;
    cin >> n;
    vector<Node> procs(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> procs[i].pid >> procs[i].burst >> procs[i].priority;
        procs[i].arrival = 0;
    }
    cout << "Initial Process : \n";
    cout << "Process_ID\tBurst time\tPriority\tWaiting Time\n";
    for (int i = 0; i < n; ++i)
    {
        cout << procs[i].pid << "\t\t"
             << procs[i].burst << "\t\t"
             << procs[i].priority << "\t\t"
             << procs[i].waiting << "\t\n";
    }
    cout << endl;
    sort(procs.begin(), procs.end(), [](const Node &a, const Node &b)
         { return a.priority < b.priority; });
    int currentTime = 0;
    for (int i = 0; i < n; ++i)
    {
        procs[i].waiting = currentTime - procs[i].arrival;
        procs[i].finish = currentTime + procs[i].burst;
        procs[i].turnaround = procs[i].finish - procs[i].arrival;
        currentTime = procs[i].finish;
    }
    double totalWT = 0, totalTAT = 0;
    cout << "After Complete Process : \n";
    cout << "Process_ID\tBurst time\tPriority\tWaiting Time\n";
    for (int i = 0; i < n; ++i)
    {
        totalWT += procs[i].waiting;
        totalTAT += procs[i].turnaround;
        cout << procs[i].pid << "\t\t"
             << procs[i].burst << "\t\t"
             << procs[i].priority << "\t\t"
             << procs[i].waiting << "\t\n";
    }
    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time : " << (totalWT * 1.00 / n);
    return 0;
}

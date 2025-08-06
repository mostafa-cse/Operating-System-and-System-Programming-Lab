#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node() : pid(""), burst(0) {}
    string pid;
    int burst;
    int priority;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};
int main()
{
    int n, quantum;
    cin >> n;
    cin >> quantum;
    vector<Node> procs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> procs[i].pid >> procs[i].burst >> procs[i].priority;
    }
    int time = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        procs[i].remaining = procs[i].burst;
        q.push(i);
    }
    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        if (procs[i].remaining > quantum)
        {
            time += quantum;
            procs[i].remaining -= quantum;
            q.push(i);
        }
        else
        {
            time += procs[i].remaining;
            procs[i].remaining = 0;
            procs[i].completion = time;
            procs[i].turnaround = time;
            procs[i].waiting = procs[i].turnaround - procs[i].burst;
        }
    }
    int total_waiting_time = 0;
    cout << "Process_ID\tBurst_Time\tPriority\tWaiting_Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << procs[i].pid << "\t\t"
             << procs[i].burst << "\t\t"
             << procs[i].priority << "\t\t"
             << procs[i].waiting << "\n";
        total_waiting_time += procs[i].waiting;
    }
    cout << "Total Average Waiting time : " << total_waiting_time * 1.00 / n << endl;
    return 0;
}

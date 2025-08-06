#include <bits/stdc++.h>
using namespace std;
struct process
{
    string processName;
    int inputSerial, arrivalTime, burstTime;
};
int32_t main()
{
    int N;
    cin >> N;
    vector<process> v(N);
    for (int i = 0; i < N; i++)
    {
        v[i].inputSerial = i;
        cin >> v[i].processName >> v[i].arrivalTime >> v[i].burstTime;
    }
    struct customCompare
    {
        bool operator()(process &a, process &b)
        {
            if (a.burstTime != b.burstTime)
                return a.burstTime > b.burstTime;
            if (a.arrivalTime != b.arrivalTime)
                return a.arrivalTime > b.arrivalTime;
            return a.inputSerial > b.inputSerial;
        }
    };
    priority_queue<process, vector<process>, customCompare> pq;

    sort(v.begin(), v.end(), [](process &a, process &b)
         { return a.arrivalTime < b.arrivalTime; });
    int time = 0, totalWaitingTime = 0;
    cout << "[Time: " << time << "]\n";
    for (int i = 0; i < N; i++)
    {
        if (time < v[i].arrivalTime)
        {
            time = v[i].arrivalTime;
            cout << "[Time: " << time << "]\n";
        }
        pq.push(v[i]);
        if (i < N - 1 && v[i + 1].arrivalTime <= time)
            continue;
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            cout << it.processName << '\n';
            time += it.burstTime;
            cout << "[Time: " << time << "]\n";
            cout << "Waiting time of " << it.processName << " is " << time

                                                                          - it.burstTime - it.arrivalTime
                 << '\n';

            totalWaitingTime += time - it.burstTime - it.arrivalTime;
            if (i < N - 1 && v[i + 1].arrivalTime <= time)
                break;
        }
    }

    double avgWaitingTime = totalWaitingTime / (1.0 * N);
    cout << "Average waiting time: " << avgWaitingTime << '\n';
    return 0;
}
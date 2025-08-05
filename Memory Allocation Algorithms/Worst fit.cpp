#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int nBlocks, nProcesses;
    cout << "Enter number of memory blocks: ";
    cin >> nBlocks;
    vector<int> blockSize(nBlocks);
    cout << "Enter sizes of memory blocks: ";
    for (int i = 0; i < nBlocks; i++) cin >> blockSize[i];

    cout << "Enter number of processes: ";
    cin >> nProcesses;
    vector<int> processSize(nProcesses);
    cout << "Enter sizes of processes: ";
    for (int i = 0; i < nProcesses; i++) cin >> processSize[i];

    vector<int> allocation(nProcesses, -1);

    for (int i = 0; i < nProcesses; i++) {
        int worstIdx = -1;
        for (int j = 0; j < nBlocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < nProcesses; i++) {
        cout << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i]+1 << endl;
        else
            cout << "Not Allocated" << endl;
    }
    return 0;
}
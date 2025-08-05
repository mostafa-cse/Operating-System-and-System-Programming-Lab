#include <bits/stdc++.h>
#define int long long
using namespace std;
#ifndef ONLINE_JUDGE
#define dout(...) cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define dout(...)
#endif
signed main() {
    int _nProcess, _nResource;
    cin >> _nProcess >> _nResource;

    vector<int> Available(_nResource);
    for (int i = 0; i < _nResource; i++) {
        cin >> Available[i];
    }

    vector<string> process(_nProcess);
    vector<vector<int>> Allocation(_nProcess, vector<int>(_nResource));
    vector<vector<int>> Max(_nProcess, vector<int>(_nResource));
    for (int i = 0; i < _nProcess; i++) {
        cin >> process[i];
        for (int j = 0; j < _nResource; j++) {
            cin >> Allocation[i][j];
        }
        for (int j = 0; j < _nResource; j++) {
            cin >> Max[i][j];
        }
    }


    vector<vector<int>> Need(_nProcess, vector<int>(_nResource));
    for (int i = 0; i < _nProcess; i++) {
        for (int j = 0; j < _nResource; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    vector<string> Sequence;
    vector<int> finished(_nProcess, 0);
    int cntFinishProcess = 0;
    bool isProceed = true;
    while (isProceed) {
        isProceed = false;
        for (int i = 0; i < _nProcess; ++i) {
            if (finished[i] == 0) {
                int canProceed = 1;
                for (int j = 0; j < _nResource; j++) {
                    canProceed &= (Need[i][j] <= Available[j]);
                }
                if (canProceed == 1) {
                    Sequence.push_back(process[i]);
                    finished[i] = 1;
                    for (int j = 0; j < _nResource; j++) {
                        Available[j] += Allocation[i][j];
                    }
                    cntFinishProcess += 1;
                    isProceed = true;
                }
            }   
        }
    }

    if (cntFinishProcess == _nProcess) {
        cout << "System is in Safe State!" << endl;
        cout << "Safe State Sequence is : ";
        for (int i = 0; i < _nProcess; i++) {
            cout << Sequence[i];
            if (i != _nProcess - 1) {
                cout << " -> ";
            }
        }
    } else {
        cout << "System is Not Safe State! This Process May occurs DeadLock.";
    }
    return 0;
}

/*
Test - 1:
5 3
3 3 2
P0 0 1 0 7 5 3
P1 2 0 0 3 2 2
P2 3 0 2 9 0 2
P3 2 1 1 2 2 2
P4 0 0 2 4 3 3

Expected :
System is in Safe State!
Safe State Sequence is : P1 -> P3 -> P4 -> P0 -> P2


Test - 2 : 
3 3
1 0 0
P0 0 1 0 7 5 3
P1 2 0 0 3 2 2
P2 3 0 2 9 0 2

Expected : 
System is Not Safe State! This Process May occurs DeadLock.

Test - 3 : 
4 2
0 0
P0 1 0 2 1
P1 1 1 2 2
P2 0 1 1 2
P3 1 0 2 1

Expected : 
System is Not Safe State! This Process May occurs DeadLock.


Test - 4:
4 4
1 5 2 0
P0 0 0 1 2 0 0 1 2
P1 1 0 0 0 1 7 5 0
P2 1 3 5 4 2 3 5 6
P3 0 6 3 2 0 6 5 2

Expected : 
System is in Safe State!
Safe State Sequence is : P0 -> P2 -> P3 -> P1

Test - 5 : 
3 2
2 1
P0 1 0 3 2
P1 0 1 2 1
P2 1 1 2 2

Expexted : 
System is in Safe State!
Safe State Sequence is : P1 -> P2 -> P0
*/
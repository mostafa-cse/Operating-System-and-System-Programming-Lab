#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int _nProcess, _nBlock;
    cin >> _nBlock >> _nProcess;

    vector<int> Block(_nBlock + 1, 1e18); // We initialize all block size to 1e18
    for (int i = 0; i < _nBlock; i++) {
        cin >> Block[i];
    }

    vector<int> Process(_nProcess);
    for (int i = 0; i < _nProcess; i++) {
        cin >> Process[i];
    }

    vector<int> Allocated(_nProcess, -1), Occupied(_nBlock, 0);
    for (int i = 0; i < _nProcess; i++) {
        int bestID = _nBlock;
        for (int j = 0; j < _nBlock; j++) {
            if (Occupied[j] == 0 and Block[j] >= Process[i]) {
                if (Block[bestID] > Block[j]) {
                    bestID = j;
                }
            }
        }
        if (bestID != _nBlock) {
            Allocated[i] = bestID;
            Occupied[bestID] = 1;
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < _nProcess; ++i) {
        cout << "   " << i + 1 << "\t\t" << Process[i] << " \t\t";
        if (Allocated[i] == -1) {
            cout << "Not Allocated";
        } else {
            cout << Allocated[i] + 1;
        }
        cout << endl;
    }
    return 0;
}

/*
Test :
3 3
5 10 20
10 20 5

Expected : 
Process No.	Process Size	Block no.
   1		    10 		        2
   2		    20 		        3
   3		    5 		        1
*/
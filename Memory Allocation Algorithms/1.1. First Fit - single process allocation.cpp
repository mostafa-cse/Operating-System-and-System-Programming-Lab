#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int _nBlock, _nProcess;
    cin >> _nBlock >> _nProcess;

    vector<int> Block(_nBlock), Process(_nProcess);
    for (int i = 0; i < _nBlock; i++) {
        cin >> Block[i];
    }

    for (int i = 0; i < _nProcess; i++) {
        cin >> Process[i];
    }

    vector<int> Allocated(_nProcess, -1), occupied(_nBlock, 0);
    for (int i = 0; i < _nProcess; i++) {
        for (int j = 0; j < _nBlock; j++) {
            if (occupied[j] == 0 and Block[j] >= Process[i]) {
                occupied[j] = 1;
                Allocated[i] = j; // i'th Process allocated at j'th Block
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < _nProcess; ++i) {
        cout << "   " << i + 1 << "\t\t  " << Process[i] << "\t\t";
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
Testcase :
3 3
30 5 10
10 6 9

Expected : 

Process No.	Process Size	Block no.
   1		  10		1
   2		  6		3
   3		  9		Not Allocated

*/
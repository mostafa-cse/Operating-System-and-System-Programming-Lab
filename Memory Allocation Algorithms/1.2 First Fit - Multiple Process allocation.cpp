#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int _nProcess, _nBlock;
    cin >> _nBlock >> _nProcess;

    vector<int> Block(_nBlock);
    for (int i = 0; i < _nBlock; i++) {
        cin >> Block[i];
    }

    vector<int> Process(_nProcess);
    for (int i = 0; i < _nProcess; i++) {
        cin >> Process[i];
    }

    vector<int> Allocated(_nProcess, -1);
    for (int i = 0; i < _nProcess; i++) {
        for (int j = 0; j < _nBlock; j++) {
            if (Block[j] >= Process[i]) {
                Allocated[i] = j;
                Block[j] -= Process[i];
                break;
            }
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
17 5 10
10 6 9

Expected : 
Process No.	Process Size	Block no.
   1		10 		1
   2		6 		1
   3		9 		3

*/
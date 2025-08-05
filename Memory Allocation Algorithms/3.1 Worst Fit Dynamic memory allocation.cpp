#include <bits/stdc++.h>
using namespace std;

int main()  {
    int _nBlock, _nProcess;
    cin >> _nBlock >> _nProcess;

    vector<int> Block(_nBlock);
    for (int i = 0; i < _nBlock; i++) {
        cin >> Block[i];
    }

    vector<int> Process(_nProcess);
    for (int i = 0; i < _nProcess; i++) {
        cin >> Process[i];
    }

    vector<int> allocate(_nProcess, -1);
    for (int i = 0; i < _nProcess; i++) {
        int wstIdx = -1;
        for (int j = 0; j < _nBlock; j++) { 
            if (Block[j] >= Process[i]) {
                if (wstIdx == -1) {
                    wstIdx = j;
                } else if (Block[wstIdx] < Block[j]) {
                    wstIdx = j;
                }
            }
        }

        if (wstIdx != -1) {
            allocate[i] = wstIdx;
            Block[wstIdx] -= Process[i];
        }
    }

    cout << "Process Number \tProcess Size\tBlock Number\n";
    for (int i = 0; i < _nProcess; i++) {
        cout << "   " << i + 1 << "\t\t" << Process[i] << "\t\t";
        if (allocate[i] != -1) {
            cout << allocate[i] + 1;
        } else {
            cout << "Not Allocated";
        }
        cout << endl;
    }
    return 0;
}

/*
Test : 
5 4
100 500 200 300 600
212 417 112 426

Expected : 
Process Number 	Process Size	Block Number
   1		        212		         5
   2		        417		         2
   3		        112		         5
   4		        426		    Not Allocated
*/
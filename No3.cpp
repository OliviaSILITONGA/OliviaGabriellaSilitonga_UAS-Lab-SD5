#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int hitung_grup(int karyawan_id, const vector<int>& manajer, vector<int>& memo) {
   
    if (memo[karyawan_id] != 0) {
        return memo[karyawan_id];
    }

    int manajer_id = manajer[karyawan_id];

    if (manajer_id == -1) {
  
        memo[karyawan_id] = 1;
        return 1;
    } else {
       
        int grup = 1 + hitung_grup(manajer_id - 1, manajer, memo);
        memo[karyawan_id] = grup;
        return grup;
    }
}

int main() {
    int n;    if (!(cin >> n)) return 0;

    vector<int> manajer(n);

    for (int i = 0; i < n; ++i) {
        int pi;
        cin >> pi;
        manajer[i] = pi;
    }


    vector<int> memo(n, 0);

    int max_grup = 0;


    for (int i = 0; i < n; ++i) {
    
        int current_grup = hitung_grup(i, manajer, memo);
        if (current_grup > max_grup) {
            max_grup = current_grup;
        }
    }

    cout << max_grup << endl;

    return 0;
}

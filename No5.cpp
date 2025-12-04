#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(const vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (low == high) {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);

        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> bangku(n);

    for (int i = 0; i < n; i++) {
        cin >> bangku[i];
    }

    int cari;
    cin >> cari;

    int idx = interpolationSearch(bangku, cari);

    cout << "Nomor bangku dicari: " << cari << "\n";
    if (idx != -1) {
        cout << "Status: TERSEDIA\n";
        cout << "Posisi index: " << idx << ", Nomor bangku: " << bangku[idx] << "\n";
    } else {
        cout << "Status: TIDAK TERSEDIA\n";
        int closest = -1;
        for (int i = 0; i < n; i++) {
            if (bangku[i] > cari) {
                closest = bangku[i];
                break;
            }
        }
        if (closest != -1) {
            cout << "Opsi bangku terdekat: " << closest << "\n";
        } else {
            cout << "Tidak ada bangku terdekat tersedia.\n";
        }
    }

    return 0;
}

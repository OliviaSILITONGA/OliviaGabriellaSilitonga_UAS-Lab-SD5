#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string layanan;
    int urutanDatang;
};

int main() {
    int n;
    cin >> n;

    vector<Pelanggan> data(n);
    
    for (int i = 0; i < n; i++) {
        cin >> data[i].nama >> data[i].berat >> data[i].layanan;
        data[i].urutanDatang = i;
    }

   
    sort(data.begin(), data.end(), [](Pelanggan a, Pelanggan b) {
        if (a.layanan != b.layanan)
            return a.layanan == "express";

       
        if (a.layanan == "express" && b.layanan == "express") {
            if (a.berat != b.berat)
                return a.berat > b.berat;
        }
         return a.urutanDatang < b.urutanDatang;
    });

    int totalWaktu = 0;

    cout << "Urutan: ";
    for (auto &p : data) {
        cout << p.nama << " ";

        if (p.layanan == "express")
            totalWaktu += p.berat * 5;
        else
            totalWaktu += p.berat * 10;
    }

    cout << "\nTotal waktu: " << totalWaktu << " menit\n";

    return 0;
}

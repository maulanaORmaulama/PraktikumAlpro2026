#include <iostream>

#define MAX 100

bool cekAngka(std::string teks);
int stringKeInt(std::string teks);
void menuStore();
void menuUtama();

void clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
void pauseScreen() {
    std::cout << "Press any key to continue . . . ";
    std::cin.ignore();
    std::cin.get();
}

void tambahData(std::string barang[], int harga[], int jumlah[], int index, std::string nama, int stok, int hargaBarang) {
    barang[index] = nama;
    jumlah[index] = stok;
    harga[index] = hargaBarang;
}

void hapusBarang(std::string barang[], int jumlah[], int harga[], int &totalData, int indexHapus) {
    for (int idx = indexHapus; idx < totalData - 1; idx++) {
        barang[idx] = barang[idx + 1];
        harga[idx] = harga[idx + 1];
        jumlah[idx] = jumlah[idx + 1];
    }
    totalData--;
}

void fungsiHapus(std::string barang[], int harga[], int jumlah[], int &totalData, int indexHapus) {
    if (indexHapus >= 0 && indexHapus < totalData) {
        std::string namaDihapus = barang[indexHapus];
        hapusBarang(barang, jumlah, harga, totalData, indexHapus);
        std::cout << "[Berhasil] " << namaDihapus << " dihapus! (Total barang: " << totalData << ")" << std::endl;
    } else {
        std::cout << "[Gagal] Nomor " << (indexHapus + 1) << " tidak valid! Pilih antara 1 sampai " << totalData << "." << std::endl;
    }
}

void storeInputBarang(std::string barang[], int jumlah[], int harga[], int &totalData) {
    clearScreen();
    std::cout << "#===============================#" << std::endl;
    std::cout << "|          TIVAIZ STORE         |" << std::endl;
    std::cout << "#===============================#" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "           INPUT BARANG         " << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    std::string inputBarang;
    int inputJumlah;
    int inputHarga;

    std::cout << "Nama Barang  : ";
    std::cin.ignore();
    std::getline(std::cin, inputBarang);
    std::cout << "--------------------------------" << std::endl;

    std::cout << "Stok (unit)  : ";
    std::cin >> inputJumlah;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Stok harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }
    std::cout << "--------------------------------" << std::endl;

    std::cout << "Harga (Rp)   : ";
    std::cin >> inputHarga;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Harga harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }
    std::cout << "--------------------------------" << std::endl;

    if (inputHarga <= 0) {
        std::cout << "[Gagal] Harga harus lebih dari 0!" << std::endl;
        pauseScreen();
        return;
    }

    tambahData(barang, harga, jumlah, totalData, inputBarang, inputJumlah, inputHarga);
    totalData++;
    std::cout << "[Berhasil] " << inputBarang << " ditambahkan! (Total barang: " << totalData << ")" << std::endl;
    pauseScreen();
}

void storeHapusBarang(std::string barang[], int jumlah[], int harga[], int &totalData) {
    clearScreen();
    std::cout << "#===============================#" << std::endl;
    std::cout << "|          TIVAIZ STORE         |" << std::endl;
    std::cout << "#===============================#" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "           HAPUS BARANG         " << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (int idx = 0; idx < totalData; idx++) {
        std::cout << "No           : " << (idx + 1) << std::endl;
        std::cout << "Nama Barang  : " << barang[idx] << std::endl;
        std::cout << "Stok Barang  : " << jumlah[idx] << std::endl;
        std::cout << "Harga/Stok   : Rp " << harga[idx] << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }

    std::cout << "Pilih nomor barang yang dihapus (1-" << totalData << "): ";
    int indeksHapus;
    std::cin >> indeksHapus;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }

    indeksHapus--;
    fungsiHapus(barang, harga, jumlah, totalData, indeksHapus);
    pauseScreen();
}

void editHarga(int &harga, std::string namaBarang) {
    int hargaBaru;
    std::cout << "Harga baru (Rp): ";
    std::cin >> hargaBaru;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }
    int hargaLama = harga;
    harga = hargaBaru;
    std::cout << "[Berhasil] Harga " << namaBarang << ": Rp " << hargaLama << " -> Rp " << harga << std::endl;
    pauseScreen();
}

void tambahStok(int &stok, std::string namaBarang) {
    int jumlahEdit;
    std::cout << "Jumlah tambah: ";
    std::cin >> jumlahEdit;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }
    int stokLama = stok;
    stok += jumlahEdit;
    std::cout << "[Berhasil] Stok " << namaBarang << ": " << stokLama << " -> " << stok << std::endl;
    pauseScreen();
}

void kurangiStok(int &stok, std::string namaBarang) {
    int jumlahEdit;
    std::cout << "Jumlah kurang: ";
    std::cin >> jumlahEdit;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
        pauseScreen();
        return;
    }
    if (jumlahEdit >= stok) {
        std::cout << "[Gagal] Stok minimal 1!" << std::endl;
        std::cout << "Stok saat ini : " << stok << std::endl;
        std::cout << "Maks dikurangi: " << (stok - 1) << std::endl;
    } else {
        int stokLama = stok;
        stok -= jumlahEdit;
        std::cout << "[Berhasil] Stok " << namaBarang << ": " << stokLama << " -> " << stok << std::endl;
    }
    pauseScreen();
}

void storeEditBarang(std::string barang[], int jumlah[], int harga[], int &totalData) {
    while (true) {
        clearScreen();
        std::cout << "#===============================#" << std::endl;
        std::cout << "|          TIVAIZ STORE         |" << std::endl;
        std::cout << "#===============================#" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "           EDIT BARANG          " << std::endl;
        std::cout << "--------------------------------" << std::endl;

        for (int idx = 0; idx < totalData; idx++) {
            std::cout << "No           : " << (idx + 1) << std::endl;
            std::cout << "Nama Barang  : " << barang[idx] << std::endl;
            std::cout << "Stok Barang  : " << jumlah[idx] << std::endl;
            std::cout << "Harga/Stok   : Rp " << harga[idx] << std::endl;
            std::cout << "--------------------------------" << std::endl;
        }

        std::cout << "Pilih nomor barang yang diedit (1-" << totalData << "): ";
        int pilihanBarang;
        std::cin >> pilihanBarang;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
            pauseScreen();
            return;
        }

        if (pilihanBarang < 1 || pilihanBarang > totalData) {
            std::cout << "[Gagal] Nomor " << pilihanBarang << " tidak valid! Pilih antara 1 sampai " << totalData << "." << std::endl;
            pauseScreen();
            return;
        }

        pilihanBarang--;

        while (true) {
            clearScreen();
            std::cout << "#===============================#" << std::endl;
            std::cout << "|          TIVAIZ STORE         |" << std::endl;
            std::cout << "#===============================#" << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "           EDIT BARANG          " << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Barang: " << barang[pilihanBarang] << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "1. Edit Harga" << std::endl;
            std::cout << "2. Tambah Stok" << std::endl;
            std::cout << "3. Kurangi Stok" << std::endl;
            std::cout << "0. Kembali" << std::endl;
            std::cout << "--------------------------------" << std::endl;
            std::cout << "Pilih opsi: ";

            int pilihanEdit;
            std::cin >> pilihanEdit;

            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
                pauseScreen();
                continue;
            }

            if (pilihanEdit == 1) {
                clearScreen();
                std::cout << "#===============================#" << std::endl;
                std::cout << "|          TIVAIZ STORE         |" << std::endl;
                std::cout << "#===============================#" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "           EDIT BARANG          " << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Barang: " << barang[pilihanBarang] << std::endl;
                std::cout << "--------------------------------" << std::endl;
                editHarga(harga[pilihanBarang], barang[pilihanBarang]);
            } else if (pilihanEdit == 2) {
                clearScreen();
                std::cout << "#===============================#" << std::endl;
                std::cout << "|          TIVAIZ STORE         |" << std::endl;
                std::cout << "#===============================#" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "           EDIT BARANG          " << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Barang: " << barang[pilihanBarang] << std::endl;
                std::cout << "--------------------------------" << std::endl;
                tambahStok(jumlah[pilihanBarang], barang[pilihanBarang]);
            } else if (pilihanEdit == 3) {
                clearScreen();
                std::cout << "#===============================#" << std::endl;
                std::cout << "|          TIVAIZ STORE         |" << std::endl;
                std::cout << "#===============================#" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "           EDIT BARANG          " << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Barang: " << barang[pilihanBarang] << std::endl;
                std::cout << "--------------------------------" << std::endl;
                kurangiStok(jumlah[pilihanBarang], barang[pilihanBarang]);
            } else if (pilihanEdit == 0) {
                break;
            } else {
                std::cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 3." << std::endl;
                pauseScreen();
            }
        }
        break;
    }
}

void storeLihatBarang(std::string barang[], int jumlah[], int harga[], int totalData) {
    clearScreen();
    std::cout << "#===============================#" << std::endl;
    std::cout << "|          TIVAIZ STORE         |" << std::endl;
    std::cout << "#===============================#" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "           LIHAT BARANG         " << std::endl;
    std::cout << "--------------------------------" << std::endl;

    for (int idx = 0; idx < totalData; idx++) {
        std::cout << "No           : " << (idx + 1) << std::endl;
        std::cout << "Nama Barang  : " << barang[idx] << std::endl;
        std::cout << "Stok Barang  : " << jumlah[idx] << std::endl;
        std::cout << "Harga/Stok   : Rp " << harga[idx] << std::endl;
        std::cout << "Total Harga  : Rp " << (harga[idx] * jumlah[idx]) << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
    }
    std::cout << "Total barang : " << totalData << " jenis" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
    pauseScreen();
}

void menuStore() {
    std::cout << "#===============================#" << std::endl;
    std::cout << "|          TIVAIZ STORE         |" << std::endl;
    std::cout << "#===============================#" << std::endl;
    std::cout << "1. Input Barang" << std::endl;
    std::cout << "2. Hapus Barang" << std::endl;
    std::cout << "3. Edit Barang" << std::endl;
    std::cout << "4. Lihat Barang" << std::endl;
    std::cout << "0. Kembali" << std::endl;
    std::cout << "===============================" << std::endl;
}

float operasiDasar(float angA, float angB, char opr) {
    if (opr == '+') return angA + angB;
    if (opr == '-') return angA - angB;
    if (opr == '*') return angA * angB;
    if (opr == '/') return angA / angB;
    return 0;
}

long long faktorial(int num) {
    if (num == 0) return 1;
    return num * faktorial(num - 1);
}

void menuKalkulator() {
    std::cout << "+===============================-" << std::endl;
    std::cout << "|          K4LKUL4T0R           |" << std::endl;
    std::cout << "x===============================/" << std::endl;
    std::cout << "1. Operasi Dasar (+, -, *, /)" << std::endl;
    std::cout << "2. Faktorial" << std::endl;
    std::cout << "0. Kembali" << std::endl;
    std::cout << "===============================" << std::endl;
}

void jalankanKalkulator() {
    while (true) {
        clearScreen();
        menuKalkulator();
        std::cout << "Pilih menu: ";

        int pilihanKalkulator;
        std::cin >> pilihanKalkulator;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
            pauseScreen();
            continue;
        }

        if (pilihanKalkulator == 1) {
            clearScreen();
            std::cout << "+===============================-" << std::endl;
            std::cout << "|          K4LKUL4T0R           |" << std::endl;
            std::cout << "x===============================/" << std::endl;
            std::cout << "--------------------------------" << std::endl;

            char opr;
            float angA, angB;

            std::cout << "Operator (+, -, *, /) : ";
            std::cin >> opr;
            if (opr != '+' && opr != '-' && opr != '*' && opr != '/') {
                std::cout << "[Gagal] Operator tidak valid!" << std::endl;
                pauseScreen();
                continue;
            }
            std::cout << "--------------------------------" << std::endl;

            std::cout << "Angka pertama : ";
            std::cin >> angA;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
                pauseScreen();
                continue;
            }
            std::cout << "--------------------------------" << std::endl;

            std::cout << "Angka kedua   : ";
            std::cin >> angB;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
                pauseScreen();
                continue;
            }
            std::cout << "--------------------------------" << std::endl;

            if (opr == '/' && angB == 0) {
                std::cout << "[Gagal] Tidak bisa dibagi nol!" << std::endl;
            } else {
                float hasil = operasiDasar(angA, angB, opr);
                std::cout << angA << " " << opr << " " << angB << " = " << hasil << std::endl;
            }
            pauseScreen();

        } else if (pilihanKalkulator == 2) {
            clearScreen();
            std::cout << "+===============================-" << std::endl;
            std::cout << "|          K4LKUL4T0R           |" << std::endl;
            std::cout << "x===============================/" << std::endl;
            std::cout << "--------------------------------" << std::endl;

            int num;
            std::cout << "N : ";
            std::cin >> num;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
                pauseScreen();
                continue;
            }
            std::cout << "--------------------------------" << std::endl;

            if (num < 0) {
                std::cout << "[Gagal] Faktorial tidak bisa untuk angka negatif!" << std::endl;
            } else {
                std::cout << num << "! = " << faktorial(num) << std::endl;
            }
            pauseScreen();

        } else if (pilihanKalkulator == 0) {
            break;
        } else {
            std::cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2." << std::endl;
            pauseScreen();
        }
    }
}

void jalankanStore(std::string daftarBarang[], int daftarJumlah[], int daftarHarga[], int &total, int &indeksBarang) {
    while (true) {
        clearScreen();
        menuStore();
        std::cout << "Pilih menu: ";

        std::string inputPilihan;
        std::cin >> inputPilihan;

        if (!cekAngka(inputPilihan)) {
            std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
            pauseScreen();
            continue;
        }

        int pilihanStore = stringKeInt(inputPilihan);

        if (pilihanStore == 1) {
            storeInputBarang(daftarBarang, daftarJumlah, daftarHarga, total);
            indeksBarang = total;
        } else if (pilihanStore == 2) {
            if (total == 0) {
                std::cout << "[Gagal] Tidak ada barang untuk dihapus!" << std::endl;
                pauseScreen();
            } else {
                storeHapusBarang(daftarBarang, daftarJumlah, daftarHarga, total);
                indeksBarang = total;
            }
        } else if (pilihanStore == 3) {
            if (total == 0) {
                std::cout << "[Gagal] Tidak ada barang untuk diedit!" << std::endl;
                pauseScreen();
            } else {
                storeEditBarang(daftarBarang, daftarJumlah, daftarHarga, total);
            }
        } else if (pilihanStore == 4) {
            if (total == 0) {
                clearScreen();
                std::cout << "#===============================#" << std::endl;
                std::cout << "|          TIVAIZ STORE         |" << std::endl;
                std::cout << "#===============================#" << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "           LIHAT BARANG         " << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "Belum ada barang." << std::endl;
                pauseScreen();
            } else {
                storeLihatBarang(daftarBarang, daftarJumlah, daftarHarga, total);
            }
        } else if (pilihanStore == 0) {
            break;
        } else {
            std::cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 4." << std::endl;
            pauseScreen();
        }
    }
}

void menuUtama() {
    std::cout << "|========================================|" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "[           MODULE 4 - FUNCTION          ]" << std::endl;
    std::cout << "|                                        |" << std::endl;
    std::cout << "|========================================|" << std::endl;
    std::cout << "1. TIVAIZ Store" << std::endl;
    std::cout << "2. Kalkulator TIVAIZ" << std::endl;
    std::cout << "0. Keluar" << std::endl;
    std::cout << "==========================================" << std::endl;
}

bool cekAngka(std::string teks) {
    if (teks.size() == 0) return false;
    if (teks.size() == 1 && teks[0] == '-') return false;
    bool valid = true;
    for (int idx = 0; idx < (int)teks.size(); idx++) {
        if (!isdigit(teks[idx]) && !(idx == 0 && teks[idx] == '-')) {
            valid = false;
        }
    }
    return valid;
}

int stringKeInt(std::string teks) {
    int hasil = 0;
    int awal = 0;
    bool negatif = false;
    if (teks.size() == 0) return 0;
    if (teks[0] == '-') {
        negatif = true;
        awal = 1;
    }
    for (int idx = awal; idx < (int)teks.size(); idx++) {
        hasil = hasil * 10 + (teks[idx] - '0');
    }
    if (negatif) hasil = -hasil;
    return hasil;
}

int main() {
    int pilihan;
    bool menuModul4 = false;
    int indeksBarang = 0;
    int total = 0;
    std::string daftarBarang[MAX];
    int daftarHarga[MAX];
    int daftarJumlah[MAX];

    while (!menuModul4) {
        clearScreen();
        menuUtama();
        std::cout << "Pilih Menu: ";
        std::cin >> pilihan;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "[Gagal] Input harus berupa angka!" << std::endl;
            pauseScreen();
            continue;
        }

        if (pilihan == 1) {
            jalankanStore(daftarBarang, daftarJumlah, daftarHarga, total, indeksBarang);
        } else if (pilihan == 2) {
            jalankanKalkulator();
        } else if (pilihan == 0) {
            menuModul4 = true;
        } else {
            std::cout << "[Gagal] Pilihan tidak valid!" << std::endl;
            pauseScreen();
        }
    }

    return 0;
}

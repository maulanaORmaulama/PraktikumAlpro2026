#include <iostream>
<<<<<<< HEAD
#include <cstdlib>
#include <ctime>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RESET   "\033[0m"
#define MAX_BAHAN_WAJIB    4
#define MAX_SAUS           6
#define MAX_BAHAN_TAMBAHAN 6
#define MAX_HISTORY        100
#define MODAL_AWAL         200000

struct bahan {
    char nama[50];
    int stok;
    int harga;

    void tampilkan() {
        std::cout << "~ " << nama << " (Stok: " << stok << ") | Rp." << harga << std::endl;
    }

    void tampilkanBeli() {
        std::cout << nama << " (Stok: " << stok << " | Harga: Rp." << harga << "/pcs)" << std::endl;
    }

    bool adaStok() {
        return stok > 0;
    }

    void tambahStok(int jumlahBeli) {
        stok += jumlahBeli;
    }

    void kurangiStok(int jumlahPakai) {
        stok -= jumlahPakai;
    }
};

struct historyPenjualan {
    char namaPatty[50];
    char namaSaus[50];
    char namaTopping[50];
    bool statusBerhasil;
    int nilaiPerolehan;

    void tampilkan(int nomorPembeli) {
        std::cout << "Pembeli #" << nomorPembeli << std::endl;
        std::cout << "  Patty   : " << namaPatty << std::endl;
        std::cout << "  Saus    : " << namaSaus << std::endl;
        std::cout << "  Topping : " << namaTopping << std::endl;
        if (statusBerhasil) {
            std::cout << "  Hasil   : " << GREEN << "Berhasil" << RESET << " | Perolehan: Rp." << nilaiPerolehan << std::endl;
        } else {
            std::cout << "  Hasil   : " << RED << "Gagal" << RESET << " | Perolehan: Rp." << nilaiPerolehan << std::endl;
        }
        std::cout << "--------------------------------------------" << std::endl;
    }
};

struct gameState {
    int uang;
    int totalPengeluaran;
    int totalPendapatan;
    int jumlahPembeli;
    historyPenjualan daftarHistory[MAX_HISTORY];

    void inisialisasi() {
        uang             = MODAL_AWAL;
        totalPengeluaran = 0;
        totalPendapatan  = 0;
        jumlahPembeli    = 0;
    }

    void tambahPendapatan(int jumlahMasuk) {
        uang            += jumlahMasuk;
        totalPendapatan += jumlahMasuk;
    }

    void tambahPengeluaran(int jumlahKeluar) {
        uang             -= jumlahKeluar;
        totalPengeluaran += jumlahKeluar;
    }

    void simpanHistory(char pattyDipilih[], char sausDipilih[], char toppingDipilih[], bool hasilTransaksi, int perolehanTransaksi) {
        if (jumlahPembeli < MAX_HISTORY) {
            int idxSalin = 0;
            while (pattyDipilih[idxSalin] != '\0') {
                daftarHistory[jumlahPembeli].namaPatty[idxSalin] = pattyDipilih[idxSalin];
                idxSalin++;
            }
            daftarHistory[jumlahPembeli].namaPatty[idxSalin] = '\0';

            idxSalin = 0;
            while (sausDipilih[idxSalin] != '\0') {
                daftarHistory[jumlahPembeli].namaSaus[idxSalin] = sausDipilih[idxSalin];
                idxSalin++;
            }
            daftarHistory[jumlahPembeli].namaSaus[idxSalin] = '\0';

            idxSalin = 0;
            while (toppingDipilih[idxSalin] != '\0') {
                daftarHistory[jumlahPembeli].namaTopping[idxSalin] = toppingDipilih[idxSalin];
                idxSalin++;
            }
            daftarHistory[jumlahPembeli].namaTopping[idxSalin] = '\0';

            daftarHistory[jumlahPembeli].statusBerhasil  = hasilTransaksi;
            daftarHistory[jumlahPembeli].nilaiPerolehan  = perolehanTransaksi;
            jumlahPembeli++;
        }
    }
};

bahan bahanWajib[MAX_BAHAN_WAJIB] = {
    {"Sosis Sapi",  2, 10000},
    {"Mozarella",   2, 13000},
    {"Sosis Ayam",  2, 7000},
    {"Roti",        100, 1000}
};

bahan daftarSaus[MAX_SAUS] = {
    {"Manis",           2, 1000},
    {"Pedas",           2, 1000},
    {"Mayonaise",       2, 1000},
    {"Manis Pedas",     2, 1000},
    {"Pedas Mayonaise", 2, 1000},
    {"All Sauce",       2, 1000}
};

bahan bahanTambahan[MAX_BAHAN_TAMBAHAN] = {
    {"Tepung Roti",   2, 1000},
    {"Kentang",       2, 3000},
    {"Macha",         2, 1000},
    {"Coklat",        2, 2000},
    {"Tiramisu",      2, 1000},
    {"Choco Crunchy", 2, 2000}
};

gameState dataGame;

void bersihkanLayar() {
    std::cout << "\033[2J\033[1;1H";
}

void tungguLanjut() {
    std::cout << "Tekan Enter untuk lanjut...";
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}

void tungguKembali() {
    std::cout << "Tekan Enter untuk kembali...";
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}

void tampilkanHeader() {
    std::cout << YELLOW;
    std::cout << " /___)/  _\\( ___\\( \\( )  ( ___\\/  _\\/___)" << std::endl;
    std::cout << "( (___( (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << " \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << RESET;
    std::cout << CYAN << "              >> Corn Dog Simulator <<         " << RESET << std::endl;
    std::cout << "===================================================" << std::endl;
}

void tampilkanUang() {
    std::cout << "Uang: Rp." << dataGame.uang << std::endl;
    std::cout << "===================================================" << std::endl;
}

void tampilkanCorndogSenang() {
    std::cout << GREEN;
    std::cout << "          .-----." << std::endl;
    std::cout << "         ( o  o )   <- pelanggan senang!" << std::endl;
    std::cout << "          \\  ~ /" << std::endl;
    std::cout << "     _____/____\\_____" << std::endl;
    std::cout << "    |  CORN DOG SHOP  |" << std::endl;
    std::cout << "    |_________________|" << std::endl;
    std::cout << "          ||    ||" << std::endl;
    std::cout << RESET;
    std::cout << YELLOW;
    std::cout << " /___)/  _\\( ___\\( \\( )  ( ___\\/  _\\/___)" << std::endl;
    std::cout << "( (___( (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << " \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << RESET;
    std::cout << CYAN << "     >> Simulator Jualan Corn Dog Terbaik! <<" << RESET << std::endl;
}

void tampilkanCorndogSedih() {
    std::cout << RED;
    std::cout << "          .-----." << std::endl;
    std::cout << "         ( > < )   <- pelanggan tidak senang!" << std::endl;
    std::cout << "          \\  _ /" << std::endl;
    std::cout << "     _____/____\\_____" << std::endl;
    std::cout << "    |  CORN DOG SHOP  |" << std::endl;
    std::cout << "    |_________________|" << std::endl;
    std::cout << "          ||    ||" << std::endl;
    std::cout << RESET;
    std::cout << YELLOW;
    std::cout << " /___)/  _\\( ___\\( \\( )  ( ___\\/  _\\/___)" << std::endl;
    std::cout << "( (___( (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << " \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << RESET;
    std::cout << CYAN << "     >> Corn Dog Simulator! <<" << RESET << std::endl;
}

bool samaString(char stringPertama[], char stringKedua[]) {
    int idxKarakter = 0;
    while (stringPertama[idxKarakter] != '\0' && stringKedua[idxKarakter] != '\0') {
        if (stringPertama[idxKarakter] != stringKedua[idxKarakter]) return false;
        idxKarakter++;
    }
    return stringPertama[idxKarakter] == '\0' && stringKedua[idxKarakter] == '\0';
}

int inputPilihanRange(int nilaiMin, int nilaiMax) {
    int pilihanUser;
    bool inputValid = false;

    while (!inputValid) {
        std::cout << "Pilihan Anda: ";
        if (!(std::cin >> pilihanUser)) {
            std::cin.clear();
            std::cin.ignore(1000000, '\n');
            std::cout << RED << "[!] Input tidak valid. Masukkan angka yang benar: " << RESET << std::endl;
        } else if (pilihanUser < nilaiMin || pilihanUser > nilaiMax) {
            std::cout << RED << "[!] Masukkan angka antara " << nilaiMin << " dan " << nilaiMax << ": " << RESET << std::endl;
        } else {
            inputValid = true;
        }
    }
    return pilihanUser;
}

void menuBeliPatty() {
    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          BELI BAHAN WAJIB (PATTY)" << std::endl;
    for (int idxBahan = 0; idxBahan < MAX_BAHAN_WAJIB; idxBahan++) {
        std::cout << "  " << (idxBahan + 1) << ". ";
        bahanWajib[idxBahan].tampilkanBeli();
    }
    std::cout << "  0. Kembali" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanBahan = inputPilihanRange(0, MAX_BAHAN_WAJIB);
    if (pilihanBahan == 0) return;

    int idxBahanDipilih = pilihanBahan - 1;
    std::cout << "Masukkan jumlah yang ingin dibeli: ";
    int jumlahBeli = inputPilihanRange(1, 9999);

    int totalHarga = bahanWajib[idxBahanDipilih].harga * jumlahBeli;
    if (totalHarga > dataGame.uang) {
        std::cout << RED << "[!] Uang tidak cukup!" << RESET << std::endl;
        tungguKembali();
        return;
    }
    bahanWajib[idxBahanDipilih].tambahStok(jumlahBeli);
    dataGame.tambahPengeluaran(totalHarga);
    std::cout << GREEN << "[+] Berhasil membeli " << jumlahBeli << "x " << bahanWajib[idxBahanDipilih].nama << " seharga Rp." << totalHarga << RESET << std::endl;
    tungguKembali();
}

void menuBeliSaus() {
    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          BELI SAUS" << std::endl;
    for (int idxSaus = 0; idxSaus < MAX_SAUS; idxSaus++) {
        std::cout << "  " << (idxSaus + 1) << ". ";
        daftarSaus[idxSaus].tampilkanBeli();
    }
    std::cout << "  0. Kembali" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanSaus = inputPilihanRange(0, MAX_SAUS);
    if (pilihanSaus == 0) return;

    int idxSausDipilih = pilihanSaus - 1;
    std::cout << "Masukkan jumlah yang ingin dibeli: ";
    int jumlahBeli = inputPilihanRange(1, 9999);

    int totalHarga = daftarSaus[idxSausDipilih].harga * jumlahBeli;
    if (totalHarga > dataGame.uang) {
        std::cout << RED << "[!] Uang tidak cukup!" << RESET << std::endl;
        tungguKembali();
        return;
    }
    daftarSaus[idxSausDipilih].tambahStok(jumlahBeli);
    dataGame.tambahPengeluaran(totalHarga);
    std::cout << GREEN << "[+] Berhasil membeli " << jumlahBeli << "x " << daftarSaus[idxSausDipilih].nama << " seharga Rp." << totalHarga << RESET << std::endl;
    tungguKembali();
}

void menuBeliTambahan() {
    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          BELI BAHAN TAMBAHAN" << std::endl;
    for (int idxTambahan = 0; idxTambahan < MAX_BAHAN_TAMBAHAN; idxTambahan++) {
        std::cout << "  " << (idxTambahan + 1) << ". ";
        bahanTambahan[idxTambahan].tampilkanBeli();
    }
    std::cout << "  0. Kembali" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanTambahan = inputPilihanRange(0, MAX_BAHAN_TAMBAHAN);
    if (pilihanTambahan == 0) return;

    int idxTambahanDipilih = pilihanTambahan - 1;
    std::cout << "Masukkan jumlah yang ingin dibeli: ";
    int jumlahBeli = inputPilihanRange(1, 9999);

    int totalHarga = bahanTambahan[idxTambahanDipilih].harga * jumlahBeli;
    if (totalHarga > dataGame.uang) {
        std::cout << RED << "[!] Uang tidak cukup!" << RESET << std::endl;
        tungguKembali();
        return;
    }
    bahanTambahan[idxTambahanDipilih].tambahStok(jumlahBeli);
    dataGame.tambahPengeluaran(totalHarga);
    std::cout << GREEN << "[+] Berhasil membeli " << jumlahBeli << "x " << bahanTambahan[idxTambahanDipilih].nama << " seharga Rp." << totalHarga << RESET << std::endl;
    tungguKembali();
}

void menuPilihKategoriBeli() {
    bool sudahKembali = false;
    while (!sudahKembali) {
        bersihkanLayar();
        tampilkanHeader();
        tampilkanUang();
        std::cout << "          PILIH KATEGORI BAHAN" << std::endl;
        std::cout << "  1. Bahan Wajib (Patty)" << std::endl;
        std::cout << "  2. Saus" << std::endl;
        std::cout << "  3. Bahan Tambahan" << std::endl;
        std::cout << "  0. Kembali" << std::endl;
        std::cout << "===================================================" << std::endl;

        int pilihanKategori = inputPilihanRange(0, 3);
        if      (pilihanKategori == 0) sudahKembali = true;
        else if (pilihanKategori == 1) menuBeliPatty();
        else if (pilihanKategori == 2) menuBeliSaus();
        else if (pilihanKategori == 3) menuBeliTambahan();
    }
}

void menuStokBahan() {
    bool sudahKembali = false;
    while (!sudahKembali) {
        bersihkanLayar();
        tampilkanHeader();
        tampilkanUang();
        std::cout << "          -- Bahan Wajib --" << std::endl;
        for (int idxBahan = 0; idxBahan < MAX_BAHAN_WAJIB; idxBahan++) {
            bahanWajib[idxBahan].tampilkan();
        }
        std::cout << std::endl;
        std::cout << "          -- Saus --" << std::endl;
        for (int idxSaus = 0; idxSaus < MAX_SAUS; idxSaus++) {
            daftarSaus[idxSaus].tampilkan();
        }
        std::cout << std::endl;
        std::cout << "          -- Bahan Tambahan --" << std::endl;
        for (int idxTambahan = 0; idxTambahan < MAX_BAHAN_TAMBAHAN; idxTambahan++) {
            bahanTambahan[idxTambahan].tampilkan();
        }
        std::cout << std::endl;
        std::cout << "===================================================" << std::endl;
        std::cout << "  1. Membeli Bahan" << std::endl;
        std::cout << "  0. Kembali ke Menu Utama" << std::endl;
        std::cout << "===================================================" << std::endl;

        int pilihanMenu = inputPilihanRange(0, 1);
        if      (pilihanMenu == 0) sudahKembali = true;
        else if (pilihanMenu == 1) menuPilihKategoriBeli();
    }
}

void menuTotalPenjualan() {
    bersihkanLayar();
    tampilkanHeader();
    std::cout << "          LAPORAN KEUANGAN & PENJUALAN" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "Modal Awal          : Rp. " << MODAL_AWAL << std::endl;
    std::cout << "Total Pengeluaran   : Rp. " << dataGame.totalPengeluaran << std::endl;
    std::cout << "Total Pendapatan    : Rp. " << dataGame.totalPendapatan << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    int nilaiUntungBersih = dataGame.totalPendapatan - dataGame.totalPengeluaran;
    std::cout << "Uang saat ini       : Rp. " << dataGame.uang << std::endl;
    std::cout << "Untung Bersih       : Rp. " << (nilaiUntungBersih >= 0 ? "+" : "") << nilaiUntungBersih << std::endl;
    std::cout << "Pembeli dilayani    : " << dataGame.jumlahPembeli << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "Tekan Enter untuk kembali ke menu..." << std::endl;
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}

void menuHistoryPenjualan() {
    bersihkanLayar();
    tampilkanHeader();
    std::cout << "          HISTORY PENJUALAN" << std::endl;
    std::cout << "===================================================" << std::endl;
    if (dataGame.jumlahPembeli == 0) {
        std::cout << "Belum ada transaksi." << std::endl;
    } else {
        for (int idxHistory = 0; idxHistory < dataGame.jumlahPembeli; idxHistory++) {
            dataGame.daftarHistory[idxHistory].tampilkan(idxHistory + 1);
        }
    }
    std::cout << "Tekan Enter untuk kembali...";
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}

void menuMulaiBerjualan() {
    if (bahanWajib[3].stok < 2) {
        bersihkanLayar();
        tampilkanHeader();
        std::cout << RED << "[!] Stok roti tidak cukup (minimal 2 roti)." << std::endl;
        std::cout << "    Silakan beli roti di menu Stok Bahan." << RESET << std::endl;
        std::cout << "===================================================" << std::endl;
        tungguKembali();
        return;
    }

    int idxPattyAcak = rand() % 3;
    int idxSausAcak  = rand() % MAX_SAUS;
    int idxTambAcak  = rand() % MAX_BAHAN_TAMBAHAN;

    char namaPattyPesanan[50];
    char namaSausPesanan[50];
    char namaTambPesanan[50];

    int idxSalin = 0;
    while (bahanWajib[idxPattyAcak].nama[idxSalin] != '\0') {
        namaPattyPesanan[idxSalin] = bahanWajib[idxPattyAcak].nama[idxSalin];
        idxSalin++;
    }
    namaPattyPesanan[idxSalin] = '\0';

    idxSalin = 0;
    while (daftarSaus[idxSausAcak].nama[idxSalin] != '\0') {
        namaSausPesanan[idxSalin] = daftarSaus[idxSausAcak].nama[idxSalin];
        idxSalin++;
    }
    namaSausPesanan[idxSalin] = '\0';

    idxSalin = 0;
    while (bahanTambahan[idxTambAcak].nama[idxSalin] != '\0') {
        namaTambPesanan[idxSalin] = bahanTambahan[idxTambAcak].nama[idxSalin];
        idxSalin++;
    }
    namaTambPesanan[idxSalin] = '\0';

    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          PESANAN PELANGGAN" << std::endl;
    std::cout << "Patty     : " << namaPattyPesanan << std::endl;
    std::cout << "Saus      : " << namaSausPesanan << std::endl;
    std::cout << "Tambahan  : " << namaTambPesanan << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "  [LANGKAH 1/3] Pilih Patty:" << std::endl;
    for (int idxPatty = 0; idxPatty < 3; idxPatty++) {
        std::cout << "  " << (idxPatty + 1) << ". " << bahanWajib[idxPatty].nama << " (Stok: " << bahanWajib[idxPatty].stok << ")" << std::endl;
    }
    std::cout << "  0. Batalkan & kembali ke menu utama" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanPatty = inputPilihanRange(0, 3);
    if (pilihanPatty == 0) return;

    int idxPattyDipilih = pilihanPatty - 1;
    if (bahanWajib[idxPattyDipilih].stok <= 0) {
        std::cout << RED << "[!] Stok " << bahanWajib[idxPattyDipilih].nama << " habis!" << RESET << std::endl;
        tungguKembali();
        return;
    }

    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          PESANAN PELANGGAN" << std::endl;
    std::cout << "Patty     : " << namaPattyPesanan << std::endl;
    std::cout << "Saus      : " << namaSausPesanan << std::endl;
    std::cout << "Tambahan  : " << namaTambPesanan << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "  [LANGKAH 2/3] Pilih Saus:" << std::endl;
    for (int idxSaus = 0; idxSaus < MAX_SAUS; idxSaus++) {
        std::cout << "  " << (idxSaus + 1) << ". " << daftarSaus[idxSaus].nama << " (Stok: " << daftarSaus[idxSaus].stok << ")" << std::endl;
    }
    std::cout << "  0. Batalkan & kembali ke menu utama" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanSaus = inputPilihanRange(0, MAX_SAUS);
    if (pilihanSaus == 0) return;

    int idxSausDipilih = pilihanSaus - 1;
    if (daftarSaus[idxSausDipilih].stok <= 0) {
        std::cout << RED << "[!] Stok " << daftarSaus[idxSausDipilih].nama << " habis!" << RESET << std::endl;
        tungguKembali();
        return;
    }

    bersihkanLayar();
    tampilkanHeader();
    tampilkanUang();
    std::cout << "          PESANAN PELANGGAN" << std::endl;
    std::cout << "Patty     : " << namaPattyPesanan << std::endl;
    std::cout << "Saus      : " << namaSausPesanan << std::endl;
    std::cout << "Tambahan  : " << namaTambPesanan << std::endl;
    std::cout << "===================================================" << std::endl;

    std::cout << "  [LANGKAH 3/3] Pilih Tambahan:" << std::endl;
    for (int idxTambahan = 0; idxTambahan < MAX_BAHAN_TAMBAHAN; idxTambahan++) {
        std::cout << "  " << (idxTambahan + 1) << ". " << bahanTambahan[idxTambahan].nama << " (Stok: " << bahanTambahan[idxTambahan].stok << ")" << std::endl;
    }
    std::cout << "  0. Batalkan & kembali ke menu utama" << std::endl;
    std::cout << "===================================================" << std::endl;

    int pilihanTambahan = inputPilihanRange(0, MAX_BAHAN_TAMBAHAN);
    if (pilihanTambahan == 0) return;

    int idxTambahanDipilih = pilihanTambahan - 1;
    if (bahanTambahan[idxTambahanDipilih].stok <= 0) {
        std::cout << RED << "[!] Stok " << bahanTambahan[idxTambahanDipilih].nama << " habis!" << RESET << std::endl;
        tungguKembali();
        return;
    }

    bool pattyBenar = samaString(bahanWajib[idxPattyDipilih].nama, namaPattyPesanan);
    bool sausBenar  = samaString(daftarSaus[idxSausDipilih].nama, namaSausPesanan);
    bool tambBenar  = samaString(bahanTambahan[idxTambahanDipilih].nama, namaTambPesanan);

    bool semuaBahanBenar = pattyBenar && sausBenar && tambBenar;

    int totalPerolehan   = 2000;
    int perolehanPatty   = 0;
    int perolehanSaus    = 0;
    int perolehanTambahan = 0;

    if (pattyBenar) perolehanPatty    = bahanWajib[idxPattyDipilih].harga + 1000;
    if (sausBenar)  perolehanSaus     = daftarSaus[idxSausDipilih].harga + 200;
    if (tambBenar)  perolehanTambahan = bahanTambahan[idxTambahanDipilih].harga + 200;

    totalPerolehan += perolehanPatty + perolehanSaus + perolehanTambahan;

    bahanWajib[idxPattyDipilih].kurangiStok(1);
    daftarSaus[idxSausDipilih].kurangiStok(1);
    bahanTambahan[idxTambahanDipilih].kurangiStok(1);
    bahanWajib[3].kurangiStok(2);

    dataGame.tambahPendapatan(totalPerolehan);

    bersihkanLayar();
    if (semuaBahanBenar) {
        tampilkanCorndogSenang();
    } else {
        tampilkanCorndogSedih();
    }
    std::cout << "===================================================" << std::endl;
    if (semuaBahanBenar) {
        std::cout << GREEN << "Corn Dog berhasil dibuat! Terima kasih!" << RESET << std::endl;
    } else {
        std::cout << RED << "Ada bahan yang salah! Pelanggan kecewa..." << RESET << std::endl;
    }
    std::cout << "===================================================" << std::endl;

    std::cout << "Patty    [" << bahanWajib[idxPattyDipilih].nama << "] -> ";
    if (pattyBenar) std::cout << GREEN << "BENAR  +Rp." << perolehanPatty << RESET << std::endl;
    else            std::cout << RED   << "SALAH  +Rp.0 (bahan hangus)" << RESET << std::endl;

    std::cout << "Saus     [" << daftarSaus[idxSausDipilih].nama << "] -> ";
    if (sausBenar)  std::cout << GREEN << "BENAR  +Rp." << perolehanSaus << RESET << std::endl;
    else            std::cout << RED   << "SALAH  +Rp.0 (bahan hangus)" << RESET << std::endl;

    std::cout << "Tambahan [" << bahanTambahan[idxTambahanDipilih].nama << "] -> ";
    if (tambBenar)  std::cout << GREEN << "BENAR  +Rp." << perolehanTambahan << RESET << std::endl;
    else            std::cout << RED   << "SALAH  +Rp.0 (bahan hangus)" << RESET << std::endl;

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Base pembayaran  : Rp.2000" << std::endl;
    std::cout << "Total Perolehan  : Rp." << totalPerolehan << std::endl;
    std::cout << "Uang sekarang    : Rp." << dataGame.uang << std::endl;
    std::cout << "===================================================" << std::endl;

    dataGame.simpanHistory(
        bahanWajib[idxPattyDipilih].nama,
        daftarSaus[idxSausDipilih].nama,
        bahanTambahan[idxTambahanDipilih].nama,
        semuaBahanBenar,
        totalPerolehan
    );

    tungguLanjut();
}

void tampilkanPesanKeluar() {
    bersihkanLayar();
    std::cout << BLUE;
    std::cout << " /___)/  _\\( ___\\( \\( )  ( ___\\/  _\\/___)" << std::endl;
    std::cout << "( (___( (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << " \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << RESET;
    std::cout << RED    << "              >> Corn Dog Simulator <<         " << RESET << std::endl;
    std::cout << YELLOW << "===================================================" << RESET << std::endl;
    std::cout <<           "          Terima Kasih Telah Bermain >_<" << std::endl;
    std::cout << YELLOW << "===================================================" << RESET << std::endl;
    std::cout << "Tekan Enter untuk keluar...";
    std::cin.ignore(1000000, '\n');
    std::cin.get();
}

int main() {
    srand((unsigned int)time(0));
    dataGame.inisialisasi();

    bool gameBerjalan = true;
    while (gameBerjalan) {
        bersihkanLayar();
        tampilkanHeader();
        tampilkanUang();

        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "  |    1. MULAI BERJUALAN        |" << std::endl;
        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "  |    2. STOK BAHAN             |" << std::endl;
        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "  |    3. TOTAL PENJUALAN        |" << std::endl;
        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "  |    4. HISTORY PENJUALAN      |" << std::endl;
        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "  |    0. KELUAR                 |" << std::endl;
        std::cout << "  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "===================================================" << std::endl;

        int pilihanUtama = inputPilihanRange(0, 4);

        if      (pilihanUtama == 0) { tampilkanPesanKeluar(); gameBerjalan = false; }
        else if (pilihanUtama == 1) menuMulaiBerjualan();
        else if (pilihanUtama == 2) menuStokBahan();
        else if (pilihanUtama == 3) menuTotalPenjualan();
        else if (pilihanUtama == 4) menuHistoryPenjualan();
    }

    return 0;
}
=======

int main(){

    double angka1;
    double angka2;
//horizon calculator
    std::cout << "=====HORIZON CALCULATOR=====" << std::endl;
    std::cout << "masukan angka pertama: "<< std::endl;
    std::cin >> angka1;
    std::cout << "masukan angka kedua" << std::endl;
    std::cin >> angka2;

    std::cout << "=====HORIZON CALCULATOR=====" << std::endl;
    std::cout << "penjumlahan : " << angka1 + angka2 << std::endl;
    std::cout << "pengurangan : " << angka1 - angka2 << std::endl;
    std::cout << "perkalian : " << angka1 * angka2 << std::endl;
    std::cout << "pembagian : " << angka1 / angka2 << std::endl;

//horizon signaturename
    char  A, B, C, D, E;
    int range;

    std::cout << "masukan 5 huruf (lowercase)" << std::endl;
    std::cin >> A >> B >> C >> D >> E ;

    std::cout << "=====HORIZON SIGANTURE NAME=====" << std::endl;
    std:: cout << "Uppercase: " << (char)(A - 32 ) << (char)(B - 32) << (char) (C - 32) << (char)(D - 32) << (char)(E - 32) << std::endl; 
    std:: cout << "ASCII: " << (int)A << " " << (int)(B) << " " << (int)(C) << " " << (int)(D) << " " << (int)(E) << std::endl;
    std:: cout << "Total ASCII: " << ( (A) + (B) + (C) + (D) + (E)) << std::endl;
    std:: cout << "Rata-Rata: " << ((char) (A) + (char) (B) + (char) (C) + (char) (D) + (char) (E)) / 5 << std::endl;

    std::cout << "enkripsi: " << std::endl;
    std::cin >> range;

//enkripsi
    char eA = (char)((((A - 'a') + range) % 26) + 'a');
    char eB = (char)((((B - 'a') + range) % 26) + 'a');
    char eC = (char)((((C - 'a') + range) % 26) + 'a');
    char eD = (char)((((D - 'a') + range) % 26) + 'a');
    char eE = (char)((((E - 'a') + range) % 26) + 'a');

//REVERSE
    char rA = (char)((((A - 'a') - range + 26) % 26) + 'a');
    char rB = (char)((((B - 'a') - range + 26) % 26) + 'a');
    char rC = (char)((((C - 'a') - range + 26) % 26) + 'a');
    char rD = (char)((((D - 'a') - range + 26) % 26) + 'a');
    char rE = (char)((((E - 'a') - range + 26) % 26) + 'a');

    std::cout << "=====ENKRIPSI=====" << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "Enkripsi : " << eA << eB << eC << eD << eE << std::endl;

    std::cout << "=====REVERSE=====" << std::endl;
    std::cout << "Range : " << range << std::endl;
    std::cout << "Reverse : " << rA << rB << rC << rD << rE << std::endl;

}
>>>>>>> 744785e16247b3660935d3bee26c43e202f60a8b

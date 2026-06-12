#include <iostream>

#define pause()                                       \
{                                                     \
    std::cout << "Press the ENTER key to continue..." << std::endl; \
    std::cin.ignore(10000, '\n');                     \
    std::cin.get();                                   \
}

int main() {
    int umurPengguna;

    std::cout << "=== GOBLET OF FIRE: TURNAMENT TRIWIZARD ===" << std::endl;

    // Cek umur
        std::cout << "Masukkan umur: ";
        std::cin >> umurPengguna;

    if(umurPengguna < 17){
        std::cout << "Piala Api Menolak Anda! Umur Anda Terlalu Kecil" << std::endl;
    }
    else{
        std::cout << "Piala Api Menyala!Anda Terpilih Sebagai Triwizard Champions." << std::endl;
        pause();
//Tugas 1
    bool statusArena = false;

    while (!statusArena) {
    int jumlahPerlindungan = 3;

    while (jumlahPerlindungan > 0) {
        int pilihanStrategi;

        std::cout << std::endl;
        std::cout << "=== TUGAS 1 : NAGA HUNGARIAN HORNTAIL ===" << std::endl;
        std::cout << "Sisa Perlindungan sihir: " << jumlahPerlindungan << " kali" << std::endl;
        std::cout << "1. Sembunyi" << std::endl;
        std::cout << "2. Panggil sapu" << std::endl;
        std::cout << "Pilih strategi: " << std::endl;

        std::cin >> pilihanStrategi;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (pilihanStrategi == 2) {
            std::cout << "Berhasil! Mendapatkan Telur Emas!" << std::endl;
            statusArena = true;
            break;
        }
        else if (pilihanStrategi == 1) {
            jumlahPerlindungan--;
            std::cout << "Naga Menyemburkan Api! Anda Terluka." << std::endl;
        }
        else {
            std::cout << "Pilihan tidak valid! Ulangi Pilihan" << std::endl;
            pause();
        }
    }

    if (jumlahPerlindungan == 0 && !statusArena) {
        std::cout << ">> KESEMPATAN HABIS! Anda diatrik keluar oleh pawang naga" << std::endl;
        std::cout << ">> MENGULANG TUGAS 1 DARI AWAL" << std::endl;
    }
    }
    if (statusArena){
        pause();
    }

//Tugas 2
        int Waktu = 0;

    while (Waktu < 60) {
        int pilihanDanau;

        std::cout << std::endl;
        std::cout << "=== TUGAS 2 : DANAU HITAM ===" << std::endl;
        std::cout << "AWAS ADA GRINDYLOW!" << std::endl;
        std::cout << "Waktu: " << Waktu << " menit" << std::endl;
        std::cout << "Apa yang akan kamu lakukan?" << std::endl;
        std::cout << "1. Hindari" << std::endl;
        std::cout << "2. Lawan" << std::endl;
        std::cout << "Pilih: " << std::endl;

        std::cin >> pilihanDanau;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        if (pilihanDanau == 1) {
            Waktu += 10;
            std::cout << "Berhasil menghindar! kamu lolos dari Grindylow" << std::endl;
        }
        else if (pilihanDanau == 2) {
            std::cout << "Oksigen anda habis karena kelelahan bertarung" << std::endl;
            std::cout << ">> WAKTU/OKSIGEN HABIS! Putri duyung membawa anda kembali ke permukaan" << std::endl;
            std::cout << ">> MENGULANG TUGAS 2 DARI AWAL..." << std::endl;
            Waktu = 0;
            pause();
        }
        else {
            std::cout << "Pilihan tidak valid! ulangi pilihan" << std::endl;
            pause();
        }
    }
    std::cout << "Tepat 60 menit! Anda berhasil menyelamatkan sandera." << std::endl;
    pause();


//Tugas 3
    int toleransiKesalahan = 2;
    int langkahBenar = 0;
    int langkahDitempuh = 0;
    bool statusLabirin = false;

while (!statusLabirin) {
    int pilihanLabirin;

    std::cout << std::endl;
    std::cout << "=== TUGAS 3: LABIRIN ===" << std::endl;
    std::cout << "Langkah Ditempuh: " << langkahDitempuh <<  std::endl;
    std::cout << "Langkah benar: " << langkahBenar << std::endl;
    std::cout << "Toleransi kesalahan: " << toleransiKesalahan << std::endl;
    std::cout << "1. Kiri" << std::endl;
    std::cout << "2. Kanan" << std::endl;
    std::cout << "3. Lurus" << std::endl;
    std::cout << "Pilih: " << std::endl;

    std::cin >> pilihanLabirin;

    if (std::cin.fail()) {
        std::cin.ignore(1000, '\n');
        std::cin.get();
        std::cin.clear();
        continue;
    }
    std::cin.ignore(1000, '\n');

    if (pilihanLabirin == 3) {
        langkahBenar++;
        langkahDitempuh++;
        std::cout << "Jalan Anda Aman, anda semakin dalam" << std::endl;

        if (langkahBenar == 3) {
            std::cout << "Kamu menemukan cahaya!..... oh tunggu, apa itu..." << std::endl;
            statusLabirin = true;
        }
    }
    else if (pilihanLabirin == 1 || pilihanLabirin == 2) {
        toleransiKesalahan--;
        langkahDitempuh++;
        std::cout << "Terkena akar berbisa!" << std::endl;

        if (toleransiKesalahan == 0) {
            std::cout << ">> KESEMPATAN HABIS! Labirin berubah bentuk dan menendang anda ke pintu masuk" << std::endl;
            std::cout << ">> MENGULANG TUGAS 3 DARI AWAL...." << std::endl;
            toleransiKesalahan = 2;
            langkahBenar = 0;
            langkahDitempuh = 0;
        }
    }
    else {
        std::cout << "Pilihan tidak valid!" << std::endl;
    }

    if (!statusLabirin) {
        pause();
    }
    }
    //JALAN KELUAR
    int sandi= 0;

    std::cout << "=== JALAN KELUAR ===" << std::endl;
    std::cout << "Anda melihat sesutau yang bersinar di tengah arena" << std::endl;
    std::cout << "Terdapat sesuatu yang terkurung di dalamnya, dan terdapat mesin yang meminta anda untuk memasukkan sebuah angka..." << std::endl;

    std::cout << "Masukkan angka (minimal 5): ";
    std::cin >> sandi;

    if(sandi >= 5){
        std::cout << "Terdapat sebuah cahaya bersinar di tanganmu kini terdapat sebuah diamond besar" << std::endl;
        int bintang = 9;
        for (int i = 1; i <= bintang; i++) {
        for (int j = 1; j <= bintang - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    for (int i = bintang - 1; i >= 1; i--) {
        for (int j = 1; j <= bintang - i; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << "*** SELAMAT ANDA PEMENANG TURNAMENT TRIWIZARD! ***" << std::endl;
    }
    else{
        std::cout << "Sandi anda salah" << std::endl;
        std::cout << "sesuatu tersebut telah dibawa pergi" << std::endl;
    }
    }
    pause();

}
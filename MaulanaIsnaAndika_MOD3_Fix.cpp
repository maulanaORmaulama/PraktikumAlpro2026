#include <iostream>

#define MAX 100

char enkripsi(char c, int key){
    if (c >= 'a' && c <= 'z'){
        return ((c - 'a' + key) % 26) + 'a';
    }
    if (c >= 'A' && c <= 'Z'){
        return ((c - 'A' + key) % 26) + 'A';
    }
    return c;
}

char dekripsi(char c, int key){
    if (c >= 'a' && c <= 'z'){
        return ((c - 'a' - key + 26) % 26) + 'a';
    }
    if (c >= 'A' && c <= 'Z'){
        return ((c - 'A' - key + 26) % 26) + 'A';
    }
    return c;
}

bool palindrome(char teks[], int panjang){

    int kiri = 0;
    int kanan = panjang - 1;

    while (kiri < kanan){

        char left = teks[kiri];
        char right = teks[kanan];

        if (left >= 'A' && left <= 'Z'){
            left = left + 32;
        }

        if (right >= 'A' && right <= 'Z'){
            right = right + 32;
        }

        if (left != right){
            return false;
        }

        kiri++;
        kanan--;
    }

    return true;
}

int insertionSort(char arr[], int panjang){

    for (int i = 1; i < panjang; i++){

        char key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    return 0;
}

bool prima(int angka){

    if (angka < 2){
        return false;
    }

    for (int i = 2; i < angka; i++){
        if (angka % i == 0){
            return false;
        }
    }

    return true;
}

bool komposit(int angka){

    if (angka < 4){
        return false;
    }

    for (int i = 2; i < angka; i++){
        if (angka % i == 0){
            return true;
        }
    }

    return false;
}

int tampilAngka(int angka){

    if (angka < 10){
        std::cout << "0";
    }

    std::cout << angka;

    return 0;
}

int main(){

    std::cout << "[TASK 1/3] DECODE SIGNAL -- Comunication Room" << std::endl;
    std::cout << ">> Kirim Sinyal Terenkripsi dan Deskripsi Balasan Dari Bumi!!." << std::endl;
    std::cout << std::endl << "[ ENKRIPSI ]" << std::endl;

    char teks[MAX];
    int kolom;
    int key;
    int panjang = 0;

    do{
        std::cout << "Masukan Teks: ";
        std::cin.getline(teks, MAX);

        if(teks[0] == '\0'){
           std::cout << "[!] Input Harus Tidak Boleh Kosong" << std::endl;
        }

    }
    while (teks[0] == '\0');

    while (teks[panjang] != '\0'){
        panjang++;
    }

    do{
        std::cout << "Masukan Jumlah Kolom: ";
        std::cin >> kolom;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            kolom = 0;
            std::cout << "[!] Input harus angka" << std::endl;
        }
        else if(kolom < 1 || kolom > panjang){
            std::cout << "[!] Kolom Harus > 0 dan <= panjang teks (" << panjang << ")" << std::endl;
        }

    }
    while (kolom < 1 || kolom > panjang);

    do{
        std::cout << "Masukan Key Shift: ";
        std::cin >> key;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            key = 0;
            std::cout << "[!] Input harus angka" << std::endl;
        }
    }
    while (key < 1);

    int baris = panjang / kolom;

    if (panjang % kolom != 0){
        baris++;
    }

    char matriks[MAX][MAX];
    int index = 0;

    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){

            if (index < panjang){
                matriks[i][j] = teks[index];
                index++;
            }
            else{
                matriks[i][j] = '_';
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Matriks Enkripsi:" << std::endl;

    for (int i = 0; i < baris; i++){
        for (int j = 0; j < kolom; j++){
            std::cout << matriks[i][j] << ' ';
        }

        std::cout << std::endl;
    }

    char sebelumShift[MAX * MAX];
    int posisi = 0;

    for (int j = 0; j < kolom; j++){
        for (int i = 0; i < baris; i++){
            sebelumShift[posisi] = matriks[i][j];
            posisi++;
        }
    }

    sebelumShift[posisi] = '\0';
    std::cout << std::endl;
    std::cout << "Enkripsi Sebelum Ditambah Key: ";
    std::cout << sebelumShift << std::endl;

    char hasilEnkripsi[MAX * MAX];
    int i = 0;

    while (sebelumShift[i] != '\0'){
        hasilEnkripsi[i] = enkripsi(sebelumShift[i], key);
        i++;
    }

    hasilEnkripsi[i] = '\0';
    std::cout << "Enkripsi Setelah Ditambah Key: ";
    std::cout << hasilEnkripsi << std::endl;
    std::cout << std::endl << "[ DEKRIPSI ]" << std::endl;

    char inputDekripsi[MAX * MAX];
    std::cout << std::endl;

    do{
        std::cout << "Masukan Teks Terenkripsi: ";
        std::cin.ignore();
        std::cin.getline(inputDekripsi, MAX * MAX);

        if(inputDekripsi[0] == '\0'){
            std::cout << "[!] Input Harus Tidak Boleh Kosong" << std::endl;
        }

    }
    while (inputDekripsi[0] == '\0');

    char hasilKurangKey[MAX * MAX];
    i = 0;

    while (inputDekripsi[i] != '\0'){
        hasilKurangKey[i] = dekripsi(inputDekripsi[i], key);
        i++;
    }

    hasilKurangKey[i] = '\0';
    std::cout << "Dekripsi Setelah Dikurang Key: ";
    std::cout << hasilKurangKey << std::endl;

    int panjangDekripsi = 0;
    while (hasilKurangKey[panjangDekripsi] != '\0'){
        panjangDekripsi++;
    }

    int barisDekripsi = panjangDekripsi / kolom;
    if (panjangDekripsi % kolom != 0){
        barisDekripsi++;
    }

    char matriksDekripsi[MAX][MAX];
    index = 0;
    for (int j = 0; j < kolom; j++){
        for (int i = 0; i < barisDekripsi; i++){

            if (hasilKurangKey[index] != '\0'){
                matriksDekripsi[i][j] = hasilKurangKey[index];
                index++;
            }
            else{
                matriksDekripsi[i][j] = '_';
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Matriks Dekripsi:" << std::endl;

    for (int i = 0; i < barisDekripsi; i++){
        for (int j = 0; j < kolom; j++){
            std::cout << matriksDekripsi[i][j] << ' ';
        }

        std::cout << std::endl;
    }

    char hasilDekripsi[MAX * MAX];
    posisi = 0;
    for (int i = 0; i < barisDekripsi; i++){
        for (int j = 0; j < kolom; j++){

            if (matriksDekripsi[i][j] != '_'){
                hasilDekripsi[posisi] = matriksDekripsi[i][j];
                posisi++;
            }
        }
    }

    hasilDekripsi[posisi] = '\0';

    std::cout << std::endl;
    std::cout << "Hasil Dekripsi: ";
    std::cout << hasilDekripsi << std::endl;

    std::cout << ">> [TASK 1/3] COMPLETE -- Signal Channel Restored" << std::endl;
    std::cout << "Tekan ENTER untuk Melanjutkan ke [ TASK 2 ]!!.";

    std::cin.ignore();
    std::cin.get();

    char ulangProgram;
    bool ulang = true;

    while (ulang){

        std::cout << std::endl;
        std::cout << "[TASK 2/3] VERIFY CREW DATA -- Database Room" << std::endl;
        std::cout << ">> Verifikasi Data Awak Kapal Sekarang!!" << std::endl;
        std::cout << std::endl;

        for (int data = 1; data <= 3; data++){

            char teks[MAX];
            char clean[MAX];
            int index = 0;
            int i = 0;

            std::cout << "Input kalimat ke-" << data << "   :";
            std::cin.getline(teks, MAX);

            std::cout << "--------------------------------------------" << std::endl;

            while (teks[i] != '\0'){

                if (teks[i] != ' '){
                    clean[index] = teks[i];
                    index++;
                }

                i++;
            }

            clean[index] = '\0';

            int panjang = 0;

            while (clean[panjang] != '\0'){
                panjang++;
            }

            std::cout << std::endl;
            std::cout << "HASIL UNTUK KALIMAT KE-" << data << ":" << std::endl;
            std::cout << "Jumlah huruf: " << panjang << std::endl;
            std::cout << "1.Asli: ";

            for (int i = 0; i < panjang; i++){
                std::cout << clean[i] << ' ';
            }

            std::cout << std::endl;
            std::cout << "2.Inverse: ";

            for (int i = panjang - 1; i >= 0; i--){

                std::cout << clean[i];

                if (i != 0){
                    std::cout << ",";
                }
            }

            std::cout << std::endl;
            std::cout << "3.Swap karakter pertama dan terakhir: ";

            char swap[MAX];

            for (int i = 0; i < panjang; i++){
                swap[i] = clean[i];
            }

            swap[panjang] = '\0';

            char temp = swap[0];
            swap[0] = swap[panjang - 1];
            swap[panjang - 1] = temp;

            for (int i = 0; i < panjang; i++){
                std::cout << swap[i];
            }

            std::cout << std::endl;

            if (panjang == 0){
                std::cout << "4.Palindrome: NO";
            }
            else if (palindrome(clean, panjang)){
                std::cout << "4.Palindrome: YES";
            }
            else{
                std::cout << "4.Palindrome: NO";
            }

            std::cout << std::endl;

            char unik[MAX];
            int unikCount = 0;

            for (int i = 0; i < panjang; i++){

                bool found = false;

                for (int j = 0; j < unikCount; j++){

                    if (clean[i] == unik[j]){
                        found = true;
                    }
                }

                if (!found){
                    unik[unikCount] = clean[i];
                    unikCount++;
                }
            }

            insertionSort(unik, unikCount);

            std::cout << "5.Diurutkan (unik): ";

            for (int i = 0; i < unikCount; i++){

                std::cout << unik[i];

                if (i != unikCount - 1){
                    std::cout << ",";
                }
            }

            std::cout << std::endl;
            std::cout << std::endl;
        }

        bool validasiInput = false;

        std::cout << "===========================================" << std::endl;

        while (!validasiInput){

            std::cout << "Verifikasi Teks Lain? (y/n): ";
            std::cin >> ulangProgram;
            std::cin.ignore();

            if (ulangProgram == 'y' || ulangProgram == 'Y'){
                validasiInput = true;
            }
            else if (ulangProgram == 'n' || ulangProgram == 'N'){
                ulang = false;
                validasiInput = true;
            }
            else{
                std::cout << "[!] Input Tidak Valid. Masukan y atau n" << std::endl;
            }
        }
    }

    std::cout << std::endl;
    std::cout << "Tekan ENTER untuk Melanjutkan ke [ TASK 3 ]!!.";

    std::cin.get();

    std::cout << std::endl;
    std::cout << "[TASK 3/3] ALIGN NAVIGATION MATRIX -- Engine Core" << std::endl;
    std::cout << ">> Sistem Navigasi Mati Total Akibat Sabotase." << std::endl;
    std::cout << ">> Rekontruksi Matriks Koordinat Sekarang!" << std::endl;
    std::cout << std::endl << "[ MATRIX NAVIGATION]" << std::endl;

    int ukuran;

    do{
        std::cout << "Masukkan ukuran Navigation Matrix (min 3, max 5): ";
        std::cin >> ukuran;

        if (std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            ukuran = 0;
            std::cout << "[!] Input harus angka" << std::endl;
        }
        else if (ukuran < 3 || ukuran > 5){
            std::cout << "[!] Input tidak valid. Masukkan ukuran antara 3 sampai 5." << std::endl;
            std::cout << std::endl;
        }
    }
    while (ukuran < 3 || ukuran > 5);

    std::cout << "----------------------------------------------" << std::endl;

    int matriksPrima[5][5];
    int matriksKomposit[5][5];
    int angkaPrima = 2;
    int angkaKomposit = 4;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){

            while (!prima(angkaPrima)){
                angkaPrima++;
            }

            matriksPrima[i][j] = angkaPrima;
            angkaPrima++;
        }
    }

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){

            while (!komposit(angkaKomposit)){
                angkaKomposit++;
            }

            matriksKomposit[i][j] = angkaKomposit;
            angkaKomposit++;
        }
    }

    std::cout << std::endl;
    std::cout << "Prime Coordinate Matrix:" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(matriksPrima[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Composite Coordinate Matrix:" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(matriksKomposit[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    int fusion[5][5];

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            fusion[i][j] = matriksPrima[i][j] + matriksKomposit[i][j];
        }
    }

    int transpose[5][5];

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            transpose[j][i] = fusion[i][j];
        }
    }

    int snake[5][5];

    for (int i = 0; i < ukuran; i++){

        if (i % 2 == 0){

            for (int j = 0; j < ukuran; j++){
                snake[i][j] = transpose[i][j];
            }
        }
        else{

            int index = 0;

            for (int j = ukuran - 1; j >= 0; j--){
                snake[i][index] = transpose[i][j];
                index++;
            }
        }
    }

    int cWise[5][5];

    for (int j = 0; j < ukuran; j++){

        if (j % 2 == 0){

            for (int i = 0; i < ukuran; i++){
                cWise[i][j] = transpose[i][j];
            }
        }
        else{

            int index = 0;

            for (int i = ukuran - 1; i >= 0; i--){
                cWise[index][j] = transpose[i][j];
                index++;
            }
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Matriks koordinat telah dipulihkan" << std::endl;
    std::cout << "Lakukanlah proses-proses berikut ini untuk membuat matriks koordinat lebih akurat:" << std::endl;
    std::cout << "1. Coordinate Matrix Integration" << std::endl;
    std::cout << "2. Matrix Transpose" << std::endl;
    std::cout << "3. Snake Traverse" << std::endl;
    std::cout << "4. C-Wise Traverse" << std::endl;

    std::cout << std::endl;
    std::cout << "COORDINATE MATRIX INTEGRATION:" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(fusion[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "MATRIX TRANSPOSE:" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(transpose[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "SNAKE TRAVERSE:" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(snake[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "C-WISE TRAVERSE:" << std::endl;
    std::cout << "==========================================" << std::endl;

    for (int i = 0; i < ukuran; i++){
        for (int j = 0; j < ukuran; j++){
            tampilAngka(cWise[i][j]);
            std::cout << ' ';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << ">> [TASK 3/3] COMPLETE - Navigation matrix aligned." << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "ALL TASKS COMPLETE - SHIP SYSTEMS RESTORED" << std::endl;
    std::cout << "==========================================" << std::endl;

    return 0;
}
#include <iostream>

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
#include <stdio.h>
#include <string.h>

//* Roman to Integer
// M = 1000, D = 500, C = 100, L = 50, X = 10, V = 5, I = 1
// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].

int main(){
    char s[128];
    scanf("%s", s);
    int idx = strlen(s); 
    int result = 0, ceck = 0, count = 1; 
    // result = hasil akhir
    // ceck = nilai sementara
    // count = jumlah karakter yang sama berturut-turut

    for(int i = 0; i < idx; i++){ 
        if(s[i] == 'M' || 'D' || 'C' || 'L' || 'X' || 'V' || 'I'){ // validasi karakter
            if(i == 0){ // inisialisasi karakter pertama
                int temp0 = 0; // nilai sementara untuk karakter pertama
                switch (s[i]){ // konversi karakter ke nilai
                    case 'M' : temp0 = 1000; break;
                    case 'D' : temp0 = 500; break;
                    case 'C' : temp0 = 100; break;
                    case 'L' : temp0 = 50; break;
                    case 'X' : temp0 = 10; break;
                    case 'V' : temp0 = 5; break;
                    case 'I' : temp0 = 1; break;
                }
                ceck = temp0; // set nilai sementara
            }else{
                int temp1 = 0; // nilai sementara untuk karakter selanjutnya
                switch (s[i]){ // konversi karakter ke nilai
                    case 'M' : temp1 = 1000; break;
                    case 'D' : temp1 = 500; break;
                    case 'C' : temp1 = 100; break;
                    case 'L' : temp1 = 50; break;
                    case 'X' : temp1 = 10; break;
                    case 'V' : temp1 = 5; break;
                    case 'I' : temp1 = 1; break;
                }

                if(temp1 == ceck){ // jika karakter sama dengan karakter sebelumnya
                    count++;
                }else{
                    count = 1;
                }
                
                if(ceck < temp1){ // jika karakter sebelumnya lebih kecil dari karakter sekarang
                    ceck = (temp1 - (ceck * count * 2)); // hitung nilai dengan pengurangan
                }else{
                    ceck = temp1;
                }
                
            }
            result += ceck; // tambahkan nilai sementara ke hasil akhir
        }
    }

    printf("%d\n", result); // output hasil akhir
    return 0;
}
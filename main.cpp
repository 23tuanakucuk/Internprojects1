#include <iostream>
#include <string>
#include <sstream>
#include "console-operations.hpp"
#include "utill.hpp"






 void found_digit( int& dgt_thousand, int& dgt_hundred, int& dgt_ten, int& dgt_one,const int& sayi) {
     dgt_thousand = sayi / 1000;
     dgt_hundred = (sayi / 100) % 10;
     dgt_ten = (sayi % 100) / 10;
     dgt_one = sayi % 10;
}


void compareNumber(const int& input_dgt_thousand ,const int& input_dgt_hundred ,const int& input_dgt_ten ,const int& input_dgt_one ,const int& randomVal_dgt_thousand , const int& randomVal_dgt_hundred ,const int& randomVal_dgt_ten , const int& randomVal_dgt_one) {
     std::string comparnn;

     if (input_dgt_thousand == randomVal_dgt_thousand)
         { comparnn += "+"; }
     else {
         if ((randomVal_dgt_hundred == randomVal_dgt_ten || randomVal_dgt_hundred == randomVal_dgt_one || randomVal_dgt_ten == randomVal_dgt_one) && (input_dgt_thousand == randomVal_dgt_hundred || input_dgt_thousand == randomVal_dgt_ten || input_dgt_thousand == randomVal_dgt_one)) { comparnn += "o"; }
         else if (input_dgt_thousand == randomVal_dgt_hundred) {
             input_dgt_hundred == randomVal_dgt_hundred ? comparnn += "x" : comparnn += "o" ;;
         } else if (input_dgt_thousand == randomVal_dgt_ten) { input_dgt_ten == randomVal_dgt_ten ? comparnn += "x" : comparnn += "o"; }
         else if (input_dgt_thousand == randomVal_dgt_one) {
             input_dgt_one == randomVal_dgt_one ? comparnn += "x" : comparnn += "o";
         } else { comparnn += "x"; }
     }





    write(comparnn, TextColor::White, BackgroundColor::BlackBright);
}

int  main() {
   int randomVal = Utill::generateRandomInteger(999, 10'000);
     int p,r,s,t; // randomVal basamaklarına atanacak int ler
     int k,l,m,n; // input basamaklarına atanacak int ler
    auto column = 3;
    clearConsole();
    locateCursor(1, 1);
    write("Oyuncu1");

    locateCursor(18, 1);
    write("Oyuncu2");

     found_digit(p,r,s,t,randomVal);
    while (true) {
        int input;
        locateCursor(1, column);
        std::cin >> input;


        if (randomVal != input) {
            locateCursor(8, column);
            found_digit(k,l,m,n,input);
            compareNumber(k,l,m,n,p,r,s,t);
            compareNumber(l,k,m,n,r,p,s,t);
            compareNumber(m,k,l,n,s,p,r,t);
            compareNumber(n,k,l,m,t,p,r,s);
            locateCursor(1, column + 2);
            write("  Kaybettiniz", TextColor::White, BackgroundColor::BlackBright);
        } else if (randomVal == input) {
            column += 4 ;
            locateCursor(1, column);
            write("  Kazandınız", TextColor::White, BackgroundColor::BlackBright);
            break;
        }


        locateCursor(15, column);
        std::cin >> input;


        if (randomVal != input) {
            locateCursor(22, column);
            found_digit(k,l,m,n,input);
            compareNumber(k,l,m,n,p,r,s,t);
            compareNumber(l,k,m,n,r,p,s,t);
            compareNumber(m,k,l,n,s,p,r,t);
            compareNumber(n,k,l,m,t,p,r,s);
            locateCursor(15, column + 2);
            write("  Kaybettiniz", TextColor::White, BackgroundColor::BlackBright);

            column+=4;
        } else if (randomVal == input) {
            locateCursor(15, column + 2);
            write("  Kazandınız", TextColor::White, BackgroundColor::BlackBright);
            break;
        }
    }
}

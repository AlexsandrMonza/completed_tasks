#include <iostream>
#include <string>

std::string get_address_part ( std::string number, int a ) {
    int i;
    int A = 0;         //Считает точки (граница между цифрами)
    std::string strA;  // Первая часть 255.0.0.0
    std::string strB;  // Вторая часть 0.255.0.0
    std::string strC;  // Третья часть 0.0.255.0
    std::string strD;  // Четвертая часть 0.0.0.255

    if (a == 1){
        for (i = 0; i<number.length(); i++){
            if(number[i]== '.'){
                break;
            }
            strA +=number[i];
        }
        return strA;
    }

    if (a == 2){
        for (i = 0; i<number.length(); i++)
            if(number[i] == '.'){
                A +=1;
            }
            else if (A == 1){
                strB += number [i];
            }
            else if (A == 2){
                break;
            }
        return strB;
    }

    if (a == 3){
        for (i = 0; i<number.length(); i++)
            if(number[i] == '.'){
                A +=1;
            }
            else if (A == 2){
                strC += number [i];
            }
            else if (A == 3){
                break;
            }
        return strC;
    }

    if (a == 4){
        for (i = 0; i<number.length(); i++)
            if(number[i] == '.'){
                A +=1;
            }
            else if (A == 3){
                strD += number [i];
            }
        return strD;
    }
}

int main ()
{
    int i;
    bool good = true;  //Проверка всего IP
    bool goodA = true; //Проверка отдельных блоков IP
    std::string number; // IP
    std::string strA; // Первая часть 255.0.0.0
    std::string strB; // Вторая часть 0.255.0.0
    std::string strC; // Третья часть 0.0.255.0
    std::string strD; // Четвертая часть 0.0.0.255

    std::cout<<"Enter IP: ";
    std::cin>>number;


//Общая проверка на наличие символов кроме цифр и точки

    for (i = 0; i<number.length(); i++) {
        if (( number[ i ] < '0' && number[ i ] > '9' ) || number[ i ] != '.' ) {
            good = false;
        }
    }


// Общая проверка на наличие точек в начале или конце IP

    for (i = 0; i<number.length(); i++){
        if ((number[0] == '.' && number[number.length()-1] == '.') || number[0] == '.' || number[number.length()-1] == '.'){
            good = false;
        }
    }


//Общая проверка на наличие двух точек подряд

    for (i = 0; i<number.length(); i++) {
        int a;
        if ( number[ i ] == '.' ) {
            a += 1;
            if ( number[ i + 1 ] == '.' )
                good = false;
        }
    }


//Вызываем функцию по отдельным блокам IP

    strA = get_address_part (number, 1);
    strB = get_address_part (number, 2);
    strC = get_address_part (number, 3);
    strD = get_address_part (number, 4);


//Проверка на начилие лишних нулей в каждом блоке

    if (strA[0] == '0'){
        if (strA[1] == '0'){
            good = false;
        }
        else if (strA[1] != '0'){
            good = false;
        }
    }

    if (strB[0] == '0'){
        if (strB[1] == '0'){
            good = false;
        }
        else if (strB[1] != '0'){
            good = false;
        }
    }

    if (strC[0] == '0'){
        if (strC[1] == '0'){
            good = false;
        }
        else if (strC[1] != '0'){
            good = false;
        }
    }

    if (strD[0] == '0') {
        if ( strD[ 1 ] == '0' ) {
            good = false;
        } else if ( strD[ 1 ] != '0' ) {
            good = false;
        }
    }


//Проверка корректности числа в каждом блоке (0-255)

    for (i = 0; i<strA.length(); i++) {
        if ( strA[ 0 ] > '2' ) {
            goodA = false;
        }
        if ( strA[ 0 ] == '2' ) {
            if ( strA[ 1 ] == '5' ) {
                if ( strA[ 2 ] > '5' ) {
                    goodA = false;
                }
            }
        }
    }

    for (i = 0; i<strB.length(); i++) {
        if ( strB[ 0 ] > '2' ) {
            goodA = false;
        }
        if ( strB[ 0 ] == '2' ) {
            if ( strB[ 1 ] == '5' ) {
                if ( strB[ 2 ] > '5' ) {
                    goodA = false;
                }
            }
        }
    }

    for (i = 0; i<strC.length(); i++) {
        if ( strC[ 0 ] > '2' ) {
            goodA = false;
        }
        if ( strC[ 0 ] == '2' ) {
            if ( strC[ 1 ] == '5' ) {
                if ( strC[ 2 ] > '5' ) {
                    goodA = false;
                }
            }
        }
    }

    for (i = 0; i<strD.length(); i++) {
        if ( strD[ 0 ] > '2' ) {
            goodA = false;
        }
        if ( strD[ 0 ] == '2' ) {
            if ( strD[ 1 ] == '5' ) {
                if ( strD[ 2 ] > '5' ) {
                    goodA = false;
                }
            }
        }
    }


// Результат проверки

    if (good && goodA){
        std::cout<<"Valid";
    }
    else {
        std::cout<<"Invalid";
    }
}
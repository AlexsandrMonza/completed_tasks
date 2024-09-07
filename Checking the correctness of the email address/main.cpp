#include <iostream>
#include <string>

std::string begin(std::string email) {
    std::string strA;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            break;
        }
        strA += email[i];
    }
    return strA;
}

std::string finish(std::string email) {
    std::string strB;
    for (int i = email.length() - 1; i > 0; i--) {
        if (email[i] == '@') {
            break;
        }
        strB += email[i];
    }
    return strB;
}

int main()
{
    std::string email;
    std::string strA;   //Первая часть email
    std::string strB;   //Вторая часть email
    int a = 0;          //Проверка наличия символов @
    int b = 0;          //Проверка кол-ва символов @
    int c = 0;          //Проверка местонахождения символов .
    int i = 0;          //Счетчик

    bool emailStrA = true;   //Проверка на соответствие первой части email
    bool emailStrB = true;   //Проверка на соответствие второй части email
    bool emailB = true;      //Проверка общего email

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    strA = begin(email);
    strB = finish(email);


    // Общие условия

    for (i = 0; i < email.length()-1; i++) {
        if (i > 128) {
            std::cout << "Incorrect email1!";
            emailB = false;
            break;
        }
    }

    while (strA.length() < 1 || strA.length() > 64) {
        std::cout << "Incorrect email!\n";
        std::cout << "Enter email: ";
        std::getline(std::cin, email);
        strA = begin(email);
    }

    while (strB.length() < 1 || strB.length() > 63) {
        std::cout << "Incorrect email!\n";
        std::cout << "Enter email: ";
        std::getline(std::cin, email);
        strB = finish(email);
    }

    for (i = 0; i < email.length(); i++) {
        if (email[i] != '@') {
            a += 1;
            if (a == email.length() ) {
                emailB = false;
                std::cout << "No '@' !";
                break;
            }
        }
    }

    for (i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            b += 1;
            if (b > 1) {
                emailB = false;
                std::cout << "Two '@' !";
                break;
            }
        }
    }


    //Проверка первой части

    for (i = 0; i < strA.length(); i++) {
        if ((strA[i] >= 'a' && strA[i] <= 'z') || (strA[i] >= 'A' && strA[i] <= 'Z') || (strA[i] >= '0' && strA[i] <= '9') || (
                strA[i] == '!' || strA[i] == '#' || strA[i] == '$' || strA[i] == '%' || strA[i] == '&' || strA[i] == '*' ||
                strA[i] == '+' || strA[i] == '-' || strA[i] == '/' || strA[i] == '=' || strA[i] == '?' || strA[i] == '^' ||
                strA[i] == '_' || strA[i] == '`' || strA[i] == '{' || strA[i] == '|' || strA[i] == '}' || strA[i] == '~' ||
                strA[i] == '.')) {
            emailStrA = true;
        }
        else {
            emailStrA = false;
            break;
        }
    }

    if ((strA[0]=='.' && strA[strA.length()-1]=='.') || strA[0]=='.' || strA[strA.length()-1]=='.') {
        emailStrA = false;
        std::cout << "'.'";
    }

    for (i = 0; i < strA.length(); i++) {
        if ( strA[ i ] == '.' ) {
            if ( strA[ i + 1 ] == '.' ) {
                emailStrA = false;
                std::cout << "Two .. !";
                break;
            }
        }
    }


    //Проверка второй части

    for (i = 0; i < strB.length(); i++) {
        if (strB[i] == '.') {
            c += 1;
            if (c > 1) {
                emailStrA = false;
                std::cout << "Two ..6 !"<<strB;
                break;
            }
        }
    }

    for (i = 0; i < strB.length(); i++) {
        if ((strB[i] >= 'a' && strB[i] <= 'z') || (strB[i] >= 'A' && strB[i] <= 'Z') || (strB[i] >= '0' && strB[i] <= '9') ||  strB[i] == '-' || strB[i] == '.') {
            emailStrB = true;
        }
        else {
            emailStrB = false;
            break;
        }
    }


    if (emailStrA && emailStrB && emailB) {
        std::cout << "Yes!";
    }
    else {
        std::cout << "No!";
    }
}
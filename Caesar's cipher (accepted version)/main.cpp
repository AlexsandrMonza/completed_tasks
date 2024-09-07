#include <iostream>
#include <string>


std::string encrypt(std::string text, int offset)
{
    std::string out;
    char a;
    for(int i=0; i<text.length(); i++)
    {
        a=text[i];
          if (a>='a' && a<='z')
          {
            a = 'a' + (a - 'a' + offset) % 26;
          }
          else if (a>='A' && a<='Z')
          {
              a = 'A' + (a - 'A' + offset) % 26;
          }
          else if (a == ' ')
          {
              a = ' ';
          }
        out+=a;
    }
    return out;
}

int main()
{
    int choice;
    int offset;
    std::string text;
    std::cout<<"Enter the text: ";
    std::getline(std::cin,text);


    for (int i=0; i<text.length(); i++ )
    {
        while (((text[i]<'a' || text[i] >'z') && text[i]!=' ') &&  ((text[i]<'A' || text[i] >'Z')&& text[i]!=' '))
        {
            std::cout<<"The input is incorrect!\n";
            std::cout<<"Enter the text: ";
            std::getline(std::cin,text);
        }
    }

    std::cout<<"Offset: ";
    std::cin>>offset;
    std::cout<<"1.Encrypt\n";
    std::cout<<"2.Decrypt\n";
    std::cin>>choice;

    std::string enc = encrypt(text, offset);;
    std::string dec = encrypt(enc, -offset);

    if (choice==1){
        std::cout << enc;
    }
    else if (choice==2){

        std::cout << encrypt(text, -offset);;
    }
    else if (choice==3){
        std::string enc = encrypt(text, offset);
        std::string dec = encrypt(enc, -offset);
        std::cout<<enc<<"\n";
        std::cout<<dec;
    }
    else {
        std::cout<<"The input is incorrect!";
    }
}

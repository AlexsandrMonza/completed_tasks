#include <iostream>
#include <string>
#include <map>

int result (){
    bool result=false;
    std::string word;

    std::map <char,int> wordOne;
    std::map<char,int> wordTwo;

    std::map <char,int>::iterator it=wordOne.begin();

    std::cout<<"Input word one\n";
    std::cin>>word;

    for (int i=0;i<word.length();i++){
        wordOne.insert(std::make_pair(word[i],0));
    }

    std::cout<<"Input word two\n";
    std::cin>>word;

    for (int i=0;i<word.length();i++){
        wordTwo.insert(std::make_pair(word[i],0));
    }

    if (wordOne==wordTwo){
        result=true;
    }
    return result;
}

int main () {
    bool res=false;
    res = result ();
    if(res){
        std::cout<<"Yes\n";
    }
    else {
        std::cout<<"No\n";
    }
}

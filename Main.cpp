#include <iostream>
#include <vector>
#include <ctype.h>
#include <string> 

std::string encode(std::string word,std::string keyWord);
char encode(char source, char key);
int  encode(int  source, int  key);
int  toInt (char character);
char toChar(int  number);

int main (){
    std::string word = "GEEKSFORGEEKS";
    std::string key = "AYUSH";
    std::string encoded = encode(word, key);

    std::cout << word << " encoded using " << key << " is: " << encoded << std::endl;
    std::cout << "IS WORKING: " << (encoded == "GCYCZFMLYLEIM" ? "YES!" : "No :(") << std::endl;
    
}

std::string encode(std::string word,std::string keyWord){
    std::string result = "";
    for (int i =0 ; i< word.length() ; i++){
        char source = word[i];
        char key = keyWord[i%(keyWord.length())];
        char encoded = encode(source, key);
        result.push_back(encoded);
    }
    return result;
}


int toInt(char character){
    return (int) (character - 'A');
}

char toChar(int number){
    return (char) ('A' + number);
}

char encode(char source, char key){
    return toChar(encode(toInt(source), toInt(key)));
}

int encode(int source, int key){
    return (source + key)%26;
}

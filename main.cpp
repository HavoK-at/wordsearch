#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <map>

void usage(void);

int main(int argc, char* argv[]) {

    if (argc < 2) {
        usage();
        return 0;
    }

    // Measure Time
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    /* implemention */

    std::map<char, int> numberOfChars;
    std::map<int, std::vector<std::string>> foundWords;

    int inputSize = 0;

    for(unsigned int i = 1; i < argc; i ++){
        for(char* it = argv[i]; *it; it++) {
            char addChar = (char)tolower(*it);
            if(97 <= addChar && addChar <= 122) {
                inputSize++;
                numberOfChars[addChar]++;
            }
        }
    }

    std::cout << "Number of Inputs: " << inputSize << " ; Input:" << std::endl;
    for(auto &it : numberOfChars){
        std::cout << it.first << " " << it.second << std::endl;
    }

    // Open wordlist
    std::ifstream file("../enable1.txt");
    if(!file.is_open()){
        std::cout << "Couldn't open file!" << std::endl;
        return 0;
    }

    std::string str;
    std::map<char, int> wordNumberOfChars;
    char currentCharCheck;
    unsigned long currentWordLength;
    int currentCharNumber;
    bool addCurrentWord;
    unsigned int wordsFound = 0;
    std::cout << "searching" << std::endl;

    while (std::getline(file, str)) {
        wordNumberOfChars.clear();
        addCurrentWord = true;
        currentWordLength = str.length();

        if (currentWordLength <= inputSize) {
            for(auto &it : str){
                wordNumberOfChars[it]++;
            }
            for(auto &it : wordNumberOfChars){
                currentCharCheck = it.first;
                currentCharNumber = it.second;
                if(numberOfChars[currentCharCheck] < currentCharNumber) {
                    addCurrentWord = false;
                }
            }
            if(addCurrentWord){
                wordsFound ++;
                foundWords[currentWordLength].push_back(str);
            }
        }
    }
    std::chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

    for(auto& mapit : foundWords){
        for(auto& vecit: mapit.second){
            std::cout << "[" << mapit.first << "] " << vecit << std::endl;
        }
    }
    std::cout << "Words found: " << wordsFound << std::endl;

    // measure end time
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
    std::cout << std::endl << "Time used = " << time << " µs" << std::endl;
    return 0;
}

void usage (void){
    std::cout << "Usage: havok_wordsearch <list of characters>" << std::endl;
}
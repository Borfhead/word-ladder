#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <vector>

class Game{
    public:
    Game(std::string dictionary);
    void listWords();
    void play(std::string first, std::string last);
    void play(std::string first);
    bool findWord(std::string toFind);
    bool isOneLetterOff(std::string base, std::string test);
    std::vector<std::string> getAllCloseWords(std::string first);
    bool hasBeenGenerated(std::string value);
    int getNumWordsInDictionary();
    void printLadder(std::vector<std::string> &toPrint);
    std::string getInDic(int index);
    
    
    private:
    std::vector<std::string> m_dictionary;
    std::vector<std::string> m_generatedWords;
    std::vector<std::vector<std::string>> m_partialLadders;
    

};


#endif
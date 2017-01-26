#ifndef _GAME_H_
#define _GAME_H_

#include <string>
#include <vector>
#include <deque>

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
    void genWordsPossible(int wordLength);
    
    
    private:
    std::vector<std::string> m_dictionary;
    std::deque<std::vector<std::string>> m_partialLadders;
    std::vector<std::string> m_generatedWords;
    std::vector<std::string> m_wordsPossible;
    

};


#endif
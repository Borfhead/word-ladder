#include "Game.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <locale>

Game::Game(std::string dictionary)
{
    std::ifstream file;
    std::string line;
    
    file.open(dictionary);
    if(!file)
    {
        std::cout << "Couldn't open file" << std::endl;
    }
    if(file.is_open())
    {
        while (std::getline(file, line))
        {
            //Borrowed code to get rid of non-printable character at the end of
            //every line.
            line.erase(remove_if(line.begin(), line.end(), [](char c) { return !isalpha(c); } ), line.end());
            m_dictionary.push_back(line);
        }
    }
    file.close();
    
    
    
}


bool Game::findWord(std::string toFind)
{
    
    if(std::binary_search(m_dictionary.begin(), m_dictionary.end(), toFind))
    {
        return true;
    }
    return false;
}

void Game::listWords()
{
    for(int i = 0; i < 10; i++)
    {
        std::cout << m_dictionary[i] << std::endl;
    }
}

void Game::play(std::string first, std::string last)
{
    m_generatedWords.clear();
    m_partialLadders.clear();
    if(first.length() != last.length())
    {
        std::cout << first << " and " << last << " are not the same length!" << std::endl;
    }
    
    else if(!findWord(first))
    {
        std::cout << first << " not found in dictionary" << std::endl;
    }
    else if(!findWord(last))
    {
        std::cout << last << " not found in dictionary" << std::endl;
    }
    
    else
    {
        genWordsPossible(first.length());
        std::vector<std::string> ladder;
        std::string current;
        m_generatedWords.push_back(first);
        ladder.push_back(first);
        m_partialLadders.push_back(ladder);
        while(!m_partialLadders.empty())
        {
            ladder = m_partialLadders.front();
            current = ladder.back();
            m_partialLadders.pop_front();
            
            if(current == last)
            {
                std::cout << "Here is the shortest ladder from " << first << " to " << last <<":" << std::endl;
                printLadder(ladder);
                return;
            }
            else
            {
                for(auto unusedWord : getAllCloseWords(current))
                {
                    if(hasBeenGenerated(unusedWord))
                    {
                        //Do nothing
                    }
                    else
                    {
                    std::vector<std::string> temp = ladder;
                    temp.push_back(unusedWord);
                    m_generatedWords.push_back(unusedWord);
                    m_partialLadders.push_back(temp);
                    }
                    
                }
            }
            
        }
        std::cout << "Could not find a ladder from " << first << " to " << last << std::endl;
    }
}

void Game::play(std::string first)
{
    int length = first.length();
    std::string rand1;
    std::string rand2;
    while(rand1.length() != length)
    {
        rand1 = getInDic((rand() % m_dictionary.size()));
    }
    while(rand2.length() != length && rand1 != rand2)
    {
       rand2 = getInDic((rand() % m_dictionary.size()));
    }
    std::cout << "Only one word given.  Playing " << rand1 << " and " << rand2 <<std::endl;
    play(rand1, rand2);
    
}

bool Game::isOneLetterOff(std::string base, std::string test)
{
    int numDiff = 0;
    if(base.length() == test.length())
    {
        for(int i = 0; i < base.length(); i++)
        {
            if(numDiff > 1)
            {
                return false;
            }
            if(base[i] != test[i])
            {
                numDiff++;
            }
        }
        if(numDiff <= 1)
        {
            return true;
        }
    }
    return false;
    
    
}

std::vector<std::string> Game::getAllCloseWords(std::string first)
{
    std::vector<std::string> rtnVector;
    for(auto word : m_wordsPossible)
        {
            if(isOneLetterOff(first, word))
            {
                rtnVector.push_back(word);
            }
        }
        return rtnVector;
}

bool Game::hasBeenGenerated(std::string value)
{
    std::sort(m_generatedWords.begin(), m_generatedWords.end());
    return (binary_search(m_generatedWords.begin(), m_generatedWords.end(), value));
}


int Game::getNumWordsInDictionary()
{
    return m_dictionary.size();
}

void Game::printLadder(std::vector<std::string> &toPrint)
{
    
    for(auto str : toPrint)
    {
        std::cout << str << std::endl;
    }
}

std::string Game::getInDic(int index)
{
    return m_dictionary[index];
}

void Game::genWordsPossible(int wordLength)
{
    m_wordsPossible.clear();
    for(auto word : m_dictionary)
    {
        if(word.length() == wordLength)
        {
            m_wordsPossible.push_back(word);
        }
    }
}




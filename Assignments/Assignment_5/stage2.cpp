
#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

int main(int argc, char *argv[])
{
    std::string filename;
    if (argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        std::cout << " Enter The File Name You Want to Read\n";
        std::cin >> filename;
    }

    std::ifstream stopwords_file("stopwords.txt");
    if (!stopwords_file)
    {

        std::cout << " Error Opening in File \n";
        return 1;
    }

    map<std::string, int> words_freq;
    map<std::string, bool> stop_words;
    std::string word;
    while (stopwords_file >> word)
    {
        std::string lower_words = "";
        for (int i = 0; i < word.size(); ++i)
        {
            lower_words += tolower(word[i]);
        }
        stop_words[lower_words] = true;
    }
    return 0;
}
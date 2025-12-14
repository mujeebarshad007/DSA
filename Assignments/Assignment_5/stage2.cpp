#include <iostream>
#include <fstream>
#include <string>
#include "map.h"

int main(int argc, char *argv[])
{
    std::string filename;
    if (argc > 1)
        filename = argv[1];
    else
    {
        std::cout << "Enter the file name: ";
        std::cin >> filename;
    }

    std::ifstream stopwords_file("stopwords.txt");
    if (!stopwords_file)
    {
        std::cout << "Error opening stopwords.txt\n";
        return 1;
    }

    map<std::string, bool> stop_words;
    std::string word;
    while (stopwords_file >> word)
    {
        std::string lower_words;
        for (int i = 0; i < word.size(); ++i)
            lower_words += tolower(word[i]); // using tolower function
        stop_words[lower_words] = true;
    }
    stopwords_file.close();

    std::ifstream file(filename);
    if (!file)
    {
        std::cout << "Cannot open file\n";
        return 1;
    }

    map<std::string, int> words_freq;
    while (file >> word)
    {
        std::string cleaned_words;
        for (int i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                cleaned_words += c;
            else if (c >= 'A' && c <= 'Z')
                cleaned_words += tolower(c);
        }

        if (cleaned_words != "" && !stop_words.contains(cleaned_words))
            words_freq[cleaned_words] = words_freq[cleaned_words] + 1;
    }
    file.close();

    std::cout << "\nAll elements in map:" << std::endl;
    map<std::string, int>::iterator it;
    it = words_freq.begin();
    while (it != words_freq.end())
    {
        std::cout << it->first << " : " << it->second << std::endl;
        ++it;
    }

    return 0;
}

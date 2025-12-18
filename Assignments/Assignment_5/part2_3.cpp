#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <curl/curl.h>

using namespace std;

size_t save_data(void *buffer, size_t size, size_t count, void *param)
{
    string *page = (string *)param;
    page->append((char *)buffer, size * count);
    return size * count;
}

int main(int argc, char **argv)
{
    string address;

    if (argc == 2)
        address = argv[1];
    else
    {
        cout << "URL: ";
        cin >> address;
    }

    /* get webpage */
    CURL *h = curl_easy_init();
    string page_data;

    if (h)
    {
        curl_easy_setopt(h, CURLOPT_URL, address.c_str());
        curl_easy_setopt(h, CURLOPT_WRITEFUNCTION, save_data);
        curl_easy_setopt(h, CURLOPT_WRITEDATA, &page_data);
        curl_easy_perform(h);
        curl_easy_cleanup(h);
    }

    // tags ko remove krna
    string plain;
    bool reading = true;

    for (int i = 0; i < page_data.length(); i++)
    {
        if (page_data[i] == '<')
            reading = false;
        else if (page_data[i] == '>')
            reading = true;
        else if (reading)
            plain += page_data[i];
    }

    // word frequency
    map<string, int> words;
    string temp;

    for (int i = 0; i < plain.length(); i++)
    {
        if (isalpha(plain[i])) // using isalpha for alphabet chek
            temp += tolower(plain[i]);
        else
        {
            if (temp.length() > 2)
                words[temp]++;

            temp.clear();
        }
    }

    ofstream file("word_cloud.html");

    file << "<html>\n<body>\n";
    file << "<h1>Word Cloud</h1>\n";

    map<string, int>::iterator p;
    for (p = words.begin(); p != words.end(); ++p)
    {
        int sz = p->second;
        if (sz > 28)
            sz = 28;

        file << "<span style='font-size:" << sz << "px'>"
             << p->first << "</span> ";
    }

    file << "\n</body>\n</html>";
    file.close();

    return 0;
}

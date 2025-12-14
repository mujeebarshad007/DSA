#include <iostream>
#include <fstream>
#include <string>
#include <curl/curl.h>

using namespace std;

size_t writeCallback(void *contents, size_t size, size_t nmemb, string *output)
{
    int total = size * nmemb;
    for (int i = 0; i < total; i++)
        output->push_back(((char *)contents)[i]);
    return total;
}

int main()
{
    string url;
    cout << "Enter URL: ";
    cin >> url;

    string html;
    CURL *curl = curl_easy_init();

    if (!curl)
    {
        cout << "Curl init failed\n";
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    // Remove HTML tags
    ofstream out("temp.txt");
    bool insideTag = false;

    for (int i = 0; i < html.size(); i++)
    {
        char c = html[i];

        if (c == '<')
            insideTag = true;
        else if (c == '>')
            insideTag = false;
        else if (!insideTag)
            out << c;
    }

    out.close();

    cout << "Webpage saved as temp.txt\n";
    cout << "Now run Stage-2 on temp.txt\n";

    return 0;
}

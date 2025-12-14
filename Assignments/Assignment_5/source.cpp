// Loading stop words
while (stopFile >> word)
{
    string lw = "";
    for (int i = 0; i < word.size(); i++)
    {
        lw += tolower(word[i]); // use tolower instead of c + 32
    }
    stopWords[lw] = true;
}

// Cleaning input words
while (file >> word)
{
    string cleaned = "";
    for (int i = 0; i < word.size(); i++)
    {
        char c = word[i];
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
            cleaned += c;
        else if (c >= 'A' && c <= 'Z')
            cleaned += tolower(c); // use tolower here
    }
    // rest of the code remains same
}

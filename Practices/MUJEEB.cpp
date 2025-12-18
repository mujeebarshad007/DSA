#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{

    /* ================= TASK 1 ================= */
    cout << "Task 1:\n";

    unordered_map<int, string> mp;

    // Insert 3 key-value pairs
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";

    // Update an existing key
    mp[2] = "TWO";

    // Check if key exists
    if (mp.find(2) != mp.end())
        cout << "Key 2 exists\n";
    else
        cout << "Key 2 not found\n";

    cout << "\n";

    /* ================= TASK 2 ================= */
    cout << "Task 2:\n";

    int N;
    cin >> N;
    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    int ans = 0, mx = 0;
    for (auto &p : freq)
    {
        if (p.second > mx ||
            (p.second == mx && p.first < ans))
        {
            mx = p.second;
            ans = p.first;
        }
    }

    cout << ans << "\n\n";

    /* ================= TASK 3 ================= */
    cout << "Task 3:\n";

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int T;
    cin >> T;

    unordered_map<int, int> indexMap;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        int need = T - arr[i];
        if (indexMap.find(need) != indexMap.end())
        {
            int j = indexMap[need];
            cout << min(i, j) << " " << max(i, j) << "\n";
            found = true;
            break;
        }
        indexMap[arr[i]] = i;
    }

    if (!found)
        cout << -1 << "\n";

    cout << "\n";

    /* ================= TASK 4 ================= */
    cout << "Task 4:\n";

    string s;
    cin >> s;

    unordered_map<char, int> charFreq;
    for (char c : s)
        charFreq[c]++;

    bool printed = false;
    for (char c : s)
    {
        if (charFreq[c] == 1)
        {
            cout << c << "\n";
            printed = true;
            break;
        }
    }

    if (!printed)
        cout << -1 << "\n";

    return 0;
}

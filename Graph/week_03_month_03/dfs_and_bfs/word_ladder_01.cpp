#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // Code here
    unordered_set<string> st;

    st.insert(wordList.begin(), wordList.end());
    st.erase(startWord);

    queue<pair<string, int>> q;

    q.push({startWord, 1});

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;

        if (word == targetWord)
        {
            return steps;
        }
        q.pop();

        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];

            for (char j = 'a'; j <= 'z'; j++)
            {
                word[i] = j;

                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }

            word[i] = original;
        }
    }

    return 0;
}

int main()
{

    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << wordLadderLength(startWord, targetWord, wordList) << endl;

    return 0;
}
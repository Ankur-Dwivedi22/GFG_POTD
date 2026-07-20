struct Trie
{
public:
    Trie *children[26];
    int numOfVis;

    Trie()
    {
        numOfVis = 0;
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};

void insertInTrie(Trie *root, string &s)
{
    Trie *temp = root;
    for (char c : s)
    {
        int ind = c - 'a';
        if (temp->children[ind] == NULL)
        {
            temp->children[ind] = new Trie();
        }
        temp = temp->children[ind];
        temp->numOfVis += 1;
    }
}

string findPrefix(Trie *root, string &s)
{
    string pre = "";
    Trie *temp = root;
    for (char c : s)
    {
        pre += c;
        int ind = c - 'a';
        temp = temp->children[ind];
        if (temp->numOfVis == 1)
        {
            return pre;
        }
    }

    return pre;
}

class Solution
{
public:
    vector<string> findPrefixes(vector<string> &arr)
    {
        // code here
        vector<string> ans;
        Trie *root = new Trie();
        for (string &s : arr)
        {
            insertInTrie(root, s);
        }

        for (string &s : arr)
        {
            ans.push_back(findPrefix(root, s));
        }

        return ans;
    }
};
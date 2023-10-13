#include <bits/stdc++.h>

using namespace std;

class Node
{
    Node *links[26];
    bool flag;

public:
    Node()
    {
        flag = false;
    }

    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }

    void addNode(char c)
    {
        Node *node = new Node();
        links[c - 'a'] = node;
    }

    Node *getNode(char c)
    {
        return links[c - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->addNode(word[i]);
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getNode(word[i]);
        }
        return node->isEnd();
    }
};

int main()
{
    return 0;
}
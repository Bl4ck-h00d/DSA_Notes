/**
 * Functionalities-
 * insert(word)
 * erase(word)
 * countWordsEqualTo(word)
 * countWordsStartingWith(word)
 *
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    int countEndWith = 0;
    int countPrefix = 0;

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    void addNode(char ch)
    {
        Node *node = new Node();
        links[ch - 'a'] = node;
    }

    Node *getNode(char ch)
    {
        return links[ch - 'a'];
    }

    void incrementEnd()
    {
        countEndWith++;
    }

    void incrementPrefix()
    {
        countPrefix++;
    }

    void deleteEnd()
    {
        countEndWith--;
    }

    void decrementPrefix()
    {
        countPrefix--;
    }

    int getEndCount()
    {
        return countEndWith;
    }

    int getPrefixCount()
    {
        return countEndWith;
    }


    bool deleteNode(Node *node, int i, string word)
    {
        if (i == word.size())
        {
            node->countEndWith--;
            node->countPrefix--;
            return true;
        }

        if (node->containsKey(word[i]))
        {
            Node *nextNode = node->getNode(word[i]);
            bool wordExist = deleteNode(nextNode, i + 1, word);

            //delete the prefix only if the word exists
            if (wordExist)
                node->countPrefix--;
        }
        return false;
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

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->addNode(word[i]);

            node = node->getNode(word[i]);
            node->incrementPrefix();
        }

        node->incrementEnd();
    }

    int countWordsEndWith(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;

            node = node->getNode(word[i]);
        }

        return node->getEndCount();
    }

    int countWordStartsWith(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                return 0;

            node = node->getNode(word[i]);
        }

        return node->getPrefixCount();
    }

    void erase(string &word)
    {
        Node *node = root;
        node->deleteNode(node, 0, word);
    }
};

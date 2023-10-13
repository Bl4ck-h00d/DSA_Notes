/**
 *
 * Trie is a tree like datastructure generally used to optimize the search time of strings.
 * Applications- Find feature, dictonary etc.
 *
 *
 * Each node is of type Trie which is similar to following structure
 *
 * class Trie {
 *  Trie* a[26]; //array for storing the ref of other nodes corresponding to their character
 *  bool flag; //flag
 * };
 *
 *
 *
 *                          Root
 *                         flag=false;
 *                         arr[26]
 *
 * Insert "apple"
 *
 * -Start with root
 * -Starting from root ask, do you have any string starting from 'a'. => arr['a'-'a']==NULL => No, so insert 'a'
 *
 *
 *                          Root
 *                         flag=false;
 *                         a-----------------------
 *                         b-null                 |
 *                         c- null                |
 *                        ...                     |
 *                         z-null                 |
 *                                                v
 *                                               Node 1
 *                                              flag=false
 *                                              a-
 *                                              b-
 *                                              c-
 *
 *
 *
 * - Now we are on Node 1, ask if there is anything starting with 'p' from here?
 * arr['p'-'a']==NULL => NO, so insert 'p'
 *
 *
 *
 *                          Root
 *                         flag=false;
 *                         a-----------------------
 *                         b-null                 |
 *                         c- null                |
 *                        ...                     |
 *                         z-null                 |
 *                                                v
 *                                               Node 1
 *                                              flag=false
 *                                              a-
 *                                              b-
 *                                              c-
 *                                              p--------
 *                                                      |
 *                                                      |
 *                                                      |
 *                                                      v
 *                                                    Node 2
 *                                                   flag=false
 *                                                    a-
 *                                                    b-
 *                                                    c-
 *
 *
 * So on..
 *
 * -> When we reach at the end of a word we mark the flag=true
 *
 *
 * */

#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[26];
    bool flag = false;

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

    void setWordEnd()
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
    /** Initialize the datastructure. */
    Trie()
    {
        root = new Node();
    }

    /** Insert a word into the trie=> O(N) */
    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->addNode(word[i]); // add the char
            }

            // move to next node
            node = node->getNode(word[i]);
        }

        node->setWordEnd();
    }

    /** Search O(N) */
    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getNode(word[i]);
        }

        // word ended check for flag
        return node->isEnd();
    }


    bool startsWith(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->getNode(word[i]);
        }

        // word ended 
        return true;
    }
};

int main()
{

    return 0;
}
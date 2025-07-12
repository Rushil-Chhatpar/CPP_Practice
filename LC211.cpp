#include "headers.h"

using namespace std;

class WordDictionary
{
    class TrieNode
    {
    public:
        TrieNode()
            : _isEOW(false)  // End of Word flag
        {};

        unordered_map<char, TrieNode*> _next;
        bool _isEOW;
    };

public:
    WordDictionary()
    {
        _root = new TrieNode();
    }
    
    void addWord(string word)
    {
        TrieNode* current = _root;
        for(char c : word)
        {
            if(current->_next.find(c) == current->_next.end())
                current->_next[c] = new TrieNode();
            
            current = current->_next[c];
        }
        current->_isEOW = true;
    }
    
    bool search(string word)
    {
        return searchWithNode(word.c_str(), _root);
    }

private:
    bool searchWithNode(const char* word, TrieNode* node)
    {
        if(word[3])
            char test = word[3];
        for(int i = 0; node; i++)
        {
            if(word[i] == '\0')
                return node->_isEOW;  // If we reach the end of the word, check if it's an end of a word
            if(word[i] != '.')
            {
                if(node->_next.find(word[i]) == node->_next.end())
                    return false;
                node = node->_next[word[i]];
            }
            else
            {
                // If we encounter a '.', we need to check all possible children
                for(auto& pair : node->_next)
                {
                    if(searchWithNode(word + i + 1, pair.second))
                        return true;
                }
                // If no match found, return false
                return false;
            }
            
        }
        return node && node->_isEOW;
    }

private:
    TrieNode* _root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 int main()
 {
    boolalpha(cout);
    WordDictionary* obj = new WordDictionary();
    obj->addWord("bad");
    obj->addWord("dad");
    obj->addWord("mad");
    cout << obj->search("pad") << endl; // returns false
    cout << obj->search("bad") << endl; // returns true
    cout << obj->search(".ad") << endl; // returns true
    cout << obj->search("b..") << endl; // returns true
    cout << obj->search("b..d") << endl; // returns false
        

    return 0;
 }
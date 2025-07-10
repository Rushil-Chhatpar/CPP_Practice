#include "headers.h"

using namespace std;

class Trie
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
    Trie()
    {
        _root = new TrieNode();
    }
    
    void insert(string word)
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
        TrieNode* current = _root;
        for(char c : word)
        {
            if(current->_next.find(c) == current->_next.end())
                return false;
            
            current = current->_next[c];
        }
        return current->_isEOW;
    }
    
    bool startsWith(string prefix)
    {
        TrieNode* current = _root;
        for(char c : prefix)
        {
            if(current->_next.find(c) == current->_next.end())
                return false;
            
            current = current->_next[c];
        }

        return true;
    }

private:
    TrieNode* _root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 int main()
 {
    boolalpha(cout);
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl; // returns true
    cout << trie.search("app") << endl; // returns false
    cout << trie.startsWith("app") << endl; // returns true
    trie.insert("app");
    cout << trie.search("app") << endl; // returns true
    return 0;
 }
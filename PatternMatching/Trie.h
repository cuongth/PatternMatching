#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    std::string *word;
    bool isEnd;

    TrieNode() : word(nullptr), isEnd(false) {}
    ~TrieNode() {
        delete word;
        for (std::pair<char, TrieNode *> p : children) {
            delete p.second;
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie();
    ~Trie();
    /// @throws std::bad_alloc only
    void insert(const std::string &word);
    void search(const std::string &road, std::vector<std::pair<std::string, int>> &matches) const;
};

#endif //TRIE_H

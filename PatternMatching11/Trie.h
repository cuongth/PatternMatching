#ifndef TRIE_H
#define TRIE_H
#include <memory>
#include <unordered_map>
#include <vector>

struct TrieNode {
    std::unordered_map<char, std::unique_ptr<TrieNode>> children;
    std::unique_ptr<std::string> word;
    bool isEnd;

    TrieNode() : word(nullptr), isEnd(false) {}
    // using unique_ptr, we don't need destructor ~TrieNode();
};

class Trie {
private:
    std::unique_ptr<TrieNode> root;
public:
    Trie();
    // using unique_ptr, we don't need destructor ~Trie();
    void insert(const std::string& word);
    void search(const std::string& road, std::vector<std::pair<std::string, int>>& matches) const;
};



#endif //TRIE_H

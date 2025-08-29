#include "Trie.h"

Trie::Trie() : root(std::make_unique<TrieNode>())
{}

void Trie::insert(const std::string& word) {
    TrieNode* node = root.get();
    for (const char& c : word) {
        if (!node->children.contains(c)) {
            node->children[c] = std::make_unique<TrieNode>();
        }
        if (!node->children[c]) // if there is exception on std::make_unique
            throw std::bad_alloc();
        node = node->children[c].get();
    }
    node->isEnd = true;
    node->word = std::make_unique<std::string>(word);
    if (!node->word)
        throw std::bad_alloc();
}

void Trie::search(const std::string& road, std::vector<std::pair<std::string, int>>& matches) {
    for (int i = 0; i < road.size(); ++i) {
        TrieNode* node = root.get();
        for (int j = i; j < road.size(); ++j) {
            if (node->children.find(road[j]) == node->children.end()) {
                break;
            }
            node = node->children[road[j]].get();
            if (node->isEnd) {
                std::string word(*(node->word.get()));
                matches.emplace_back(word, i);
            }
        }
    }
}



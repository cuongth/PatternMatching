#include "Trie.h"

#include <iostream>

Trie::Trie() : root(new TrieNode())
{}

Trie::~Trie() {
    delete root;
}
void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (const char& c : word) {
        if (!node->children.contains(c)) {
            try {
                node->children[c] = new TrieNode();
            } catch (const std::bad_alloc& e) {
                node->isEnd = true;
                std::cerr << e.what() << std::endl;
                throw std::bad_alloc();
            }
        }
        node = node->children[c];
    }
    node->isEnd = true;
    try {
        node->word = new std::string(word);
    } catch (const std::bad_alloc& e) {
        std::cerr << e.what() << std::endl;
        throw std::bad_alloc();
    }
}

void Trie::search(const std::string& road, std::vector<std::pair<std::string, int>>& matches) const {
    for (int i = 0; i < road.size(); ++i) {
        TrieNode* node = root;
        for (int j = i; j < road.size(); ++j) {
            if (node->children.find(road[j]) == node->children.end()) {
                break;
            }
            node = node->children[road[j]];
            if (node->isEnd && node->word) {
                std::string word(*(node->word));
                matches.emplace_back(word, i);
            }
        }
    }
}

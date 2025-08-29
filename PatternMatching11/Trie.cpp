#include "Trie.h"

Trie::Trie() : root(std::make_unique<TrieNode>())
{}

void Trie::insert(const std::string& word) {
    TrieNode* node = root.get();
    for (const char& c : word) {
        if (!node->children.contains(c)) {
            node->children[c] = std::make_unique<TrieNode>();
        }
        if (!node->children[c]) {
            // std::make_unique failed to create smart pointer
            break;
        }
        node = node->children[c].get();
    }
    node->isEnd = true;
    node->word = std::make_unique<std::string>(word);
}

void Trie::search(const std::string& road, std::vector<std::pair<std::string, int>>& matches) const {
    for (int i = 0; i < road.size(); ++i) {
        TrieNode* node = root.get();
        for (int j = i; j < road.size(); ++j) {
            if (!node->children.contains(road[j])) {
                break;
            }
            node = node->children[road[j]].get();
            if (node->isEnd && node->word) {
                std::string word(*(node->word));
                matches.emplace_back(word, i);
            }
        }
    }
}



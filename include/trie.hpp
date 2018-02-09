#ifndef TRIE_HPP
#define TRIE_HPP

#include <map>
#include <string>
#include <vector>

struct trie_node
{
    std::map<char, trie_node *> children;

    trie_node() {}
    ~trie_node() {
        for (const std::pair<char, trie_node *> &p : this->children) {
            delete p.second;
        }
    }
};

class trie
{
private:
    trie_node *_root;

public:
    trie();
    ~trie();

    trie_node *root();

    void insert_word(trie_node *from_node, const std::string &word);
    bool is_pattern_present(const trie_node *from_node, const std::string &pattern);
    void get_all_patterns(trie_node *from_node, std::vector<std::string> &patterns);

private:
    void dfs_into_patterns(trie_node *from_node, std::string prefix, std::vector<std::string> &patterns);
};

#endif
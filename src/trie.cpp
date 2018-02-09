#include "trie.hpp"

trie::trie() : _root(new trie_node())
{

}

trie::~trie()
{
    delete _root;
}

trie_node *trie::root()
{
    return _root;
}

void trie::insert_word(trie_node *from_node, const std::string &word)
{
    trie_node *root = from_node;
    for (const char &c : word) {
        if (root->children.find(c) == root->children.end()) {
            trie_node *new_node = new trie_node();
            root->children[c] = new_node;

            root = new_node; 
        } else {
            root = root->children[c];
        }
    }
}

bool trie::is_pattern_present(const trie_node *from_node, const std::string &pattern)
{
    return false;
}

void trie::get_all_patterns(trie_node *from_node, std::vector<std::string> &patterns)
{
    std::string prefix = "";
    dfs_into_patterns(from_node, prefix, patterns);
}

void trie::dfs_into_patterns(trie_node *from_node, std::string prefix, std::vector<std::string> &patterns)
{
    if (from_node->children.size() == 0) {
        if (!prefix.empty()) {
            patterns.push_back(prefix);
        }
    } else {
        for (const std::pair<char, trie_node *> &p : from_node->children) {
            dfs_into_patterns(p.second, prefix + p.first, patterns);
        }
    }
}
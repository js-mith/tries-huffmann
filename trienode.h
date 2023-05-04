class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(string word)
    {
        
        return search(this->root, word);
    }

    bool search(TrieNode *root, string word)
    {

        if (word.size() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'a';

        bool ans;
        if (root->children[index] != NULL)
            ans = search(root->children[index], word.substr(1));
        else
            ans = false;
        return ans;
    }

    void removeword(TrieNode *root, string word){
         if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
           return ;
        }

        removeword(child , word.substr(1));

        //remove child node if it is useless

        if(child -> isTerminal == false){
            for(int i =0 ; i < 26 ; i++){
                if(child -> children[i] != NULL){
                    return ;
                }
            }
            delete child;
            root -> children[index] = NULL;
        }

    }

    void removeword(string word){
        removeword(root , word);
    }
};
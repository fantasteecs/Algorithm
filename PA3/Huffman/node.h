#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
    unsigned freq;
    char character;
    node* lchild=NULL;
    node* rchild=NULL;
    string code;
    int flag=0;

private:

};

class huffcoding
{
public:
    string huffman_coding[128];
    void coding_tree();
    int coding(node* parent, string code);
    void initial();
    string text;
    int ascii_freq[128] = {0};
    vector<int> freq;
    vector<char> character;
    vector<node*> nodelist;
    void print();
};

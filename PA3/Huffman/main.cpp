#include "node.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

bool compare(node* a, node* b) {
    return (a->freq > b->freq);
}

//???int coding_tree(vector<node*> &nlist);
//???int coding(node* parent, string code);


int main()
{
 //std::string str="We think in generalities, but we live in details.";
 //std::string str2 = str.substr (2,5);

    huffcoding *Coding;
    Coding = new huffcoding;
    Coding->initial();
    Coding->coding_tree();
    Coding->print();


    return 0;
}

void huffcoding::initial()
{

    getline(cin, text);

    for (int i = 0; i < text.size(); ++i)
    {
       if((int)text[i]<0)
        {
            char qq='-';
            freq.push_back(2);
            character.push_back(qq);
            //cout<<character[0]<<(int)('-')<<endl;
            ++i;
        }
        else
        {
            ascii_freq[ (int)(text[i]) ]++;
        }

    }

    for (int i = 0; i < 128; ++i)
	{
        if(ascii_freq[i]>0) {
            freq.push_back(ascii_freq[i]);
            character.push_back(i);
        }
    }

    node *Node;

    for (int i = 0; i < freq.size(); i++) {

        Node = new node;
        Node->freq = freq[i];
        Node->character = character[i];
        nodelist.push_back(Node);
        Node->flag=1;
    }
}

void huffcoding::coding_tree()
{
    node *Node;
    //cout<<"raw:"<<nlist.size()<<endl;
    int times=nodelist.size()-1;
    for (int i = 0; i < times; ++i)
    {
        //cout<<nlist.size()<<endl;
        stable_sort(nodelist.begin(), nodelist.end(), compare);
        Node = new node;
        Node->freq = nodelist[nodelist.size()-1]->freq + nodelist[nodelist.size()-2]->freq;

        Node->lchild = nodelist[nodelist.size()-2];
        Node->rchild = nodelist[nodelist.size()-1];
        nodelist.pop_back();
        nodelist.pop_back();
        nodelist.push_back(Node);
    }
    coding(nodelist.front(), "");

}

int huffcoding::coding(node* parent, string code)
{

    if(parent->lchild!=NULL) {
        parent->lchild->code = code + "0";
        if(parent->lchild->flag==1)
        {
            huffman_coding[(int)(parent->lchild->character)]=parent->lchild->code;
           // cout<<parent->lchild->character<<"  "<<(int)(parent->lchild->character)<<"  "<<huffman_coding[(int)(parent->lchild->character)]<<endl;
        }
        else
        {
            coding(parent->lchild, parent->lchild->code);
        }

    }

    if(parent->rchild!=NULL) {
        parent->rchild->code = code + "1";
        if(parent->rchild->flag==1)
        {
            huffman_coding[(int)(parent->rchild->character)]=parent->rchild->code;
           // cout<<parent->rchild->character<<"  "<<(int)(parent->rchild->character)<<"  "<<huffman_coding[(int)(parent->rchild->character)]<<endl;
        }
        else
        {
            coding(parent->rchild, parent->rchild->code);
        }
    }
    return 0;

}

void huffcoding::print()
{   cout<<"\nResult:\nid:[char,freq]:huffman_coding"<<endl;
    for (int i = 0; i < freq.size(); i++)
    {
        cout<<i<<":["<<character[i]<<","<<freq[i]<<"]:"<<huffman_coding[(int)character[i]]<<endl;
    }
    cout<<"encoded_text:\n";
    for(int i=0;i<text.size();i++)
    {
        if((int)text[i]<0)
        {
            cout<<huffman_coding[45];
            cout<<huffman_coding[45];
            ++i;
        }
        else
        {
            cout<<huffman_coding[(int)text[i]];
        }
    }


    ofstream out;
    out.open("encoded_text.txt");
     for (int i = 0; i < freq.size(); i++)
    {
        out<<character[i]<<":"<<huffman_coding[(int)character[i]]<<endl;
    }
    for(int i=0;i<text.size();i++)
    {
        if((int)text[i]<0)
        {
            out<<huffman_coding[45];
            out<<huffman_coding[45];
            ++i;
        }
        else
        {
            out<<huffman_coding[(int)text[i]];
        }
    }

}
